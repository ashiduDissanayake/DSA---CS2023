#include <iostream>
#include <vector>
#include <sstream>

void selectionSort(std::vector<int>& arr) {
    int n = arr.size();

    for (int i = 0; i < n - 1; ++i) {
        // Find the minimum element in the unsorted part of the array
        int minIndex = i;
        for (int j = i + 1; j < n; ++j) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }

        // Swap the found minimum element with the first element
        int temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;
    }
}

int main() {
    std::string input;
    std::getline(std::cin, input);

    std::vector<int> arr;
    int num;

    // Extract integers from the input string
    std::istringstream iss(input);
    while (iss >> num) {
        arr.push_back(num);
    }

    // Perform selection sort
    selectionSort(arr);

    // Print the sorted array
    for (const int& element : arr) {
        std::cout << element << " ";
    }

    return 0;
}
