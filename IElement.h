#pragma once

#include "IRace.h"
#include <memory>
#include <random>
#include <iostream>

using namespace std;

// IElement class is an abstract class that is inherited by all elements
class IElement
{
public:
    // IElement constructor utilizing IRace class constructor as a parameter
    IElement(std::shared_ptr<IRace> race) : m_elementName(""), m_hitPoints(0), m_hitStrength(0), m_defense(0), m_stamina(0), m_luck(0), m_leaderStatus(0), m_uses(0), m_race(race)
    {}

    // IElement class is an abstract class, so all of the functions are pure virtual
    virtual int gethitPoints()
    {
        int retVal =  m_race->gethitPointsMod() + m_hitPoints;
        return retVal;
    }
    virtual int getStrength()
    {
        int retVal = m_race->gethitStrengthMod() + m_hitStrength;
        return retVal;
    }
    virtual int getDefense()
    {
        int retVal = m_race->getdefenseMod() + m_defense;
        return retVal;
    }
    virtual int getStamina()
    {
        int retVal = m_stamina;
        // if the character has not be used before, set the stamina to the initial stamina + the stamina from character race
        if (m_uses == 0)
        {
            retVal = m_race->getstaminaMod() + m_stamina;
        }
        return retVal;
    }
    virtual int getLuck()
    {
        int retVal = m_luck;
        // if the character has not be used before, set the luck to the initial luck + the luck modifier from character race
        if (m_uses == 0)
        {
            retVal = m_race->getluckMod() + m_luck;
        }
        return retVal;
    }
    virtual int getUses()
    {
        return m_uses;
    }
    virtual string getRace()
    {
        return m_race->getName();
    }
    virtual string getElement()
    {
        return m_elementName;
    }

    // Attack method to be used to attack the enemy parameter
    virtual void attack(std::shared_ptr<IElement> enemy)
    {
        // if stamina of the character is >= 50
        if (getStamina() >= 50)
        {
            srand((unsigned) time(NULL));   // Seed random number generator
            int initialDamage = (getStrength()/2) + (rand() % (getStrength()/2));   // Calculate initial damage (half of strength + random number between 0 and half of strength)
            int luckNum = ((rand() % getLuck())/100);   // Calculate luck number (random number between 0 and luck divided by 100)
            int luckDamage = initialDamage + (initialDamage * luckNum); // Calculate luck damage (initial damage + initial damage * luck number)    
            int defense = enemy->getDefense() * luckNum;    // Calculate defense (enemy defense * luck number)
            int finalDamage = initialDamage + luckDamage - defense; // Calculate final damage (initial damage + luck damage - defense)

            enemy->m_hitPoints -= finalDamage;  // Subtract final damage from enemy hit points
            m_stamina = getStamina() - 50;  // Subtract 50 from stamina of the character
            m_luck = getLuck() - 5; // Subtract 5 from luck of the character
            m_uses++;   // Increment uses of the character

            // If stamina or luck of character is less than 0, set to 0
            if (m_stamina < 0)
            {
                m_stamina = 0;
            }
            if (m_luck < 0)
            {
                m_luck = 0;
            }

            // Print final damage
            cout << finalDamage;
        }
        else
        {
            // Print below if character stamina is below 50
            cout << "Not enough stamina to attack! Consider resting!" << endl;
        }
    }
    
    // Rest method to be used to rest the character and regain stamina and luck
    virtual void rest()
    {
        m_stamina = getStamina() + 50;  // Add 50 to stamina to the character
        m_luck = getLuck() + 5; // Add 5 to luck to the character
        m_uses++;   // Increment uses for the character
    }

    virtual ~IElement() {}

protected:
    string m_elementName;
    int m_hitPoints, m_hitStrength, m_defense, m_stamina, m_luck, m_leaderStatus, m_uses;
    std::shared_ptr<IRace> m_race;
};