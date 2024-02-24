#include <iostream>

using namespace std;

// Function to merge two subarrays
// A[] is the array, start, mid1, mid2, end are the indices of the array where:
// start is the starting index of the first subarray
// mid1 is the ending index of the first subarray
// mid2 is the starting index of the second subarray
// end is the ending index of the second subarray
void merge(int A[], int start, int mid1, int mid2,  int end) {
    // Calculate the size of the two subarrays
    int n1 = mid1 - start + 1;
    int n2 = end - mid2 + 1;

    // Create temporary arrays to hold the subarrays
    int Left[n1];
    int Right[n2];

    // Copy the elements from the original array to the temporary arrays
    for (int i = 0; i < n1; i++)
        Left[i] = A[start + i];
    for (int i = 0; i < n2; i++) 
        Right[i] = A[mid2 + i];

    // Append INT_MAX to the end of both arrays to act as a sentinel
    Left[n1] = INT_MAX;
    Right[n2] = INT_MAX;

    // Initialize indices for the temporary arrays
    int i = 0;
    int j = 0;

    // Merge the temporary arrays back into the original array
    for (int k = start; k <= end; k++) {  
        if(Left[i] <= Right[j]) {
            A[k] = Left[i];
            i++;
        } else {
            A[k] = Right[j];
            j++;
        }
    }
}

// Function to perform iterative merge sort on array arr[] of size n
void mergerSort(int arr[], int n){
    // Initialize length of subarrays to be merged
    int len = 1;

    // Continue until the length of the subarray is less than the size of the array
    while (len < n){
        int i = 0;

        // Merge subarrays of current size
        while(i < n){
            // Calculate indices for subarrays to be merged
            int L1 = i; 
            int R1 = i + len - 1;
            int L2 = i + len;
            int R2 = i + 2*len - 1;

            // If the starting index of the second subarray is greater than the size of the array, break
            if (L2 >= n){
                break;
            }

            // If the ending index of the second subarray is greater than the size of the array, adjust it
            if (R2 >= n){
                R2 = n - 1;
            }

            // Merge the subarrays
            merge(arr, L1, R1, L2, R2);

            // Move to the next pair of subarrays
            i = i + 2 * len;
        }

        // Double the size of the subarray to be merged
        len = 2 * len; 
    }
}

// Driver function
int main(){
    // Initialize array
    int arr[] = {20, 25, 39, 0, 12, 12, 1};

    // Calculate size of array
    int size = sizeof(arr) / sizeof(int);

    // Perform merge sort on array
    mergerSort(arr, size);  

    // Print sorted array
    for(int i = 0; i < size; i++){
        cout << arr[i] << " ";
    }

    return 0;
}
