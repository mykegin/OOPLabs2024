#include "Sentence.h"
#include <iostream>

Sentence::Sentence(const std::string& text) : text(text) {}

Sentence::~Sentence() {
    for (auto processor : processors) {
        delete processor;
    }
}

void Sentence::operator+=(Processor* p) {
    processors.push_back(p);
}

void Sentence::ListAll() {
    for (auto processor : processors) {
        std::cout << "Name:" << processor->GetName() << std::endl;
    }
}

void Sentence::RunAll() {
    for (auto processor : processors) {
        std::cout << "Name:" << processor->GetName() << " -> " << processor->Run(text) << std::endl;
    }
}

void Sentence::Run(const std::string& name) {
    for (auto processor : processors) {
        if (processor->GetName() == name) {
            std::cout << processor->Run(text) << std::endl;
        }
    }
}
