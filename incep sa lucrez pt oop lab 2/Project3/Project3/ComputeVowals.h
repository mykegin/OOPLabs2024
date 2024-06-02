#ifndef COMPUTEVOWELS_H
#define COMPUTEVOWELS_H

#include "Processor.h"

class ComputeVowels : public Processor {
public:
    ComputeVowels(const std::string& name) : Processor(name) {}
    int Run(const std::string& text) override;
};

#endif // COMPUTEVOWELS_H
