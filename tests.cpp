#include <gtest/gtest.h>
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

// Test to ensure the factory can create a character
TEST(FactoryTest, TestCharacterCreation)
{
    shared_ptr<IElement> character = Factory::GetFactory().CreateCharacter(Factory::WATER, Factory::AESIR);
    ASSERT_NE(character, nullptr);
}

// Test the factory created the correct type of character
TEST(FactoryTest, TestCharacterCreationType)
{
    shared_ptr<IElement> character = Factory::GetFactory().CreateCharacter(Factory::WATER, Factory::AESIR);
    ASSERT_EQ(character->getRace(), "Aesir");
    ASSERT_EQ(character->getElement(), "Water");
}

// Test the Army class can add a character
TEST(ArmyTest, TestAddCharacter)
{
    shared_ptr<IElement> character = Factory::GetFactory().CreateCharacter(Factory::WATER, Factory::AESIR);
    Army army;
    army.addUnit(character);
    ASSERT_EQ(army.getArmy().size(), 1);
}

// Test the Army class can remove a character
TEST(ArmyTest, TestRemoveCharacter)
{
    shared_ptr<IElement> character = Factory::GetFactory().CreateCharacter(Factory::WATER, Factory::AESIR);
    Army army;
    army.addUnit(character);
    army.removeUnit(character);
    ASSERT_EQ(army.getArmy().size(), 0);
}

// Test the Army class allows for unique leaders to be set in the army vector
TEST(ArmyTest, TestUniqueLeader)
{
    shared_ptr<IElement> character1 = Factory::GetFactory().CreateCharacter(Factory::WATER, Factory::AESIR);
    shared_ptr<IElement> character2 = Factory::GetFactory().CreateCharacter(Factory::WATER, Factory::AESIR);
    Army army;
    army.addUnit(character1);
    army.addUnit(character2);
    army.setLeader(character2);
    ASSERT_EQ(army.getLeader(), character2);
    army.setLeader(character1);
    ASSERT_EQ(army.getLeader(), character1);
}

// Test the IElement class attack method works as intended
TEST(IElementTest, TestAttack)
{
    shared_ptr<IElement> character1 = Factory::GetFactory().CreateCharacter(Factory::WATER, Factory::AESIR);
    shared_ptr<IElement> character2 = Factory::GetFactory().CreateCharacter(Factory::WATER, Factory::AESIR);
    int initialHP = character2->gethitPoints();
    character1->attack(character2);
    ASSERT_TRUE(character2->gethitPoints() < initialHP);
}

// Test the IElement class rest method works as intended
TEST(IElementTest, TestRest)
{
    shared_ptr<IElement> character1 = Factory::GetFactory().CreateCharacter(Factory::WATER, Factory::AESIR);
    int initialStamina = character1->getStamina();
    int initialLuck = character1->getLuck();
    character1->rest();
    ASSERT_TRUE(character1->getStamina() > initialStamina);
    ASSERT_TRUE(character1->getLuck() > initialLuck);
}

// Test the Air Element class returns the correct Element name
TEST(AirTest, TestAirName)
{
    shared_ptr<IRace> aesir = make_shared<Aesir>();
    shared_ptr<IElement> character = make_shared<Air>(aesir);
    ASSERT_EQ(character->getElement(), "Air");
}

// Test the Air Element class has the correct base attributes
// Note: The Aesir race is used as the modifier so its modification
// values will be subtracted from the final values to get the base values
TEST(AirTest, TestAirAttributes)
{
    shared_ptr<IRace> aesir = make_shared<Aesir>();
    shared_ptr<IElement> character = make_shared<Air>(aesir);
    ASSERT_EQ(character->gethitPoints()-200, 80);
    ASSERT_EQ(character->getStrength()-25, 10);
    ASSERT_EQ(character->getDefense()-25, 15);
    ASSERT_EQ(character->getStamina()-100, 100);
    ASSERT_EQ(character->getLuck()-10, 20);
}

// Test the Earth Element class returns the correct Element name
TEST(EarthTest, TestEarthName)
{
    shared_ptr<IRace> aesir = make_shared<Aesir>();
    shared_ptr<IElement> character = make_shared<Earth>(aesir);
    ASSERT_EQ(character->getElement(), "Earth");
}

// Test the Earth Element class has the correct base attributes
// Note: The Aesir race is used as the modifier so its modification
// values will be subtracted from the final values to get the base values
TEST(EarthTest, TestEarthAttributes)
{
    shared_ptr<IRace> aesir = make_shared<Aesir>();
    shared_ptr<IElement> character = make_shared<Earth>(aesir);
    ASSERT_EQ(character->gethitPoints()-200, 120);
    ASSERT_EQ(character->getStrength()-25, 20);
    ASSERT_EQ(character->getDefense()-25, 20);
    ASSERT_EQ(character->getStamina()-100, 20);
    ASSERT_EQ(character->getLuck()-10, 5);
}

// Test the Fire Element class returns the correct Element name
TEST(FireTest, TestFireName)
{
    shared_ptr<IRace> aesir = make_shared<Aesir>();
    shared_ptr<IElement> character = make_shared<Fire>(aesir);
    ASSERT_EQ(character->getElement(), "Fire");
}

