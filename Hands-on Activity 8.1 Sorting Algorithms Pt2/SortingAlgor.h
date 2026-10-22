#ifndef SORTINGALGOR_H
#define SORTINGALGOR_H

#include <iostream>
#include <utility>

template <typename T>
void shellSort(T arr[], int size) {
    for (int i = size / 2; i > 0; i /= 2) {
        for (int j = i; j < size; j++) {
            T temp = arr[j];
            int k = j;
            while (k >= i && arr[k - i] > temp) {
                arr[k] = arr[k - i];
                k -= i;
            }
            arr[k] = temp;
        }
    }
}

template <typename T>
void merge(T Arr[], int left, int middle, int right) {
    int n1 = middle - left + 1;
    int n2 = right - middle;

    T* L = new T[n1];
    T* R = new T[n2];

    for (int i = 0; i < n1; i++) L[i] = Arr[left + i];
    for (int j = 0; j < n2; j++) R[j] = Arr[middle + 1 + j];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            Arr[k] = L[i];
            i++;
        } else {
            Arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        Arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        Arr[k] = R[j];
        j++;
        k++;
    }

    delete[] L;
    delete[] R;
}

template <typename T>
void merge_sort(T Arr[], int left, int right) {
    if (left < right) {
        int middle = (left + right) / 2;
        merge_sort(Arr, left, middle);
        merge_sort(Arr, middle + 1, right);
        merge(Arr, left, middle, right);
    }
}

template <typename T>
int partition(T A[], int low, int high) {
    T pivot = A[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (A[j] < pivot) {
            i++;
            std::swap(A[i], A[j]);
        }
    }
    std::swap(A[i + 1], A[high]);
    return i + 1;
}

template <typename T>
void quicksort(T A[], int low, int high) {
    if (low < high) {
        int pivot = partition(A, low, high);
        quicksort(A, low, pivot - 1);
        quicksort(A, pivot + 1, high);
    }
}

#endif