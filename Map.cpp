// CSCI 1300 Spring 2022
// Author: Isabella Bates
// Recitation: 104 – Daniel Torres
// Project 3 Skeleton - Map Class

#include "Map.h"
#include <iostream>
using namespace std; 

Map::Map()
{
    resetMap();
}

/*
 * Algorithm: Resets positions of player, shops, monsters, puzzles to -1 and clears mapData  
 * Set Player position coordinates to 0
 * Set shop position coordinates to -1
 * Set shop_on_map to false
 * Set monster_count to 0
 * Set puzzle_count to 0
 * loop i from 0 to num_monsters
 *      Set row, col and type of monster location to -1
 * loop i from 0 to num_puzzles
 *      Set row, col and type of puzzle location to -1
 * loop i from 0 to num_rows
 *      loop i from 0 to num_cols
 *          Set (x,y) location on mapData to '-'
 * Parameters: none
 * Return: nothing (void)
 */
void Map::resetMap() {
    // resets player position, count values, and initializes values in position arrays to -1
    playerPosition[0] = 0; 
    playerPosition[1] = 0;

    shopPosition[0] = -1;
    shopPosition[1] = -1;

    npc[0] = -1;
    npc[1] = -1;

    save[0] = -1;
    save[1] = -1;

    shop_on_map = false;
    npc_on_map = false;
    save_on_map = false;
    monster_count = 0;
    puzzle_count = 0;

    for (int i = 0; i < num_monsters; i++) {
        monsters[i][0] = -1;
        monsters[i][1] = -1;
        monsters[i][2] = -1;
    }

    for (int i = 0; i < num_puzzles; i++) {
        puzzle[i][0] = -1;
        puzzle[i][1] = -1;
        puzzle[i][2] = -1;
    }

    for (int i = 0; i < num_rows; i++) {
        for (int j = 0; j < num_cols; j++) {
            mapData[i][j] = '-';
        }
    }
}

// return player's row position
int Map::getPlayerRowPosition() {
    return playerPosition[0];
}

// return player's column position
int Map::getPlayerColPosition() {
    return playerPosition[1];
}

int Map::getPuzzleCount() {
    return puzzle_count;
}

int Map::getMonsterCount() {
    return monster_count;
}

int random1(int min, int max)
{
    return (rand() % (max - min + 1)) + min;
}

/*
 * Algorithm: Checks if the location is a Shop location  
 * if player position is Shop location and shop_on_map is true
 *      return true
 * return false
 * Parameters: none
 * Return: boolean (bool)
 */
bool Map::isShopLocation(){
    if (playerPosition[0] == shopPosition[0] && playerPosition[1] == shopPosition[1] && shop_on_map == true){
        return true;
    }
    return false;
}

/*
 * Algorithm: Checks if the location is an NPC location  
 * if player position is NPC location and NPC_on_map is true
 *      return true
 * return false
 * Parameters: none
 * Return: boolean (bool)
 */
bool Map::isNPCLocation(){
    if (playerPosition[0] == npc[0] && playerPosition[1] == npc[1] && npc_on_map == true){
        return true;
    }
    return false;
}

/*
 * Algorithm: Checks if the location is a save location  
 * if player position is save location and save_on_map is true
 *      return true
 * return false
 * Parameters: none
 * Return: boolean (bool)
 */
bool Map::isSaveLocation(){
    if (playerPosition[0] == save[0] && playerPosition[1] == save[1] && save_on_map == true){
        return true;
    }
    return false;
}

/*
 * Algorithm: Checks if the location is a monster  
 * loop i from 0 to monster_count
 *      if player position is a monster location
 *          if monster type is -1
 *              return false
 *          return true  
 * return false
 * Parameters: none
 * Return: boolean (bool)
 */
bool Map::isMonsterLocation(){
    for(int i = 0; i < monster_count; i++){
        if (playerPosition[0] == monsters[i][0] && playerPosition[1] == monsters[i][1]){
            if (monsters[i][2] == -1){
                return false;
            }
            return true;
        }
    }
    return false;
}

/*
 * Algorithm: Checks if the location is puzzle 
 * loop i from 0 to num_puzzles
 *      if player position is a puzzle location
 *          if puzzle type is -1
 *              return false
 *          return true  
 * return false
 * Parameters: none
 * Return: boolean (bool)
 */
