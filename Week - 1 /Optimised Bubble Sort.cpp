#include <iostream>
#include <vector>
#include <sstream>

void optimizedBubbleSort(std::vector<int>& arr) {
    bool swapped;
    int n = arr.size();

    for (int i = 0; i < n - 1; ++i) {
        swapped = false;

        // Last i elements are already in place, no need to check them
        for (int j = 0; j < n - i - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                // Swap arr[j] and arr[j + 1]
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;

                swapped = true;
            }
        }

        // If no two elements were swapped in inner loop, the array is already sorted
        if (!swapped) {
            break;
        }
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

    // Perform optimized bubble sort
    optimizedBubbleSort(arr);

    // Print the sorted array
    for (const int& element : arr) {
        std::cout << element << " ";
    }

    return 0;
}
