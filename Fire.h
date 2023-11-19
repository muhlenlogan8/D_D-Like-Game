#pragma once

#include "IElement.h"
#include "IRace.h"
#include <memory>

// Fire is a concrete class that inherits from IElement
class Fire : public IElement
{
public:
    // Fire constructor utilizing IElement class constructor and IRace class constructor as a parameter
    Fire(std::shared_ptr<IRace> race) : IElement(race)
    {
        m_elementName = "Fire";
        m_hitPoints = 40;
        m_hitStrength = 40;
        m_defense = 5;
        m_stamina = 30;
        m_luck = 5;
    }
    virtual ~Fire() {};

    Fire() = delete;
};