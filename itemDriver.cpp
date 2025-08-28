// CSCI 1300 Spring 2022
// Author: Isabella Bates
// Recitation: 104 – Daniel Torres
// Project 3 Skeleton - itemDriver

#include "Item.h"
#include <iostream>
#include <fstream>
#include <cassert>
#include <cmath>
#include <iomanip>
#include <string>
using namespace std;

int main()
{
    // test 1 for Item class
    Item defaultItem;
    assert(defaultItem.getType() == "");
    assert(defaultItem.getIndex() == 0);
    assert(defaultItem.getItemName() == "");
    assert(defaultItem.getDescription() == "");
    assert(defaultItem.getAddHP() == 0);
    assert(defaultItem.getAddATK() == 0);
    assert(defaultItem.getAddDF() == 0);
    assert(defaultItem.getAddSoul() == 0);
    assert(defaultItem.getCost() == 0);

    // test 2 for Item class
    Item balletShoes("W", 2, "Ballet Shoes", "These used shoes make you feel incredibly dangerous.", 0, 7, 0, 0, 50);
    assert(balletShoes.getType() == "W");
    assert(balletShoes.getIndex() == 2);
    assert(balletShoes.getItemName() == "Ballet Shoes");
    assert(balletShoes.getDescription() == "These used shoes make you feel incredibly dangerous.");
    assert(balletShoes.getAddHP() == 0);
    assert(balletShoes.getAddATK() == 7);
    assert(balletShoes.getAddDF() == 0);
    assert(balletShoes.getAddSoul() == 0);
    assert(balletShoes.getCost() == 50);
}