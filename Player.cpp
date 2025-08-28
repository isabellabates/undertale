// CSCI 1300 Spring 2022
// Author: Isabella Bates
// Recitation: 104 – Daniel Torres
// Project 3 Skeleton - Player Class
 
#include "Player.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

Player::Player()
{
    username = "";
    HP = 50;
    ATK = 0;
    DF = 0;
    soul = 3;
    gold = 0;
    numInv = 0;
    LV = 0;
}

Player::Player(string _username, int _soul, int _HP, int _ATK, int _DF, int _LV, int _gold, int _numInv)
{
    username = _username;
    HP = _HP;
    ATK = _ATK;
    DF = _DF;
    soul = _soul;
    gold = _gold;
    numInv = _numInv;
    LV = _LV;
} 

string Player::getUsername()
{
    return username;
}

int Player::getHP()
{
    return HP;
}

int Player::getATK()
{
    return ATK;
}

int Player::getDF()
{
    return DF;
}

int Player::getSoul()
{
    return soul;
}

int Player::getGold()
{
    return gold;
}

int Player::getNumInv()
{
    return numInv;
}

int Player::getLV()
{
    return LV;
}

void Player::setUsername(string _username)
{
    username = _username;
}

void Player::setHP(int _HP)
{
    HP = _HP;
}

void Player::setATK(int _ATK)
{
    ATK = _ATK;
}

void Player::setDF(int _DF)
{
    DF = _DF;
}

void Player::setSoul(int _soul)
{
    soul = _soul;
}

void Player::setGold(int _gold)
{
    gold = _gold;
}

void Player::setLV(int _LV)
{
    LV = _LV;
}

void Player::updateHP(int _HP)
{
    HP += _HP;
}

void Player::updateLV(int _soul)
{
    soul += _soul;
}

void Player::updateGold(int _gold)
{
    gold += _gold;
}

void Player::updateSoul(int _soul)
{
    soul += _soul;
}

// int function named split with parameters inputString, separator, arr[], size
int split(string inputString, char separator, string arr[], int size)
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
 
// string function named uppercase with parameters phrase
string uppercase(string phrase)
{
    // declare and initialize phraseUpper
    string phraseUpper = "";
    // loop through characters in phrase
    for (int i = 0; i < phrase.length(); i++)
    {
        // if character is lowercase alphabet letter
        if (int(phrase[i]) >= 97 && int(phrase[i]) < 123)
        {
            // append uppercase version of letter to phraseUpper
            phraseUpper += char(int(phrase[i] - 32));
        }
        // if character is upper case alphabet letter
        else
        {
            // append to phraseUpper
            phraseUpper += phrase[i];
        }
    }
    // return capitalized phrase
    return phraseUpper;
}

// int function named saveItem with parameters type and idx
int Player::saveItem(string type, int idx)
{
    if (inventory.size() > 10)
    {
        // return -2
        return -2;
    }
    else
    {
        // loop through items[]
        for (int i = 0; i < numItems; i++)
        {
            // if the input type and type of items element match
            if (uppercase(type) == uppercase(items[i].getType()))
            {
                // if the input index and index of items element match
                if (idx == items[i].getIndex())
                {
                    // save items element in inventory
                    inventory.push_back(items[i]);
                    // remove cost of item from player's gold
                    gold -= items[i].getCost();
                    if (type != "c")
                    {
                        HP += items[i].getAddHP();
                        ATK += items[i].getAddATK();
                        DF += items[i].getAddDF();
                        soul += items[i].getAddSoul();
                    }
                }
            }
        }
        // increment number of items in inventory
        numInv++;
        // return 1
        return 1;
    }
}

// int function named useItem with parameters idx
int Player::useItem(int idx)
{
    // adjust user input to be index value
    idx--;
    // if idx is valid
    if (idx < numInv)
    {
        // if item trying to be used is a consumable
        if (inventory[idx].getType() == "c")
        {
            HP += inventory[idx].getAddHP();
            ATK += inventory[idx].getAddATK();
            DF += inventory[idx].getAddDF();
            soul += inventory[idx].getAddSoul();
            // remove item from inventory
            inventory.erase(inventory.begin() + idx);
            numInv--;
            return 2;
        }
        // if item trying to be used is not a consumable
        else
        {
            // return -1
            return 1;
        }
    }
    // if idx is invalid (idx is greater than number of items in inventory)
    else
    {
        // return -2
        return -2;
    }
}

int Player::dropItem(int idx)
{
    // adjust user input to be index value
    idx--;
    // if idx is valid
    if (idx < numInv)
    {
        // if item trying to be used is a consumable
        if (inventory[idx].getType() != "c")
        {
            // remove item's HP from player's HP
            HP -= inventory[idx].getAddHP();
            // remove item's ATK from player's ATK
            ATK -= inventory[idx].getAddATK();
            // remove item's DF from player's DF
            DF -= inventory[idx].getAddDF();
            // remove item's LV from player's soul
            soul -= inventory[idx].getAddSoul();
            // remove item from inventory
            inventory.erase(inventory.begin() + idx);
            numInv--;
            return 2;
        }
        // if item trying to be used is not a consumable
        else
        {
            // remove item from inventory
            inventory.erase(inventory.begin() + idx);
            numInv--;
            return 1;
        }
    }
    // if idx is invalid (idx is greater than number of items in inventory)
    else
    {
        // return -2
        return -2;
    }

}

// int function named readItems with parameters fileName
// populates an array of Item objects with the type, index, name, description, HP, ATK, DF, LV, and cost data found in a file 
int Player::readItems(string fileName)
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
                    // declare array with size 50
                    string arr[50];
                    // apply split function to each line
                    int s = split(line, ',', arr, 50);
                    // if number of splits is 9
                    if (s > 0)
                    {
                        Item item(arr[0], stoi(arr[1]), arr[2], arr[3], stoi(arr[4]), stoi(arr[5]), stoi(arr[6]), stoi(arr[7]), stoi(arr[8]));
                        // append each item object to items vector
                        items.push_back(item);
                        // increment numItems
                        numItems++;
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
    // return number of items stored
    return numItems;
}

// void function named printInventory()
void Player::printInventory()
{
    int idx = 0;
    // loop through inventory
    for (int i = 0; i < inventory.size(); i++)
    {
        // adjust i to be used for index of list of items
        idx = i + 1;
        // print "Index. Item Name"
        cout << idx << ". " << inventory[i].getItemName() << endl;
    }
    for (int i = inventory.size(); i < 10; i++)
    {
        // adjust i to be used for index of list of items
        idx = i + 1;
        // print "Index. Item Name"
        cout << idx << ". " << endl;
    }
}


string Player::getItem(int idx)
{
    idx--;
    if (idx <= numInv)
    {
        return inventory[idx].getItemName();
    }
    return "";
}

