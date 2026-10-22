#include <iostream>



int main() {
    double kelvin, a, Fahrenheit, b;
    double const1 = 1.8, const2 = 273.15, const3 = 32;
    std::cout << "Enter temperature in Kelvin: ";
    std::cin >> kelvin;
    a = kelvin - const2;
    b = const1 * a;
    Fahrenheit = b + const3;

    std::cout << "Fahrenheit = " << Fahrenheit << std::endl;

    return 0;
}