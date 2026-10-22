#include <iostream>
#include <cstdlib> // Required for srand() and rand()
#include <ctime>   // Required for time()
#include "sorting.h"

const int maxSize = 100;

void displayArr(int arr[]);

int main() {
    // create an array with unsorted list with 100 maxim
    int unsortedArr[maxSize];
    // use time (0) as seed for random values
    srand(time(0));
    // populate the array with random values
    for(int i = 0; i < maxSize; i++) {
        unsortedArr[i] = rand() % 100;
    }
    std::cout << "This is the unsorted 100 list" << std::endl;
    displayArr(unsortedArr);
    std::cout << "This is the bubble sort" << std::endl;
    bubbleSort(unsortedArr, maxSize);
    displayArr(unsortedArr);
    std::cout << "This is the selection sort" << std::endl;
    selectionSort(unsortedArr, maxSize);
    displayArr(unsortedArr);
    std::cout << "This is the insertion sort" << std::endl;
    insertionSort(unsortedArr, maxSize);
    displayArr(unsortedArr);
}

void displayArr(int arr[]) {
    for (int i = 0; i < maxSize; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}