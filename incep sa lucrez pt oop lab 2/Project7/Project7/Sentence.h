#ifndef SENTENCE_H
#define SENTENCE_H

#include "Processor.h"
#include <string>
#include <vector>
#include <iostream>

class Sentence {
    std::string name;
    std::vector<Processor*> processors;
public:
    Sentence(const std::string& name) : name(name) {}
    Sentence& operator+=(Processor* processor) {
        processors.push_back(processor);
        return *this;
    }
    void ListAll() const {
        for (const auto& processor : processors) {
            std::cout << "Name:" << processor->GetName() << std::endl;
        }
    }
    void RunAll() const {
        for (const auto& processor : processors) {
            std::cout << "Name:" << processor->GetName() << " => " << processor->Compute(name) << std::endl;
        }
    }
    void Run(const std::string& processorName) const {
        for (const auto& processor : processors) {
            if (processor->GetName() == processorName) {
                std::cout << processor->Compute(name) << std::endl;
                return;
            }
        }
    }
    ~Sentence() {
        for (auto processor : processors) {
            delete processor;
        }
    }
};

#endif // SENTENCE_H
