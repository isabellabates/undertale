// CSCI 1300 Spring 2022
// Author: Isabella Bates
// Recitation: 104 – Daniel Torres
// Project 3 Skeleton - Encounter Class

#include "Encounter.h"
#include <iostream>
#include <fstream>
#include <cassert>
#include <cmath>
#include <iomanip>
#include <string>
#include <array>
using namespace std;

// default constructor
Encounter::Encounter()
{
    kind = 0;
}

// parameterized constructor
Encounter::Encounter(int k)
{
    kind = k;
}

// function to get encounter
int Encounter::getEncounter()
{
    return kind;
}

// function to set encounter
void Encounter::setEncounter(int k)
{
    kind = k;
}

// int function named split with parameters inputString, separator, arr[], size
int split1(string inputString, char separator, string arr[], int size)
{ 
    // check that string is not empty
    if (inputString.length() > 0)
    {
        // declare and initialize instance and startPos
        int instance = 0;  
        int startPos = 0; 
        // loop through characters in inputString
        for (int i = 0; i < inputString.length()+1; i++)
        {
            // if character matches the separator character
            if (inputString[i] == separator)  
            {
                // if the number of instances found of the separator, meaning how many substrings created, is greater than the size of array
                if (instance >= size)
                {
                    // return -1
                    return -1;
                }
                // save substring between startPos and separator as array element
                arr[instance] = inputString.substr(startPos, i - startPos); 
                // add 1 to instance counter 
                instance++;  
                // startPos = current index + 1
                startPos = i + 1;  
            }
            // save substring between startPos and separator as array element
            arr[instance] = inputString.substr(startPos, i - startPos);
        }
        // if the separator was not found in the string
        if (instance == 0)
        {
            // save the entire string in the array as the first element
            arr[0] = inputString;
            // return 1
            return 1;
        }
        // otherwise, if split was successful
        else
        {
            // return the number of pieces the input text string was split into
            return instance+1;
        }
    }
    // if string is empty
    else
    {
        // return 0
        return 0;
    }
}

// int function named readMonsters with parameters fileName
// populates a vector of Monster objects with the data found in a file 
int Encounter::readMonsters(string fileName)
{
        // open the file
        ifstream fin(fileName);
        // check that file was opened successfully
        if (fin.is_open())
        {
            // declare line
            string line;
            // read each line from the file
            while (getline(fin, line))
            {
                if (line.length() > 0)
                {
                    // declare array
                    string arr[50];
                    // apply split function to each line
                    int s = split1(line, ',', arr, 50);
                    // declare r
                    int r = s;
                    // if split function does not output -1
                    if (r != -1)
                    {
                        std::array<std::string, 5> temp{};
                        int j = 0;
                        for (int i = 8; i < r && j < 5; ++i, ++j) {
                            temp[j] = arr[i];
                        }
                        // make monster object out of data from arrays
                        Monster m(
                            stoi(arr[0]),        // mtype
                            arr[1],              // mname
                            stoi(arr[2]),        // mHP
                            stoi(arr[3]),        // mATK
                            stoi(arr[4]),        // mDF
                            stoi(arr[5]),        // mLV
                            stoi(arr[6]),        // mgold
                            arr[7],              // intro
                            temp.data()          // string[] pointer (size 5)
                        );
                        // save monster objects in monsters
                        monsters.push_back(m);
                        // increment numMonster
                        numMonster++;
                    }
                }
            }
        }
        // if file could not be opened
        else
        {
            // return -1
            return -1;
        }
    // close the file
    fin.close();
    // return number of monsters stored
    return numMonster;
}

Monster Encounter::getMonster(int type)
{
    Monster m;
    // loop through monsters
    for (int i = 0; i < monsters.size(); i++)
    {
        // if the input type and type of the monster object match
        if (type == monsters[i].getMType())
        {
            // save monster object in m
            m = monsters[i];
        }
    }
    return m;
}

