#pragma once

#include <memory>
#include <map>

// forward declaration
class IElement;
class IRace;

class Factory
{
public:
    // Enum of element and race types to be used to create characters
    enum enumOfTypeElement { AIR, FIRE, EARTH, WATER };
    enum raceOfTypeElement { AESIR, DWARF, JOTNAR, VANIR };

    // CreateCharacter method that takes in the enum values and creates an IElement character based on the values
    std::shared_ptr<IElement> CreateCharacter(enumOfTypeElement elementType, raceOfTypeElement raceType);

    // GetFactory method that returns a reference to the Factory object
    static Factory & GetFactory();

    // Delete copy constructor and assignment operator
    Factory(const Factory &) = delete;
    // Delete copy constructor and assignment operator
    Factory & operator=(const Factory &) = delete;

private:
    std::map<raceOfTypeElement, std::shared_ptr<IRace>> m_raceMap;  // Map of race types

    Factory(); // Constructor
    ~Factory(); // Destructor
};