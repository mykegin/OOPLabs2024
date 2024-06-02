#ifndef PROCESSOR_H
#define PROCESSOR_H

#include <string>

class Processor {
public:
    Processor(const std::string& name) : name(name) {}
    virtual ~Processor() {}
    virtual int Run(const std::string& text) = 0;
    std::string GetName() const 
    {
        return name;
    }

protected:
    std::string name;
};

#endif // PROCESSOR_H
