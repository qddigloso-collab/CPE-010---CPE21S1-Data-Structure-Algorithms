#ifndef STACK_LIST_H
#define STACK_LIST_H

// class node that contains data and the next
template <typename T>
class Node{
    public:
    T data;     // Value that we need store
    Node* next; // pointer to the next node
};


// global pointer for the top of the stack
template <typename T>
Node<T> *head = nullptr;


// push
template <typename T>
void push(T newData){
    // create a new node and assign the newData
    Node<T>* newNode = new Node<T>;
    newNode->data = newData;
    
    // new node points to current top, then becomes the new top
    newNode->next = head<T>;
    head<T> = newNode;
}
// pop
template <typename T>
T pop(){
    // check if the stack is empty
    if (head<T> == nullptr){
        std::cout << "stack underflow" << std::endl;
        return T();
    }
    // save the current top node
    Node<T>* temp = head<T>;
    //store its data
    T tempVal = temp->data;
    // move the head to the next node
    head<T> = head<T>->next;
    // free the removed node
    delete temp;
    // return the removed value
    return tempVal;
}


// isEmpty
template <typename T>
bool isEmpty(){
    return head<T> == nullptr;
}

// top
template <typename T>
void Top(){
    // error catching
    if(head<T> == nullptr){
        std::cout << "Stack Underflow" << std::endl;
    }
    // display the top node
    std::cout << "The top of the stack is: " << head<T>->data << std::endl;
}


// display all
template <typename T>
void displayAll(){
    if (head<T> == nullptr){
        std::cout << "stack underflow\n";
        return;
    }
    std::cout << "Displaying the stack:\n";
    Node<T>* temp = head<T>;
    while(temp != nullptr){
        std::cout << temp->data << " ";
        temp = temp->next;
    }
    std::cout << std::endl;
}

template <typename T>
void checking(){
    T input;
    std::cout << "Enter the expression ('~' to stop): " << std::endl; 
    while(std::cin >> input && input != '~'){
        if (input != '(' && input != '{' && input != '[' && input != ')' && input != '}' && input != ']') {
            std::cout << "Ignore: " << input << std::endl;
        }
        else if (input == '(' || input == '{' || input == '[') {
            push(input);
            std::cout << "Pushing: " << input << std::endl;
        }
        else if (input == ')' || input == '}' || input == ']') {
            if (head<T> == nullptr) {
                std::cout << "Error: Stack Underflow." << input << std::endl;
                return;
            }
            else {
                T popped = pop<T>();
                if ((input == ')' && popped != '(') ||
                    (input == '}' && popped != '{') ||
                    (input == ']' && popped != '[')) {
                    std::cout << "Error: Mismatched symbols! Popped " << popped << " but found " << input << std::endl;
                    return;
                } else {
                    std::cout << "Matched: " << input << std::endl;
                }
            }
        }

    }
    if (head<T> != nullptr) {
        std::cout << "There is an error on the line.\n";
    } else {
        std::cout << "Success!\n";
    }
}


#endif