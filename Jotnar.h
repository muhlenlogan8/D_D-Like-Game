#pragma once
#include "IRace.h"

// Jotnar is a concrete class that inherits from IRace
class Jotnar : public IRace
{
public:
    // Jotnar constructor utilizing IRace class constructor
    Jotnar() : IRace("Jotnar", 300, 40, 30, 50, 3)
    {}
    virtual ~Jotnar() {}
};