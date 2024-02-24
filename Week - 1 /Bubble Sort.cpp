#include <iostream>
#include <vector>

using namespace std;

void bubbleSort(vector<int>& arr) {//taking the reference to modify the original
    int n = arr.size();
    bool swapped;
		//this do-while loop is running unless the inside array is sorted.
    do {
        swapped = false;
				//this for loop is bubbling the largest element in every turn
        for (int i = 1; i < n; i++) {
            if (arr[i - 1] > arr[i]) {//getting the maximum of adjacent.
                int temp = arr[i];
                arr[i] = arr[i - 1];
                arr[i - 1] = temp;
                swapped = true;//if there is atleast one swap that means this is not sorted.
            }
        }
    } while (swapped);
}

int main() {
    vector<int> arr;
    // Read integers from the input and store them in the vector.
    int num;
    while (cin >> num) {
        arr.push_back(num);
    }

		//calling the function.
    bubbleSort(arr);

		//Printing the sorted array.
    for (int x : arr) {
        cout << x << " ";
    }
    return 0;
}
