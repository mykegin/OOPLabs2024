#ifndef COUNTLETTER_H
#define COUNTLETTER_H

#include "Processor.h"
#include <functional>
#include <string>

class CountLetter : public Processor {
    std::string name;
    std::function<bool(char)> predicate;
public:
    CountLetter(const std::string& name, std::function<bool(char)> predicate)
        : name(name), predicate(predicate) {}
    std::string GetName() override {
        return name;
    }
    int Compute(const std::string& str) override {
        int count = 0;
        for (char ch : str) {
            if (predicate(ch)) {
                count++;
            }
        }
        return count;
    }
};

#endif // COUNTLETTER_H
