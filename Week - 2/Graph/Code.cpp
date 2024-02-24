#include <iostream>
#include <chrono>
#include <vector>
#include <cstdlib>
#include <fstream>
#include "matplotlibcpp.h"

namespace plt = matplotlibcpp;
using namespace std;
using namespace chrono;


void merge(int A[], int start, int mid1, int mid2,  int end) {
    int n1 = mid1 - start + 1;
    int n2 = end - mid2 + 1;

    int Left[n1];
    int Right[n2];

    for (int i = 0; i < n1; i++)
        Left[i] = A[start + i];
    for (int i = 0; i < n2; i++) 
        Right[i] = A[mid2 + i];

    Left[n1] = INT_MAX;
    Right[n2] = INT_MAX;

    int i = 0;
    int j = 0;

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

void mergerSort(int arr[], int n){
    int len = 1;
    while (len < n){
        int i = 0;
        while(i < n){
            int L1 = i; 
            int R1 = i + len - 1;
            int L2 = i + len;
            int R2 = i + 2*len - 1;
            if (L2 >= n){
                break;
            }
            if (R2 >= n){
                R2 = n - 1;
            }
            merge(arr, L1, R1, L2, R2);
            i = i + 2 * len;
        }
        len = 2 * len; 
    }
}
void merge(int A[], int start, int mid, int end) {
    int n1 = mid - start + 1;
    int n2 = end - mid;

    int Left[n1];
    int Right[n2];

    for (int i = 0; i < n1; i++)
        Left[i] = A[start + i];
    for (int i = 0; i < n2; i++)  
        Right[i] = A[mid + 1 + i];

    Left[n1] = INT_MAX;
    Right[n2] = INT_MAX;

    int i = 0;
    int j = 0;

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

void mergerSort(int A[], int start, int end) {
    if (start < end) {
        int mid = (start + end) / 2;
        mergerSort(A, start, mid);
        mergerSort(A, mid + 1, end);  
        merge(A, start, mid, end);
    }
}

int main(){
    ofstream outputFile;
    vector<vector<vector<int> > > sample;
    for(int i = 3; i < 50; i ++){
        vector<vector<int> > temp1;
        for(int j = 0 ; j < 5; j++){
            vector<int> temp2;
            for(int k = 0; k < i; k++){
                int a = rand() % 10;
                temp2.push_back(a);
            }
            temp1.push_back(temp2);
        }
        sample.push_back(temp1);
    }

    vector<double> avg_times_1;
    double avg;
    for(vector<vector<int> > a : sample){
        double time_sum;
        for(vector<int> b : a){
            vector<int> vector_array = b;
            int n =vector_array.size();
            int arr[n];
            for (int i = 0; i < n; i++){
                arr[i] = vector_array[i];
            }
            auto start = steady_clock::now();
            /////////////////////////////
            
            mergerSort(arr, 0, sizeof(arr) / sizeof(int) - 1); 

            /////////////////////////////
            auto end = steady_clock::now();
            auto diff = duration_cast<duration<double> >(end - start);
            double durationInSeconds = diff.count();
            time_sum += durationInSeconds;
        }
        avg = time_sum / 5;
        avg_times_1.push_back(avg);
    }

    vector<double> avg_times_2;
    for(vector<vector<int> > a : sample){
        double time_sum;
        for(vector<int> b : a){
            vector<int> vector_array = b;
            int n =vector_array.size();
            int arr[n];
            for (int i = 0; i < n; i++){
                arr[i] = vector_array[i];
            }
            auto start = steady_clock::now();
            /////////////////////////////
            
            mergerSort(arr, n);  

            /////////////////////////////
            auto end = steady_clock::now();
            auto diff = duration_cast<duration<double> >(end - start);
            double durationInSeconds = diff.count();
            time_sum += durationInSeconds;
        }
        avg = time_sum / 5;
        avg_times_2.push_back(avg);
    }

    vector<int> input_size(49-3);
    for(int i = 3; i < 50; i++){
        input_size.push_back(i);
    }    

    outputFile.open("data.txt");

    
    if (outputFile.is_open()) {
        // Write to the file using the stream insertion operator (<<)
        for(int i = 0; i < 48; i){
            outputFile << avg_times_1[i] << " " << input_size[i] << endl;
        }
        // Close the file when done
        outputFile.close();
        cout << "Output written to file successfully." << endl;
    } else {
        cout << "Unable to open file for writing." << endl;
    }


    // Plot the data
    plt::plot(input_size, avg_times_1);

    plt::plot(input_size, avg_times_2);

    // Set plot labels
    plt::xlabel("Input-Array-Size");
    plt::ylabel("Time-taken");
    plt::title("Time Complexity of Recursive and Iterative Merge Sort");

    // Save the plot to a file
    plt::save("plot.png");

    // Show the plot
    plt::show();
                
    return 0;
}
