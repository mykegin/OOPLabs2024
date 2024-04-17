#include <iostream>

float operator""_Kelvin(long double value) {
    return static_cast<float>(value - 273.15);
}

float operator""_Fahrenheit(long double value) {
    return static_cast<float>((value - 32) * 5 / 9);
}

int main() {
    float a = 300.0_Kelvin;
    float b = 120.0_Fahrenheit;

    std::cout << "300 Kelvin in Celsius: " << a << std::endl;
    std::cout << "120 Fahrenheit in Celsius: " << b << std::endl;

    return 0;
}