// CSCI 1300 Spring 2022
// Author: Isabella Bates
// Recitation: 104 – Daniel Torres
// Project 3 Skeleton - Item Class

#include <iostream>
#include <fstream>
#include <cassert>
#include <cmath>
#include <iomanip>
#include <string>
using namespace std;
 
class Item
{
public:
    // default constructor
    Item(); 
    // parameterized constructor
    Item(string _type, int _index, string _name, string _description, int _addHP, int _addATK, int _addDF, int _addSoul, int _cost);
    
    // function to get type
    string getType();
    // function to get item name
    string getItemName();
    // function to get index
    int getIndex();
    // function to get description
    string getDescription();
    // function to get addHP
    int getAddHP();
    // function to get addATK
    int getAddATK();
    // function to get addDF
    int getAddDF();
    // function to get addSoul
    int getAddSoul();
    // function to get cost
    int getCost();
 
    // function to set type
    void setType(string _type);
    // function to set item name
    void setItemName(string _name);
    // function to set index
    void setIndex(int _index);
    // function to set description
    void setDescription(string _description);
    // function to set addHP
    void setAddHP(int _addHP);
    // function to set addATK
    void setAddATK(int _addATK);
    // function to set addDF
    void setAddDF(int _addDF);
    // function to set addSoul
    void setAddSoul(int _addSoul);
    // function to set cost
    void setCost(int _cost);

private:
    // declare type, name, index, description, addHP, addATK, addDF, addSoul, cost
    string type;
    string name;
    int index;
    string description;
    int addHP;
    int addATK;
    int addDF;
    int addSoul;
    int cost;
};