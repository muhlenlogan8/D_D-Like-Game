#pragma once
#include "IRace.h"

// Aesir is a concrete class that inherits from IRace
class Aesir : public IRace
{
public:
    // Aesir constructor utilizing IRace class constructor
    Aesir() : IRace("Aesir", 200, 25, 25, 100, 10)
    {}
    virtual ~Aesir() {}
};