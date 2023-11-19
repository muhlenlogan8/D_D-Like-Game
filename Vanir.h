#pragma once
#include "IRace.h"

// Vanir class inheriting from IRace class
class Vanir : public IRace
{
public:
    // Vanir constructor utilizing IRace class constructor
    Vanir() : IRace("Vanir", 150, 15, 20, 200, 25)
    {}
    virtual ~Vanir() {}
};