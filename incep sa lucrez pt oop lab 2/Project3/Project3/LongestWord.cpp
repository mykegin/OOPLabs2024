#include "LongestWord.h"
#include <sstream>

LongestWord::LongestWord(const std::string& name) : Processor(name) {}

int LongestWord::Run(const std::string& text) {
    std::istringstream stream(text);
    std::string word;
    int maxLength = 0;

    while (stream >> word) {
        if (word.length() > maxLength) {
            maxLength = word.length();
        }
    }

    return maxLength;
}
