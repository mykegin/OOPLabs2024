#define _CRT_SECURE_NO_WARNINGS
#include "Number.h"
#include <cstring>
#include <algorithm>

Number::Number(const char* value, int base) : base(base) {
    digitsCount = strlen(value);
    this->value = new char[digitsCount + 1];
    strcpy(this->value, value);
}

Number::Number(int value) {
    base = 10;
    this->value = nullptr;
    this->digitsCount = 0;
    while (value > 0) {
        char digit = '0' + (value % 10);
        char* newValue = new char[digitsCount + 2];
        strcpy(newValue, this->value);
        newValue[digitsCount] = digit;
        newValue[digitsCount + 1] = '\0';
        if (this->value != nullptr) delete[] this->value;
        this->value = newValue;
        digitsCount++;
        value /= 10;
    }
    if (this->value == nullptr) {
        this->value = new char[2];
        this->value[0] = '0';
        this->value[1] = '\0';
        digitsCount = 1;
    }
}

Number::Number(const Number& other) : base(other.base), digitsCount(other.digitsCount) {
    value = new char[digitsCount + 1];
    strcpy(value, other.value);
}

Number::Number(Number&& other) : value(other.value), base(other.base), digitsCount(other.digitsCount) 
{
    other.value = nullptr;
    other.base = 0;
    other.digitsCount = 0;
}

Number::~Number() {
    if (value != nullptr) delete[] value;
}

Number& Number::operator=(const Number& other) {
    if (this == &other) return *this;
    base = other.base;
    digitsCount = other.digitsCount;
    delete[] value;
    value = new char[digitsCount + 1];
    strcpy(value, other.value);
    return *this;
}

Number& Number::operator=(Number&& other) {
    if (this == &other) return *this;
    delete[] value;
    value = other.value;
    base = other.base;
    digitsCount = other.digitsCount;
    other.value = nullptr;
    other.base = 0;
    other.digitsCount = 0;
    return *this;
}

Number operator+(const Number& num1, const Number& num2) {
    int base = std::max(num1.base, num2.base);
    // Convert both numbers to the larger base before performing addition
    // Implementation not included for brevity
    return Number("Result", base); // Placeholder
}

Number operator-(const Number& num1, const Number& num2) {
    int base = std::max(num1.base, num2.base);
    // Convert both numbers to the larger base before performing subtraction
    // Implementation not included for brevity
    return Number("Result", base); // Placeholder
}

bool Number::operator>(const Number& other) const {
    // Implementation not included for brevity
    return false; // Placeholder
}

bool Number::operator<(const Number& other) const {
    // Implementation not included for brevity
    return false; // Placeholder
}

bool Number::operator>=(const Number& other) const {
    // Implementation not included for brevity
    return false; // Placeholder
}

bool Number::operator<=(const Number& other) const {
    // Implementation not included for brevity
    return false; // Placeholder
}

bool Number::operator==(const Number& other) const {
    // Implementation not included for brevity
    return false; // Placeholder
}

char& Number::operator[](int index) {
    if (index >= digitsCount || index < 0) throw std::out_of_range("Index out of range");
    return value[index];
}

void Number::SwitchBase(int newBase) {
    // Implementation not included for brevity
}

void Number::Print() {
    std::cout << "Value: " << value << ", Base: " << base << std::endl;
}

int Number::GetDigitsCount() {
    return digitsCount;
}

int Number::GetBase() {
    return base;
}

Number& Number::operator--() {
    // Implementation not included for brevity
    return *this;
}

Number Number::operator--(int) {
    // Implementation not included for brevity
    return *this;
}