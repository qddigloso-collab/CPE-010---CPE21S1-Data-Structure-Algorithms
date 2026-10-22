#ifndef SORTINGALGO_H
#define SORTINGALGO_H
#include <iostream>
#include <utility>

template <typename T>
void bubbleSort(T arr[], int arrSize) {
    for (int i = 0; i < arrSize - 1; i++) {
        for (int j = i+1 ; j < arrSize - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                std::swap(arr[j], arr[i]);
            }
        }
    }
}

template <typename T>
void insertionSort(T arr[], int arrSize){
    int k = 1, j, temp;

    while(k < arrSize){
        temp = arr[k];
        j = k-1;
        while(j >= 0 && temp <= arr[j]){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = temp;
        k++;
    }
}

template <typename T>
int routine_smallest(T A[], int maxSize, int k){
    int position, j;
    T smallestElem = A[k];
    for(int J = k+1; J < maxSize; J++){
        if(A[J] < smallestElem){
            smallestElem = A[J];
            position = J;
        }
    }
    return position;
}
template <typename T>
void selectionSort(T arr[], int arrSize){
    int POS, temp;
    for(int i = 0; i < arrSize; i++){
        POS = routine_smallest(arr, arrSize, i);
        // returns the index of the smallest value
        temp = arr[i];
        arr[i] = arr[POS];
        arr[POS] = temp;
    }
}

template <typename T>
void Insertion(T arr[], int arrSize) {
    T temp;
    for (int k = 1; k < arrSize; k++) {
        temp = arr[k];
        int j;
        for (j = k - 1; j >= 0 && temp <= arr[j]; j--) {
            arr[j + 1] = arr[j];
        }
        arr[j + 1] = temp;
    }
}
#endif