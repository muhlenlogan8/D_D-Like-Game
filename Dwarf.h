#pragma once
#include "IRace.h"

// Dwarf is a concrete class that inherits from IRace
class Dwarf : public IRace
{
public:
    // Dwarf constructor utilizing IRace class constructor
    Dwarf() : IRace("Dwarf", 200, 20, 30, 150, 15)
    {}
    virtual ~Dwarf() {}
};