#pragma once
#include <string>

// IRace class is an absract class inherinted by all races to apply the race modifiers to the character
class IRace
{
public:
    IRace(std::string name, int hitPointsMod, int hitStrengthMod, int defenseMod, int staminaMod, int luckMod) : m_name(name), m_hitPoints(hitPointsMod), m_hitStrength(hitStrengthMod), m_defense(defenseMod), m_stamina(staminaMod), m_luck(luckMod)
    {}

    virtual std::string getName() const { return m_name; }
    virtual int gethitPointsMod() const { return m_hitPoints; }
    virtual int gethitStrengthMod() const { return m_hitStrength; }
    virtual int getdefenseMod() const { return m_defense; }
    virtual int getstaminaMod() const { return m_stamina; }
    virtual int getluckMod() const { return m_luck; }

    ~IRace() {}

protected:
    std::string m_name;
    int m_hitPoints, m_hitStrength, m_defense, m_stamina, m_luck;
};