// CSCI 1300 Spring 2022
// Author: Isabella Bates
// Recitation: 104 – Daniel Torres
// Project 3 Skeleton - playerDriver

#include "Player.h"
#include <iostream>
#include <fstream>
#include <cassert>
#include <cmath>
#include <iomanip>
#include <string>
using namespace std;

int main()
{
    // test 1 for Player class
    Player defaultPlayer;
    assert(defaultPlayer.getUsername() == "");
    assert(defaultPlayer.getSoul() == 3);
    assert(defaultPlayer.getHP() == 50);
    assert(defaultPlayer.getATK() == 0);
    assert(defaultPlayer.getDF() == 0);
    assert(defaultPlayer.getLV() == 0);
    assert(defaultPlayer.getGold() == 0);
    assert(defaultPlayer.getNumInv() == 0);

    // test 2 for Player class
    Player isabella("isabella", 3, 50, 10, 11, 0, 175, 2);
    assert(isabella.getUsername() == "isabella");
    assert(isabella.getSoul() == 3);
    assert(isabella.getHP() == 50);
    assert(isabella.getATK() == 10);
    assert(isabella.getDF() == 11);
    assert(isabella.getLV() == 0);
    assert(isabella.getGold() == 175);
    assert(isabella.getNumInv() == 2);

    // tests for readItems()
    // declare and initailze Player object p
    Player p;
    // if file cannot be opened
    assert(p.readItems("file_doesnt_exist.txt") == -1);
    // file can be opened and function returns number of items saved
    assert(p.readItems("Item.txt") == 21);

    // tests for saveItem()
    // save weapon "Toy Knife" into player's inventory
    assert(p.saveItem("W", 0) == 1);
    // save consumable "Nice Cream" into player's inventory
    assert(p.saveItem("C", 1) == 1);
    // save armor "Manly Bandana" into player's inventory
    assert(p.saveItem("A", 1) == 1);
    // save armor "Old Tutu" into player's inventory
    assert(p.saveItem("A", 2) == 1);
    // save consumable "Unisicle" into player's inventory
    assert(p.saveItem("C", 3) == 1);
    // save consumable "Bisicle" into player's inventory
    assert(p.saveItem("C", 2) == 1);
    // save weapon "Ballet Shoes" into player's inventory
    assert(p.saveItem("W", 2) == 1);
    
    
    // tests for useItem()
    // use consumable "Nice Cream" in player's inventory
    assert(p.useItem(2) == 1);

    // tests for dropItem()
    // drop consumable "Unisicle" from player's inventory
    assert(p.dropItem(5) == 1);
    // drop weapon "Toy Knife" from player's inventory
    assert(p.dropItem(1) == 2);

    // tests for printInventory
    /* expected output:
        1. Manly Bandana
        2. Old Tutu
        3. Unisicle
        4. Ballet Shoes
        5. 
        6. 
        7. 
        8. 
        9. 
        10. 
    */
    p.printInventory();
}