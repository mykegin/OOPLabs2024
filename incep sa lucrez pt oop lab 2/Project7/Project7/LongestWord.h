#ifndef LONGESTWORD_H
#define LONGESTWORD_H

#include "Processor.h"
#include <string>
#include <sstream>

class LongestWord : public Processor {
    std::string name;
public:
    LongestWord(const std::string& name) : name(name) {}
    std::string GetName() override {
        return name;
    }
    int Compute(const std::string& str) override {
        std::istringstream iss(str);
        std::string word;
        int maxLength = 0;
        while (iss >> word) {
            if (word.length() > maxLength) {
                maxLength = word.length();
            }
        }
        return maxLength;
    }
};

#endif // LONGESTWORD_H
