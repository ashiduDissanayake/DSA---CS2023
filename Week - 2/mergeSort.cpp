#include <iostream>
#include <vector> // Include the vector header

using namespace std;

// Function to merge two subarrays into a single sorted array
void merge(int A[], int start, int mid, int end) {
    // Calculate the sizes of the two subarrays
    int n1 = mid - start + 1;
    int n2 = end - mid;

    // Create vectors to hold the subarrays
    std::vector<int> Left(n1);
    std::vector<int> Right(n2);

    // Copy data to temporary vectors Left[] and Right[]
    for (int i = 0; i < n1; i++)
        Left[i] = A[start + i];
    for (int i = 0; i < n2; i++)  
        Right[i] = A[mid + 1 + i];

    // Append INT_MAX to the end of both vectors to act as a sentinel
    Left.push_back(INT_MAX);
    Right.push_back(INT_MAX);

    // Initial indexes of first and second subarrays
    int i = 0;
    int j = 0;

    // Merge the temp arrays back into A[start..end]
    for (int k = start; k <= end; k++) { 
        // Pick the smaller element from Left and Right and put them in the original array
        if (Left[i] <= Right[j]) {
            A[k] = Left[i];
            i++;
        } else {
            A[k] = Right[j];
            j++;
        }
    }
}

// Function to implement merge sort
void mergerSort(int A[], int start, int end) {
    // Base case: If the array has only one element or no element, then return
    if (start < end) {
        // Find the middle point to divide the array into two halves
        int mid = (start + end) / 2;

        // Call mergeSort for first half
        mergerSort(A, start, mid);

        // Call mergeSort for second half
        mergerSort(A, mid + 1, end);  

        // Merge the two halves sorted in step 2 and 3
        merge(A, start, mid, end);
    }
}

// Driver code
int main() {
    // Define a vector to be sorted
    vector<int> arr;
    int n, input;

    // Ask the user for the number of elements
    cout << "Enter the number of elements: ";
    cin >> n;

    // Take user input for the elements
    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++) {
        cin >> input;
        arr.push_back(input);
    }

    // Convert the vector to an array
    int* arrPtr = &arr[0];

    // Call the merge sort function
    mergerSort(arrPtr, 0, n - 1); 

    // Print the sorted array
    cout << "Sorted array: ";
    for(int i = 0; i < n; i++){
        cout << arrPtr[i] << " ";
    }

    return 0;
}
