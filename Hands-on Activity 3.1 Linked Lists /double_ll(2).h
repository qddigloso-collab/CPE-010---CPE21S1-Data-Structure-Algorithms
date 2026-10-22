#ifndef DOUBLE_LL_H
#define DOUBLE_LL_H

template <typename T>
class doubleList{
    public:
    T data;
    doubleList<T>* next = nullptr;
    doubleList<T>* prev = nullptr;
};

// creating the node
template <typename T>
doubleList<T>* new_Node(T newData){
    // dynamically allocate memory for a new node
    doubleList<T>* newNode = new doubleList<T>;
    // store data in the node
    newNode->data = newData;
    // since its a new node, it will point to null
    newNode->next = nullptr;
    newNode->prev = nullptr;
    return newNode;
}

template <typename T>
void dllTraverse(doubleList<T>* currentNode){
    doubleList<T>* tail = nullptr;
    // traversal to the end
    std::cout << "Forward traversal: ";
    while(currentNode != nullptr){
        //prints the data
        std::cout << currentNode->data << "  ";
        // save the current node as the last visited node
        tail = currentNode;
        // move to the next node
        currentNode = currentNode->next;
    }
    std::cout << std::endl;
    // reverse traversal
    std::cout << "Reverse traversal: ";
    while (tail != nullptr){
        std::cout << tail->data << " ";
        tail = tail->prev;
    }
}

template <typename T>
void dllInsertHead(T newData, doubleList<T>** currentHead){
    // create a newNode
    doubleList<T>* newNode = new_Node(newData);
    // set the new node to point to the current head
    newNode->next = *currentHead;
    (*currentHead)->prev = newNode;
    // update the head pointer
    *currentHead = newNode;
}

// insertion at the end
template <typename T>
void dllInsertEnd(T newData, doubleList<T>** currentHead){
    // create a new node
    doubleList<T>* newNode = new_Node(newData);
    
    doubleList<T>* currentNode = *currentHead;
    // traverse until the last node
    while(currentNode->next != nullptr){
        currentNode = currentNode->next;
    }
    // connect the last node to the new node
    currentNode->next = newNode;
    //connect the prev node to the new node
    newNode->prev = currentNode;
}

template <typename T>
void dllDelete(T findData, doubleList<T>** head){
    // check if there is a list
    if (*head == nullptr) return;
    doubleList<T>* currNode = *head;
    doubleList<T>* prevNode = nullptr;
    // Search for the node
    while (currNode != nullptr && currNode->data != findData){
        prevNode = currNode;
        currNode = currNode->next;
    }
    // if data is not found
    if (currNode == nullptr) return;
    // delete the head node (the head node is the findData)
    if (prevNode == nullptr){
        *head = currNode->next;
        if (*head != nullptr){
            (*head)->prev = nullptr;
        }
    } else {
        prevNode->next = currNode->next;
        if (currNode->next != nullptr){
            currNode->next->prev = prevNode;
        }
    }

    delete currNode;
}

template <typename T>
void dllGeneralInsertion(T newData, doubleList<T>* prevNode){
    // check if the prev node is not null
    if (prevNode == nullptr){
        std::cout << "The Previous node cannot be null." << std::endl;
        return;
    }
    doubleList<T>* newNode = new doubleList<T>;
    newNode->data = newData;
    newNode->next = prevNode->next;
    newNode->prev = prevNode;
    if (prevNode->next != nullptr){
        prevNode->next->prev = newNode;
    }

    prevNode->next = newNode;
}


#endif