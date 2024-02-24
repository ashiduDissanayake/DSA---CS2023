#include <iostream>
#include <vector>
#include <sstream>

void insertionSort(std::vector<int>& arr) {
    int n = (int) arr.size();
    for (int i = 1; i < n; ++i) {
        int key = arr[i];
        int j = i - 1;

        // Move elements of arr[0..i-1] that are greater than key
        // to one position ahead of their current position
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

int main() {

    std::string input;
    std::getline(std::cin, input);

    std::vector<int> arr;
    std::stringstream ss(input);
    int num;

    // Extract integers from the input string
    while (ss >> num) {
        arr.push_back(num);
    }

    // Perform insertion sort
    insertionSort(arr);

    // Print the sorted array
    for (int i = 0; i < (int) arr.size(); ++i) {
        std::cout << arr[i] << " ";
    }

    return 0;
}
