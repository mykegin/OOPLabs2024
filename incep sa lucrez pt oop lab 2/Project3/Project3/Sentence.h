#ifndef SENTENCE_H
#define SENTENCE_H

#include <vector>
#include <string>
#include "Processor.h"

class Sentence {
public:
    Sentence(const std::string& text);
    ~Sentence();
    void operator+=(Processor* p);
    void ListAll();
    void RunAll();
    void Run(const std::string& name);

private:
    std::string text;
    std::vector<Processor*> processors;
};

#endif // SENTENCE_H