bool Map::isPuzzleLocation(){
    for(int i = 0; i < num_puzzles; i++){
        if (playerPosition[0] == puzzle[i][0] && playerPosition[1] == puzzle[i][1]){
            if (puzzle[i][2] == -1){
                return false;
            }
            return true;
        }
    }
    return false;
}

/*
 * Algorithm: Checks if the given row and column on map is a free space 
 * if row and column is not within the map boundaries
 *      return false
 * loop i from 0 to misfortune_count
 *      if (row,col) is a misfortune location
 *          return false
 * loop i from 0 to num_sites
 *      if (row,col) is a site location
 *          return false
 * if (row,col) is a npc position
 *      return false
 * return true
 * Parameters: row (int), col (int)
 * Return: boolean (bool)
 */
bool Map::isFreeSpace(int row, int col){
    if (!(row >= 0 && row < num_rows && col >= 0 && col < num_cols)) {
        return false;
    }
    for(int i = 0; i < monster_count; i++){
        if (row == monsters[i][0] && col == monsters[i][1]){
            return false;
        }
    }
    for(int i = 0; i < num_puzzles; i++){
        if (row == puzzle[i][0] && col == puzzle[i][1]){
            return false;
        }
    }
    if (row == shopPosition[0] && col == shopPosition[1]){
        return false;
    }
    if (row == npc[0] && col == npc[1]){
        return false;
    }
    return true;
}

void Map::setMonsterCount(int num_monster){
    monster_count = num_monsters;
}

void Map::setShop(bool isShop){
    shop_on_map = isShop;
}

void Map::setNPC(bool isNPC){
    npc_on_map = isNPC;
}

void Map::setSave(bool isSave){
    save_on_map = isSave;
}

void Map::setPlayerRowPosition(int row) {
    playerPosition[0] = row;
}


void Map::setPlayerColPosition(int col) {
    playerPosition[1] = col;
}

/*
 * Algorithm: Create a shop on the map 
 * if shop is present on map
 *      return false
 * if (row,col) is not a free space
 *      return false
 * store row and col values in shopPosition array
 * set (row,col) value in mapData to 'A'
 * set shop_on_map to true
 * return true
 * Parameters: row (int), col (int)
 * Return: boolean (bool)
 */
bool Map::spawnShop(int row, int col) {
    if (shop_on_map) {
        return false;
    }

    if (!isFreeSpace(row, col)) {
        return false;
    }

    shopPosition[0] = row;
    shopPosition[1] = col;
    mapData[row][col] = 'S';
    shop_on_map = true;
    return true;
}

/*
 * Algorithm: Create a save on the map 
 * if save is present on map
 *      return false
 * if (row,col) is not a free space
 *      return false
 * store row and col values in save array
 * set (row,col) value in mapData to '✭'
 * set save_on_map to true
 * return true
 * Parameters: row (int), col (int)
 * Return: boolean (bool)
 */
bool Map::spawnSave(int row, int col) {
    if (save_on_map) {
        return false;
    }

    if (!isFreeSpace(row, col)) {
        return false;
    }

    save[0] = row;
    save[1] = col;
    mapData[row][col] = '*';
    save_on_map = true;
    return true;
}

/*
 * Algorithm: Create a NPC on the map 
 * if npc is present on map
 *      return false
 * if (row,col) is not a free space
 *      return false
 * store row and col values in npcPosition array
 * set (row,col) value in mapData to 'F'
 * set npc_on_map to true
 * return true
 * Parameters: row (int), col (int)
 * Return: boolean (bool)
 */
bool Map::spawnNPC(int row, int col) {
    if (npc_on_map) {
        return false;
    }

    // location must be blank to spawn
    if (!isFreeSpace(row, col)) {
        return false;
    }

    if (npc[0] == -1 && npc[1] == -1) {
        npc[0] = row;
        npc[1] = col;
        mapData[row][col] = 'F';
        npc_on_map = true;
        return true;
    }
    return false;
}