int Encounter::Fight(Player p, int type)
{
    Monster m;
    // loop through monsters
    for (int i = 0; i < monsters.size(); i++)
    {
        // if the input type and type of the monster object match
        if (type == monsters[i].getMType())
        {
            // save monster object in m
            m = monsters[i];
        }
    }
    // if the player and monster have HP greater than 0
    if (p.getHP() > 0 && m.getMHP() > 0)
    {
        // if player has higher ATK than monster
        if (p.getATK() > m.getMATK())
        {
            // if player has higher DF than monster
            if (p.getDF() > mstats.getMDF())
            {
                // print monster's death message
                cout << "You killed " << m.getMName() << endl;
                // add gold from monster to player's gold
                p.updateGold(m.getMGold());
                mstats.getMATK();
                return -2;
            }
            else
            {
                // monster loses HP
                mstats.updateMHP(-p.getATK());
                // player loses HP
                p.updateHP(-m.getMATK());
                if (mstats.getMHP() > 0 && p.getHP() > 0)
                {
                    cout << p.getUsername() << " HP: " << p.getHP() << endl;
                    cout << m.getMName() << " HP: " << mstats.getMHP() << endl;
                }
            }
        }
        // if player has lower or equal ATK to monster
        else if (p.getATK() <= m.getMATK())
        {
            // if player has higher DF than monster
            if (p.getDF() > mstats.getMDF())
            {
                // monster loses HP
                mstats.updateMHP(-p.getATK());
                if (mstats.getMHP() > 0 && p.getHP() > 0)
                {
                    cout << p.getUsername() << " HP: " << p.getHP() << endl;
                    cout << m.getMName() << " HP: " << mstats.getMHP() << endl;
                }
            }
            else
            {
                // player loses HP
                p.updateHP(-m.getMATK());
                if (mstats.getMHP() > 0 && p.getHP() > 0)
                {
                    cout << p.getUsername() << " HP: " << p.getHP() << endl;
                    cout << m.getMName() << " HP: " << mstats.getMHP() << endl;
                }
            }
        }
    }
    // if players health reaches zero
    if (p.getHP() <= 0)
    {
        // player loses a soul
        p.updateSoul(-1);
        // print monster killed you message
        cout << m.getMName() << " killed you but at least you still have DETERMINATION." << endl;
        return mstats.getMATK();
    }
    // declare and initialize lowHP
    int lowHP = (m.getMHP() / 3);
    // if monsters health reaches zero
    if (mstats.getMHP() <= 0)
    {
        // print monster's death message
        cout << "You killed " << m.getMName() << endl;
        // add gold from monster to player's gold
        p.updateGold(m.getMGold());
        // increment player LV
        p.updateLV(1);
        return -2;
    }
    // if monster health is greater than 0 but less than its lowHP
    else if (mstats.getMHP() > 0 && mstats.getMHP() <= lowHP)
    {
        cout << m.getMName() << " has low enough health to spare." << endl;
        // return 1
        return mstats.getMATK();
    }
    else
    {
        cout << m.getMName() << " does not have low enough health to spare. Maybe a conversation could convince " << m.getMName() << "?" << endl;
        return mstats.getMATK();
    }
} 

