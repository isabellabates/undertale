// CSCI 1300 Spring 2022
// Author: Isabella Bates
// Recitation: 104 – Daniel Torres
// Project 3 Skeleton - Item Class

#include "Item.h"
#include <iostream>
#include <fstream>
#include <cassert>
#include <cmath>
#include <iomanip>
#include <string>
using namespace std;

// default constructor
Item::Item()
{
    type = "";
    name = "";
    index = 0;
    description = "";
    addHP = 0;
    addATK = 0;
    addDF = 0;
    addSoul = 0;
    cost = 0;
}

// parameterized constructor
Item::Item(string _type, int _index, string _name, string _description, int _addHP, int _addATK, int _addDF, int _addSoul, int _cost)
{
    type = _type;
    index = _index;
    name = _name;
    description = _description;
    addHP = _addHP;
    addATK = _addATK;
    addDF = _addDF;
    addSoul = _addSoul;
    cost = _cost;
}
    
// function to get type
string Item::getType()
{
    return type;
}

// function to get item name
string Item::getItemName()
{
    return name;
}

// function to get index
int Item::getIndex()
{
    return index;
}

// function to get description
string Item::getDescription()
{
    return description;
}

// function to get addHP
int Item::getAddHP()
{
    return addHP;
}

// function to get addATK
int Item::getAddATK()
{
    return addATK;
}

// function to get addDF
int Item::getAddDF()
{
    return addDF;
}

// function to get addSoul
int Item::getAddSoul()
{
    return addSoul;
}

// function to get cost
int Item::getCost()
{
    return cost;
}

// function to set type
void Item::setType(string _type)
{
    type = _type;
}

// function to set item name
void Item::setItemName(string _name)
{
    name = _name;
}

// function to set index
void Item::setIndex(int _index)
{
    index = _index;
}

// function to set description
void Item::setDescription(string _description)
{
    description = _description;
}

// function to set addHP
void Item::setAddHP(int _addHP)
{
    addHP = _addHP;
}

// function to set addATK
void Item::setAddATK(int _addATK)
{
    addATK = _addATK;
}

// function to set addDF
void Item::setAddDF(int _addDF)
{
    addDF = _addDF;
}

// function to set addSoul
void Item::setAddSoul(int _addSoul)
{
    addSoul = _addSoul;
}

// function to set cost
void Item::setCost(int _cost)
{
    cost = _cost;
}