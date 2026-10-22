#include <iostream>
#include <cstdlib> // Required for srand() and rand()
#include <ctime>   // Required for time()
#include "sortingalgor.h"

const int maxSize = 100;
void displayArr(int arr[]);

int main() {
    // create an array with unsorted list with 100 maximum
    int unsortedArr[maxSize];
    // use time (0) as seed for random values
    srand(time(0));
    // populate the array with random values
    for(int i = 0; i < maxSize; i++) {
        unsortedArr[i] = rand() % 100;
    }
    std::cout << "This is the shell sort" << std::endl;
    shellSort(unsortedArr, maxSize);
    displayArr(unsortedArr);
    std::cout << "This is the merge sort" << std::endl;
    merge_sort(unsortedArr, 0, maxSize - 1);
    displayArr(unsortedArr);
    std::cout << "This is the quick sort" << std::endl;
    quicksort(unsortedArr, 0, maxSize - 1);
    displayArr(unsortedArr);
}

void displayArr(int arr[]) {
    for (int i = 0; i < maxSize; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}