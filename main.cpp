#include <iostream>
#include <memory>
#include <unistd.h>
#include "Factory.h"
#include "Army.h"
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

using namespace std;

int main()
{
    // Create army 1
    Army army1;

    shared_ptr<IElement> val = Factory::GetFactory().CreateCharacter(Factory::WATER, Factory::AESIR);
    shared_ptr<Water> waterChar = dynamic_pointer_cast<Water>(val);
    shared_ptr<IElement> val2 = Factory::GetFactory().CreateCharacter(Factory::FIRE, Factory::VANIR);
    shared_ptr<Fire> fireChar = dynamic_pointer_cast<Fire>(val2);
    shared_ptr<IElement> val3 = Factory::GetFactory().CreateCharacter(Factory::EARTH, Factory::DWARF);
    shared_ptr<Earth> earthChar = dynamic_pointer_cast<Earth>(val3);
    shared_ptr<IElement> val4 = Factory::GetFactory().CreateCharacter(Factory::AIR, Factory::JOTNAR);
    shared_ptr<Air> airChar = dynamic_pointer_cast<Air>(val4);

    army1.addUnit(waterChar);
    army1.addUnit(fireChar);
    army1.addUnit(earthChar);
    army1.addUnit(airChar);

    // Create army 2
    Army army2;

    val = Factory::GetFactory().CreateCharacter(Factory::WATER, Factory::JOTNAR);
    shared_ptr<Water> waterChar2 = dynamic_pointer_cast<Water>(val);
    val2 = Factory::GetFactory().CreateCharacter(Factory::FIRE, Factory::DWARF);
    shared_ptr<Fire> fireChar2 = dynamic_pointer_cast<Fire>(val2);
    val3 = Factory::GetFactory().CreateCharacter(Factory::AIR, Factory::VANIR);
    shared_ptr<Air> airChar2 = dynamic_pointer_cast<Air>(val3);
    val4 = Factory::GetFactory().CreateCharacter(Factory::EARTH, Factory::AESIR);
    shared_ptr<Earth> earthChar2 = dynamic_pointer_cast<Earth>(val4);


    army2.addUnit(earthChar2);
    army2.addUnit(airChar2);
    army2.addUnit(waterChar2);
    army2.addUnit(fireChar2);

    // Battle
    int winner = 0;

    // Print rules
    cout << "Game Knowledge: " << endl;
    cout << "1. Each player has 4 units." << endl;
    cout << "2. Each unit has different stats based on their element and race." << endl;
    cout << "3. Attacking will deal damage to the enemy's unit based on the attacker's strength and the defender's defense." << endl;
    cout << "4. Attacking will also use up the attacking units stamina and decrease the units luck as a result." << endl;
    cout << "5. Resting will restore some of the unit's stamina and increase the unit's luck." << endl;
    cout << "6. The first player to defeat all of the enemy's units wins." << endl;
    cout << "7. Enter \"-1\" at any time to exit the game." << endl << endl;
    cout << "Game Start!" << endl << endl;

    while (winner == 0)
    {
        // Print the enemy's army
        cout << "Enemy's Army: " << endl;
        for (int i = 0; i < army2.getArmy().size(); i++) 
        {
            std::cout << "Unit " << i + 1 << ": " << army2.getArmy()[i]->getRace() << " " << army2.getArmy()[i]->getElement() << " bender - "
            << army2.getArmy()[i]->gethitPoints() << " hp - " << army2.getArmy()[i]->getLuck() << " luck - "
            << army2.getArmy()[i]->getStamina() << " stamina" << std::endl;
        }

        // Print your army
        cout << endl << "Your Army: " << endl;
        for (int i = 0; i < army1.getArmy().size(); i++) 
        {
            std::cout << "Unit " << i + 1 << ": " << army1.getArmy()[i]->getRace() << " " << army1.getArmy()[i]->getElement() << " bender - "
            << army1.getArmy()[i]->gethitPoints() << " hp - " << army1.getArmy()[i]->getLuck() << " luck - "
            << army1.getArmy()[i]->getStamina() << " stamina" << std::endl;
        }

        // User chooses which unit to be the leader
        int leaderChoice = 0;
        int iteration = 0;
        while ((leaderChoice < 1 || leaderChoice > army1.getArmy().size()) && leaderChoice != -1)
        {
            if (iteration > 0)
            {
                cout << "Invalid choice! Try again!" << endl;
            }
            cout << endl << "Pick your unit (Enter the unit number only): ";
            cin >> leaderChoice;
            iteration++;
        }

        // Check exit game
        if (leaderChoice == -1)
        {
            winner = 3;
            break;
        }

        // Set the leader
        cout << endl << "You picked unit " << leaderChoice << endl;
        switch(leaderChoice)
        {
            case 1:
                army1.setLeader(army1.getArmy()[0]);
                break;
            case 2:
                army1.setLeader(army1.getArmy()[1]);
                break;
            case 3:
                army1.setLeader(army1.getArmy()[2]);
                break;
            case 4:
                army1.setLeader(army1.getArmy()[3]);
                break;
            default:
                cout << "Error!" << endl;
                break;
        }

        // User chooses which unit to attack
        int attackChoice = 0;
        iteration = 0;
        while ((attackChoice < 1 || attackChoice > army1.getArmy().size()) && attackChoice != -1)
        {
            if (iteration > 0)
            {
                cout << "Invalid choice! Try again!" << endl;
            }
            cout << endl << "Choose which unit you want to target (Enter the unit number only): ";
            cin >> attackChoice;
            iteration++;
        }

        // Check exit game
        if (attackChoice == -1)
        {
            winner = 3;
            break;
        }

        // Set the enemy leader to attack
        switch(attackChoice)
        {
            case 1:
                army2.setLeader(army2.getArmy()[0]);
                break;
            case 2:
                army2.setLeader(army2.getArmy()[1]);
                break;
            case 3:
                army2.setLeader(army2.getArmy()[2]);
                break;
            case 4:
                army2.setLeader(army2.getArmy()[3]);
                break;
            default:
                cout << "Error!" << endl;
                break;
        }

        // User attack or rest choice
        int attackOrRest = 0;
        iteration = 0;
        while (attackOrRest != 1 && attackOrRest != 2 && attackOrRest != -1)
        {
            if (iteration > 0)
            {
                cout << "Invalid choice! Try again!" << endl;
            }
            cout << endl << "Attack this unit or rest? (1 for attack, 2 for rest): ";
            cin >> attackOrRest;
            iteration++;
        }

        // Check exit game
        if (attackOrRest == -1)
        {
            winner = 3;
            break;
        }

        // User attack or rest
        switch(attackOrRest)
        {
            case 1:
                if (army1.getLeader()->getStamina() < 50)
                {
                    cout << "Not enough stamina to attack! Consider resting! Current stamina: " << army1.getLeader()->getStamina() << endl << endl;
                    break;
                }
                else
                {
                    cout << endl << "You attacked the enemy's " << army2.getLeader()->getRace() << " " << army2.getLeader()->getElement() << " bender" << " and hit them for ";
                    army1.getLeader()->attack(army2.getLeader());
                    cout << " damage!" << endl << endl;
                    break;
                }
            case 2:
                cout << endl << "You rested!" << endl << endl;
                army1.getLeader()->rest();
                break;
            default:
                cout << "Error!" << endl;
                break;
        }

        // Remove army2 leader if leader hp <= 0
        if (army2.getLeader()->gethitPoints() <= 0)
        {
            army2.removeUnit(army2.getLeader());
            cout << "Enemy unit has been defeated!" << endl;
        }

        // Check if game winner due to last user attack
        if (army2.getArmy().size() == 0)
        {
            winner = 1;
            break;
        }
        else if (army1.getArmy().size() == 0)
        {
            winner = 2;
            break;
        }

        // Enemy leader choice
        srand((unsigned) time(NULL));
        int enemyLeaderChoice = rand() % army2.getArmy().size() + 1;
        cout << endl << "Enemy picked unit " << enemyLeaderChoice << endl << endl;
        switch(enemyLeaderChoice)
        {
            case 1:
                army2.setLeader(army2.getArmy()[0]);
                break;
            case 2:
                army2.setLeader(army2.getArmy()[1]);
                break;
            case 3:
                army2.setLeader(army2.getArmy()[2]);
                break;
            case 4:
                army2.setLeader(army2.getArmy()[3]);
                break;
            default:
                cout << "Error!" << endl;
                break;
        }

        // Enemy chose who to attack
        sleep(1);
        srand((unsigned) time(NULL));
        int enemyAttackChoice = rand() % army1.getArmy().size() + 1;
        switch(enemyAttackChoice)
        {
            case 1:
                army1.setLeader(army1.getArmy()[0]);
                break;
            case 2:
                army1.setLeader(army1.getArmy()[1]);
                break;
            case 3:
                army1.setLeader(army1.getArmy()[2]);
                break;
            case 4:
                army1.setLeader(army1.getArmy()[3]);
                break;
            default:
                cout << "Error!" << endl;
                break;
        }

        // Enemy attack or rest choice
        sleep(1);
        srand((unsigned) time(NULL));
        int enemyAttackOrRest = rand() % 2 + 1;
        if (army2.getLeader()->getStamina() <= 50)
        {
            enemyAttackOrRest = 2;
        }
        switch(enemyAttackOrRest)
        {
            case 1:
                cout << "Enemy attacked your " << army1.getLeader()->getRace() << " " << army1.getLeader()->getElement() << " bender" << " and hit them for ";
                army2.getLeader()->attack(army1.getLeader());
                cout << " damage!" << endl << endl;
                break;
            case 2:
                cout << "Enemy rested!" << endl << endl;
                army2.getLeader()->rest();
                break;
            default:
                cout << "Error!" << endl;
                break;
        }

        // Remove army1 leader if leader hp <= 0
        if (army1.getLeader()->gethitPoints() <= 0)
        {
            army1.removeUnit(army1.getLeader());
            cout << "Your unit has been defeated!" << endl << endl;
        }

        // Check if game winner due to last enemy attack
        if (army2.getArmy().size() == 0)
        {
            winner = 1;
            break;
        }
        else if (army1.getArmy().size() == 0)
        {
            winner = 2;
            break;
        }
    }
    
    // Print winner
    switch(winner)
    {
        case 1:
            cout << "You win!" << endl;
            break;
        case 2:
            cout << "You lose!" << endl;
            break;
        case 3:
            cout << "Game ended!" << endl;
            break;
        default:
            cout << "Error!" << endl;
            break;
    }
}