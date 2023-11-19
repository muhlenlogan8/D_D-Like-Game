#pragma once

#include "../IElement.h"
#include "../IRace.h"
#include <memory>

// Air is a concrete class that inherits from IElement
class Air : public IElement
{
public:
    // Air constructor utilizing IElement class constructor and IRace class constructor as a parameter
    Air(std::shared_ptr<IRace> race) : IElement(race)
    {
        m_elementName = "Air";
        m_hitPoints = 80;
        m_hitStrength = 10;
        m_defense = 15;
        m_stamina = 100;
        m_luck = 20;
    }
    virtual ~Air() {};

    Air() = delete; // Delete the default constructor
};