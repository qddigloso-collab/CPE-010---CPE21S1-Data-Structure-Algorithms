#include<iostream>
#include "stacklist.h"

int main(){
    std::cout << "----- Pushing 'c' 'p' 'e' Onto the stack ----\n";
    // push
    push('c');
    push('p');
    push('e');

    // Display all elements currently in the stack
    displayAll<char>();

    // display the current top
    Top<char>(); // Top should be 'e'
    
    std::cout << "\n ----- Popping all the elements -----\n";

    while(!isEmpty<char>()){
        std::cout << "Popped: " << pop<char>() << std::endl;
    }
    std::cout << "\n ----- Testing the Underflow ------\n";
    pop<char>();

    std::cout << "\n ----- Symbol Balancing Algorithm ------\n";
    checking<char>();

    return 0;
}