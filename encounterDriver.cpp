// CSCI 1300 Spring 2022
// Author: Isabella Bates
// Recitation: 104 – Daniel Torres
// Project 3 Skeleton - encounterDriver

#include "Encounter.h"
#include <iostream>
#include <fstream>
#include <cassert>
#include <cmath>
#include <iomanip>
#include <string>
using namespace std;

int main()
{
    // test 1 for Encounter class
    Encounter defaultEncounter;
    assert(defaultEncounter.getEncounter() == 0);

    // test 2 for Encounter class
    Encounter Friend(1);
    assert(Friend.getEncounter() == 1);

    // declare Encounter object
    Encounter e;
    // test 1 for readMonsters()
    assert(e.readMonsters("does-not-exist.txt") == -1);
    // test 2 for readMonsters()
    assert(e.readMonsters("Monsters.txt") == 16);

    // declare Player object
    Player isabella("Isabella", 3, 50, 8, 1, 0, 10, 2);
 
    // tests for Fight()
        // expected output: "You killed Dummy"
        e.Fight(isabella, 1);
        cout << endl;

        // expected output: "You killed Whimsum"
        e.Fight(isabella, 3);
        cout << endl;

        /* expected output: 
            Isabella HP: 50
            So Sorry HP: 992
        */
        e.Fight(isabella, 10);
        cout << endl;

    // tests for Act()
        // expected output: "Dummy — ATK 0 DEF -5"
        e.Act(isabella, 1, 1);
        cout << endl;

        // expected output: "Dummy looks like it is going to fall over."
        e.Act(isabella, 1, 2);
        cout << endl;

    // tests for Spare()
        /* expected output:
            YOU WON!
            You earned 5 gold.
        */
        e.Spare(isabella, 1);
}