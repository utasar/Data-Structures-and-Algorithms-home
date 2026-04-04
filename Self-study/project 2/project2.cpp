//---------------------------------------------------------------
// Name: Utsav Acharya
// Project: FightSim (Project 2)
// File: project2.cpp
// Description: Main program that prompts for two characters
//              and simulates combat until one wins.
//---------------------------------------------------------------
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "character.h"
using namespace std;

void initializeCharacter(Character &c, string label);
void fight(Character &c1, Character &c2);
void checkWinner(Character &c1, Character &c2);

int main()
{
    srand(time(nullptr));
    Character c1;
    initializeCharacter(c1, "First");
    Character c2;
    initializeCharacter(c2, "Second");
    cout << "\nSimulated Combat:" << endl;
    fight(c1, c2);
    checkWinner(c1, c2);
    return 0;
}

void initializeCharacter(Character &c, string label)
{
    string name, role;
    int hp, ab, db, ac;
    cout << label << " character name?" << endl; cin >> name;
    cout << name << "'s role?" << endl; cin >> role;
    c = Character(name, role, 0, 0, 0, 0);
    cout << name << " the " << role << "'s hit points?" << endl; cin >> hp;
    cout << name << " the " << role << "'s attack bonus?" << endl; cin >> ab;
    cout << name << " the " << role << "'s damage bonus?" << endl; cin >> db;
    cout << name << " the " << role << "'s armor class?" << endl; cin >> ac;
    c = Character(name, role, hp, ab, db, ac);
    cout << "\nCharacter summary" << endl;
    cout << "-----------------" << endl;
    c.print(cout);
    cout << endl;
}

void fight(Character &c1, Character &c2)
{
    while (c1.getHealth() > 0 && c2.getHealth() > 0)
    {
        c1.attack(c2); cout << endl;
        if (c2.getHealth() <= 0) break;
        c2.attack(c1); cout << endl;
    }
}

void checkWinner(Character &c1, Character &c2)
{
    if (c1.getHealth() > 0)
    {
        cout << c1.getName() << " wins!" << endl;
        cout << c2.getName() << " has brought shame to his/her/their ancestors" << endl;
    }
    else
    {
        cout << c2.getName() << " wins!" << endl;
        cout << c1.getName() << " has brought shame to his/her/their ancestors" << endl;
    }
}
