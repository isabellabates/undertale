#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <cmath>
#include "Encounter.h"
#include "Map.h"
using namespace std;

// function stoc with parameter str
char stoc(string str)
{
    // declare letter
    char letter;
    // loop through str
    for (int i = 0; i < str.length(); i++)
    {
        // convert str into char
        letter = char(int(str[i]));
    }
    // return letter
    return letter;
}

// function named random with parameters min, max
int random(int min, int max)
{
    // return random integer between min and max
    return (rand() % (max - min + 1)) + min;
}

// string function named uppercase with parameters phrase
string upper(string phrase)
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

int main()
{
    // declare and initialize class objects
    Player p; Monster m; Encounter e; Map map; Puzzle puzzle;

    // declare and initialize name
    string name;
    string c;

    // load monsters for game 
    e.readMonsters("Monsters.txt");
    p.readItems("Item.txt");
    map.readPuzzles("questions.txt");

    // for map
    // declare row, col, npuzzles, nmonsters, type, npc, s, n, done, t, pComplete, room, totalMonsters, mchoice, act, flee, spare
    int row; int col; int npuzzles; int nmonsters; int type; int npc; bool s; bool n; bool done = false; int t = 0;
    int pComplete = 0; int room = 0; int totalMonsters = 0; string mchoice; string act; int flee = 5; int spare = 0;

    // for menu
    // declare move, i, i1, idx, input, c, confirm, confirm1, cont, choice, c1, c2 item, mhp
    string move; string i; string i1; string idx; char input; char confirm; char confirm1; char cont; 
    string choice; char c1; string c2; string item; int mhp;

    // print out game start message
    cout << endl;
    cout << "UNDERTALE" << endl;
    cout << endl;
    cout << "enter 'u' to start" << endl;
    cout << "enter 'q' to quit" << endl;

    // read user input
    getline(cin, c);
    // save user input in input
    input = stoc(c);

    // while user input is not q
    while (input != 'q')
    {
        // switch statement for input
        switch (input)
        {
            // if input is u
            case 'u':
            {
                // print game intro
                cout << endl;
                cout << "Long ago, two races ruled over Earth: HUMANS and MONSTERS." << endl;
                cout << "One day, war broke out between the two races. After a long battle, the humans were victorious." << endl;
                cout << "They sealed the monsters underground with a magic spell." << endl;
                cout << "Many years later…" << endl;
                cout << endl;

                // prompt user for username
                cout << "Name the fallen human." << endl;
                // read user input
                getline(cin, name);
                // save in name
                name = upper(name);
                // prompt user if name is correct
                cout << "Is this name correct? '" << name << "'" << endl;
                // print y / n
                cout << "y / n" << endl;
                // save input in c
                getline(cin, c);
                // convert c to char and save in confirm
                confirm = stoc(c);
                // print new line
                cout << endl;
                // while confirm is not y
                while (confirm != 'y')
                {
                    switch (confirm)
                    {
                        // if confirm is n
                        case 'n':
                        {
                            break;
                        }
                        // if confirm is anything else
                        default:
                        {
                            // print invalid input
                            cout << "Invalid input." << endl;
                            break;
                        }
                    }
                    // prompt user for username
                    cout << "Name the fallen human." << endl;
                    // read user input
                    getline(cin, name);
                    // save in name
                    name = upper(name);
                    // prompt user if name is correct
                    cout << "Is this name correct? '" << name << "'" << endl;
                    // print y / n
                    cout << "y / n" << endl;
                    // save input in c
                    getline(cin, c);
                    // convert c to char and save in confirm
                    confirm = stoc(c);
                    // print new line
                    cout << endl;
                }
                // if confirm is y
                if (confirm == 'y')
                {
                    // set player username
                    p.setUsername(name);
                }

                // continue to print game intro
                cout << "The player spawns in a small patch of flowers." << endl;
                cout << "After walking away from the flowers, the player walks through a gate and up to a single flower in the ground." << endl;
                // print "➤ enter 'c' to continue"
                cout << "➤ enter 'c' to continue" << endl;
                // save user input in c
                getline(cin, c);
                // convert c to char and save in cont
                cont = stoc(c);
                // while cont is not c
                while (cont != 'c')
                {
                    // print invalid input
                    cout << "Invalid input." << endl;
                    // print "➤ enter 'c' to continue"
                    cout << "➤ enter 'c' to continue" << endl;
                    // save user input in c
                    getline(cin, c);
                    // convert c to char and save in cont
                    cont = stoc(c);
                }
                cout << endl;
                // if cont is c
                if (cont == 'c')
                {
                    // print FLOWEY introduction
                    cout << "FLOWEY:" << endl;
                    cout << "Howdy! I'm FLOWEY. FLOWEY the FLOWER! Hmmm..." << endl;
                    cout << "You're new to the UNDERGROUND, aren't cha? Golly, you must be so confused." << endl;
                    cout << "Someone ought to teach you how things work around here!" << endl;
                    cout << "I guess little old me will have to do. Ready?" << endl;
                    cout << "Here we go!" << endl;
                    // print "➤ enter 'c' to continue"
                    cout << "➤ enter 'c' to continue" << endl;
                    // save user input in c
                    getline(cin, c);
                    // convert c to char and save in cont
                    cont = stoc(c);
                    // while cont is not c
                    while (cont != 'c')
                    {
                        // print invalid input
                        cout << "Invalid input." << endl;
                        // print "➤ enter 'c' to continue"
                        cout << "➤ enter 'c' to continue" << endl;
                        // save user input in c
                        getline(cin, c);
                        // convert c to char and save in cont
                        cont = stoc(c);
                    }
                    cout << endl;
                    // if cont is c
                    if (cont == 'c')
                    {
                        // print flowey fight
                        cout << "You entered a fight with Flowey." << endl;
                        cout << "╭―――――――――――――╮" << endl;
                        cout << "│             │" << endl;
                        cout << "│      ♥      │" << endl;
                        cout << "│             │" << endl;
                        cout << "╰―――――――――――――╯" << endl;
                        // print fight menu
                        cout << "1. Fight" << endl;
                        cout << "2. Act" << endl;
                        cout << "3. Item" << endl;
                        cout << "4. Spare" << endl;
                        cout << "5. Flee" << endl;
                        cout << endl; 

                        // continue flowey conversation
                        cout << "FLOWEY:" << endl;
                        cout << "See that heart? That is your SOUL, the very culmination of your being." << endl;
                        cout << "Your SOUL starts off weak, but can grow strong if you gain a lot of LV." << endl;
                        cout << "What's LV stand for? Why, LOVE, of course!" << endl;
                        cout << "You want some LOVE, don't you? Don't worry, I'll share some with you!" << endl;
                        // print "➤ enter 'c' to continue"
                        cout << "➤ enter 'c' to continue" << endl;
                        // save user input in c
                        getline(cin, c);
                        // convert c to char and save in cont
                        cont = stoc(c);
                        // while cont is not c
                        while (cont != 'c')
                        {
                            // print invalid input
                            cout << "Invalid input." << endl;
                            // print "➤ enter 'c' to continue"
                            cout << "➤ enter 'c' to continue" << endl;
                            // save user input in c
                            getline(cin, c);
                            // convert c to char and save in cont
                            cont = stoc(c);
                        }
                        cout << endl;
                        // if cont is c
                        if (cont == 'c')
                        {
                            // call fight function
                            e.Fight(p, 17);
                            // print that flowey drained players HP
                            cout << "FLOWEY drains your HP by 19. Flowey's expression changes from a friendly smile to an evil smile." << endl;
                            cout << endl;

                            // continue to print flowey conversation
                            cout << "FLOWEY:" << endl;
                            cout << "You idiot! In this world, it's kill or BE killed. Why would ANYONE pass up an opportunity like this!?" << endl;
                            cout << "Die!" << endl;
                            // print "➤ enter 'c' to continue"
                            cout << "➤ enter 'c' to continue" << endl;
                            // save user input in c
                            getline(cin, c);
                            // convert c to char and save in cont
                            cont = stoc(c);
                            // while cont is not c
                            while (cont != 'c')
                            {
                                // print invalid input
                                cout << "Invalid input." << endl;
                                // print "➤ enter 'c' to continue"
                                cout << "➤ enter 'c' to continue" << endl;
                                // save user input in c
                                getline(cin, c);
                                // convert c to char and save in cont
                                cont = stoc(c);
                            }
                            cout << endl;
                            // if cont is c
                            if (cont == 'c')
                            {
                                // print flowey conversation
                                cout << "Right before Flowey goes to attack your SOUL, a fireball appears next to Flowey and knocks him away." << endl;
                                cout << "Your HP is restored, and a large goat-like creature slides in." << endl;
                                // set player health to 50
                                p.setHP(50);
                                // print "➤ enter 'c' to continue"
                                cout << "➤ enter 'c' to continue" << endl;
                                // save user input in c
                                getline(cin, c);
                                // convert c to char and save in cont
                                cont = stoc(c);
                                // while cont is not c
                                while (cont != 'c')
                                {
                                    // print invalid input
                                    cout << "Invalid input." << endl;
                                    // print "➤ enter 'c' to continue"
                                    cout << "➤ enter 'c' to continue" << endl;
                                    // save user input in c
                                    getline(cin, c);
                                    // convert c to char and save in cont
                                    cont = stoc(c);
                                }
                                cout << endl;
                                // if cont is c
                                if (cont == 'c')
                                {
                                    // print Toriel intro
                                    cout << "TORIEL:" << endl;
                                    cout << "What a terrible creature, torturing such a poor, innocent youth. Ah, do not be afraid, my child." << endl;
                                    cout << "I am TORIEL, caretaker of the RUINS. I pass through this place every day to see if anyone has fallen down." << endl;
                                    cout << "You are the first human to come here in a long time. Come!" << endl;
                                    cout << "I will guide you through the catacombs." << endl;
                                    // print "➤ enter 'c' to continue"
                                    cout << "➤ enter 'c' to continue" << endl;
                                    // save user input in c
                                    getline(cin, c);
                                    // convert c to char and save in cont
                                    cont = stoc(c);
                                    // while cont is not c
                                    while (cont != 'c')
                                    {
                                        // print invalid input
                                        cout << "Invalid input." << endl;
                                        // print "➤ enter 'c' to continue"
                                        cout << "➤ enter 'c' to continue" << endl;
                                        // save user input in c
                                        getline(cin, c);
                                        // convert c to char and save in cont
                                        cont = stoc(c);
                                    }
                                    cout << endl;
                                    // if cont is c
                                    if (cont == 'c')
                                    {
                                        // print that player follow Toriel
                                        cout << "You follow Toriel through a purple gate, and end up in a new room." << endl;
                                        cout << endl;
                                        // print welcome message
                                        cout << "TORIEL:" << endl;
                                        cout << "Welcome to your new home, innocent one. Allow me to educate you in the operation of the RUINS." << endl;
                                            
                                            // creating random map layout for Ruins
                                            // initialize npuzzles
                                            npuzzles = random(4, 7);
                                            // initialize nmonsters
                                            nmonsters = random(4, 8);
                                            // initialize npc
                                            npc = (random(0, 100) % 2);
                                            // initialize save
                                            map.spawnSave(1, 2);
                                            do
                                            {
                                                // initialize row
                                                row = rand() % 11;
                                                // initialize col
                                                col = rand() % 11;
                                                // initialize type
                                                type = rand() % 86;
                                                // spawn puzzle
                                                map.spawnPuzzle(row, col, type);
                                            } while (map.getPuzzleCount() < npuzzles);
                                            do
                                            {
                                                // initialize row
                                                row = rand() % 11;
                                                // initialize col
                                                col = rand() % 11;
                                                // initialize type
                                                type = random(1, 4);
                                                // spawn monster
                                                map.spawnMonster(row, col, type);
                                            } while (map.getMonsterCount() < nmonsters);
                                            do
                                            {
                                                // initialize row
                                                row = rand() % 11;
                                                // initialize col
                                                col = rand() % 11;
                                                // spawn shop
                                                s = map.spawnShop(row, col);
                                            } while (s != true);
                                            // print map
                                            map.displayMap();
                                        // print "➤ enter 'c' to continue"
                                        cout << "➤ enter 'c' to continue" << endl;
                                        // save user input in c
                                        getline(cin, c);
                                        // convert c to char and save in cont
                                        cont = stoc(c);
                                        // while cont is not c
                                        while (cont != 'c')
                                        {
                                            // print invalid input
                                            cout << "Invalid input." << endl;
                                            // print "➤ enter 'c' to continue"
                                            cout << "➤ enter 'c' to continue" << endl;
                                            // save user input in c
                                            getline(cin, c);
                                            // convert c to char and save in cont
                                            cont = stoc(c);
                                        }
                                        cout << endl;
                                        // if cont is c
                                        if (cont == 'c')
                                        {
                                            // print intro to map
                                            cout << "TORIEL:" << endl;
                                            cout << "The RUINS are full of PUZZLES. Ancient fusions between diversions and doorkeys." << endl;
                                            cout << "One must solve them to move from room to room. Please adjust yourself to the sight of them. They are marked by 'P'." << endl;
                                            cout << "As a human living in the Underground, MONSTERS may attack you. You will need to be prepared for this situation." << endl;
                                            cout << "However, worry not! The process is simple. When you encounter a monster, you will enter a FIGHT." << endl;
                                            cout << "You will be given the choices to FIGHT, ACT, use ITEM, SPARE, or FLEE." << endl;
                                            cout << "It is best to try to ACT, and then TALK. There is then a change that the MONSTER won't want to fight anymore." << endl;
                                            cout << "You must complete everything in a room to unlock the next room." << endl;
                                            cout << "Take this Butterscotch Pie, Toy Knife, and 50G. Use them wisely!" << endl;
                                            // save item in inventory
                                            p.saveItem("C", 0);
                                            // save item in inventory
                                            p.saveItem("W", 0);
                                            // add 50 to gold
                                            p.updateGold(50);
                                            
                                            cout << endl;
                                            // print puzzles complete out of total puzzles
                                            cout << "Puzzles: " << pComplete << "/" << npuzzles << endl;
                                            // print map
                                            map.displayMap();
                                            // print map menu
                                            cout << "Select one:" << endl;
                                            cout << "1. Move" << endl;
                                            cout << "2. View Status" << endl;
                                            cout << "3. View Inventory" << endl;
                                            cout << "4. Go to next room" << endl;
                                            cout << "5. Back to start screen" << endl;

                                            cout << endl;
                                            // print save hint
                                            cout << "A twinkling yellow star comes into view. Move toward it." << endl;
                                            // save user input in choice
                                            getline(cin, choice);
                                            // while choice is not 5 and room is less than 9
                                            while (choice != "5" && room < 9)
                                            {
                                                // if choice is 1
                                                if (choice == "1")
                                                {
                                                    // print move menu
                                                    cout << "Select one: w. up s. down d. right a. left m. menu" << endl;
                                                    // save user input in move
                                                    getline(cin, move);
                                                        // while move is not m
                                                        while (move != "m")
                                                        {
                                                            // if move is w
                                                            if (move == "w")
                                                            {
                                                                // execute move
                                                                map.move(move);
                                                            }
                                                            // if move is a
                                                            else if (move == "a" )
                                                            {
                                                                // execute move
                                                                map.move(move);
                                                            }
                                                            // if move is s
                                                            else if (move == "s" )
                                                            {
                                                                // execute move
                                                                map.move(move);
                                                            }
                                                            // if move is d
                                                            else if (move == "d" )
                                                            {
                                                                // execute move
                                                                map.move(move);
                                                            }
                                                            // if move is invalid
                                                            else
                                                            {
                                                                // print invalid input
                                                                cout << "Invalid input." << endl;
                                                            }
                                                            // if player is on monster location
                                                            if (map.isMonsterLocation() == true)
                                                            {
                                                                // save player col in col
                                                                col = map.getPlayerColPosition();
                                                                // save player row in row
                                                                row = map.getPlayerRowPosition();
                                                                // reveal monster
                                                                map.revealMonster(row, col);
                                                                // player is in RUINS location
                                                                if (room < 2)
                                                                {
                                                                    // get type of monster
                                                                    type = random(1, 4);
                                                                }
                                                                // player is in SNOWDIN location
                                                                else if (room >= 2 && room < 5)
                                                                {
                                                                    // get type of monster
                                                                    type = random(1, 9);
                                                                }
                                                                // player is in WATERFALLS location
                                                                else if (room >= 5 && room < 7)
                                                                {
                                                                    // get type of monster
                                                                    type = random(1, 11);
                                                                }
                                                                // player is in HOTLAND location
                                                                else if (room >= 7 && room < 9)
                                                                {
                                                                    // get type of monster
                                                                    type = random(1, 12);
                                                                }
                                                                            
                                                                    // get monster object using type
                                                                    m = e.getMonster(type);
                                                                    // print monster intro
                                                                    cout << m.getIntro() << endl;
                                                                    // print encounter menu
                                                                    cout << "╭―――――――――――――╮" << endl;
                                                                    cout << "│             │" << endl;
                                                                    cout << "│      ♥      │" << endl;
                                                                    cout << "│             │" << endl;
                                                                    cout << "╰―――――――――――――╯" << endl;
                                                                    cout << "1. Fight" << endl;
                                                                    cout << "2. Act" << endl;
                                                                    cout << "3. Item" << endl;
                                                                    cout << "4. Spare" << endl;
                                                                    cout << "5. Flee" << endl;
                                                                    // get user input
                                                                    getline(cin, mchoice);
                                                                    cout << endl;
                                                                    // set done to false
                                                                    done = false;
                                                                    // set inst to zero
                                                                    int inst = 0;
                                                                    // while monster has not been defeated
                                                                    do
                                                                    {
                                                                        // player choice is Fight
                                                                        if (mchoice == "1")
                                                                        {
                                                                            // if first time choosing fight with this monster
                                                                            if (inst == 0)
                                                                            {
                                                                                // save monster hp in mhp
                                                                                mhp = e.Fight(p, type);
                                                                            }
                                                                            // if not first time using fight
                                                                            else if (inst > 0)
                                                                            {
                                                                                // update monster hp
                                                                                mhp = e.Fight1(p, type, mhp);
                                                                            }
                                                                            // if result of fight is -2
                                                                            if (mhp == -2)
                                                                            {
                                                                                // monster was killed, encounter is done
                                                                                done = true;
                                                                            }
                                                                            // if result of fight is -3
                                                                            else if (mhp == -3)
                                                                            {
                                                                                // monster has low enough health to spare
                                                                                spare = 1;
                                                                            }
                                                                            // increment inst
                                                                            inst++;
                                                                            cout << endl;
                                                                        }
                                                                        // player choice is Act
                                                                        else if (mchoice == "2")
                                                                        {
                                                                            // print Act menu
                                                                            cout << "1. Check" << endl;
                                                                            cout << "2. Talk" << endl;
                                                                            cout << "3. Back to menu" << endl;
                                                                            // read user input and save in act
                                                                            getline(cin, act);
                                                                            cout << endl;
                                                                            // while act is not 3
                                                                            while (act != "3")
                                                                            {
                                                                                // if act is 1
                                                                                if (act == "1")
                                                                                {
                                                                                    // print player and monster stats
                                                                                    cout << upper(p.getUsername()) << " — HP " << p.getHP() << " ATK " << p.getATK() << " DEF " << p.getDF() << endl;
                                                                                    spare = e.Act(p, type, 1);
                                                                                }
                                                                                // if act is 2
                                                                                else if (act == "2")
                                                                                {
                                                                                    // save result of Act in spare
                                                                                    spare = e.Act(p, type, 2);
                                                                                }
                                                                                // if act is neither of those choices
                                                                                else
                                                                                {
                                                                                    // print invalid input
                                                                                    cout << "Invalid input." << endl;
                                                                                }
                                                                                // print Act menu
                                                                                cout << "1. Check" << endl;
                                                                                cout << "2. Talk" << endl;
                                                                                cout << "3. Back to menu" << endl;
                                                                                // read user input and save in act
                                                                                getline(cin, act);
                                                                                cout << endl;
                                                                            }
                                                                        }
                                                                        // player choice is Item
                                                                        else if (mchoice == "3")
                                                                        {
                                                                            // print use item instructions
                                                                            cout << "To USE ITEM, enter the index of the ITEM in your inventory." << endl;
                                                                            // print player's inventory
                                                                            cout << upper(p.getUsername()) << " INVENTORY" << endl;
                                                                            // print inventory function
                                                                            p.printInventory();
                                                                            // print back to menu choice
                                                                            cout << "m. Back to menu" << endl;
                                                                            // read user input and save in c2
                                                                            getline(cin, c2);
                                                                            cout << endl;
                                                                            // while c2 is not m
                                                                            while (c2 != "m")
                                                                            {
                                                                                // if c2 is within range of inventory
                                                                                if (stoi(c2) <= p.getNumInv())
                                                                                {
                                                                                    // save item name in item
                                                                                    item = p.getItem(stoi(c2));
                                                                                    // prompt user to use item
                                                                                    cout << "Use '" << item << "'?" << endl;;
                                                                                    // print y / n message
                                                                                    cout << "y / n" << endl;
                                                                                    // read user input
                                                                                    getline(cin, c);
                                                                                    // convert to char and save in confirm
                                                                                    confirm = stoc(c);
                                                                                    cout << endl;
                                                                                    // if confirm is not n
                                                                                    if (confirm != 'n')
                                                                                    {
                                                                                        // if confirm is y
                                                                                        if (confirm == 'y')
                                                                                        {
                                                                                            // save result of useItem in u
                                                                                            int u = p.useItem(stoi(c2));
                                                                                            // if u is 2
                                                                                            if (u == 2)
                                                                                            {
                                                                                                // item was successfully used
                                                                                                // print that the player ate the item
                                                                                                cout << "You quickly eat a snack and then rejoin the fight." << endl;
                                                                                                cout << endl;
                                                                                            }
                                                                                            // if u is 1
                                                                                            else if (u == 1)
                                                                                            {
                                                                                                // print that player cannot eat that item because it is not consumable
                                                                                                cout << "You are already using WEAPONS and ARMOR. You can only choose to use CONSUMABLES." << endl;
                                                                                                cout << endl;
                                                                                            }
                                                                                        }
                                                                                        // if confirm is not y
                                                                                        else
                                                                                        {
                                                                                            // while confirm is not n
                                                                                            while (confirm != 'n')
                                                                                            {
                                                                                                // print invalid input
                                                                                                cout << "Invalid input." << endl;
                                                                                                // print y / n message
                                                                                                cout << "y / n" << endl;
                                                                                                // read user input and save in c
                                                                                                getline(cin, c);
                                                                                                // convert to char and save in confirm
                                                                                                confirm = stoc(c);
                                                                                                cout << endl;
                                                                                            }
                                                                                        }
                                                                                    }
                                                                                }
                                                                                // if c2 is not within inventory range
                                                                                else
                                                                                {
                                                                                    // print that user does not have item saved there
                                                                                    cout << "You do not have an ITEM saved in that index." << endl;
                                                                                    cout << endl;
                                                                                }
                                                                                // print use item instructions
                                                                                cout << "To USE ITEM, enter the index of the ITEM in your inventory." << endl;
                                                                                // print player's inventory
                                                                                cout << upper(p.getUsername()) << " INVENTORY" << endl;
                                                                                // print inventory function
                                                                                p.printInventory();
                                                                                // print back to menu choice
                                                                                cout << "m. Back to menu" << endl;
                                                                                // read user input and save in c2
                                                                                getline(cin, c2);
                                                                                cout << endl;
                                                                            }
                                                                        }
                                                                        // player choice is Spare
                                                                        else if (mchoice == "4")
                                                                        {
                                                                            // if spare does equal 0
                                                                            if (spare != 0)
                                                                            {
                                                                                // prompt user to spare monster
                                                                                cout << "Spare " << m.getMName() << "? y / n" << endl;
                                                                                // read user input and save in c
                                                                                getline(cin, c);
                                                                                // convert c to char and save in confirm1
                                                                                confirm1 = stoc(c);
                                                                                // print new line
                                                                                cout << endl;
                                                                                // if confirm1 != n
                                                                                if (confirm1 != 'n')
                                                                                {
                                                                                    // if confirm1 equals y
                                                                                    if (confirm1 == 'y')
                                                                                    {
                                                                                        // spare monster
                                                                                        e.Spare(p, type);
                                                                                        // add to player's gold
                                                                                        p.updateGold(m.getMGold());
                                                                                        // set done to true
                                                                                        done = true;
                                                                                        // print new line
                                                                                        cout << endl;
                                                                                    }
                                                                                    // if confirm1 is not y
                                                                                    else
                                                                                    {
                                                                                        // while confirm1 is not n
                                                                                        while (confirm1 != 'n')
                                                                                        {
                                                                                            // print invalid input
                                                                                            cout << "Invalid input." << endl;
                                                                                            // prompt user to spare monster
                                                                                            cout << "Spare " << m.getMName() << "? y / n" << endl;
                                                                                            // read user input and save in c
                                                                                            getline(cin, c);
                                                                                            // convert c to char and save in confirm1
                                                                                            confirm1 = stoc(c);
                                                                                            // print new line
                                                                                            cout << endl;
                                                                                        }
                                                                                    }
                                                                                }
                                                                            }
                                                                            // if spare is 0
                                                                            else
                                                                            {
                                                                                // print that monster can not be spared yet
                                                                                cout << m.getMName() << " needs more convincing. You can not spare until you talk to the monster enough or its health is low enough." << endl;
                                                                                cout << endl;
                                                                            }
                                                                        }
                                                                        // player choice is Flee
                                                                        else if (mchoice == "5")
                                                                        {
                                                                            // print users amount of flees
                                                                            cout << "You have " << flee << " flees left." << endl;
                                                                            // prompt user to flee
                                                                            cout << "Flee? y / n" << endl;
                                                                            // read user input and save in c
                                                                            getline(cin, c);
                                                                            // convert c to char and save in confirm1
                                                                            confirm1 = stoc(c);
                                                                            // print new line
                                                                            cout << endl;
                                                                            // if confirm1 != n
                                                                            if (confirm1 != 'n')
                                                                            {
                                                                                // if confirm1 equals y
                                                                                if (confirm1 == 'y')
                                                                                {
                                                                                    // if player has flees left
                                                                                    if (flee > 0)
                                                                                    {
                                                                                        // subtract one from flee
                                                                                        flee--;
                                                                                        // print "Escaped..."
                                                                                        cout << "Escaped..." << endl;
                                                                                        // print users updated amount of flees
                                                                                        cout << "You have " << flee << " flees left." << endl;
                                                                                        // set done to true
                                                                                        done = true;
                                                                                        // print new line
                                                                                        cout << endl;
                                                                                    }
                                                                                    else
                                                                                    {
                                                                                        cout << "You have no flees left." << endl;
                                                                                        cout << endl;
                                                                                    }
                                                                                }
                                                                                // if confirm1 is not y
                                                                                else
                                                                                {
                                                                                    // while confirm1 is not n
                                                                                    while (confirm1 != 'n')
                                                                                    {
                                                                                        // print invalid input
                                                                                        cout << "Invalid input." << endl;
                                                                                        // print users amount of flees
                                                                                        cout << "You have " << flee << " flees left." << endl;
                                                                                        // prompt user to flee
                                                                                        cout << "Flee? y / n" << endl;
                                                                                        // read user input and save in c
                                                                                        getline(cin, c);
                                                                                        // convert c to char and save in confirm1
                                                                                        confirm1 = stoc(c);
                                                                                        // print new line
                                                                                        cout << endl;
                                                                                    }
                                                                                }
                                                                            }
                                                                        }
                                                                        // player choice is invalid
                                                                        else
                                                                        {
                                                                            cout << "Invalid input." << endl;
                                                                        }
                                                                        // if monster has not been defeated
                                                                        if (done != true)
                                                                        {
                                                                            // print encounter menu
                                                                            cout << "1. Fight" << endl;
                                                                            cout << "2. Act" << endl;
                                                                            cout << "3. Item" << endl;
                                                                            cout << "4. Spare" << endl;
                                                                            cout << "5. Flee" << endl;
                                                                            // get user input
                                                                            getline(cin, mchoice);
                                                                            cout << endl;
                                                                        }
                                                                    } while (done != true);
                                                                }
                                                                // if player is on npc location
                                                                else if (map.isNPCLocation() == true)
                                                                {
                                                                    // increment t
                                                                    t++;
                                                                    // if t is 1
                                                                    if (t == 1)
                                                                    {
                                                                        // player meets Sans
                                                                        // print Sans intro message
                                                                        cout << endl;
                                                                        cout << "Human." << endl;
                                                                        cout << "Don't you know how to greet a new pal?" << endl;
                                                                        cout << "Turn around and shake my hand" << endl;
                                                                        // print "➤ enter 'c' to continue"
                                                                        cout << "➤ enter 'c' to continue" << endl;
                                                                        // read user input
                                                                        getline(cin, c);
                                                                        // convert user input to char
                                                                        cont = stoc(c);
                                                                        // if user input is invalid
                                                                        while (cont != 'c')
                                                                        {
                                                                            // print invalid input
                                                                            cout << "Invalid input." << endl;
                                                                            // print "➤ enter 'c' to continue"
                                                                            cout << "➤ enter 'c' to continue" << endl;
                                                                            // read user input
                                                                            getline(cin, c);
                                                                            // convert user input to char
                                                                            cont = stoc(c);
                                                                        }
                                                                        // print new line
                                                                        cout << endl;
                                                                        // if user input is c
                                                                        if (cont == 'c')
                                                                        {
                                                                            // continue with conversation with Sans
                                                                            cout << "SANS:" << endl;
                                                                            cout << "heheh...the old whoopee cushion in the hand trick." << endl;
                                                                            cout << "it's ALWAYS funny." << endl;
                                                                            cout << "anyways, you're a human, right?" << endl;
                                                                            // print "➤ enter 'c' to continue"
                                                                            cout << "➤ enter 'c' to continue" << endl;
                                                                            // read user input
                                                                            getline(cin, c);
                                                                            // convert user input to char
                                                                            cont = stoc(c);
                                                                            // if user input is invalid
                                                                            while (cont != 'c')
                                                                            {
                                                                                // print invalid input
                                                                                cout << "Invalid input." << endl;
                                                                                // print "➤ enter 'c' to continue"
                                                                                cout << "➤ enter 'c' to continue" << endl;
                                                                                // read user input
                                                                                getline(cin, c);
                                                                                // convert user input to char
                                                                                cont = stoc(c);
                                                                            }
                                                                            // print new line
                                                                            cout << endl;
                                                                            // if user input is c
                                                                            if (cont == 'c')
                                                                            {
                                                                                // continue conversation with Sans
                                                                                cout << "SANS:" << endl;                                                                                        
                                                                                cout << "that's hilarious." << endl;
                                                                                cout << "i'm sans. sans the skeleton." << endl;
                                                                                cout << "i'm actually supposed to be on watch for humans right now." << endl;
                                                                                cout << "but y'know...i don't really care about capturing anybody." << endl;
                                                                                // print "➤ enter 'c' to continue"
                                                                                cout << "➤ enter 'c' to continue" << endl;
                                                                                // read user input
                                                                                getline(cin, c);
                                                                                // convert user input to char
                                                                                cont = stoc(c);
                                                                                // if user input is invalid
                                                                                while (cont != 'c')
                                                                                {
                                                                                    // print invalid input
                                                                                    cout << "Invalid input." << endl;
                                                                                    // print "➤ enter 'c' to continue"
                                                                                    cout << "➤ enter 'c' to continue" << endl;
                                                                                    // read user input
                                                                                    getline(cin, c);
                                                                                    // convert user input to char
                                                                                    cont = stoc(c);
                                                                                }
                                                                                // print new line
                                                                                cout << endl;
                                                                                // if user input is c
                                                                                if (cont == 'c')
                                                                                {
                                                                                    // continue conversation with Sans
                                                                                    cout << "SANS:" << endl;  
                                                                                    cout << "now my brother papyrus...he's a human-hunting FANATIC." << endl;
                                                                                    cout << "he thinks if he catches a human and can join the Royal Guard that he will be able to make FRIENDS." << endl;
                                                                                    // print "➤ enter 'c' to continue"
                                                                                    cout << "➤ enter 'c' to continue" << endl;
                                                                                    // read user input
                                                                                    getline(cin, c);
                                                                                    // convert user input to char
                                                                                    cont = stoc(c);
                                                                                    // if user input is invalid
                                                                                    while (cont != 'c')
                                                                                    {
                                                                                        // print invalid input
                                                                                        cout << "Invalid input." << endl;
                                                                                        // print "➤ enter 'c' to continue"
                                                                                        cout << "➤ enter 'c' to continue" << endl;
                                                                                        // read user input
                                                                                        getline(cin, c);
                                                                                        // convert user input to char
                                                                                        cont = stoc(c);
                                                                                    }
                                                                                    // print new line
                                                                                    cout << endl;
                                                                                    // if user input is c
                                                                                    if (cont == 'c')
                                                                                    {
                                                                                        // end conversation with Sans
                                                                                        cout << "SANS:" << endl;  
                                                                                        cout << "if you encounter him, try being his friend. he might not capture you then." << endl;
                                                                                        cout << "also take this stick. might help you fight heheh." << endl;
                                                                                        // add stick to inventory
                                                                                        p.saveItem("w", 10);
                                                                                        cout << "okay bye pal!" << endl;
                                                                                    }
                                                                                }
                                                                            }
                                                                        }
                                                                    }
                                                                    // if t is 2
                                                                    else if (t == 2)
                                                                    {
                                                                        // player meets Papyrus
                                                                        // print Papyrus intro message
                                                                        cout << endl;
                                                                        cout << "PAPYRUS:" << endl;
                                                                        cout << "HUMAN." << endl;
                                                                        cout << "ALLOW ME TO TELL YOU ABOUT SOME COMPLEX FEELINGS." << endl;
                                                                        cout << "FEELINGS LIKE..." << endl;
                                                                        cout << "THE JOY OF FINDING ANOTHE RPASTA LOVER." << endl;
                                                                        cout << "THE ADMIRATION FOR ONE'S PUZZLE-SOLVING SKILLS." << endl;
                                                                        cout << "THE DESIRE TO HAVE A COOL, SMART PERSON THINK YOU ARE COOL." << endl;
                                                                        // print "➤ enter 'c' to continue"
                                                                        cout << "➤ enter 'c' to continue" << endl;
                                                                        // read user input
                                                                        getline(cin, c);
                                                                        // convert user input to char
                                                                        cont = stoc(c);
                                                                        // if user input is invalid
                                                                        while (cont != 'c')
                                                                        {
                                                                            // print invalid input
                                                                            cout << "Invalid input." << endl;
                                                                            // print "➤ enter 'c' to continue"
                                                                            cout << "➤ enter 'c' to continue" << endl;
                                                                            // read user input
                                                                            getline(cin, c);
                                                                            // convert user input to char
                                                                            cont = stoc(c);
                                                                        }
                                                                        // print new line
                                                                        cout << endl;
                                                                        // if user input is c
                                                                        if (cont == 'c')
                                                                        {
                                                                            // continue with conversation with Sans
                                                                            cout << "PAPYRUS:" << endl;
                                                                            cout << "THESE FEELING MUST WHAT YOU ARE FEELING NOW!!!" << endl;
                                                                            cout << "AFTER ALL, I AM VERY GREAT." << endl;
                                                                            cout << "IMAGINE NOT HAVING FRIENDS LONELY HUMAN..." << endl;
                                                                            // print "➤ enter 'c' to continue"
                                                                            cout << "➤ enter 'c' to continue" << endl;
                                                                            // read user input
                                                                            getline(cin, c);
                                                                            // convert user input to char
                                                                            cont = stoc(c);
                                                                            // if user input is invalid
                                                                            while (cont != 'c')
                                                                            {
                                                                                // print invalid input
                                                                                cout << "Invalid input." << endl;
                                                                                // print "➤ enter 'c' to continue"
                                                                                cout << "➤ enter 'c' to continue" << endl;
                                                                                // read user input
                                                                                getline(cin, c);
                                                                                // convert user input to char
                                                                                cont = stoc(c);
                                                                            }
                                                                            // print new line
                                                                            cout << endl;
                                                                            // if user input is c
                                                                            if (cont == 'c')
                                                                            {
                                                                                // continue conversation with Sans
                                                                                cout << "WORRY NOT!! YOU SHALL NOT BE LONELY NO LONGER!" << endl;
                                                                                cout << "I, THE GREAT PAPYRUS, WILL BE YOUR..." << endl;
                                                                                cout << "FRIEND!" << endl;
                                                                                cout << "BUT YOU WILL HAVE TO SOLVE SOME OF THE PUZZLES I HAVE LEFT AROUND THIS MAP FOR YOU." << endl;
                                                                                // print "➤ enter 'c' to continue"
                                                                                cout << "➤ enter 'c' to continue" << endl;
                                                                                // read user input
                                                                                getline(cin, c);
                                                                                // convert user input to char
                                                                                cont = stoc(c);
                                                                                // if user input is invalid
                                                                                while (cont != 'c')
                                                                                {
                                                                                    // print invalid input
                                                                                    cout << "Invalid input." << endl;
                                                                                    // print "➤ enter 'c' to continue"
                                                                                    cout << "➤ enter 'c' to continue" << endl;
                                                                                    // read user input
                                                                                    getline(cin, c);
                                                                                    // convert user input to char
                                                                                    cont = stoc(c);
                                                                                }
                                                                                // print new line
                                                                                cout << endl;
                                                                                // if user input is c
                                                                                if (cont == 'c')
                                                                                {
                                                                                    // continue conversation with Sans
                                                                                    cout << "NYOO HOO HOO." << endl;
                                                                                    cout << "BECAUSE WE ARE FRIENDS. I WILL GIVE YOU ONE LESS PUZZLE TO SOLVE." << endl;
                                                                                    cout << "AND HAVE THIS HEART LOCKET. IT HAS 'BEST FRIENDS FOREVER' WRITTEN ON IT!" << endl;
                                                                                    pComplete++;
                                                                                    // add heart locket to inventory
                                                                                    p.saveItem("a", 0);
                                                                                    // print "➤ enter 'c' to continue"
                                                                                    cout << "➤ enter 'c' to continue" << endl;
                                                                                    // read user input
                                                                                    getline(cin, c);
                                                                                    // convert user input to char
                                                                                    cont = stoc(c);
                                                                                    // if user input is invalid
                                                                                    while (cont != 'c')
                                                                                    {
                                                                                        // print invalid input
                                                                                        cout << "Invalid input." << endl;
                                                                                        // print "➤ enter 'c' to continue"
                                                                                        cout << "➤ enter 'c' to continue" << endl;
                                                                                        // read user input
                                                                                        getline(cin, c);
                                                                                        // convert user input to char
                                                                                        cont = stoc(c);
                                                                                    }
                                                                                    // print new line
                                                                                    cout << endl;
                                                                                }
                                                                            }
                                                                        }
                                                                    }
                                                                }
                                                                // if player is on save location
                                                                else if (map.isSaveLocation() == true)
                                                                {
                                                                    // add 10 HP
                                                                    p.updateHP(10);
                                                                    // print new line
                                                                    cout << endl;
                                                                    // print save message
                                                                    cout << "(The shadow of the ruins looms above, filling you with determination. HP fully restored.)" << endl;
                                                                    cout << endl;
                                                                }
                                                                // if player is on shop location
                                                                else if (map.isShopLocation() == true)
                                                                {
                                                                            // print shop message
                                                                            cout << "You have come across a SHOP. Do you want to enter?" << endl;
                                                                            // print y / n message
                                                                            cout << "y / n" << endl;
                                                                            // read user input
                                                                            getline(cin, c);
                                                                            // convert to char and save in confirm
                                                                            confirm = stoc(c);
                                                                            cout << endl;
                                                                            if (confirm != 'n')
                                                                            {
                                                                                if (confirm == 'y')
                                                                                {
                                                                                    // print shop keeper message
                                                                                    cout << "Hello traveler. How can I help you?" << endl;
                                                                                    // print main shop menu
                                                                                    cout << "Select one:" << endl;
                                                                                    cout << "c. Consumables" << endl;
                                                                                    cout << "w. Weapons" << endl;
                                                                                    cout << "a. Armor" << endl;
                                                                                    cout << "e. Exit" << endl;
                                                                                    // read user input
                                                                                    getline(cin, i);
                                                                                    // while i is not e
                                                                                    while (i != "e")
                                                                                    {
                                                                                        // print new line
                                                                                        cout << endl;
                                                                                        // print player's gold
                                                                                        cout << upper(p.getUsername()) << ": " << p.getGold() << "G" << endl;
                                                                                        
                                                                                        // if i is c
                                                                                        if (i == "c")
                                                                                        {
                                                                                            // print consumable menu
                                                                                            cout << "Select one:" << endl;
                                                                                            cout << "1. Nice Cream" << endl;
                                                                                            cout << "2. Bisicle" << endl;
                                                                                            cout << "3. Unisicle" << endl;
                                                                                            cout << "4. Cinnamon Bunny" << endl;
                                                                                            cout << "5. Exit" << endl;
                                                                                            cout << endl;
                                                                                            // read user input
                                                                                            getline(cin,idx);
                                                                                            // while idx is not 5
                                                                                            while (idx != "5")
                                                                                            {
                                                                                                // if idx is 1
                                                                                                if (idx == "1")
                                                                                                {
                                                                                                    // print nice cream message
                                                                                                    cout << "15G - Nice Cream: Instead of a joke the wrapper says something nice." << endl;
                                                                                                    // prompt user to buy
                                                                                                    cout << "Buy? y / n" << endl;
                                                                                                    // read user input and save in c
                                                                                                    getline(cin, c);
                                                                                                    // convert c to char and save in confirm1
                                                                                                    confirm1 = stoc(c);
                                                                                                    // print new line
                                                                                                    cout << endl;
                                                                                                    // if confirm1 != n
                                                                                                    if (confirm1 != 'n')
                                                                                                    {
                                                                                                        // if confirm1 equals y
                                                                                                        if (confirm1 == 'y')
                                                                                                        {
                                                                                                            // if player has enough gold
                                                                                                            if (p.getGold() >= 15)
                                                                                                            {
                                                                                                                p.saveItem("c", 1);
                                                                                                                cout << "'Nice Cream' has been added to your inventory!" << endl;
                                                                                                                cout << endl;
                                                                                                            }
                                                                                                            else
                                                                                                            {
                                                                                                                cout << "You do not have enough Gold." << endl;
                                                                                                                cout << endl;
                                                                                                            }
                                                                                                        }
                                                                                                        // if confirm1 is not y
                                                                                                        else
                                                                                                        {
                                                                                                            // while confirm1 is not n
                                                                                                            while (confirm1 != 'n')
                                                                                                            {
                                                                                                                // print invalid input
                                                                                                                cout << "Invalid input." << endl;
                                                                                                                // prompt user to buy
                                                                                                                cout << "Buy? y / n" << endl;
                                                                                                                // read user input and save in c
                                                                                                                getline(cin, c);
                                                                                                                // convert c to char and save in confirm1
                                                                                                                confirm1 = stoc(c);
                                                                                                                // print new line
                                                                                                                cout << endl;
                                                                                                            }
                                                                                                        }
                                                                                                    }
                                                                                                }
                                                                                                // idx is 2
                                                                                                else if (idx == "2")
                                                                                                {
                                                                                                    cout << "25G - Bisicle: It is a two pronged popsicle so it is double the health!" << endl;
                                                                                                    // prompt user to buy
                                                                                                    cout << "Buy? y / n" << endl;
                                                                                                    // read user input and save in c
                                                                                                    getline(cin, c);
                                                                                                    // convert c to char and save in confirm1
                                                                                                    confirm1 = stoc(c);
                                                                                                    // print new line
                                                                                                    cout << endl;
                                                                                                    // if confirm1 != n
                                                                                                    if (confirm1 != 'n')
                                                                                                    {
                                                                                                        // if confirm1 equals y
                                                                                                        if (confirm1 == 'y')
                                                                                                        {
                                                                                                            // if player has enough gold
                                                                                                            if (p.getGold() >= 25)
                                                                                                            {
                                                                                                                p.saveItem("c", 2);
                                                                                                                cout << "'Bisicle' has been added to your inventory!" << endl;
                                                                                                                cout << endl;
                                                                                                            }
                                                                                                            else
                                                                                                            {
                                                                                                                cout << "You do not have enough Gold." << endl;
                                                                                                                cout << endl;
                                                                                                            }
                                                                                                        }
                                                                                                        // if confirm1 does equal y
                                                                                                        else
                                                                                                        {
                                                                                                            // while confirm1 does not equal n
                                                                                                            while (confirm1 != 'n')
                                                                                                            {
                                                                                                                // print invalid input
                                                                                                                cout << "Invalid input." << endl;
                                                                                                                // prompt user to buy
                                                                                                                cout << "Buy? y / n" << endl;
                                                                                                                // read user input and save in c
                                                                                                                getline(cin, c);
                                                                                                                // convert c to char and save in confirm1
                                                                                                                confirm1 = stoc(c);
                                                                                                                // print new line
                                                                                                                cout << endl;
                                                                                                            }
                                                                                                        }
                                                                                                    }
                                                                                                }
                                                                                                // idx is 3
                                                                                                else if (idx == "3")
                                                                                                {
                                                                                                    cout << "15G - Unisicle: It is a SINGLE pronged popsicle. Wait thats just normal..." << endl;
                                                                                                    // prompt user to buy
                                                                                                    cout << "Buy? y / n" << endl;
                                                                                                    // read user input and save in c
                                                                                                    getline(cin, c);
                                                                                                    // convert c to char and save in confirm1
                                                                                                    confirm1 = stoc(c);
                                                                                                    // print new line
                                                                                                    cout << endl;
                                                                                                    // if confirm1 != n
                                                                                                    if (confirm1 != 'n')
                                                                                                    {
                                                                                                        // if confirm1 equals y
                                                                                                        if (confirm1 == 'y')
                                                                                                        {
                                                                                                            // if player has enough gold
                                                                                                            if (p.getGold() >= 15)
                                                                                                            {
                                                                                                                p.saveItem("c", 3);
                                                                                                                cout << "'Unisicle' has been added to your inventory!" << endl;
                                                                                                                cout << endl;
                                                                                                            }
                                                                                                            else
                                                                                                            {
                                                                                                                cout << "You do not have enough Gold." << endl;
                                                                                                                cout << endl;
                                                                                                            }
                                                                                                        }
                                                                                                        // if confirm1 does equal y
                                                                                                        else
                                                                                                        {
                                                                                                            // while confirm1 does not equal n
                                                                                                            while (confirm1 != 'n')
                                                                                                            {
                                                                                                                // print invalid input
                                                                                                                cout << "Invalid input." << endl;
                                                                                                                // prompt user to buy
                                                                                                                cout << "Buy? y / n" << endl;
                                                                                                                // read user input and save in c
                                                                                                                getline(cin, c);
                                                                                                                // convert c to char and save in confirm1
                                                                                                                confirm1 = stoc(c);
                                                                                                                // print new line
                                                                                                                cout << endl;
                                                                                                            }
                                                                                                        }
                                                                                                    }
                                                                                                }
                                                                                                // idx is 4
                                                                                                else if (idx == "4")
                                                                                                {
                                                                                                    cout << "25G - Cinnamon Bunny: A cinnamon roll in the shape of a bunny." << endl;
                                                                                                    // prompt user to buy
                                                                                                    cout << "Buy? y / n" << endl;
                                                                                                    // read user input and save in c
                                                                                                    getline(cin, c);
                                                                                                    // convert c to char and save in confirm1
                                                                                                    confirm1 = stoc(c);
                                                                                                    // print new line
                                                                                                    cout << endl;
                                                                                                    // if confirm1 != n
                                                                                                    if (confirm1 != 'n')
                                                                                                    {
                                                                                                        // if confirm1 equals y
                                                                                                        if (confirm1 == 'y')
                                                                                                        {
                                                                                                            // if player has enough gold
                                                                                                            if (p.getGold() >= 25)
                                                                                                            {
                                                                                                                p.saveItem("c", 4);
                                                                                                                cout << "'Cinnamon Bunny' has been added to your inventory!" << endl;
                                                                                                                cout << endl;
                                                                                                            }
                                                                                                            else
                                                                                                            {
                                                                                                                cout << "You do not have enough Gold." << endl;
                                                                                                                cout << endl;
                                                                                                            }
                                                                                                        }
                                                                                                        // if confirm1 does equal y
                                                                                                        else
                                                                                                        {
                                                                                                            // while confirm1 does not equal n
                                                                                                            while (confirm1 != 'n')
                                                                                                            {
                                                                                                                // print invalid input
                                                                                                                cout << "Invalid input." << endl;
                                                                                                                // prompt user to buy
                                                                                                                cout << "Buy? y / n" << endl;
                                                                                                                // read user input and save in c
                                                                                                                getline(cin, c);
                                                                                                                // convert c to char and save in confirm1
                                                                                                                confirm1 = stoc(c);
                                                                                                                // print new line
                                                                                                                cout << endl;
                                                                                                            }
                                                                                                        }
                                                                                                    }   
                                                                                                }
                                                                                                // idx is invalid
                                                                                                else
                                                                                                {
                                                                                                    cout << "Invalid input." << endl;
                                                                                                }
                                                                                                cout << "Select one:" << endl;
                                                                                                cout << "1. Nice Cream" << endl;
                                                                                                cout << "2. Bisicle" << endl;
                                                                                                cout << "3. Unisicle" << endl;
                                                                                                cout << "4. Cinnamon Bunny" << endl;
                                                                                                cout << "5. Exit" << endl;
                                                                                                cout << endl;
                                                                                                getline(cin,idx);
                                                                                            }    
                                                                                        }
                                                                                        else if (i == "w")
                                                                                        {
                                                                                            // print weapons menu
                                                                                            cout << "Select one:" << endl;
                                                                                            cout << "1. Tough Glove" << endl;
                                                                                            cout << "2. Ballet Shoes" << endl;
                                                                                            cout << "3. Torn Notebook" << endl;
                                                                                            cout << "4. Burnt Pan" << endl;
                                                                                            cout << "5. Exit" << endl;
                                                                                            // print new line
                                                                                            cout << endl;
                                                                                            // read user input and save in idx
                                                                                            getline(cin,idx);
                                                                                            // while idx is not 5
                                                                                            while (idx != "5")
                                                                                            {
                                                                                                // idx is 1
                                                                                                if (idx == "1")
                                                                                                {    
                                                                                                    cout << "20G - Tough Glove: A worn pink leather glove. For five fingered folk." << endl;
                                                                                                    // prompt user to buy
                                                                                                    cout << "Buy? y / n" << endl;
                                                                                                    // read user input and save in c
                                                                                                    getline(cin, c);
                                                                                                    // convert c to char and save in confirm1
                                                                                                    confirm1 = stoc(c);
                                                                                                    // print new line
                                                                                                    cout << endl;
                                                                                                    // if confirm1 != n
                                                                                                    if (confirm1 != 'n')
                                                                                                    {
                                                                                                        // if confirm1 equals y
                                                                                                        if (confirm1 == 'y')
                                                                                                        {
                                                                                                            // if player has enough gold
                                                                                                            if (p.getGold() >= 20)
                                                                                                            {
                                                                                                                p.saveItem("w", 1);
                                                                                                                cout << "'Tough Glove' has been added to your inventory!" << endl;
                                                                                                                cout << endl;
                                                                                                            }
                                                                                                            else
                                                                                                            {
                                                                                                                cout << "You do not have enough Gold." << endl;
                                                                                                                cout << endl;
                                                                                                            }
                                                                                                        }
                                                                                                        // if confirm1 does equal y
                                                                                                        else
                                                                                                        {
                                                                                                            // while confirm1 does not equal n
                                                                                                            while (confirm1 != 'n')
                                                                                                            {
                                                                                                                // print invalid input
                                                                                                                cout << "Invalid input." << endl;
                                                                                                                // prompt user to buy
                                                                                                                cout << "Buy? y / n" << endl;
                                                                                                                // read user input and save in c
                                                                                                                getline(cin, c);
                                                                                                                // convert c to char and save in confirm1
                                                                                                                confirm1 = stoc(c);
                                                                                                                // print new line
                                                                                                                cout << endl;
                                                                                                            }
                                                                                                        }
                                                                                                    }       
                                                                                                }
                                                                                                // idx is 2
                                                                                                else if (idx == "2")
                                                                                                {
                                                                                                    cout << "50G - Ballet Shoes: These used shoes make you feel incredibly dangerous." << endl;
                                                                                                    // prompt user to buy
                                                                                                    cout << "Buy? y / n" << endl;
                                                                                                    // read user input and save in c
                                                                                                    getline(cin, c);
                                                                                                    // convert c to char and save in confirm1
                                                                                                    confirm1 = stoc(c);
                                                                                                    // print new line
                                                                                                    cout << endl;
                                                                                                    // if confirm1 != n
                                                                                                    if (confirm1 != 'n')
                                                                                                    {
                                                                                                        // if confirm1 equals y
                                                                                                        if (confirm1 == 'y')
                                                                                                        {
                                                                                                            // if player has enough gold
                                                                                                            if (p.getGold() >= 50)
                                                                                                            {
                                                                                                                p.saveItem("w", 2);
                                                                                                                cout << "'Ballet Shoes' has been added to your inventory!" << endl;
                                                                                                                cout << endl;
                                                                                                            }
                                                                                                            else
                                                                                                            {
                                                                                                                cout << "You do not have enough Gold." << endl;
                                                                                                                cout << endl;
                                                                                                            }
                                                                                                        }
                                                                                                        // if confirm1 does equal y
                                                                                                        else
                                                                                                        {
                                                                                                            // while confirm1 does not equal n
                                                                                                            while (confirm1 != 'n')
                                                                                                            {
                                                                                                                // print invalid input
                                                                                                                cout << "Invalid input." << endl;
                                                                                                                // prompt user to buy
                                                                                                                cout << "Buy? y / n" << endl;
                                                                                                                // read user input and save in c
                                                                                                                getline(cin, c);
                                                                                                                // convert c to char and save in confirm1
                                                                                                                confirm1 = stoc(c);
                                                                                                                // print new line
                                                                                                                cout << endl;
                                                                                                            }
                                                                                                        }
                                                                                                    }
                                                                                                }
                                                                                                // idx is 3
                                                                                                else if (idx == "3")
                                                                                                {
                                                                                                    cout << "55G - Torn Notebook: Contains illegible scrawls. Increases DEF by 6." << endl;
                                                                                                    // prompt user to buy
                                                                                                    cout << "Buy? y / n" << endl;
                                                                                                    // read user input and save in c
                                                                                                    getline(cin, c);
                                                                                                    // convert c to char and save in confirm1
                                                                                                    confirm1 = stoc(c);
                                                                                                    // print new line
                                                                                                    cout << endl;
                                                                                                    // if confirm1 != n
                                                                                                    if (confirm1 != 'n')
                                                                                                    {
                                                                                                        // if confirm1 equals y
                                                                                                        if (confirm1 == 'y')
                                                                                                        {
                                                                                                            // if player has enough gold
                                                                                                            if (p.getGold() >= 55)
                                                                                                            {
                                                                                                                p.saveItem("w", 3);
                                                                                                                cout << "'Torn Notebook' has been added to your inventory!" << endl;
                                                                                                                cout << endl;
                                                                                                            }
                                                                                                            else
                                                                                                            {
                                                                                                                cout << "You do not have enough Gold." << endl;
                                                                                                                cout << endl;
                                                                                                            }
                                                                                                        }
                                                                                                        // if confirm1 does equal y
                                                                                                        else
                                                                                                        {
                                                                                                            // while confirm1 does not equal n
                                                                                                            while (confirm1 != 'n')
                                                                                                            {
                                                                                                                // print invalid input
                                                                                                                cout << "Invalid input." << endl;
                                                                                                                // prompt user to buy
                                                                                                                cout << "Buy? y / n" << endl;
                                                                                                                // read user input and save in c
                                                                                                                getline(cin, c);
                                                                                                                // convert c to char and save in confirm1
                                                                                                                confirm1 = stoc(c);
                                                                                                                // print new line
                                                                                                                cout << endl;
                                                                                                            }
                                                                                                        }
                                                                                                    }
                                                                                                }
                                                                                                // idx is 4
                                                                                                else if (idx == "4")
                                                                                                {
                                                                                                    cout << "70G - Burnt Pan: Damage is rather consistent." << endl;
                                                                                                    // prompt user to buy
                                                                                                    cout << "Buy? y / n" << endl;
                                                                                                    // read user input and save in c
                                                                                                    getline(cin, c);
                                                                                                    // convert c to char and save in confirm1
                                                                                                    confirm1 = stoc(c);
                                                                                                    // print new line
                                                                                                    cout << endl;
                                                                                                    // if confirm1 != n
                                                                                                    if (confirm1 != 'n')
                                                                                                    {
                                                                                                        // if confirm1 equals y
                                                                                                        if (confirm1 == 'y')
                                                                                                        {
                                                                                                            // if player has enough gold
                                                                                                            if (p.getGold() >= 70)
                                                                                                            {
                                                                                                                // save item in player inventory
                                                                                                                p.saveItem("w", 4);
                                                                                                                cout << "'Burnt Pan' has been added to your inventory!" << endl;
                                                                                                                cout << endl;
                                                                                                            }
                                                                                                            // if player does not have enough gold
                                                                                                            else
                                                                                                            {
                                                                                                                // print player does not have enough gold
                                                                                                                cout << "You do not have enough Gold." << endl;
                                                                                                                // print new line
                                                                                                                cout << endl;
                                                                                                            }
                                                                                                        }
                                                                                                        // if confirm1 does equal y
                                                                                                        else
                                                                                                        {
                                                                                                            // while confirm1 does not equal n
                                                                                                            while (confirm1 != 'n')
                                                                                                            {
                                                                                                                // print invalid input
                                                                                                                cout << "Invalid input." << endl;
                                                                                                                // prompt user to buy
                                                                                                                cout << "Buy? y / n" << endl;
                                                                                                                // read user input and save in c
                                                                                                                getline(cin, c);
                                                                                                                // convert c to char and save in confirm1
                                                                                                                confirm1 = stoc(c);
                                                                                                                // print new line
                                                                                                                cout << endl;
                                                                                                            }
                                                                                                        }
                                                                                                    }
                                                                                                }
                                                                                                // idx is invalid
                                                                                                else
                                                                                                {
                                                                                                    // print invalid input
                                                                                                    cout << "Invalid input." << endl;         
                                                                                                }
                                                                                                // print weapons menu
                                                                                                cout << "Select one:" << endl;
                                                                                                cout << "1. Tough Glove" << endl;
                                                                                                cout << "2. Ballet Shoes" << endl;
                                                                                                cout << "3. Torn Notebook" << endl;
                                                                                                cout << "4. Burnt Pan" << endl;
                                                                                                cout << "5. Exit" << endl;
                                                                                                // print new line
                                                                                                cout << endl;
                                                                                                // read user input and save in idx
                                                                                                getline(cin,idx);
                                                                                            }
                                                                                        }
                                                                                        else if (i == "a")
                                                                                        {
                                                                                            // print armor menu
                                                                                            cout << "Select one:" << endl;
                                                                                            cout << "1. Faded Ribbon" << endl;
                                                                                            cout << "2. Manly Bandana" << endl;
                                                                                            cout << "3. Old Tutu" << endl;
                                                                                            cout << "4. Cloudy Glasses" << endl;
                                                                                            cout << "5. Exit" << endl;
                                                                                            // print new line
                                                                                            cout << endl;
                                                                                            // read user input and save in idx
                                                                                            getline(cin,idx);
                                                                                            // while idx is not 5
                                                                                            while (idx != "5")
                                                                                            {
                                                                                                // idx is 1
                                                                                                if (idx == "1")
                                                                                                {   
                                                                                                    cout << "10G - Faded Ribbon: Monsters will not hit you as hard if you are cuter." << endl;
                                                                                                    // prompt user to buy
                                                                                                    cout << "Buy? y / n" << endl;
                                                                                                    // read user input and save in c
                                                                                                    getline(cin, c);
                                                                                                    // convert c to char and save in confirm1
                                                                                                    confirm1 = stoc(c);
                                                                                                    // print new line
                                                                                                    cout << endl;
                                                                                                    // if confirm1 != n
                                                                                                    if (confirm1 != 'n')
                                                                                                    {
                                                                                                        // if confirm1 equals y
                                                                                                        if (confirm1 == 'y')
                                                                                                        {
                                                                                                            // if player has enough gold
                                                                                                            if (p.getGold() >= 10)
                                                                                                            {
                                                                                                                // save item in player inventory
                                                                                                                p.saveItem("a", 1);
                                                                                                                cout << "'Faded Ribbon' has been added to your inventory!" << endl;
                                                                                                                cout << endl;
                                                                                                            }
                                                                                                            else
                                                                                                            {
                                                                                                                cout << "You do not have enough Gold." << endl;
                                                                                                                cout << endl;
                                                                                                            }     
                                                                                                        }
                                                                                                        // if confirm1 does equal y
                                                                                                        else
                                                                                                        {
                                                                                                            // while confirm1 does not equal n
                                                                                                            while (confirm1 != 'n')
                                                                                                            {
                                                                                                                // print invalid input
                                                                                                                cout << "Invalid input." << endl;
                                                                                                                // prompt user to buy
                                                                                                                cout << "Buy? y / n" << endl;
                                                                                                                // read user input and save in c
                                                                                                                getline(cin, c);
                                                                                                                // convert c to char and save in confirm1
                                                                                                                confirm1 = stoc(c);
                                                                                                                // print new line
                                                                                                                cout << endl;
                                                                                                            }
                                                                                                        }
                                                                                                    }
                                                                                                }
                                                                                                // idx is 2
                                                                                                else if (idx == "2")
                                                                                                {
                                                                                                    cout << "50G - Manly Bandana: It has seen some wear. It has abs drawn on it." << endl;
                                                                                                    // prompt user to buy
                                                                                                    cout << "Buy? y / n" << endl;
                                                                                                    // read user input and save in c
                                                                                                    getline(cin, c);
                                                                                                    // convert c to char and save in confirm1
                                                                                                    confirm1 = stoc(c);
                                                                                                    // print new line
                                                                                                    cout << endl;
                                                                                                    // if confirm1 != n
                                                                                                    if (confirm1 != 'n')
                                                                                                    {
                                                                                                        // if confirm1 equals y
                                                                                                        if (confirm1 == 'y')
                                                                                                        {
                                                                                                            if (p.getGold() >= 50)
                                                                                                            {
                                                                                                                // save item in player inventory
                                                                                                                p.saveItem("a", 2);
                                                                                                                cout << "'Manly Bandana' has been added to your inventory!" << endl;
                                                                                                                cout << endl;
                                                                                                            }
                                                                                                            else
                                                                                                            {
                                                                                                                cout << "You do not have enough Gold." << endl;
                                                                                                                cout << endl;
                                                                                                            }      
                                                                                                        }
                                                                                                        // if confirm1 does equal y
                                                                                                        else
                                                                                                        {
                                                                                                            // while confirm1 does not equal n
                                                                                                            while (confirm1 != 'n')
                                                                                                            {
                                                                                                                // print invalid input
                                                                                                                cout << "Invalid input." << endl;
                                                                                                                // prompt user to buy
                                                                                                                cout << "Buy? y / n" << endl;
                                                                                                                // read user input and save in c
                                                                                                                getline(cin, c);
                                                                                                                // convert c to char and save in confirm1
                                                                                                                confirm1 = stoc(c);
                                                                                                                // print new line
                                                                                                                cout << endl;
                                                                                                            }
                                                                                                        }
                                                                                                    }
                                                                                                }
                                                                                                // idx is 3
                                                                                                else if (idx == "3")
                                                                                                {
                                                                                                    cout << "65G - Old Tutu: Finally a protective piece of armor." << endl;
                                                                                                    // prompt user to buy
                                                                                                    cout << "Buy? y / n" << endl;
                                                                                                    // read user input and save in c
                                                                                                    getline(cin, c);
                                                                                                    // convert c to char and save in confirm1
                                                                                                    confirm1 = stoc(c);
                                                                                                    // print new line
                                                                                                    cout << endl;
                                                                                                    // if confirm1 != n
                                                                                                    if (confirm1 != 'n')
                                                                                                    {
                                                                                                        // if confirm1 equals y
                                                                                                        if (confirm1 == 'y')
                                                                                                        {
                                                                                                            // if player has enough gold
                                                                                                            if (p.getGold() >= 65)
                                                                                                            {
                                                                                                                // save item in player inventory
                                                                                                                p.saveItem("a", 3);
                                                                                                                // print success message
                                                                                                                cout << "'Old Tutu' has been added to your inventory!" << endl;
                                                                                                                cout << endl;
                                                                                                            }
                                                                                                            else
                                                                                                            {
                                                                                                                cout << "You do not have enough Gold." << endl;
                                                                                                                cout << endl;
                                                                                                            }
                                                                                                        }
                                                                                                        // if confirm1 does equal y
                                                                                                        else
                                                                                                        {
                                                                                                            // while confirm1 does not equal n
                                                                                                            while (confirm1 != 'n')
                                                                                                            {
                                                                                                                // print invalid input
                                                                                                                cout << "Invalid input." << endl;
                                                                                                                // prompt user to buy
                                                                                                                cout << "Buy? y / n" << endl;
                                                                                                                // read user input and save in c
                                                                                                                getline(cin, c);
                                                                                                                // convert c to char and save in confirm1
                                                                                                                confirm1 = stoc(c);
                                                                                                                // print new line
                                                                                                                cout << endl;
                                                                                                            }
                                                                                                        }
                                                                                                    }
                                                                                                }
                                                                                                // idx is 4
                                                                                                else if (idx == "4")
                                                                                                {
                                                                                                    cout << "65G - Cloudy Glasses: Glasses marred with wear." << endl;
                                                                                                    // prompt user to buy
                                                                                                    cout << "Buy? y / n" << endl;
                                                                                                    // read user input and save in c
                                                                                                    getline(cin, c);
                                                                                                    // convert c to char and save in confirm1
                                                                                                    confirm1 = stoc(c);
                                                                                                    // print new line
                                                                                                    cout << endl;
                                                                                                    // if confirm1 != n
                                                                                                    if (confirm1 != 'n')
                                                                                                    {
                                                                                                        // if confirm1 equals y
                                                                                                        if (confirm1 == 'y')
                                                                                                        {
                                                                                                            // if player has enough gold
                                                                                                            if (p.getGold() >= 65)
                                                                                                            {
                                                                                                                // save item in player inventory
                                                                                                                p.saveItem("a", 4);
                                                                                                                // print success message
                                                                                                                cout << "'Cloudy Glasses' has been added to your inventory!" << endl;
                                                                                                                // print new line
                                                                                                                cout << endl;
                                                                                                            }
                                                                                                            else
                                                                                                            {
                                                                                                                cout << "You do not have enough Gold." << endl;
                                                                                                                cout << endl;
                                                                                                            }
                                                                                                        }
                                                                                                        // if confirm1 does equal y
                                                                                                        else
                                                                                                        {
                                                                                                            // while confirm1 does not equal n
                                                                                                            while (confirm1 != 'n')
                                                                                                            {
                                                                                                                // print invalid input
                                                                                                                cout << "Invalid input." << endl;
                                                                                                                // prompt user to buy
                                                                                                                cout << "Buy? y / n" << endl;
                                                                                                                // read user input and save in c
                                                                                                                getline(cin, c);
                                                                                                                // convert c to char and save in confirm1
                                                                                                                confirm1 = stoc(c);
                                                                                                                // print new line
                                                                                                                cout << endl;
                                                                                                            }
                                                                                                        }
                                                                                                    }
                                                                                                }
                                                                                                // idx is invalid
                                                                                                else
                                                                                                {
                                                                                                    // print invalid input
                                                                                                    cout << "Invalid input." << endl;
                                                                                                }
                                                                                            // print armor menu
                                                                                            cout << "Select one:" << endl;
                                                                                            cout << "1. Faded Ribbon" << endl;
                                                                                            cout << "2. Manly Bandana" << endl;
                                                                                            cout << "3. Old Tutu" << endl;
                                                                                            cout << "4. Cloudy Glasses" << endl;
                                                                                            cout << "5. Exit" << endl;
                                                                                            // print new line
                                                                                            cout << endl;
                                                                                            // read user input and save in idx
                                                                                            getline(cin,idx);
                                                                                        }
                                                                                    }
                                                                                    // i is invalid
                                                                                    else
                                                                                    {
                                                                                        // print invalid input
                                                                                        cout << "Invalid input." << endl;
                                                                                    }
                                                                                    // print main shop menu
                                                                                    cout << "Select one:" << endl;
                                                                                    cout << "c. Consumables" << endl;
                                                                                    cout << "w. Weapons" << endl;
                                                                                    cout << "a. Armor" << endl;
                                                                                    cout << "e. Exit" << endl;
                                                                                    // print new line
                                                                                    cout << endl;
                                                                                    // save user input in i
                                                                                    getline(cin, i);
                                                                                    }
                                                                                    // if confirm is e
                                                                                    if (confirm == 'e')
                                                                                    {
                                                                                        // print bye message
                                                                                        cout << "Bye now! Come around again sometime." << endl;
                                                                                    }
                                                                                }
                                                                                // if confirm is not y
                                                                                else
                                                                                {
                                                                                    // while confirm is not n
                                                                                    while (confirm != 'n')
                                                                                    {
                                                                                        // print invalid input
                                                                                        cout << "Invalid input." << endl;
                                                                                        // print shop message
                                                                                        cout << "You have come across a SHOP. Do you want to enter?" << endl;
                                                                                        // print y / n message
                                                                                        cout << "y / n" << endl;
                                                                                        // save user input in c
                                                                                        getline(cin, c);
                                                                                        // convert c to char and save in confirm
                                                                                        confirm = stoc(c);
                                                                                        // print new line
                                                                                        cout << endl;
                                                                                    }
                                                                                }
                                                                            }
                                                                }
                                                                // if player is on puzzle location
                                                                else if (map.isPuzzleLocation() == true)
                                                                {
                                                                    // save random integer between 0 and 84 in type
                                                                    type = rand() % 84;
                                                                    // print new line
                                                                    cout << endl;
                                                                    // print puzzle intro
                                                                    cout << "You must solve this puzzle to continue." << endl;
                                                                    // print puzzle
                                                                    map.printPuzzle(type);
                                                                    // save user input in choice
                                                                    getline(cin, choice);
                                                                    // save result of answer in s
                                                                    int s = map.correctAnswer(choice, type);
                                                                    // while s is -1
                                                                    while (s == -1)
                                                                    {
                                                                        // subract 1 from player HP
                                                                        p.updateHP(-1);
                                                                        // print puzzle
                                                                        map.printPuzzle(type);
                                                                        // save user input in choice
                                                                        getline(cin, choice);
                                                                        // save result of answer in s
                                                                        s = map.correctAnswer(choice, type);
                                                                    } 
                                                                    // if s is -1  
                                                                    if (s != -1)
                                                                    {
                                                                        // increment pComplete
                                                                        pComplete++;
                                                                        // add 2 to player HP
                                                                        p.updateHP(2);
                                                                    }
                                                                }
                                                                // print new line
                                                                cout << endl;
                                                                // print puzzles complete out of total puzzles
                                                                cout << "Puzzles: " << pComplete << "/" << npuzzles << endl;
                                                                // print map
                                                                map.displayMap();
                                                                // print move menu
                                                                cout << "Select one: w. up s. down d. right a. left m. main menu" << endl;
                                                                // save user input in move
                                                                getline(cin, move);
                                                        }
                                                }
                                                //if choice is 2
                                                else if (choice == "2")
                                                {
                                                    // print player's stats
                                                    cout << p.getUsername() << " STATS" << endl;
                                                    // print player's souls
                                                    cout << "Souls: " << p.getSoul() << endl;
                                                    // print player's HP
                                                    cout << "HP: " << p.getHP() << endl;
                                                    // print player's ATK
                                                    cout << "ATK: " << p.getATK() << endl;
                                                    // print player's DEF
                                                    cout << "DEF: " << p.getDF() << endl;
                                                    // print player's LV
                                                    cout << "LV: " << p.getLV() << endl;
                                                    // print player's Gold
                                                    cout << "Gold: " << p.getGold() << endl;
                                                    // print player's Determination
                                                    cout << "Determination: 10000000000 :)" << endl;
                                                    cout << endl;
                                                }
                                                // if choice is 3
                                                else if (choice == "3")
                                                {
                                                    // print player's inventory
                                                    cout << endl;
                                                    cout << upper(p.getUsername()) << " INVENTORY" << endl;
                                                    p.printInventory();
                                                    cout << endl;
                                                }
                                                // if choice is 4
                                                else if (choice == "4")
                                                {
                                                    // if all puzzles in a room have been complete
                                                    if (pComplete >= npuzzles)
                                                    {
                                                        // increment room
                                                        room++;
                                                        // reset map
                                                        map.resetMap();
                                                        // generate total number of puzzles there will be in room
                                                        npuzzles = random(4, 7);
                                                        // generate total number of monsters there will be in room
                                                        nmonsters = random(4, 8);
                                                        // spawn save in free space on map
                                                        map.spawnSave(1, 2);
                                                        do
                                                        {
                                                            // generate random row and col on map
                                                            row = rand() % 11;
                                                            col = rand() % 11;
                                                            type = rand() % 86;
                                                            // spawn puzzle in free space on map
                                                            map.spawnPuzzle(row, col, type);
                                                        } while (map.getPuzzleCount() < npuzzles);
                                                        do
                                                        {
                                                            // generate random row and col on map
                                                            row = rand() % 11;
                                                            col = rand() % 11;
                                                            type = random(1, 4);
                                                            // spawn monster in free space on map
                                                            map.spawnMonster(row, col, type);
                                                        } while (map.getMonsterCount() < nmonsters);
                                                        do
                                                        {
                                                            // generate random row and col on map
                                                            row = rand() % 11;
                                                            col = rand() % 11;
                                                            // spawn shop in free space on map
                                                            s = map.spawnShop(row, col);
                                                        } while (s != true);
                                                        // if npc is even number between 0 and 99
                                                        if (room == 2)
                                                        {
                                                            do
                                                            {
                                                                // generate random row and col on map
                                                                row = rand() % 11;
                                                                col = rand() % 11;
                                                                // spawn npc in free space on map
                                                                n = map.spawnNPC(row, col);
                                                            } while (n != true); 
                                                        }
                                                        else if (room == 4)
                                                        {
                                                            do
                                                            {
                                                                // generate random row and col on map
                                                                row = rand() % 11;
                                                                col = rand() % 11;
                                                                // spawn npc in free space on map
                                                                n = map.spawnNPC(row, col);
                                                            } while (n != true); 
                                                        }
                                                        // reset puzzles complete
                                                        pComplete = 0;
                                                    }
                                                    // if all puzzles in room have not been complete
                                                    else
                                                    {
                                                        // print that the player can not move on yet
                                                        cout << "You can not unlock the next room until you have completed this one." << endl;
                                                    }
                                                }
                                                // if choice is 5
                                                else if (choice == "5")
                                                {
                                                    // take user back to start screen
                                                    cout << endl;
                                                }
                                                // if choice is invalid
                                                else if (choice != "5")
                                                {
                                                    // print invalid input
                                                    cout << "Invalid input." << endl;
                                                }
                                                cout << "➤ enter 'c' to continue" << endl;
                                                getline(cin, c);
                                                cont = stoc(c);
                                                while (cont != 'c')
                                                {
                                                    cout << "Invalid input." << endl;
                                                    cout << "➤ enter 'c' to continue" << endl;
                                                    getline(cin, c);
                                                    cont = stoc(c);
                                                }
                                                cout << endl;
                                                if (cont == 'c')
                                                {
                                                    cout << "Puzzles: " << pComplete << "/" << npuzzles << endl;
                                                    map.displayMap();
                                                    cout << "Select one:" << endl;
                                                    cout << "1. Move" << endl;
                                                    cout << "2. View Status" << endl;
                                                    cout << "3. View Inventory" << endl;
                                                    cout << "4. Go to next room" << endl;
                                                    cout << "5. Back to start screen" << endl;
                                                    getline(cin, choice);
                                                    cout << endl;
                                                }
                                            }
                                            // if player passes final room
                                            if (room >= 9)
                                            {
                                                // initiate final ending
                                                cout << "              |;| |;| |;|        " << endl;
                                                cout << " _  _ _  _    \\.    .  /    _  _ _  _" << endl;
                                                cout << "|;|_|;|_|;|    \\:. ,  /    |;|_|;|_|;|" << endl;
                                                cout << "\\..      /    ||;   . |    \\.    .  /" << endl;
                                                cout << " \\.  ,  /     ||:  .  |     \\:  .  /" << endl;
                                                cout << "  ||:   |_   _ ||_ . _ | _   _||:   |" << endl;
                                                cout << "  ||:  .|||_|;|_|;|_|;|_|;|_|;||:.  |" << endl;
                                                cout << "  ||:   ||.    .     .      . ||:  .|" << endl;
                                                cout << "  ||: . || .     . .   .  ,   ||:   |" << endl;
                                                cout << "  ||:   ||:  ,  _______   .   ||: , |" << endl;
                                                cout << "  ||:   || .   |+++++++|    . ||:   |" << endl;
                                                cout << "  ||:   ||.    |+++++++| .    ||: . |" << endl;
                                                cout << "  ||: . ||: ,  |+++++++|.  . _||_   |" << endl;
                                                cout << " #%*###&*##&*&#*&##&&*###*&&#&&###**#&##" << endl;
                                                cout << "#%*###&*##&*&#*&##&&*###*&&#&&###**#&###%#" << endl;
                                                cout << "You now stand outside the castle doors." << endl;
                                                cout << "You can see the stream back to the HUMAN world come out the top of the castle." << endl;
                                                cout << "In the bushes, there is a 'Worn Dagger'." << endl;
                                                // prompt user to take item
                                                cout << "Take it? y / n '" << endl;
                                                // read user input
                                                getline(cin, c);
                                                // convert to char and save in confirm
                                                confirm = stoc(c);
                                                cout << endl;
                                                // if confirm is not n
                                                if (confirm != 'n')
                                                {
                                                    // if confirm is y
                                                    if (confirm == 'y')
                                                    {
                                                        // save item in inventory
                                                        p.saveItem("w",5);
                                                        // print that item is not in inventory
                                                        cout << "'Worn Dagger' has been added to your inventory." << endl;
                                                        cout << endl;
                                                    }
                                                    // if confirm is not y
                                                    else
                                                    {
                                                        // while confirm is not n
                                                        while (confirm != 'n')
                                                        {
                                                            // print invalid input
                                                            cout << "Invalid input." << endl;
                                                            // prompt user to take item
                                                            cout << "Take it? y / n '" << endl;
                                                            // read user input
                                                            getline(cin, c);
                                                            // convert to char and save in confirm
                                                            confirm = stoc(c);
                                                            // print new line
                                                            cout << endl;
                                                        }
                                                    }
                                                }
                                                cout << "You enter the castle." << endl;
                                                // print "➤ enter 'c' to continue"
                                                cout << "➤ enter 'c' to continue" << endl;
                                                // read user input
                                                getline(cin, c);
                                                // convert user input to char
                                                cont = stoc(c);
                                                // if user input is invalid
                                                while (cont != 'c')
                                                {
                                                    // print invalid input
                                                    cout << "Invalid input." << endl;
                                                    // print "➤ enter 'c' to continue"
                                                    cout << "➤ enter 'c' to continue" << endl;
                                                    // read user input
                                                    getline(cin, c);
                                                    // convert user input to char
                                                    cont = stoc(c);
                                                }
                                                // print new line
                                                cout << endl;
                                                // if user input is c
                                                if (cont == 'c')
                                                {
                                                    cout << "FROGGITS:" << endl;
                                                    cout << "A long time ago, a human fell into the RUINS." << endl;
                                                    cout << "Injured by its fall, the human called out for help." << endl;
                                                    cout << "He brought the human back to the castle." << endl;
                                                    cout << "Over time, ASRIEL and the human became like siblings." << endl;
                                                    cout << "The King and Queen treated the human child as their own." << endl;
                                                    cout << "The underground was full of hope." << endl;
                                                    cout << "Then... One day..." << endl;
                                                    // print "➤ enter 'c' to continue"
                                                    cout << "➤ enter 'c' to continue" << endl;
                                                    // read user input
                                                    getline(cin, c);
                                                    // convert user input to char
                                                    cont = stoc(c);
                                                    // if user input is invalid
                                                    while (cont != 'c')
                                                    {
                                                        // print invalid input
                                                        cout << "Invalid input." << endl;
                                                        // print "➤ enter 'c' to continue"
                                                        cout << "➤ enter 'c' to continue" << endl;
                                                        // read user input
                                                        getline(cin, c);
                                                        // convert user input to char
                                                        cont = stoc(c);
                                                    }
                                                    // print new line
                                                    cout << endl;
                                                    // if user input is c
                                                    if (cont == 'c')
                                                    {
                                                        cout << "WHIMSUM:" << endl;
                                                        cout << "The human became very ill. The sick human had only one request." << endl;
                                                        cout << "To see the flowers from their village. The next day." << endl;
                                                        cout << "The human died. ASRIEL, wracked with grief, absorbed the human's SOUL." << endl;
                                                        cout << "He transformed into a being with incredible power." << endl;
                                                        cout << "With the human SOUL, ASRIEL crossed through the barrier." << endl;
                                                        // print "➤ enter 'c' to continue"
                                                        cout << "➤ enter 'c' to continue" << endl;
                                                        // read user input
                                                        getline(cin, c);
                                                        // convert user input to char
                                                        cont = stoc(c);
                                                        // if user input is invalid
                                                        while (cont != 'c')
                                                        {
                                                            // print invalid input
                                                            cout << "Invalid input." << endl;
                                                            // print "➤ enter 'c' to continue"
                                                            cout << "➤ enter 'c' to continue" << endl;
                                                            // read user input
                                                            getline(cin, c);
                                                            // convert user input to char
                                                            cont = stoc(c);
                                                        }
                                                        // print new line
                                                        cout << endl;
                                                        // if user input is c
                                                        if (cont == 'c')
                                                        {
                                                            cout << "VEGETOIDS:" << endl;
                                                            cout << "He carried the human's body into the sunset." << endl;
                                                            cout << "Back to the village of the humans. ASRIEL reached the center of the village." << endl;
                                                            cout << "There, he found a bed of golden flowers. He carried the human onto it." << endl;
                                                            cout << "Suddenly, screams rang out. The villagers saw ASRIEL holding the human's body." << endl;
                                                            cout << "They thought that he had killed the child." << endl;
                                                            // print "➤ enter 'c' to continue"
                                                            cout << "➤ enter 'c' to continue" << endl;
                                                            // read user input
                                                            getline(cin, c);
                                                            // convert user input to char
                                                            cont = stoc(c);
                                                            // if user input is invalid
                                                            while (cont != 'c')
                                                            {
                                                                // print invalid input
                                                                cout << "Invalid input." << endl;
                                                                // print "➤ enter 'c' to continue"
                                                                cout << "➤ enter 'c' to continue" << endl;
                                                                // read user input
                                                                getline(cin, c);
                                                                // convert user input to char
                                                                cont = stoc(c);
                                                            }
                                                            // print new line
                                                            cout << endl;
                                                            // if user input is c
                                                            if (cont == 'c')
                                                            {
                                                                cout << "NAPSTABLOOK:" << endl;
                                                                cout << "The humans attacked him with everything they had. He was struck with blow after blow." << endl;
                                                                cout << "ASRIEL had the power to destroy them all." << endl;
                                                                cout << "But...ASRIEL did not fight back." << endl;
                                                                cout << "Clutching the human...ASRIEL smiled, and walked away. Wounded, ASRIEL stumbled home." << endl;
                                                                // print "➤ enter 'c' to continue"
                                                                cout << "➤ enter 'c' to continue" << endl;
                                                                // read user input
                                                                getline(cin, c);
                                                                // convert user input to char
                                                                cont = stoc(c);
                                                                // if user input is invalid
                                                                while (cont != 'c')
                                                                {
                                                                    // print invalid input
                                                                    cout << "Invalid input." << endl;
                                                                    // print "➤ enter 'c' to continue"
                                                                    cout << "➤ enter 'c' to continue" << endl;
                                                                    // read user input
                                                                    getline(cin, c);
                                                                    // convert user input to char
                                                                    cont = stoc(c);
                                                                }
                                                                // print new line
                                                                cout << endl;
                                                                // if user input is c
                                                                if (cont == 'c')
                                                                {
                                                                    cout << "WOSHUAS:" << endl;
                                                                    cout << "He entered the castle and collapsed. His dust spread across the garden." << endl;
                                                                    cout << "The kingdom fell into despair. The king and queen had lost two children in one night." << endl;
                                                                    cout << "The humans had once again taken everything from us. The king decided it was time to end our suffering." << endl;
                                                                    cout << "Every human who falls down here must die. With enough human SOULS, monsters can shatter the barrier forever." << endl;
                                                                    cout << "You're going to be free." << endl;
                                                                    // print "➤ enter 'c' to continue"
                                                                    cout << "➤ enter 'c' to continue" << endl;
                                                                    // read user input
                                                                    getline(cin, c);
                                                                    // convert user input to char
                                                                    cont = stoc(c);
                                                                    // if user input is invalid
                                                                    while (cont != 'c')
                                                                    {
                                                                        // print invalid input
                                                                        cout << "Invalid input." << endl;
                                                                        // print "➤ enter 'c' to continue"
                                                                        cout << "➤ enter 'c' to continue" << endl;
                                                                        // read user input
                                                                        getline(cin, c);
                                                                        // convert user input to char
                                                                        cont = stoc(c);
                                                                    }
                                                                    // print new line
                                                                    cout << endl;
                                                                    // if user input is c
                                                                    if (cont == 'c')
                                                                    {
                                                                        cout << "You enter the last corridor." << endl;
                                                                        // reset map
                                                                        map.resetMap();
                                                                        // spawn npc
                                                                        map.spawnNPC(6,6);
                                                                        // display map
                                                                        map.displayMap();
                                                                        // print move menu
                                                                        cout << "Select one: w. up s. down d. right a. left" << endl;
                                                                        // save user input in move
                                                                        getline(cin, move);
                                                                        // while move is not m
                                                                        while (map.isNPCLocation() == false)
                                                                        {
                                                                            // if move is w
                                                                            if (move == "w")
                                                                            {
                                                                                // execute move
                                                                                map.move(move);
                                                                            }
                                                                            // if move is a
                                                                            else if (move == "a" )
                                                                            {
                                                                                // execute move
                                                                                map.move(move);
                                                                            }
                                                                            // if move is s
                                                                            else if (move == "s" )
                                                                            {
                                                                                // execute move
                                                                                map.move(move);
                                                                            }
                                                                            // if move is d
                                                                            else if (move == "d" )
                                                                            {
                                                                                // execute move
                                                                                map.move(move);
                                                                            }
                                                                            // if move is invalid
                                                                            else
                                                                            {
                                                                                // print invalid input
                                                                                cout << "Invalid input." << endl;
                                                                            }
                                                                            // display map
                                                                            map.displayMap();
                                                                            // print move menu
                                                                            cout << "Select one: w. up s. down d. right a. left" << endl;
                                                                            // save user input in move
                                                                            getline(cin, move);
                                                                        }
                                                                        if (map.isNPCLocation() == true)
                                                                        {
                                                                            cout << "SANS:" << endl;
                                                                            cout << "So you finally made it." << endl;
                                                                            cout << "The end of your journey is at hand." << endl;
                                                                            cout << "In a few moments, you will meet the king." << endl;
                                                                            cout << "Together...you will determine the future of this world." << endl;
                                                                            cout << "That's then. Now. You will be judged." << endl;
                                                                            // print "➤ enter 'c' to continue"
                                                                            cout << "➤ enter 'c' to continue" << endl;
                                                                            // read user input
                                                                            getline(cin, c);
                                                                            // convert user input to char
                                                                            cont = stoc(c);
                                                                            // if user input is invalid
                                                                            while (cont != 'c')
                                                                            {
                                                                                // print invalid input
                                                                                cout << "Invalid input." << endl;
                                                                                // print "➤ enter 'c' to continue"
                                                                                cout << "➤ enter 'c' to continue" << endl;
                                                                                // read user input
                                                                                getline(cin, c);
                                                                                // convert user input to char
                                                                                cont = stoc(c);
                                                                            }
                                                                            // print new line
                                                                            cout << endl;
                                                                            // if user input is c
                                                                            if (cont == 'c')
                                                                            {
                                                                                cout << "SANS:" <<endl;
                                                                                cout << "You will be judged for your every action." << endl;
                                                                                cout << "You will be judged for the amount of LV you earned." << endl;
                                                                                cout << "What's LV?" << endl;
                                                                                // print "➤ enter 'c' to continue"
                                                                                cout << "➤ enter 'c' to continue" << endl;
                                                                                // read user input
                                                                                getline(cin, c);
                                                                                // convert user input to char
                                                                                cont = stoc(c);
                                                                                // if user input is invalid
                                                                                while (cont != 'c')
                                                                                {
                                                                                    // print invalid input
                                                                                    cout << "Invalid input." << endl;
                                                                                    // print "➤ enter 'c' to continue"
                                                                                    cout << "➤ enter 'c' to continue" << endl;
                                                                                    // read user input
                                                                                    getline(cin, c);
                                                                                    // convert user input to char
                                                                                    cont = stoc(c);
                                                                                }
                                                                                // print new line
                                                                                cout << endl;
                                                                                // if user input is c
                                                                                if (cont == 'c')
                                                                                {
                                                                                    cout << "SANS:" <<endl;
                                                                                    cout << "LV is LOVE. It's an acronym for 'Level of Violence'." << endl;
                                                                                    cout << "A way of measuring someone's capacity to hurt." << endl;
                                                                                    // if player killed no monsters, pacifist ending
                                                                                    if (p.getLV() == 0)
                                                                                    {
                                                                                        cout << "SANS:" <<endl;
                                                                                        cout << "...but you. you never gained any LOVE." << endl;
                                                                                        cout << "'course that doesn't mean you're completely innocent or naive." << endl;
                                                                                        cout << "just that you kept a certain tenderness in your heart." << endl;
                                                                                        cout << "you never gained LOVE, but you gained love." << endl;
                                                                                        // print "➤ enter 'c' to continue"
                                                                                        cout << "➤ enter 'c' to continue" << endl;
                                                                                        // read user input
                                                                                        getline(cin, c);
                                                                                        // convert user input to char
                                                                                        cont = stoc(c);
                                                                                        // if user input is invalid
                                                                                        while (cont != 'c')
                                                                                        {
                                                                                            // print invalid input
                                                                                            cout << "Invalid input." << endl;
                                                                                            // print "➤ enter 'c' to continue"
                                                                                            cout << "➤ enter 'c' to continue" << endl;
                                                                                            // read user input
                                                                                            getline(cin, c);
                                                                                            // convert user input to char
                                                                                            cont = stoc(c);
                                                                                        }
                                                                                        // print new line
                                                                                        cout << endl;
                                                                                        // if user input is c
                                                                                        if (cont == 'c')
                                                                                        {
                                                                                            cout << "SANS:" << endl;
                                                                                            cout << "now you're about to face the greatest challenge of your entire journey." << endl;
                                                                                            cout << "your actions here will determine the fate of the entire world." << endl;
                                                                                            cout << "if you refuse to fight, ASGORE may take your soul and destroy humanity." << endl;
                                                                                            cout << "if you kill ASGORE and go home, monsters will remain trapped underground." << endl;
                                                                                            cout << "what will you do?" << endl;
                                                                                            cout << "if i were you, i would've thrown in the towel by now. but you have something called DETERMINATION." << endl;
                                                                                            cout << "we're all counting on you kid. good luck." << endl;
                                                                                        }
                                                                                    }
                                                                                    // if player killed some monsters and spared some, neutral ending
                                                                                    else
                                                                                    {
                                                                                        // NEUTRAL ENDING
                                                                                    }
                                                                                }
                                                                            }
                                                                        }
                                                                    }
                                                                }
                                                            }
                                                        }
                                                    }
                                                }
                                                // player meets asgore
                                                cout << "You walk outside to the castle garden." << endl;
                                                cout << endl;
                                                cout << "ASGORE:" << endl;
                                                cout << "Dum dee dum..." << endl;
                                                cout << "Oh? Is someone there?" << endl;
                                                cout << "Just a moment. I have almost finished watering these flowers." << endl;
                                                // print "➤ enter 'c' to continue"
                                                cout << "➤ enter 'c' to continue" << endl;
                                                // read user input
                                                getline(cin, c);
                                                // convert user input to char
                                                cont = stoc(c);
                                                // if user input is invalid
                                                while (cont != 'c')
                                                {
                                                    // print invalid input
                                                    cout << "Invalid input." << endl;
                                                    // print "➤ enter 'c' to continue"
                                                    cout << "➤ enter 'c' to continue" << endl;
                                                    // read user input
                                                    getline(cin, c);
                                                    // convert user input to char
                                                    cont = stoc(c);
                                                }
                                                // print new line
                                                cout << endl;
                                                // if user input is c
                                                if (cont == 'c')
                                                {
                                                    cout << "ASGORE turns around." << endl;
                                                    cout << endl;
                                                    cout << "ASGORE:" << endl;
                                                    cout << "I so badly want to say 'would you like a cup of tea?'" << endl;
                                                    cout << "But you know how it is" << endl;
                                                    cout << "You know what we must do." << endl;
                                                    cout << "When you are ready, come into the next room." << endl;
                                                    // print "➤ enter 'c' to continue"
                                                    cout << "➤ enter 'c' to go to the next room" << endl;
                                                    // read user input
                                                    getline(cin, c);
                                                    // convert user input to char
                                                    cont = stoc(c);
                                                    // if user input is invalid
                                                    while (cont != 'c')
                                                    {
                                                        // print invalid input
                                                        cout << "Invalid input." << endl;
                                                        // print "➤ enter 'c' to continue"
                                                        cout << "➤ enter 'c' to continue" << endl;
                                                        // read user input
                                                        getline(cin, c);
                                                        // convert user input to char
                                                        cont = stoc(c);
                                                    }
                                                    // print new line
                                                    cout << endl;
                                                    // if user input is c
                                                    if (cont == 'c')
                                                    {
                                                        cout << "You follow Asgore into the next room." << endl;
                                                        cout << endl;
                                                        cout << "ASGORE:" << endl;
                                                        cout << "This is the barrier. This is what keeps us all trapped underground." << endl;
                                                        cout << "Human...It was nice to meet you. Goodbye" << endl;
                                                        cout << endl;
                                                                    // get monster object using type
                                                                    m = e.getMonster(13);
                                                                    // print monster intro
                                                                    cout << m.getIntro() << endl;
                                                                    // print encounter menu
                                                                    cout << "╭―――――――――――――╮" << endl;
                                                                    cout << "│             │" << endl;
                                                                    cout << "│      ♥      │" << endl;
                                                                    cout << "│             │" << endl;
                                                                    cout << "╰―――――――――――――╯" << endl;
                                                                    cout << "1. Fight" << endl;
                                                                    cout << "2. Act" << endl;
                                                                    cout << "3. Item" << endl;
                                                                    cout << "4. Spare" << endl;
                                                                    // get user input
                                                                    getline(cin, mchoice);
                                                                    cout << endl;
                                                                    // set done to false
                                                                    done = false;
                                                                    // set inst to zero
                                                                    int inst = 0;
                                                                    // while monster has not been defeated
                                                                    do
                                                                    {
                                                                        // player choice is Fight
                                                                        if (mchoice == "1")
                                                                        {
                                                                            // if first time choosing fight with this monster
                                                                            if (inst == 0)
                                                                            {
                                                                                // save monster hp in mhp
                                                                                mhp = e.Fight(p, type);
                                                                            }
                                                                            // if not first time using fight
                                                                            else if (inst > 0)
                                                                            {
                                                                                // update monster hp
                                                                                mhp = e.Fight1(p, type, mhp);
                                                                            }
                                                                            // if result of fight is -2
                                                                            if (mhp == -2)
                                                                            {
                                                                                // monster was killed, encounter is done
                                                                                done = true;
                                                                            }
                                                                            // if result of fight is -3
                                                                            else if (mhp == -3)
                                                                            {
                                                                                // monster has low enough health to spare
                                                                                spare = 1;
                                                                            }
                                                                            // increment inst
                                                                            inst++;
                                                                            cout << endl;
                                                                        }
                                                                        // player choice is Act
                                                                        else if (mchoice == "2")
                                                                        {
                                                                            // print Act menu
                                                                            cout << "1. Check" << endl;
                                                                            cout << "2. Talk" << endl;
                                                                            cout << "3. Back to menu" << endl;
                                                                            // read user input and save in act
                                                                            getline(cin, act);
                                                                            cout << endl;
                                                                            // while act is not 3
                                                                            while (act != "3")
                                                                            {
                                                                                // if act is 1
                                                                                if (act == "1")
                                                                                {
                                                                                    // print player and monster stats
                                                                                    cout << upper(p.getUsername()) << " — HP " << p.getHP() << " ATK " << p.getATK() << " DEF " << p.getDF() << endl;
                                                                                    spare = e.Act(p, type, 1);
                                                                                }
                                                                                // if act is 2
                                                                                else if (act == "2")
                                                                                {
                                                                                    // save result of Act in spare
                                                                                    spare = e.Act(p, type, 2);
                                                                                }
                                                                                // if act is neither of those choices
                                                                                else
                                                                                {
                                                                                    // print invalid input
                                                                                    cout << "Invalid input." << endl;
                                                                                }
                                                                                // print Act menu
                                                                                cout << "1. Check" << endl;
                                                                                cout << "2. Talk" << endl;
                                                                                cout << "3. Back to menu" << endl;
                                                                                // read user input and save in act
                                                                                getline(cin, act);
                                                                                cout << endl;
                                                                            }
                                                                        }
                                                                        // player choice is Item
                                                                        else if (mchoice == "3")
                                                                        {
                                                                            // print use item instructions
                                                                            cout << "To USE ITEM, enter the index of the ITEM in your inventory." << endl;
                                                                            // print player's inventory
                                                                            cout << upper(p.getUsername()) << " INVENTORY" << endl;
                                                                            // print inventory function
                                                                            p.printInventory();
                                                                            // print back to menu choice
                                                                            cout << "m. Back to menu" << endl;
                                                                            // read user input and save in c2
                                                                            getline(cin, c2);
                                                                            cout << endl;
                                                                            // while c2 is not m
                                                                            while (c2 != "m")
                                                                            {
                                                                                // if c2 is within range of inventory
                                                                                if (stoi(c2) <= p.getNumInv())
                                                                                {
                                                                                    // save item name in item
                                                                                    item = p.getItem(stoi(c2));
                                                                                    // prompt user to use item
                                                                                    cout << "Use '" << item << "'?" << endl;;
                                                                                    // print y / n message
                                                                                    cout << "y / n" << endl;
                                                                                    // read user input
                                                                                    getline(cin, c);
                                                                                    // convert to char and save in confirm
                                                                                    confirm = stoc(c);
                                                                                    cout << endl;
                                                                                    // if confirm is not n
                                                                                    if (confirm != 'n')
                                                                                    {
                                                                                        // if confirm is y
                                                                                        if (confirm == 'y')
                                                                                        {
                                                                                            // save result of useItem in u
                                                                                            int u = p.useItem(stoi(c2));
                                                                                            // if u is 2
                                                                                            if (u == 2)
                                                                                            {
                                                                                                // item was successfully used
                                                                                                // print that the player ate the item
                                                                                                cout << "You quickly eat a snack and then rejoin the fight." << endl;
                                                                                                cout << endl;
                                                                                            }
                                                                                            // if u is 1
                                                                                            else if (u == 1)
                                                                                            {
                                                                                                // print that player cannot eat that item because it is not consumable
                                                                                                cout << "You are already using WEAPONS and ARMOR. You can only choose to use CONSUMABLES." << endl;
                                                                                                cout << endl;
                                                                                            }
                                                                                        }
                                                                                        // if confirm is not y
                                                                                        else
                                                                                        {
                                                                                            // while confirm is not n
                                                                                            while (confirm != 'n')
                                                                                            {
                                                                                                // print invalid input
                                                                                                cout << "Invalid input." << endl;
                                                                                                // print y / n message
                                                                                                cout << "y / n" << endl;
                                                                                                // read user input and save in c
                                                                                                getline(cin, c);
                                                                                                // convert to char and save in confirm
                                                                                                confirm = stoc(c);
                                                                                                cout << endl;
                                                                                            }
                                                                                        }
                                                                                    }
                                                                                }
                                                                                // if c2 is not within inventory range
                                                                                else
                                                                                {
                                                                                    // print that user does not have item saved there
                                                                                    cout << "You do not have an ITEM saved in that index." << endl;
                                                                                    cout << endl;
                                                                                }
                                                                                // print use item instructions
                                                                                cout << "To USE ITEM, enter the index of the ITEM in your inventory." << endl;
                                                                                // print player's inventory
                                                                                cout << upper(p.getUsername()) << " INVENTORY" << endl;
                                                                                // print inventory function
                                                                                p.printInventory();
                                                                                // print back to menu choice
                                                                                cout << "m. Back to menu" << endl;
                                                                                // read user input and save in c2
                                                                                getline(cin, c2);
                                                                                cout << endl;
                                                                            }
                                                                        }
                                                                        // player choice is Spare
                                                                        else if (mchoice == "4")
                                                                        {
                                                                            // if spare does equal 0
                                                                            if (spare != 0)
                                                                            {
                                                                                cout << "ASGORE is tired and beat." << endl;
                                                                                cout << "ASGORE:" << endl;
                                                                                cout << "So that is how it is." << endl;
                                                                                cout << "I remember the day my son died. The future had once again been taken from us by the humans." << endl;
                                                                                cout << "In a fit of anger, I declared war. I would kill any human who came to the UNDERGROUND and use their SOULS to free us." << endl;
                                                                                cout << "Well, the world's fate is up to you, human." << endl;
                                                                                cout << endl;
                                                                                // prompt user to spare monster
                                                                                cout << "Spare " << m.getMName() << "? y / n" << endl;
                                                                                // read user input and save in c
                                                                                getline(cin, c);
                                                                                // convert c to char and save in confirm1
                                                                                confirm1 = stoc(c);
                                                                                // print new line
                                                                                cout << endl;
                                                                                // if confirm1 != n
                                                                                if (confirm1 != 'n')
                                                                                {
                                                                                    // if confirm1 equals y
                                                                                    if (confirm1 == 'y')
                                                                                    {
                                                                                        // spare monster
                                                                                        e.Spare(p, type);
                                                                                        cout << "You spared ASGORE and decided to stay in the monster realm for a bit." << endl;
                                                                                        cout << "There is still plenty to do." << endl;
                                                                                        // set done to true
                                                                                        done = true;
                                                                                        // print new line
                                                                                        cout << endl;
                                                                                    }
                                                                                    // if confirm1 is not y
                                                                                    else
                                                                                    {
                                                                                        // while confirm1 is not n
                                                                                        while (confirm1 != 'n')
                                                                                        {
                                                                                            // print invalid input
                                                                                            cout << "Invalid input." << endl;
                                                                                            // prompt user to spare monster
                                                                                            cout << "Spare " << m.getMName() << "? y / n" << endl;
                                                                                            // read user input and save in c
                                                                                            getline(cin, c);
                                                                                            // convert c to char and save in confirm1
                                                                                            confirm1 = stoc(c);
                                                                                            // print new line
                                                                                            cout << endl;
                                                                                        }
                                                                                    }
                                                                                }
                                                                                if (confirm == 'n')
                                                                                {
                                                                                    // print kill message
                                                                                    cout << "You killed ASGORE and returned to the human world." << endl;
                                                                                    cout << "Monsters stayed underground. And you gained 1 LV." << endl;
                                                                                    // increment player LV
                                                                                    p.updateLV(1);
                                                                                    // set done to true
                                                                                    done = true;
                                                                                    cout << endl;
                                                                                }
                                                                            }
                                                                            // if spare is 0
                                                                            else
                                                                            {
                                                                                // print that monster can not be spared yet
                                                                                cout << m.getMName() << " needs more convincing. You can not spare until you talk to the monster enough or its health is low enough." << endl;
                                                                                cout << endl;
                                                                            }
                                                                        }
                                                                    } while (done != true);
                                                                    // open file
                                                                    ofstream fout("game.txt");
                                                                    // check that file opened
                                                                    if (fout.is_open())
                                                                    {
                                                                        // print player's stats
                                                                        fout << p.getUsername() << " GAME RECAP" << endl;
                                                                        // print player's souls
                                                                        fout << "Souls: " << p.getSoul() << endl;
                                                                        // print player's HP
                                                                        fout << "HP: " << p.getHP() << endl;
                                                                        // print player's ATK
                                                                        fout << "ATK: " << p.getATK() << endl;
                                                                        // print player's DEF
                                                                        fout << "DEF: " << p.getDF() << endl;
                                                                        // print player's LV
                                                                        fout << "LV: " << p.getLV() << endl;
                                                                        // print player's Gold
                                                                        fout << "Gold: " << p.getGold() << endl;
                                                                        // print player's Determination
                                                                        fout << "Determination: 10000000000 :)" << endl;
                                                                        fout << endl;
                                                                        fout.close();
                                                                    }
                                                                    else
                                                                    {
                                                                        // print could not open file
                                                                        cout << "Could not open file." << endl;
                                                                    }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
                break;
            }
            // if user input is invalid
            default:
            {
                // print invalid input
                cout << "Invalid input." << endl;
                break;
            }
        }
        // print undertale start screen
        cout << "UNDERTALE" << endl;
        cout << endl;
        cout << "press 'u' to start" << endl;
        cout << "press 'q' to quit" << endl;
        // read user input
        getline(cin, c);
        // convert to char and save in input
        input = stoc(c);
    }
    if (input == 'q')
    {
        // open file
        ofstream fout("game.txt");
        // check that file opened
        if (fout.is_open())
        {
            // print player's stats
            fout << p.getUsername() << " GAME RECAP" << endl;
            // print player's souls
            fout << "Souls: " << p.getSoul() << endl;
            // print player's HP
            fout << "HP: " << p.getHP() << endl;
            // print player's ATK
            fout << "ATK: " << p.getATK() << endl;
            // print player's DEF
            fout << "DEF: " << p.getDF() << endl;
            // print player's LV
            fout << "LV: " << p.getLV() << endl;
            // print player's Gold
            fout << "Gold: " << p.getGold() << endl;
            // print player's Determination
            fout << "Determination: 10000000000 :)" << endl;
            fout << endl;
            fout.close();
        }
        else
        {
            // print could not open file
            cout << "Could not open file." << endl;
        }
        // print bye
        cout << "Bye!" << endl;
        return 0;
    }
}