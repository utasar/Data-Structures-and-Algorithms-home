//---------------------------------------------------------------
// Name: Utsav Acharya
// Project: FightSim (Project 2)
// File: character.cpp
// Description: Implements the Character class functions,
//              including attack and health logic.
//---------------------------------------------------------------
#include "character.h"
#include <cstdlib>

Character::Character(string newName, string newRole, int newHitPoints,
                     int newAttackBonus, int newDamageBonus, int newArmorClass)
    : name(newName), role(newRole), hitPoints(newHitPoints),
      attackBonus(newAttackBonus), damageBonus(newDamageBonus),
      armorClass(newArmorClass) {}

ostream& Character::print(ostream& os) const
{
    os << name << " the " << role << endl;
    os << "HP: " << hitPoints << endl;
    os << "AB: " << attackBonus << endl;
    os << "DB: " << damageBonus << endl;
    os << "AC: " << armorClass  << endl;
    return os;
}

void Character::attack(Character &otherCharacter)
{
    int roll20       = (rand() % 20) + 1;
    int attackResult = roll20 + attackBonus;
    cout << name << " attacks!" << endl;
    cout << "Attack roll: " << roll20 << " + " << attackBonus
         << " = " << attackResult;
    if (attackResult >= otherCharacter.armorClass)
    {
        cout << " --> HIT!" << endl;
        int roll10       = (rand() % 10) + 1;
        int damageResult = roll10 + damageBonus;
        cout << "Damage: " << roll10 << " + " << damageBonus
             << " = " << damageResult << endl;
        otherCharacter.damage(damageResult);
        hitPoints += damageResult / 2;
        cout << otherCharacter.getName() << " has "
             << otherCharacter.getHealth()
             << " hit points remaining" << endl;
    }
    else { cout << " --> MISS!" << endl; }
}

void Character::damage(int amount)
{
    hitPoints -= amount;
    if (hitPoints < 0) hitPoints = 0;
}

int    Character::getHealth() const { return hitPoints; }
string Character::getName()   const { return name; }
string Character::getRole()   const { return role; }
void   Character::turnEvil()        { role = "Evil " + role; }
