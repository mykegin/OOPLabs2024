#ifndef COMPUTEVOWELS_H
#define COMPUTEVOWELS_H

#include "Processor.h"
#include <string>

class ComputeVowels : public Processor {
    std::string name;
public:
    ComputeVowels(const std::string& name) : name(name) {}
    std::string GetName() override {
        return name;
    }
    int Compute(const std::string& str) override {
        int count = 0;
        for (char ch : str) {
            if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' ||
                ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U') {
                count++;
            }
        }
        return count;
    }
};

#endif // COMPUTEVOWELS_H
