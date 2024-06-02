#ifndef COUNTLETTER_H
#define COUNTLETTER_H

#include "Processor.h"
#include <functional>

class CountLetter : public Processor {
public:
    CountLetter(const std::string& name, std::function<bool(char)> func);
    int Run(const std::string& text) override;

private:
    std::function<bool(char)> func;
};

#endif // COUNTLETTER_H
