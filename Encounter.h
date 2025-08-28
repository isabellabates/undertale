// CSCI 1300 Spring 2022
// Author: Isabella Bates
// Recitation: 104 – Daniel Torres
// Project 3 Skeleton - Encounter Class

#include "Player.h"
#include "Monster.h"
#include <iostream>
#include <fstream>
#include <cassert>
#include <cmath>
#include <iomanip>
#include <string>
using namespace std;

class Encounter
{
    public:
        // default constructor
        Encounter();
        // parameterized constructor
        Encounter(int k);

        // function to get encounter
        int getEncounter();
        // function to set encounter
        void setEncounter(int k);

        // int function named readMonsters with parameters fileName
        int readMonsters(string fileName);
        // Monster function named getMonster with parameters type
        Monster getMonster(int type);

        // int function named Fight with parameters p and type
        int Fight(Player p, int type);
        // int function named Fight1 with parameters p, type, hp
        int Fight1(Player p, int type, int hp);
        // int function named Act with parameters p, type, and choice
        int Act(Player p, int type, int choice);
        // void function named Spare with parameters p and m
        void Spare(Player p, int type);

    private:
        int kind;
        vector<Monster> monsters;
        int numMonster;
        Monster mstats;
};