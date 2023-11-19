#include "Army.h"
#include "IElement.h"

// Default constructor
Army::Army()
{
}

// Constructor with leader
Army::Army(const std::shared_ptr<IElement> leader) : m_leader(leader)
{
}

void Army::setLeader(const std::shared_ptr<IElement> leader)
{
    m_leader = leader;
}

// Get the leader of the army
std::shared_ptr<IElement> Army::getLeader() const
{
    return m_leader;
}

// Add a unit to the army vector
void Army::addUnit(const std::shared_ptr<IElement> element)
{
    m_army.push_back(element);
}

// Remove a unit from the army vector
void Army::removeUnit(const std::shared_ptr<IElement> element)
{
    for (auto it = m_army.begin(); it != m_army.end(); it++)
    {
        if (*it == element)
        {
            m_army.erase(it);
            break;
        }
    }
}

// Get the army as a vector of IElements
std::vector<std::shared_ptr<IElement>> Army::getArmy()
{
    return m_army;
}
