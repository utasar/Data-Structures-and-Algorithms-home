//---------------------------------------------------------------
// Name: Utsav Acharya
// Project: FightSim (Project 2)
// File: character.h
// Description: Defines the Character class for the combat
//              simulation program.
//---------------------------------------------------------------
//
#ifndef CHARACTER_H
#define CHARACTER_H
#include <iostream>
#include <string>
using namespace std;

class Character
{
private:
    string name;
    string role;
    int hitPoints;
    int attackBonus;
    int damageBonus;
    int armorClass;

public:
    Character()
    {
        name = ""; role = ""; hitPoints = 0;
        attackBonus = 0; damageBonus = 0; armorClass = 0;
    }
    Character(string newName, string newRole, int newHitPoints,
              int newAttackBonus, int newDamageBonus, int newArmorClass);
    ostream& print(ostream& os) const;
    void attack(Character &otherCharacter);
    void damage(int amount);
    int getHealth() const;
    string getName() const;
    string getRole() const;
    void turnEvil();
};

#endif