/*
 * Algorithm: Create a monster on the map 
 * if monster_count is more than or equal to number of monsters
 *      return false
 * if (row,col) is not a free space
 *      return false
 * if next row in monsters matrix is -1 -1
 *      store row, col and type values in the current row of monsters matrix
 *      increment monster_count
 *      return true
 * Parameters: row (int), col (int), type (int)
 * Return: boolean (bool)
 */
bool Map::spawnMonster(int row, int col, int type) {

    if (monster_count >= num_monsters) {
        return false;
    }

    // location must be blank to spawn
    if (!isFreeSpace(row, col)) {
        return false;
    }

    if (monsters[monster_count][0] == -1 && monsters[monster_count][1] == -1) {
        monsters[monster_count][0] = row;
        monsters[monster_count][1] = col;
        monsters[monster_count][2] = type;
        mapData[row][col] = 'm';
        monster_count++;
        return true;
    }
    return false;
}

/*
 * Algorithm: Create a puzzle on the map 
 * if puzzle_count is more than or equal to number of puzzles
 *      return false
 * if (row,col) is not a free space
 *      return false
 * if next row in puzzles matrix is -1 -1
 *      store row, col and type values in the current row of puzzles matrix
 *      increment puzzles_count
 *      Set (row,col) value in mapData to 'P'
 *      return true
 * Parameters: row (int), col (int), type (int)
 * Return: boolean (bool)
 */
bool Map::spawnPuzzle(int row, int col, int type) {

    if (puzzle_count >= num_puzzles) {
        return false;
    }

    // location must be blank to spawn
    if (!isFreeSpace(row, col)) {
        return false;
    }

    if (puzzle[puzzle_count][0] == -1 && puzzle[puzzle_count][1] == -1) {
        puzzle[puzzle_count][0] = row;
        puzzle[puzzle_count][1] = col;
        puzzle[puzzle_count][2] = type;
        puzzle_count++;
        mapData[row][col] = 'P';
        return true;
    }

    return false;
}

/*
 * Algorithm: This function prints "*" to reveal a position of misfortune
 * Set the value of (row, col) in mapData to '*'
 * Parameters: row (int), col (int)
 * Return: nothing (void)
 */
void Map::revealMonster(int row, int col) {
    mapData[row][col] = 'M';
}

// string function named toUpper with parameters phrase
string toUpper(string phrase)
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

/*
 * Algorithm: Make the player move based on the given command 
 * if user inputs w and if its not the top row of the map
 *      Move the player up by one row
 *      return true
 * if user inputs s and if its not the bottom row of the map
 *      Move the player down by one row
 *      return true
 * if user inputs a and if its not the leftmost column
 *      Move the player left by one column
 *      return true
 * if user inputs d and if its not the rightmost column
 *      Move the player right by one column
 *      return true
 * Parameters: move (char)
 * Return: boolean (bool)
 */
bool Map::move(string move){
    // if user inputs w, move up if it is an allowed move
    if(!(playerPosition[0] == 0) && (toUpper(move) == "W")){
        playerPosition[0] -= 1;
        return true; 
    }
    // if user inputs s, move down if it is an allowed move
    else if(!(playerPosition[0] == (num_rows - 1))&& (toUpper(move) == "S")){
        playerPosition[0] += 1;
        return true; 
    }
    // if user inputs a, move left if it is an allowed move
    else if(!(playerPosition[1] == 0)&& (toUpper(move) == "A")){
        playerPosition[1] -= 1;
        return true; 
    }
    // if user inputs d, move right if it is an allowed move
    else if(!(playerPosition[1] == (num_cols - 1))&& (toUpper(move) == "D")){
        playerPosition[1] += 1;
        return true; 
    }
    else{
        cout << "Invalid Move" << endl; 
        return false; 
    }
}

/*
 * Algorithm: This function prints a 2D map in the terminal.
 * Loop i from 0 to number of rows
 *      Loop j from 0 to number of columns
 *          if player position is at (i,j)
 *              print "x"
 *          else if Monster is at (i,j)
 *              print "-"
 *          else
 *              print the value of (i,j) in mapData
 * Parameters: none
 * Return: nothing (void)
 */
