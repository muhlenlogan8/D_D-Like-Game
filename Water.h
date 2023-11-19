#pragma once

#include "IElement.h"
#include "IRace.h"
#include <memory>

// Water is a concrete class that inherits from IElement
class Water : public IElement
{
public:
    //  Water constructor utilizing IElement class constructor  and IRace class constructor as a parameter
    Water(std::shared_ptr<IRace> race) : IElement(race)
    {
        m_elementName = "Water";
        m_hitPoints = 60;
        m_hitStrength = 10;
        m_defense = 20;
        m_stamina = 80;
        m_luck = 10;
    }
    virtual ~Water() {};

    Water() = delete;
};