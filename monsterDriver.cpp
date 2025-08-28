// CSCI 1300 Spring 2022
// Author: Isabella Bates
// Recitation: 104 – Daniel Torres
// Project 3 Skeleton - monsterDriver

#include "Monster.h"
#include <iostream>
#include <fstream>
#include <cassert>
#include <cmath>
#include <iomanip>
#include <string>
using namespace std;

int main()
{
    // test 1 for Monster class
    Monster defaultMonster;
    assert(defaultMonster.getMType() == 0);
    assert(defaultMonster.getMName() == "");
    assert(defaultMonster.getMHP() == 0);
    assert(defaultMonster.getMATK() == 0);
    assert(defaultMonster.getMDF() == 0);
    assert(defaultMonster.getMLV() == 0);
    assert(defaultMonster.getMGold() == 0);
    assert(defaultMonster.getIntro() == "");
    assert(defaultMonster.getPhraseAt(0) == "...");

    // test 2 for Monster class
    string phrases[5] = {"A cotton heart and a button eye. You are the apple of my eye.", "Dummy looks like it is going to fall over.", "Dummy looks like it is going to fall over.", "..."};
    Monster Dummy(1, "Dummy", 15, 0, -5, 0, 0, "You encountered the Dummy.", phrases);
    assert(Dummy.getMType() == 1);
    assert(Dummy.getMName() == "Dummy");
    assert(Dummy.getMHP() == 15);
    assert(Dummy.getMATK() == 0);
    assert(Dummy.getMDF() == -5);
    assert(Dummy.getMLV() == 0);
    assert(Dummy.getMGold() == 0);
    assert(Dummy.getIntro() == "You encountered the Dummy.");
    assert(Dummy.getPhraseAt(0) == "A cotton heart and a button eye. You are the apple of my eye.");
}