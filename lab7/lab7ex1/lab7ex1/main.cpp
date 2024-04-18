#include <iostream>

float operator""_Kelvin(unsigned long long value) {
    return (value - 273.15);
}

float operator""_Fahrenheit(unsigned long long value) {
    return ((value - 32) * 5 / 9);
}

int main() {
    float a = 300_Kelvin;
    float b = 120_Fahrenheit;

    std::cout << "300 Kelvin in Celsius: " << a << std::endl;
    std::cout << "120 Fahrenheit in Celsius: " << b << std::endl;

    return 0;
}