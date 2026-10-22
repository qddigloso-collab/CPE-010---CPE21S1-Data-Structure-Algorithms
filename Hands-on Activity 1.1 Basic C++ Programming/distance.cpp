#include <iostream>

int main(){
    double x1, x2, y1, y2, distance;
    std::cout << "Enter the x1 value: ";
    std::cin >> x1;
    std::cout << "Enter the x2 value: ";
    std::cin >> x2;
    std::cout << "Enter the y1 value: ";
    std::cin >> y1;
    std::cout << "Enter the y2 value: ";
    std::cin >> y2;

    double dx = x2 - x1;
    double dy = y2 - y1;
    double squared = (dx * dx) + (dy * dy);
    
    double x = squared;
    double y = 1.0;
    double e = 0.000001; 
    while (x - y > e) {
        x = (x + y) / 2.0;
        y = squared / x;
    }
    distance = x;

    std::cout << "The Distance is: " << distance << std::endl;
}