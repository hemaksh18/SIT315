#include <chrono>
#include <cstdlib>
#include <iostream>
#include <time.h>

using namespace std::chrono;
using namespace std;

// assigning random values to fill the array 
void randomVector1(int v1[], int size) {
  for (int i = 0; i < size; i++) {
    v1[i] = rand() % 100;
  }
}
// assigning random values to fill the array 
void randomVector2(int v2[], int size) {
  for (int i = 0; i < size; i++) {
    v2[i] = rand() % 100;
  }
}
// addition of the two arrays to form the third one 
void add( int *v1, int *v2, int *v3, int size)
{
    for (int i = 0; i < size; i++) {
    v3[i] = v1[i] + v2[i];
  }
}


  
int main() {
  unsigned long size = 100000000; // size of arrays 
  srand(time(0));
  int *v1, *v2, *v3; // initalising pointers 
  
  // beginning of the execution time measurement high resoulution clock
  auto start = high_resolution_clock::now();
 // allocating integral values to arrays 
  v1 = (int *)malloc(size * sizeof(int));
  v2 = (int *)malloc(size * sizeof(int));
  v3 = (int *)malloc(size * sizeof(int));

  // calling functions 
  randomVector1(v1, size);
  randomVector2(v2, size);

  add(v1,v2,v3,size);

  auto stop = high_resolution_clock::now(); // execution time measuring stops 
  auto duration = duration_cast<microseconds>(stop - start); 
  cout << "Time taken by function :" << duration.count() << " microseconds"
    << endl;
  
  return 0;
}