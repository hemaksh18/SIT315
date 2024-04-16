#include <iostream>
#include <vector>
#include <chrono>
#include <cstdlib> 
#include <ctime>  
#include <thread>

using namespace std;
using namespace std::chrono;

int dividing(vector<int>& arr, int low, int high) {
    int rightEnd = arr[high]; 
    int i = low - 1; 

    for (int j = low; j < high; j++) {
        if (arr[j] < rightEnd) {
            i++;
            swap(arr[i], arr[j]); 
        }
    }
    swap(arr[i + 1], arr[high]); 
    return i + 1; 
}

void quickSort(vector<int>& arr, int low, int high, int chunk_size) {
    if (low < high) { 
        int pi = dividing(arr, low, high);

        if (high - low < chunk_size) {
            quickSort(arr, low, pi - 1, chunk_size);
            quickSort(arr, pi + 1, high, chunk_size);
        } else {
            thread left_thread(quickSort, ref(arr), low, pi - 1, chunk_size);
            thread right_thread(quickSort, ref(arr), pi + 1, high, chunk_size);

            left_thread.join();
            right_thread.join();
        }
    }
}

int main() {
    srand(time(0)); 
    vector<int> arr;
    const int SIZE = 1000; 
    for (int i = 0; i < SIZE; ++i) {
        arr.push_back(rand() % 100); 
    }

    auto start = high_resolution_clock::now();

    // Define chunk size
    int chunk_size = 10000;

    quickSort(arr, 0, SIZE - 1, chunk_size);

    auto stop = high_resolution_clock::now();

    auto duration = duration_cast<microseconds>(stop - start);
    cout << "Time taken by Quick Sort: " << duration.count() << " microseconds" << endl;

    return 0;
}
