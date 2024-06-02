#include <cctype>
#include <string>
#include "ComputeVowals.h"


int ComputeVowels::Run(const std::string& text)
{
    int count = 0;
    for (char ch : text) {
        if (std::tolower(ch) == 'a' || std::tolower(ch) == 'e' || std::tolower(ch) == 'i' || std::tolower(ch) == 'o' || std::tolower(ch) == 'u') {
            count++;
        }
    }
    return count;
}


