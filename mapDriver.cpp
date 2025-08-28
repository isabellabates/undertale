// CSCI 1300 Spring 2022
// Author: Isabella Bates
// Recitation: 104 – Daniel Torres
// Project 3 Skeleton - mapDriver

#include <iostream>
#include <string>
#include "Map.h"

using namespace std;

int main()
{
    Map map;
    cout << "Initial map: " << endl;
    map.displayMap(); // starting point
    cout << "Default constructor: " << endl;
    cout << "Puzzle #: " << map.getPuzzleCount() << endl;
    cout << "Let's add some puzzles: " << endl;
    map.spawnPuzzle(2,2,1); 
    map.spawnPuzzle(8,11,2); 
    map.spawnPuzzle(2,7,3);
    map.spawnPuzzle(15,15,1); // should not show on map nor error out, out of bounds
    map.spawnShop(2,2); // will not do anything since space is occupied
    map.displayMap();
    cout << "Spawning a Shop: " << endl;
    map.spawnShop(4,4);
    map.displayMap();
    cout << "Lets move a little" << endl;
    map.executeMove('s'); // go down
    map.executeMove('d'); // go right
    map.displayMap();
    cout << "Adding monster to the right of the player, should be hidden" << endl;
    map.spawnMonster(1,2,2);
    map.displayMap();
    cout << "On monster right now? " << map.isMonsterLocaton() << endl;
    cout << "Lets move onto it..." << endl;
    map.executeMove('d'); // go right
    cout << "On monster right now? " << map.isMonsterLocaton() << endl;
    map.displayMap();
    int playerPosX = map.getPlayerRowPosition();
    int playerPosY = map.getPlayerColPosition();
    map.executeMove('d'); // go right
    map.revealMonster(playerPosX, playerPosY);
    map.displayMap();
    cout << "On NPC right now? " << map.isNPCLocation() << endl;
    cout << "Lets move to a NPC" << endl;
    map.executeMove('s'); 
    map.executeMove('a'); 
    cout << "On NPC right now? " << map.isNPCLocation() << endl;
    map.displayMap();
    cout << "... and move right off" << endl;
    map.executeMove('a'); 
    map.displayMap();
    return 0;
}
