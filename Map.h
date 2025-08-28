// CSCI 1300 Spring 2022
// Author: Isabella Bates
// Recitation: 104 – Daniel Torres
// Project 3 Skeleton - Map Class

#ifndef MAP_H
#define MAP_H

#include <iostream>
#include <vector>
#include "Puzzle.h"
using namespace std; 

class Map
{
     private:
          static const int num_rows = 12;
          static const int num_cols = 12;
          static const int num_monsters = 8;
          static const int num_puzzles = 7;

          bool complete;
          int playerPosition[2];
          int shopPosition[2];
          int save[2];
          int npc[2];
          int monsters[num_monsters][3];
          char mapData[num_rows][num_cols];

          bool shop_on_map;
          bool npc_on_map;
          bool save_on_map;
          int monster_count;
          int puzzle_count;

          int puzzle[num_puzzles][3];
          vector<Puzzle> puzzles;
          string op1;
          string op2;
          string op3;
          string op4;

     public :
          Map();

          void resetMap();

          // getters
          int getPlayerRowPosition();
          int getPlayerColPosition();
          int getPuzzleCount();
          int getMonsterCount();
          bool isShopLocation();
          bool isMonsterLocation();
          bool isSaveLocation();
          bool isNPCLocation();
          bool isPuzzleLocation();
          bool isFreeSpace(int row, int col);

          // setters
          void setMonsterCount(int num_monster);
          void setShop(bool isShop);
          void setNPC(bool isNPC);
          void setSave(bool isSave);
          void setPlayerRowPosition(int row);
          void setPlayerColPosition(int col);
          int readPuzzles(string fileName);

          // other
          void displayMap();
          bool move(string move);
          bool spawnShop(int row, int col);
          bool spawnSave(int row, int col);
          bool spawnNPC(int row, int col);
          bool spawnMonster(int row, int col, int type);
          bool spawnPuzzle(int row, int col, int type);
          void revealMonster(int row, int col);
          void printPuzzle(int type);
          int correctAnswer(string choice, int type);
};
 
#endif