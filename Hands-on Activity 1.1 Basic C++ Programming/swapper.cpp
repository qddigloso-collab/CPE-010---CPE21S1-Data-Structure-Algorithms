#include <iostream>

int main() {
    int num1, num2, swapper;
    std::cout << "Enter the first number: ";
    std::cin >> num1;
    std::cout << "Enter the second number: ";
    std::cin >> num2;
    
    std::cout << "Before swap: first number = " << num1 << ", second number = " << num2 << std::endl;
    swapper = num1;
    num1 = num2;
    num2 = swapper;

    std::cout << "After swap: first number = " << num1 << ", second number = " << num2 << std::endl;

    return 0;
}