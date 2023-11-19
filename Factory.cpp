#include "Factory.h"

#include "IElement.h"
#include "IRace.h"

#include "Races/Aesir.h"
#include "Races/Dwarf.h"
#include "Races/Jotnar.h"
#include "Races/Vanir.h"

#include "Elements/Air.h"
#include "Elements/Earth.h"
#include "Elements/Fire.h"
#include "Elements/Water.h"

// GetFactory method that returns a reference to the Factory object
Factory & Factory::GetFactory()
{
    static Factory factory;
    return factory;
}

// CreateCharacter method that returns a shared pointer to an IElement object
std::shared_ptr<IElement> Factory::CreateCharacter(enumOfTypeElement elementType, raceOfTypeElement race)
{
    std::shared_ptr<IElement> retVal = nullptr;
    if (elementType == AIR)
    {
        retVal = std::make_shared<Air>(m_raceMap[race]);
    }
    else if (elementType == EARTH)
    {
        retVal = std::make_shared<Earth>(m_raceMap[race]);
    }
    else if (elementType == FIRE)
    {
        retVal = std::make_shared<Fire>(m_raceMap[race]);
    }
    else if (elementType == WATER)
    {
        retVal = std::make_shared<Water>(m_raceMap[race]);
    }
    return retVal;
}

// Constructor
Factory::Factory()
{
    std::shared_ptr<IRace> aesir = std::make_shared<Aesir>();
    std::shared_ptr<IRace> dwarf = std::make_shared<Dwarf>();
    std::shared_ptr<IRace> jotnar = std::make_shared<Jotnar>();
    std::shared_ptr<IRace> vanir = std::make_shared<Vanir>();

    // Mapping race types
    m_raceMap[AESIR] = aesir;
    m_raceMap[DWARF] = dwarf;
    m_raceMap[JOTNAR] = jotnar;
    m_raceMap[VANIR] = vanir;
}

// Destructor
Factory::~Factory()
{
    m_raceMap.clear();
}