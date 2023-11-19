#pragma once

#include "../IElement.h"
#include "../IRace.h"
#include <memory>

// Earth is a concrete class that inherits from IElement
class Earth : public IElement
{
public:
    // Earth constructor utilizing IElement class constructor and IRace class constructor as a parameter
    Earth(std::shared_ptr<IRace> race) : IElement(race)
    {
        m_elementName = "Earth";
        m_hitPoints = 120;
        m_hitStrength = 20;
        m_defense = 20;
        m_stamina = 20;
        m_luck = 5;
    }
    virtual ~Earth() {};

    Earth() = delete;
};