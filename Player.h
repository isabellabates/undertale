// CSCI 1300 Spring 2022
// Author: Isabella Bates
// Recitation: 104 – Daniel Torres
// Project 3 Skeleton - Player Class
 
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include "Item.h"
using namespace std;

class Player
{
public:
    // default constructor
    Player();
    // parameterized constructor
    Player(string _username, int _soul, int _HP, int _ATK, int _DF, int _LV, int _gold, int _numInv);

    // get username
    string getUsername();
    // set username
    void setUsername(string _username);

    // get HP value
    int getHP();
    // set HP value
    void setHP(int _HP);
    // update HP value
    void updateHP(int _HP);

    // get ATK value
    int getATK();
    // set ATK value
    void setATK(int _ATK);

    // get DF value
    int getDF();
    // set DF value
    void setDF(int _DF);

    // get LV value
    int getSoul();
    // set LV value
    void setSoul(int _soul);
    // update LV value
    void updateSoul(int _soul);

    // get gold value
    int getGold();
    // set gold value
    void setGold(int _gold);
    // update gold value
    void updateGold(int _gold);

    // get gold value
    int getLV();
    // set gold value
    void setLV(int _LV);
    // update gold value
    void updateLV(int _LV);

    // get numInv
    int getNumInv();

    // read items from a file
    int readItems(string filename);
    // int function named saveItem with parameters type and idx
    int saveItem(string type, int idx);
    // int function named useItem with parameters idx
    int useItem(int idx);
    // int function named dropItem with parameters idx
    int dropItem(int idx);
    // function to get item in items
    string getItem(int idx);

    // print player's current inventory
    void printInventory();
    

private:
    // declare username
    string username;
    // declare health level HP
    int HP;
    // declare attack level ATK
    int ATK;
    // declare defense level DF
    int DF;
    // declare number of souls
    int soul;
    // declare LV: love, level of violence
    int LV;
    // declare gold level
    int gold;
    // declare inventory
    vector<Item> inventory;
    // declare number of items in inventory
    int numInv;
    // declare items
    vector<Item> items;
    // declare number of items in items vector
    int numItems = 0;
}; 