int Encounter::Fight1(Player p, int type, int hp)
{
    Monster m;
    // loop through monsters
    for (int i = 0; i < monsters.size(); i++)
    {
        // if the input type and type of the monster object match
        if (type == monsters[i].getMType())
        {
            // save monster object in m
            m = monsters[i];
        }
    }
    // if the player and monster have HP greater than 0
    if (p.getHP() > 0 && hp > 0)
    {
        // if player has higher ATK than monster
        if (p.getATK() > m.getMATK())
        {
            // if player has higher DF than monster
            if (p.getDF() > mstats.getMDF())
            {
                // print monster's death message
                cout << "You killed " << m.getMName() << endl;
                // add gold from monster to player's gold
                p.updateGold(m.getMGold());
                p.updateLV(1);
                mstats.getMATK();
                return -2;
            }
            else
            {
                // monster loses HP
                hp -= p.getATK();
                // player loses HP
                p.updateHP(-m.getMATK());
                if (mstats.getMHP() > 0 && p.getHP() > 0)
                {
                    cout << p.getUsername() << " HP: " << p.getHP() << endl;
                    cout << m.getMName() << " HP: " << hp << endl;
                }
            }
        }
        // if player has lower or equal ATK to monster
        else if (p.getDF() <= mstats.getMDF())
        {
            // if player has higher DF than monster
            if (p.getDF() > mstats.getMDF())
            {
                // monster loses HP
                hp -= p.getATK();
                if (mstats.getMHP() > 0 && p.getHP() > 0)
                {
                    cout << p.getUsername() << " HP: " << p.getHP() << endl;
                    cout << m.getMName() << " HP: " << hp << endl;
                }
            }
            else
            {
                // player loses HP
                p.updateHP(-m.getMATK());
                if (mstats.getMHP() > 0 && p.getHP() > 0)
                {
                    cout << p.getUsername() << " HP: " << p.getHP() << endl;
                    cout << m.getMName() << " HP: " << hp << endl;
                }
            }
        }
    }
    // if players health reaches zero
    if (p.getHP() <= 0)
    {
        // player loses a soul
        p.updateSoul(-1);
        // print monster killed you message
        cout << m.getMName() << " killed you but at least you still have DETERMINATION." << endl;
        return hp;
    }
    // declare and initialize lowHP
    int lowHP = (m.getMHP() / 3);
    // if monsters health reaches zero
    if (hp <= 0)
    {
        // print monster's death message
        cout << "You killed " << m.getMName() << endl;
        // add gold from monster to player's gold
        p.updateGold(m.getMGold());
        // increment player LV
        p.updateLV(1);
        return -2;
    }
    // if monster health is greater than 0 but less than its lowHP
    else if (hp > 0 && hp <= lowHP)
    {
        cout << m.getMName() << " has low enough health to spare." << endl;
        // return -3
        return -3;
    }
    else
    {
        cout << m.getMName() << " does not have low enough health to spare. Maybe a conversation could convince " << m.getMName() << "?" << endl;
        return hp;
    }

}

// int function named Spare with parameters p and type
void Encounter::Spare(Player p, int type)
{
    Monster m;
    // loop through monsters
    for (int i = 0; i < monsters.size(); i++)
    {
        // if the input type and type of the monster object match
        if (type == monsters[i].getMType())
        {
            // save monster object in m
            m = monsters[i];
        }
    }
    // print you won and amount of gold earned
    cout << "YOU WON!" << endl;
    cout << "You earned " << m.getMGold() << " gold." << endl;
}

// function to get randum number between two index values
int randomNumbers(int min, int max)
{
    // return number
    return (rand() % (max - min + 1)) + min;
}

// int function named Act with parameters p, type, choice
int Encounter::Act(Player p, int type, int choice)
{
    Monster m;
    // loop through monsters
    for (int i = 0; i < monsters.size(); i++)
    {
        // if the input type and type of the monster object match
        if (type == monsters[i].getMType())
        {
            // save monster object in m
            m = monsters[i];
        }
    }
    switch (choice)
    {
    // if choice is 1
    case 1:
    {
        // print the monster stats
        cout << m.getMName() << " — MAX HP " << m.getMHP() << " ATK " << m.getMATK() << " DEF " << m.getMDF() << endl;
        return 0;
        break;
    }
    // if choice is 2
    case 2:
    {
        // get a randum num between 0 and 4
        int num = rand() % 4;
        // print monster phrase based on num
        cout << m.getPhraseAt(0) << endl;
        // if num is 0
        if (num == 0)
        {
            cout << "You can now spare " << m.getMName() << endl;
            // return 1
            // player now has option to spare
            return 1;
        }
        // if the monster phrase at index num is the same as the monster phrase at index 0
        else if (m.getPhraseAt(num) == m.getPhraseAt(0))
        {
            cout << "You can now spare " << m.getMName() << endl;
            // return 1
            // player now has option to spare
            return 1;
        }
        else
        {
            cout << m.getMName() << " needs more convincing. You can not spare until you talk to the monster enough or get its health low." << endl;
        }
        break;
    }
    default:
        // if choice is not 1 or 2
        cout << "Invalid input. Please enter one of the following numbers." << endl;
        return 0;
        break;
    }
    return 0;
}