void Map::displayMap() {
    for (int i = 0; i < num_rows; i++) {
        for (int j = 0; j < num_cols; j++) {
            if (playerPosition[0] == i && playerPosition[1] == j) {
                cout << "X";
            } else if (mapData[i][j] == 'm') {  // don't show Monster on the map
                cout << "-";
            }
            else {
                cout << mapData[i][j];
            }
        }
        cout << endl;
    }
}

// int function named split with parameters inputString, separator, arr[], size
int split2(string inputString, char separator, string arr[], int size)
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

// int function named readPuzzles with parameters fileName
// populates an array of puzzles found in a file 
int Map::readPuzzles(string fileName)
{
    int npuzzles = 0;
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
                    int s = split2(line, ',', arr, 50);
                    // if number of splits is greater than 0
                    if (s > 0)
                    {
                        Puzzle p(arr[0], arr[1], arr[2], arr[3], arr[4]);
                        // append each item object to puzzles vector
                        puzzles.push_back(p);
                        npuzzles++;
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
    // return number of puzzles stored
    return npuzzles;
}

void Map::printPuzzle(int type)
{
    int order = random1(1, 4);
    cout << puzzles[type].getQuestion() << endl;
    if (order == 1)
        {
            cout << "1. " << puzzles[type].getA1() << endl;
            cout << "2. " << puzzles[type].getA2() << endl;
            cout << "3. " << puzzles[type].getA3() << endl;
            cout << "4. " << puzzles[type].getA4() << endl;
            op1 = puzzles[type].getA1();
            op2 = puzzles[type].getA2();
            op3 = puzzles[type].getA3();
            op4 = puzzles[type].getA4();
        }
    else if (order == 2)
        {
            cout << "1. " << puzzles[type].getA2() << endl;
            cout << "2. " << puzzles[type].getA3() << endl;
            cout << "3. " << puzzles[type].getA4() << endl;
            cout << "4. " << puzzles[type].getA1() << endl;
            op1 = puzzles[type].getA2();
            op2 = puzzles[type].getA3();
            op3 = puzzles[type].getA4();
            op4 = puzzles[type].getA1();
        }
    else if (order == 3)
        {
            cout << "1. " << puzzles[type].getA3() << endl;
            cout << "2. " << puzzles[type].getA1() << endl;
            cout << "3. " << puzzles[type].getA2() << endl;
            cout << "4. " << puzzles[type].getA4() << endl;
            op1 = puzzles[type].getA3();
            op2 = puzzles[type].getA1();
            op3 = puzzles[type].getA2();
            op4 = puzzles[type].getA4();
        }
    else if (order == 4)
        {
            cout << "1. " << puzzles[type].getA4() << endl;
            cout << "2. " << puzzles[type].getA3() << endl;
            cout << "3. " << puzzles[type].getA1() << endl;
            cout << "4. " << puzzles[type].getA2() << endl;
            op1 = puzzles[type].getA4();
            op2 = puzzles[type].getA3();
            op3 = puzzles[type].getA1();
            op4 = puzzles[type].getA2();
        }
}

int Map::correctAnswer(string choice, int type)
{
    if (choice == "1")
    { 
        if (op1 == puzzles[type].getA1())
        {
            cout << "You got the puzzle! 1 HP added." << endl;
            return 1;
        }
        else
        {
            cout << "Incorrect answer. -1 HP." << endl;
            return -1;
        }
    }
    else if (choice == "2")
    { 
        if (op2 == puzzles[type].getA1())
        {
            cout << "You got the puzzle! 2 HP added." << endl;
            return 1;
        }
        else
        {
            cout << "Incorrect answer. -1 HP." << endl;
            return -1;
        }
    }
    else if (choice == "3")
    { 
        if (op3 == puzzles[type].getA1())
        {
            cout << "You got the puzzle! 2 HP added." << endl;
            return 1;
        }
        else
        {
            cout << "Incorrect answer. -1 HP." << endl;
            return -1;
        }
    }
    else if (choice == "4")
    { 
        if (op4 == puzzles[type].getA1())
        {
            cout << "You got the puzzle! 2 HP added." << endl;
            return 1;
        }
        else
        {
            cout << "Incorrect answer. -1 HP." << endl;
            return -1;
        }
    }
    else
    {
        return 2;
    }
}