// Test the Fire Element class has the correct base attributes
// Note: The Aesir race is used as the modifier so its modification
// values will be subtracted from the final values to get the base values
TEST(FireTest, TestFireAttributes)
{
    shared_ptr<IRace> aesir = make_shared<Aesir>();
    shared_ptr<IElement> character = make_shared<Fire>(aesir);
    ASSERT_EQ(character->gethitPoints()-200, 40);
    ASSERT_EQ(character->getStrength()-25, 40);
    ASSERT_EQ(character->getDefense()-25, 5);
    ASSERT_EQ(character->getStamina()-100, 30);
    ASSERT_EQ(character->getLuck()-10, 5);
}

// Test the Water Element class returns the correct Element name
TEST(WaterTest, TestWaterName)
{
    shared_ptr<IRace> aesir = make_shared<Aesir>();
    shared_ptr<IElement> character = make_shared<Water>(aesir);
    ASSERT_EQ(character->getElement(), "Water");
}

// Test the Water Element class has the correct base attributes
// Note: The Aesir race is used as the modifier so its modification
// values will be subtracted from the final values to get the base values
TEST(WaterTest, TestWaterAttributes)
{
    shared_ptr<IRace> aesir = make_shared<Aesir>();
    shared_ptr<IElement> character = make_shared<Water>(aesir);
    ASSERT_EQ(character->gethitPoints()-200, 60);
    ASSERT_EQ(character->getStrength()-25, 10);
    ASSERT_EQ(character->getDefense()-25, 20);
    ASSERT_EQ(character->getStamina()-100, 80);
    ASSERT_EQ(character->getLuck()-10, 10);
}

// Test the Aesir class returns the correct Race name
TEST(AesirTest, TestAesirName)
{
    shared_ptr<IRace> aesir = make_shared<Aesir>();
    ASSERT_EQ(aesir->getName(), "Aesir");
}

// Test the Aesir Race class has the correct modification attributes and the IRace methods return these values
TEST(AesirTest, TestAesirAttributes)
{
    shared_ptr<IRace> aesir = make_shared<Aesir>();
    ASSERT_EQ(aesir->gethitPointsMod(), 200);
    ASSERT_EQ(aesir->gethitStrengthMod(), 25);
    ASSERT_EQ(aesir->getdefenseMod(), 25);
    ASSERT_EQ(aesir->getstaminaMod(), 100);
    ASSERT_EQ(aesir->getluckMod(), 10);
}

// Test the Dwarf class returns the correct Race name
TEST(DwarfTest, TestDwarfName)
{
    shared_ptr<IRace> dwarf = make_shared<Dwarf>();
    ASSERT_EQ(dwarf->getName(), "Dwarf");
}

// Test the Dwarf Race class has the correct modification attributes and the IRace methods return these values
TEST(DwarfTest, TestDwarfAttributes)
{
    shared_ptr<IRace> dwarf = make_shared<Dwarf>();
    ASSERT_EQ(dwarf->gethitPointsMod(), 200);
    ASSERT_EQ(dwarf->gethitStrengthMod(), 20);
    ASSERT_EQ(dwarf->getdefenseMod(), 30);
    ASSERT_EQ(dwarf->getstaminaMod(), 150);
    ASSERT_EQ(dwarf->getluckMod(), 15);
}

// Test the Jotnar class returns the correct Race name
TEST(JotnarTest, TestJotnarName)
{
    shared_ptr<IRace> jotnar = make_shared<Jotnar>();
    ASSERT_EQ(jotnar->getName(), "Jotnar");
}

// Test the Jotnar Race class has the correct modification attributes and the IRace methods return these values
TEST(JotnarTest, TestJotnarAttributes)
{
    shared_ptr<IRace> jotnar = make_shared<Jotnar>();
    ASSERT_EQ(jotnar->gethitPointsMod(), 300);
    ASSERT_EQ(jotnar->gethitStrengthMod(), 40);
    ASSERT_EQ(jotnar->getdefenseMod(), 30);
    ASSERT_EQ(jotnar->getstaminaMod(), 50);
    ASSERT_EQ(jotnar->getluckMod(), 3);
}

// Test the Vanir class returns the correct Race name
TEST(VanirTest, TestVanirName)
{
    shared_ptr<IRace> vanir = make_shared<Vanir>();
    ASSERT_EQ(vanir->getName(), "Vanir");
}

// Test the Vanir Race class has the correct modification attributes and the IRace methods return these values
TEST(VanirTest, TestVanirAttributes)
{
    shared_ptr<IRace> vanir = make_shared<Vanir>();
    ASSERT_EQ(vanir->gethitPointsMod(), 150);
    ASSERT_EQ(vanir->gethitStrengthMod(), 15);
    ASSERT_EQ(vanir->getdefenseMod(), 20);
    ASSERT_EQ(vanir->getstaminaMod(), 200);
    ASSERT_EQ(vanir->getluckMod(), 25);
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}