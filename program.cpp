#include <iostream>
#include <vector>
#include <chrono>
#include <cstdlib> // For rand() function

using namespace std;
using namespace std::chrono;

// Function that divides the array and then returns the index of positioned element
int dividing(vector<int>& arr, int low, int high) {
    int rightEnd = arr[high]; // selecting the right most element to compare
    int i = low - 1; // Index of smaller element smaller than the element that has to be placed

    for (int j = low; j < high; j++) {
        // If current element is smaller than the right most
        if (arr[j] < rightEnd) {
            i++; // elements moves to the left 
            swap(arr[i], arr[j]); // Swap arr[i] and arr[j]
        }
    }
    swap(arr[i + 1], arr[high]); // Swap arr[i+1] and right most elment
    return i + 1;
}

// Function to perform quicksort
void quickSort(vector<int>& arr, int low, int high) {
    if (low < high) { // it checks if the index is already divided 
        // dividing index
        int pi = dividing(arr, low, high);

        // sorts the element in left or right from middle 
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {
    // 
    srand(time(0));

    // random values for the array
    vector<int> arr;
    for (int i = 0; i < 100; ++i) {
        arr.push_back(rand() % 100);
    }
    int n = arr.size();

   

    // Start time measurement
    auto start = high_resolution_clock::now();

    // Perform quicksort
    quickSort(arr, 0, n - 1);

    // End time measurement
    auto stop = high_resolution_clock::now();

    

    
    auto duration = duration_cast<nanoseconds>(stop - start);
    cout << "Time taken by quicksort: " << duration.count() << " nanoseconds " << endl;

    return 0;
}