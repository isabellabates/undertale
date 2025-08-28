// CSCI 1300 Spring 2022
// Author: Isabella Bates
// Recitation: 104 – Daniel Torres
// Project 3 Skeleton - Monster Class

#include <iostream>
#include <vector>
using namespace std;

class Monster
{
public: 
    // default constructor
    Monster();
    // parameterized constructor
    Monster(int _mtype, string _mname, int _mHP, int _mATK, int _mDF, int _mLV, int _mgold, string _intro, string _phrase[]);

    // function to get mtype
    int getMType();
    // function to get mname
    string getMName();
    // function to get mHP
    int getMHP();
    // function to get mATK
    int getMATK();
    // function to get mDF
    int getMDF();
    // function to get mLV
    int getMLV();
    // function to get mgold
    int getMGold();
    // function to get into
    string getIntro();
    // function to get phrase at index
    string getPhraseAt(int index);

    // function to set mtype
    void setMType(int _mtype);
    // function to set mname
    void setMName(string _mname);
    // function to set mHP
    void setMHP(int _mHP);
    // function to set mATK
    void setMATK(int _mATK);
    // function to set mDF
    void setMDF(int _mDF);
    // function to set mLV
    void setMLV(int _mLV);
    // function to set mgold
    void setMGold(int _mgold);
    // function to set intro
    void setIntro(string _intro);
    // function to set phrase at index
    bool setPhraseAt(int index, string p);
    // function to update mHP
    void updateMHP(int _mHP);

private:
    // declare mtype, mname, mHP, mATK, mDF, mLV, mgold, psize, phrase[]
    int mtype;
    string mname;
    int mHP;
    int mATK;
    int mDF;
    int mLV;
    int mgold;
    string intro;
    const static int psize = 5;
    string phrase[psize];
}; 