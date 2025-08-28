// CSCI 1300 Spring 2022
// Author: Isabella Bates
// Recitation: 104 – Daniel Torres
// Project 3 Skeleton - Monster Class

#include <iostream>
#include "Monster.h"
using namespace std;

// default constructor
Monster::Monster()
{ 
    mtype = 0;
    mname = "";
    mHP = 0;
    mATK = 0;
    mDF = 0;
    mLV = 0;
    mgold = 0;
    intro = "";
    // loop through elements in phrase
    for (int i = 0; i < psize; i++)
    {
        // replace with "..."
        phrase[i] = "...";
    }
}

// parameterized constructor
Monster::Monster(int _mtype, string _mname, int _mHP, int _mATK, int _mDF, int _mLV, int _mgold, string _intro, string _phrase[])
{
    mtype = _mtype;
    mname = _mname;
    mHP = _mHP;
    mATK = _mATK;
    mDF = _mDF;
    mLV = _mLV;
    mgold = _mgold;
    intro = _intro;
    // loop through elements in phrase
    for (int i = 0; i < psize; i++)
    {
        // replace with phrases
        phrase[i] = _phrase[i];
    }
}

// function to get mtype
int Monster::getMType()
{
    return mtype;
}

// function to get mname
string Monster::getMName()
{
    return mname;
}

// function to get mHP
int Monster::getMHP()
{
    return mHP;
} 

// function to get mATK
int Monster::getMATK()
{
    return mATK;
}

// function to get mDF
int Monster::getMDF()
{
    return mDF;
}

// function to get mLV
int Monster::getMLV()
{
    return mLV;
}

// function to get mgold
int Monster::getMGold()
{
    return mgold;
}

// function to set mtype
void Monster::setMType(int _mtype)
{
    mtype = _mtype;
}

// function to set mname
void Monster::setMName(string _mname)
{
    mname = _mname;
}

// function to set mHP
void Monster::setMHP(int _mHP)
{
    mHP = _mHP;
}

// function to set mATK
void Monster::setMATK(int _mATK)
{
    mATK = _mATK;
}

// function to set mDF
void Monster::setMDF(int _mDF)
{
    mDF = _mDF;
}

// function to set mLV
void Monster::setMLV(int _mLV)
{
    mLV = _mLV;
}

// function to set mgold
void Monster::setMGold(int _mgold)
{
    mgold = _mgold; 
}

// function to update mHP
void Monster::updateMHP(int _mHP)
{
    mHP += _mHP;
}

// string function to get intro
string Monster::getIntro()
{
    return intro;
}

// function to get phrase at index
string Monster::getPhraseAt(int index)
{
    // if index is  negative, or greater than or equal to psize
    if (index >= psize || index < 0)
    {
        // return "-1"
        return "-1";
    }
    else
    {
        // return phrase at index
        return phrase[index];
    }
}

// function to set phrase at index
bool Monster::setPhraseAt(int index, string p)
{
    // check that index is less than size and value is between 0 and 5
    if (index < 5)
    {
        // save value in ratings with index
        phrase[index] = p;
        // if successful, return true
        return true;
    }
    else
    {
        // if not successful, return false
        return false;
    }
}


