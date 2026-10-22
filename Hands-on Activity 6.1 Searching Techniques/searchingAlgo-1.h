#ifndef SEARCHING_ALGO_H
#define SEARCHING_ALGO_H
#include "nodes.h"

/*
N -> Boundary of the list
Item -> Searching number
Data -> Linear array
Step 1: I := 0
Step 2: Repeat while I <= n
If (item = data[i])
Print "Searching is successful"
Exit
Else
Print "Searching is Unsuccessful"
Exit
*/

template <typename T>
void linearSearchArr(T data[], int arrSize, T dataFind){
    //Step 1: I := 0
    int i = 0;

    //Repeat while I < arrSize
    while( i < arrSize ){
        if(dataFind == data[i]){
            std::cout << "The search is success\n";
            return;
        }
        //increment i to move to the next element
        i++;
    }
    std::cout << "The element is not found \n";
    return;
}

// nodes -> starting node
// item that we are searching 
template <typename T>
void linearSearchLL(Node<T>* node, T dataFind){
    //repeat the loop until the current node is null
    while(node != nullptr){
        // if item = current nodes data then display searching is successful
        if(dataFind == node->data){
            std::cout << "the search was a success\n";
            return;
        }
        //if not, move to the next node
        node = node->next;
    }
    // the searching reached nullptr, -> search is unsuccessful
    std::cout << "the search was unsuccessful\n";
} 

template <typename T>
Node<T>* getMiddle(Node<T>* start, Node<T>* last){
    //use two pointers: 1. slow one node at a time, fast moves two at a time
    Node<T>* slow = start;
    Node<T>* fast = start;

    //get middle:
    while(fast != last && fast->next != last){
        //move slow (one step)
        slow = slow->next;
        //move fast (two steps)
        fast = fast->next->next;
    }
    //when fast reaches the end
    // slow points to the middle node
    return slow;
}

template <typename T>
void binarySearchLL(Node<T>* start, T findData) {
    Node<T>* last = nullptr;

    while (start != last) {
        Node<T>* mid = getMiddle(start, last);

        if (mid == nullptr) {
            std::cout << "The search was unsuccessful\n";
            return;
        }

        if (mid->data == findData) {
            std::cout << "The search was a success\n";
            return;
        } else if (mid->data < findData) {
            start = mid->next;
        } else {
            last = mid;
        }
    }

    std::cout << "The search was unsuccessful\n";
}

template <typename T>
void binarySearchArr(T data[], int arrSize, T findData) {
    int low = 0;
    int high = arrSize - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (data[mid] == findData) {
            std::cout << "The search was a success\n";
            return;
        }
        if (data[mid] < findData) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    std::cout << "The search was unsuccessful\n";
}


template <typename T>
void linearSearchModified(T data[], int arrSize, T k){
    int i = 0;
    int compCount = 0;
    int instances = 0;

    while( i < arrSize ){
        compCount++;
        if(k == data[i]){
            instances++;
        }
        i++;
    }

    if(instances > 0){
        std::cout << "The search was a success\n";
        std::cout << "Total comparisons made: " << compCount << "\n";
        std::cout << "Repeating instances for " << k << ": " << instances << "\n";
    } else {
        std::cout << "The search was unsuccessful\n";
    }
}

template <typename T>
void binarySearchTrace(T data[], int arrSize, T findData) {
    int low = 0;
    int high = arrSize - 1;
    int step = 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;
        std::cout << "Iteration " << step << ": low=" << low << ", high=" << high << ", mid=" << mid << " (val=" << data[mid] << ")\n";

        if (data[mid] == findData) {
            std::cout << "The search was a success\n";
            return;
        }
        if (data[mid] < findData) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
        step++;
    }
    std::cout << "The search was unsuccessful\n";
}

template <typename T>
int binarySearchRecursive(T data[], int low, int high, T findData) {
    if (low > high) {
        return -1;
    }
    int mid = low + (high - low) / 2;

    if (data[mid] == findData) {
        return mid;
    }
    if (data[mid] < findData) {
        return binarySearchRecursive(data, mid + 1, high, findData);
    } else {
        return binarySearchRecursive(data, low, mid - 1, findData);
    }
}

#endif