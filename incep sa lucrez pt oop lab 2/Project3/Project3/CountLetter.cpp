#include "CountLetter.h"

CountLetter::CountLetter(const std::string& name, std::function<bool(char)> func) : Processor(name), func(func) {}

int CountLetter::Run(const std::string& text) {
    int count = 0;
    for (char ch : text) {
        if (func(ch)) {
            count++;
        }
    }
    return count;
}
