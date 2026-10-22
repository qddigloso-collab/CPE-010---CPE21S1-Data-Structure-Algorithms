#include <iostream>
#include "nodes.h"
#include "searchingAlgo.h"

int main() {
    int list1[10] = {15, 18, 2, 19, 18, 0, 8, 14, 19, 14};

    Node<int>* node1 = new_node(15);
    Node<int>* node2 = new_node(18);
    Node<int>* node3 = new_node(2);
    Node<int>* node4 = new_node(19);
    Node<int>* node5 = new_node(18);
    Node<int>* node6 = new_node(0);
    Node<int>* node7 = new_node(8);
    Node<int>* node8 = new_node(14);
    Node<int>* node9 = new_node(19);
    Node<int>* node10 = new_node(14);

    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;
    node5->next = node6;
    node6->next = node7;
    node7->next = node8;
    node8->next = node9;
    node9->next = node10;

    linearSearchModified(list1, 10, 18);

    int list2[10] = {3, 5, 6, 8, 11, 12, 14, 15, 17, 18};

    binarySearchTrace(list2, 10, 8);

    int result = binarySearchRecursive(list2, 0, 9, 8);
    if (result != -1) {
        std::cout << "The search was a success at index " << result << "\n";
    } else {
        std::cout << "The search was unsuccessful\n";
    }

    return 0;
}