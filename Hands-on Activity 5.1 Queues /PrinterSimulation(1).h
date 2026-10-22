#ifndef PRINTER_SIMULATION_H
#define PRINTER_SIMULATION_H

#include <iostream>
#include <string>

template <typename T>
class qNode {
public:
    T data;
    qNode* next;
};

// Create a new node
template <typename T>
qNode<T>* new_node(T newData) {
    qNode<T>* newNode = new qNode<T>;
    newNode->data = newData;
    newNode->next = nullptr;
    return newNode;
}

template <typename T>
void enqueue(qNode<T>** frontPtr, qNode<T>** backPtr, T newData) {
    qNode<T>* newNode = new_node(newData);

    // Inserting into an empty queue
    if (*frontPtr == nullptr && *backPtr == nullptr) {
        *frontPtr = newNode;
        *backPtr = newNode;
    } else {
        (*backPtr)->next = newNode;
        *backPtr = newNode;
    }
}

template <typename T>
void dequeue(qNode<T>** frontPtr, qNode<T>** backPtr) {
    // Check if the queue is empty
    if (*frontPtr == nullptr) {
        std::cout << "Queue is empty\n";
        return;
    }
    qNode<T>* deleteNode = *frontPtr;
    *frontPtr = (*frontPtr)->next;
    if (*frontPtr == nullptr) {
        *backPtr = nullptr;
    }
    delete deleteNode;
}

template <typename T>
void printQueue(qNode<T>* frontPtr) {
    if (frontPtr == nullptr) {
        std::cout << "Queue is empty\n";
        return;
    }

    qNode<T>* current = frontPtr;
    int pos = 1;
    while (current != nullptr) {
        std::cout << " " << pos++ << ". Job ID: " << current->data.id
                  << " | User: " << current->data.userName
                  << " | Pages: " << current->data.pageCount << "\n";
        current = current->next;
    }
}

class Job {
public:
    int id;
    std::string userName;
    int pageCount;

    Job(int Id = 0, std::string uName = "", int pages = 0) {
        id = Id;
        userName = uName;
        pageCount = pages;
    }
};

class Printer {
private:
    qNode<Job>* front;
    qNode<Job>* back;
    int count;

public:
    Printer() {
        front = nullptr;
        back = nullptr;
        count = 0;
    }

    ~Printer() {
        while (front != nullptr) {
            dequeue(&front, &back);
        }
    }

    void addJob(int id, std::string userName, int pages) {
        Job newJob(id, userName, pages);
        enqueue(&front, &back, newJob);
        count++;
        std::cout << "-> Added Job #" << id << " from " << userName 
                  << " (" << pages << " pages) to the queue.\n";
    }

    void processNextJob() {
        if (front == nullptr) {
            std::cout << "Queue is empty.\n";
            return;
        }

        Job currentJob = front->data;
        dequeue(&front, &back);
        count--;

        std::cout << "Processing Job #" << currentJob.id 
                  << " (" << currentJob.userName << ", " 
                  << currentJob.pageCount << " pages)\n";
    }

    void displayQueue() {
        std::cout << "\n-------------------------------------------\n";
        std::cout << " Pending Printer Queue (" << count << " waiting)\n";
        std::cout << "-------------------------------------------\n";
        printQueue(front);
        std::cout << "-------------------------------------------\n\n";
    }
};

#endif