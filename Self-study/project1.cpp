//
// Created by achar on 2/23/2026.
//
//---------------------------------------------------------------
// Name: Utsav Acharya
// Course: CS 3100
// Project: Project 1 - Dice Roller
// File: project1.cpp
// Description:
//   Simulates rolling two six-sided dice N times, tracks how often
//   each total (2..12) occurs using an array, and prints results.
//   Special rules:
//     - If either die is 6, the count for that roll's total is doubled.
//     - If the total is even, add 1 to that roll's count.
//---------------------------------------------------------------

#include <iostream>
#include <cstdlib>   // rand, srand
#include <ctime>     // time

using namespace std;

//----------------------------------------------------------------
// rollDie: Simulates a single 6-sided die roll.
// Returns:
//   int - random value in range [1, 6]
// Parameters:
//   None
//----------------------------------------------------------------
int rollDie() {
   return (rand() % 6) + 1;
}
//----------------------------------------------------------------
// computeIncrement: Determines how much to add to the count for a
//                   given roll total based on special rules.
// Parameters:
//   d1 (int) - first die roll
//   d2 (int) - second die roll
//   total (int) - sum of dice
// Returns:
//   int - increment amount to add into counts[total]
//----------------------------------------------------------------
int computeIncrement(int d1, int d2, int total) {
   int inc = 1;

   // Rule: If either die is 6, double the count for that result
   if (d1 == 6 || d2 == 6) {
      inc *= 2;
   }

   // Rule: Each even total should have 1 added
   if (total % 2 == 0) {
      inc += 1;
   }

   return inc;
}

//----------------------------------------------------------------
// printResults: Prints totals 2..12 and how many times each was rolled.
// Parameters:
//   counts (int[]) - counts array where counts[sum] tracks occurrences
// Returns:
//   None
//----------------------------------------------------------------
void printResults(const int counts[]) {
   cout << "Results:" << endl;
   for (int total = 2; total <= 12; total++) {
      cout << total << " was rolled " << counts[total] << " times" << endl;
   }
}

//----------------------------------------------------------------
// main: Prompts user for number of rolls, simulates dice rolls,
//       updates counts array, then prints results.
//----------------------------------------------------------------
int main() {
   int rolls;

   cout << "How many rolls?  ";
   cin >> rolls;

   // Basic input protection (optional)
   if (rolls <= 0) {
      cout << "Please enter a positive number of rolls." << endl;
      return 0;
   }

   // Seed random number generator using current time
   srand(static_cast<unsigned int>(time(nullptr)));

   // counts[2]..counts[12] used; others ignored
   int counts[13] = {0};

   cout << "Simulating " << rolls << " rolls..." << endl;

   for (int i = 0; i < rolls; i++) {
      int d1 = rollDie();
      int d2 = rollDie();
      int total = d1 + d2;

      int inc = computeIncrement(d1, d2, total);
      counts[total] += inc;
   }

   printResults(counts);

   return 0;
}