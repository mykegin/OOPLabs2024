#ifndef LONGESTWORD_H
#define LONGESTWORD_H

#include "Processor.h"

class LongestWord : public Processor {
public:
    LongestWord(const std::string& name);
    int Run(const std::string& text) override;
};

#endif // LONGESTWORD_H
