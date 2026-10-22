#include<iostream>
#include"singly_ll.h"
#include"double_ll.h"

int main(){

    doubleList<char>* head = new_Node('C');
    // creation of other nodes
    doubleList<char>* second = new_Node('P');
    doubleList<char>* third = new_Node('E');

    //LINK THE NODES
    head->next = second;
    second->prev = head;

    second->next = third;
    third->prev = second;

    std::cout << "Initial Traversal:" << std::endl;
    dllTraverse(head);

    std::cout << "Inserting at the head" << std::endl;
    dllInsertHead('G',&head);
    dllTraverse(head);

    std::cout << "Inserting at the end" << std::endl;
    dllInsertEnd('1', &head);
    dllTraverse(head);

    std::cout << std::endl << std::endl;
    std::cout << "deleting a node \n";
    dllDelete('S', &head);
    dllTraverse(head);

    std::cout << std::endl << std::endl;
    dllGeneralInsertion('4', head->next->next);
    dllTraverse(head);

    return 0;
}







