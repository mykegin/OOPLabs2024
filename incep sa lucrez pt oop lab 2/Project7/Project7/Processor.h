#ifndef PROCESSOR_H
#define PROCESSOR_H

#include <string>

class Processor {
public:
    virtual std::string GetName() = 0;
    virtual int Compute(const std::string& str) = 0;
    virtual ~Processor() = default;
};

#endif // PROCESSOR_H
