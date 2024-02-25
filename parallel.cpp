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
struct Thread {
    vector<int>& arr;
    int low;
    int high;
};

void* threadAssign(void* arg) {
    // assigning arguments to threads
    Thread* args = static_cast<Thread*>(arg);
    vector<int>& arr = args->arr;
    int low = args->low;
    int high = args->high;

    if (low < high) {
        int mid= dividing(arr, low, high);

        // creating threads for the left and right parts of arrays
        pthread_t leftThread, rightThread;
        Thread leftArgs = {arr, low, mid - 1};
        Thread rightArgs = {arr, mid + 1, high};
        pthread_create(&leftThread, NULL, threadAssign, &leftArgs);
        pthread_create(&rightThread, NULL, threadAssign, &rightArgs);


        pthread_join(leftThread, NULL);
        pthread_join(rightThread, NULL);
    }

    pthread_exit(NULL);
}

// performing parallel quicksort 
void quickSort(vector<int>& arr, int low, int high) {
    pthread_t thread;
    Thread args = {arr, low, high};
    pthread_create(&thread, NULL, threadAssign, &args);
    pthread_join(thread, NULL);
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

   

   
    auto start = high_resolution_clock::now();

    // Perform quicksort
    quickSort(arr, 0, n - 1);

    auto stop = high_resolution_clock::now();
       
    auto duration = duration_cast<nanoseconds>(stop - start);
    cout << "Time taken by quicksort: " << duration.count() << " nanoseconds " << endl;

    return 0;
}

