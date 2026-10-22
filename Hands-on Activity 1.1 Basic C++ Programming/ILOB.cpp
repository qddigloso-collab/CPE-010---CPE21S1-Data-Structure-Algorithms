#include <iostream>
#include <cmath>

class Triangle{
    private:
        double total_angle, angleA, angleB, angleC;
    public:
        Triangle(double A, double B, double C);
        void setAngles(double A, double B, double C);
        const bool ValidateTriangle();
};

void Convertion(double A, double B, double C){
    double rad1 = A * 0.01745329251;
    double rad2 = B * 0.01745329251;
    double rad3 = C * 0.01745329251;
    
    double sideA = 10.0 * std::sin(rad1);
    double sideB = 10.0 * std::sin(rad2);
    double sideC = 10.0 * std::sin(rad3);

    double perimeter = sideA + sideB + sideC;
    double area = 0.5 * sideA * sideB * std::sin(rad3);

    std::cout << "Perimeter: " << perimeter << std::endl;
    std::cout << "Area: " << area << std::endl;
}

int main() {
    double ang1, ang2, ang3;
    std::cout << "Enter the first angle: ";
    std::cin >> ang1;
    std::cout << "Enter the second angle: ";
    std::cin >> ang2;
    std::cout << "Enter the third angle: ";
    std::cin >> ang3;
    Triangle set1(ang1,ang2,ang3);
    if (set1.ValidateTriangle()){
        std::cout << "The shape is a valid Triangle" << std::endl;
        Convertion(ang1,ang2,ang3);
    } else {
        std::cout << "The shape is NOT a valid triangle. \n";
    }
    return 0;
}
Triangle::Triangle(double A, double B, double C){
    angleA = A;
    angleB = B;
    angleC = C;
    total_angle = A + B + C;
}

void Triangle::setAngles(double A, double B, double C){
    angleA = A;
    angleB = B;
    angleC = C;
    total_angle = A + B + C;
}

const bool Triangle::ValidateTriangle() {
    return total_angle <= 180.0;
}