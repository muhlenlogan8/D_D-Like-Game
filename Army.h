#pragma once

#include <vector>
#include <memory>

class IElement;

class Army
{
private:
    std::shared_ptr<IElement> m_leader; // Leader of the army used for attacking, resting, and targeting
    std::vector<std::shared_ptr<IElement>> m_army;  // Army of IElements which is used as an army of characters for battle

public:
    Army(); // Default constructor
    Army(const std::shared_ptr<IElement> leader);   // Constructor with leader as a parameter

    void setLeader(const std::shared_ptr<IElement> leader); // Set the leader of the army
    std::shared_ptr<IElement> getLeader() const;    // Get the leader of the army

    void addUnit(const std::shared_ptr<IElement> element);  // Add a unit to the army
    void removeUnit(const std::shared_ptr<IElement> element);   // Remove a unit from the army

    std::vector<std::shared_ptr<IElement>> getArmy();   // Get the army as a vector of IElements
};