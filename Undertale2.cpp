#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include "Encounter.h"
#include "Map.h"
using namespace std;


char stoc(string str)
{
    char letter;
    for (int i = 0; i < str.length(); i++)
    {
        letter = char(int(str[i]));
    }
    return letter;
}

int random(int min, int max)
{
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

    // load monsters for game 
    e.readMonsters("Monsters.txt");
    p.readItems("Item.txt");
    map.readPuzzles("questions.txt");
    
    char input; string c; char confirm; char confirm1; char cont; int choice; 

    // for map
    int row; int col; int npuzzles; int nmonsters; int type; int npc; bool s; bool n;
    int pComplete = 0; int room = 0; int totalMonsters = 0;

    // for menu
    char move; char i; char i1; int idx;

    cout << "UNDERTALE" << endl;
    cout << endl;
    cout << "enter 'u' to start" << endl;
    cout << "enter 'q' to quit" << endl;

    getline(cin, c);
    input = stoc(c);

    while (input != 'q')
    {
        switch (input)
        {
            case 'u':
            {
                cout << "" << endl;
                cout << "Long ago, two races ruled over Earth: HUMANS and MONSTERS." << endl;
                cout << "One day, war broke out between the two races. After a long battle, the humans were victorious." << endl;
                cout << "They sealed the monsters underground with a magic spell." << endl;
                cout << "Many years later…" << endl;
                cout << endl;

                cout << "Name the fallen human." << endl;
                getline(cin, name);
                name = upper(name);
                cout << "Is this name correct? '" << name << "'" << endl;
                cout << "Y / N" << endl;
                getline(cin, c);
                confirm = stoc(c);
                cout << endl;
                while (confirm != 'Y')
                {
                    switch (confirm)
                    {
                        case 'N':
                        {
                            break;
                        }
                        default:
                        {
                            cout << "Invalid input." << endl;
                            break;
                        }
                    }
                    cout << "Name the fallen human." << endl;
                    getline(cin, name);
                    cout << "Is this name correct? '" << name << "'" << endl;
                    cout << "Y / N" << endl;
                    getline(cin, c);
                    confirm = stoc(c);
                    cout << endl;
                }
                if (confirm == 'Y')
                {
                    p.setUsername(name);
                }

                cout << "The player spawns in a small patch of flowers." << endl;
                cout << "After walking away from the flowers, the player walks through a gate and up to a single flower in the ground." << endl;
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
                    cout << "FLOWEY:" << endl;
                    cout << "Howdy! I'm FLOWEY. FLOWEY the FLOWER! Hmmm..." << endl;
                    cout << "You're new to the UNDERGROUND, aren't cha? Golly, you must be so confused." << endl;
                    cout << "Someone ought to teach you how things work around here!" << endl;
                    cout << "I guess little old me will have to do. Ready?" << endl;
                    cout << "Here we go!" << endl;
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
                        cout << "You entered a fight with Flowey." << endl;
                        cout << "╭―――――――――――――╮" << endl;
                        cout << "│             │" << endl;
                        cout << "│      ♥      │" << endl;
                        cout << "│             │" << endl;
                        cout << "╰―――――――――――――╯" << endl;
                        cout << "1. Fight" << endl;
                        cout << "2. Act" << endl;
                        cout << "3. Item" << endl;
                        cout << "4. Mercy" << endl;
                        cout << endl;

                        cout << "FLOWEY:" << endl;
                        cout << "See that heart? That is your SOUL, the very culmination of your being." << endl;
                        cout << "Your SOUL starts off weak, but can grow strong if you gain a lot of LV." << endl;
                        cout << "What's LV stand for? Why, LOVE, of course!" << endl;
                        cout << "You want some LOVE, don't you? Don't worry, I'll share some with you!" << endl;
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
                            e.Fight(p, 17);
                            cout << "Flowey drains your HP by 19. Flowey's expression changes from a friendly smile to an evil smile." << endl;
                            cout << endl;

                            cout << "FLOWEY:" << endl;
                            cout << "You idiot! In this world, it's kill or BE killed. Why would ANYONE pass up an opportunity like this!?" << endl;
                            cout << "Die!" << endl;
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
                                cout << "Right before Flowey goes to attack your SOUL, a fireball appears next to Flowey and knocks him away." << endl;
                                cout << "Your HP is restored, and a large goat-like creature slides in." << endl;
                                p.setHP(50);
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
                                    cout << "TORIEL:" << endl;
                                    cout << "What a terrible creature, torturing such a poor, innocent youth. Ah, do not be afraid, my child." << endl;
                                    cout << "I am TORIEL, caretaker of the RUINS. I pass through this place every day to see if anyone has fallen down." << endl;
                                    cout << "You are the first human to come here in a long time. Come!" << endl;
                                    cout << "I will guide you through the catacombs." << endl;
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
                                        cout << "You follow Toriel through a purple gate, and end up in a new room." << endl;
                                        cout << endl;
                                        cout << "TORIEL:" << endl;
                                        cout << "Welcome to your new home, innocent one. Allow me to educate you in the operation of the RUINS." << endl;
                                            
                                            // creating random map layout for Ruins
                                            npuzzles = random(4, 7);
                                            nmonsters = random(4, 8);
                                            npc = (random(0, 100) % 2);
                                            map.spawnSave(1, 2);
                                            do
                                            {
                                                row = rand() % 11;
                                                col = rand() % 11;
                                                type = rand() % 86;
                                                map.spawnPuzzle(row, col, type);
                                            } while (map.getPuzzleCount() < npuzzles);
                                            do
                                            {
                                                row = rand() % 11;
                                                col = rand() % 11;
                                                type = random(1, 4);
                                                map.spawnMonster(row, col, type);
                                            } while (map.getMonsterCount() < nmonsters);
                                            do
                                            {
                                                row = rand() % 11;
                                                col = rand() % 11;
                                                s = map.spawnShop(row, col);
                                            } while (s != true);
                                            map.displayMap();
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
                                            cout << "TORIEL:" << endl;
                                            cout << "The RUINS are full of PUZZLES. Ancient fusions between diversions and doorkeys." << endl;
                                            cout << "One must solve them to move from room to room. Please adjust yourself to the sight of them. They are marked by 'P'." << endl;
                                            cout << "As a human living in the Underground, MONSTERS may attack you. You will need to be prepared for this situation." << endl;
                                            cout << "However, worry not! The process is simple. When you encounter a monster, you will enter a FIGHT." << endl;
                                            cout << "You will be given the choices to FIGHT, ACT, use ITEM, or MERCY." << endl;
                                            cout << "It is best to try to ACT." << endl;
                                            cout << "You must complete everything in a room to unlock next room." << endl;
                                            cout << "Take this Butterscotch Pie, Toy Knife, and 50G. Use them wisely!" << endl;
                                            p.saveItem("C", 0);
                                            p.saveItem("W", 0);
                                            p.updateGold(50);
                                            
                                            cout << endl;
                                            cout << "Puzzles: " << pComplete << "/" << npuzzles << endl;
                                            map.displayMap();
                                            cout << "Select one:" << endl;
                                            cout << "1. Move" << endl;
                                            cout << "2. View Status" << endl;
                                            cout << "3. View Inventory" << endl;
                                            cout << "4. Go to next room" << endl;
                                            cout << "5. Quit Game" << endl;

                                            cout << endl;
                                            cout << "A twinkling yellow star comes into view. Move toward it." << endl;
                                            getline(cin, c);
                                            choice = stoi(c);
                                            while (choice != 5 || room < 9)
                                            {
                                                switch (choice)
                                                {
                                                    case 1:
                                                    {
                                                        cout << "Select one: w. up s. down d. right a. left m. menu" << endl;
                                                        getline(cin, c);
                                                        move = stoc(c);
                                                        while (move != 'm')
                                                        {
                                                            if (move == 'w' || move == 'a' || move == 's' || move == 'd')
                                                            {
                                                                map.move(move);
                                                                if (map.isMonsterLocation() == true)
                                                                {
                                                                    // player is in RUINS location
                                                                    if (room < 2)
                                                                    {
                                                                        type = random(1, 4);
                                                                    }
                                                                    // player is in SNOWDIN location
                                                                    else if (room >= 2 && room < 5)
                                                                    {
                                                                        type = random(1, 8);
                                                                    }
                                                                    // player is in WATERFALLS location
                                                                    else if (room >= 5 && room < 7)
                                                                    {
                                                                        type = random(1, 8);
                                                                    }
                                                                    // player is in HOTLAND location
                                                                    else if (room >= 7 && room < 9)
                                                                    {
                                                                        type = random(1, 12);
                                                                    }
                                                                    
                                                                    m = e.getMonster(type);
                                                                    cout << m.getIntro() << endl;
                                                                    cout << "╭―――――――――――――╮" << endl;
                                                                    cout << "│             │" << endl;
                                                                    cout << "│      ♥      │" << endl;
                                                                    cout << "│             │" << endl;
                                                                    cout << "╰―――――――――――――╯" << endl;
                                                                    cout << "1. Fight" << endl;
                                                                    cout << "2. Act" << endl;
                                                                    cout << "3. Item" << endl;
                                                                    cout << "4. Mercy" << endl;
                                                                    cout << endl;
                                                                    
                                                                    
                                                                }
                                                                // else if (map.isNPCLocation() == true)
                                                                // {

                                                                // }
                                                                if (map.isSaveLocation() == true)
                                                                {
                                                                    p.setHP(50);
                                                                    cout << endl;
                                                                    cout << "(The shadow of the ruins looms above, filling you with determination. HP fully restored.)" << endl;
                                                                }
                                                                else if (map.isShopLocation() == true)
                                                                {
                                                                    cout << "You have come across a SHOP. Do you want to enter?" << endl;
                                                                    cout << "Y / N" << endl;
                                                                    getline(cin, c);
                                                                    confirm = stoc(c);
                                                                    cout << endl;
                                                                    if (confirm != 'N')
                                                                    {
                                                                        if (confirm == 'Y')
                                                                        {
                                                                            cout << "Hello traveler. How can I help you?" << endl;
                                                                            cout << "Select one:" << endl;
                                                                            cout << "C. Consumables" << endl;
                                                                            cout << "W. Weapons" << endl;
                                                                            cout << "A. Armor" << endl;
                                                                            cout << "E. Exit" << endl;
                                                                            getline(cin, c);
                                                                            i = stoc(c);
                                                                            while (i != 'E')
                                                                            {
                                                                                cout << p.getUsername() << ": " << p.getGold() << "G" << endl;
                                                                                cout << endl;
                                                                                switch (i)
                                                                                {
                                                                                    case 'C':
                                                                                    {
                                                                                        cout << "Select one:" << endl;
                                                                                        cout << "1. Nice Cream" << endl;
                                                                                        cout << "2. Bisicle" << endl;
                                                                                        cout << "3. Unisicle" << endl;
                                                                                        cout << "4. Cinnamon Bunny" << endl;
                                                                                        cout << "5. Exit" << endl;
                                                                                        cout << endl;
                                                                                        getline(cin,c);
                                                                                        idx = stoi(c);
                                                                                        while (idx != 5)
                                                                                        {
                                                                                            switch (idx)
                                                                                            {
                                                                                                case 1:
                                                                                                {
                                                                                                    
                                                                                                    cout << "15G - Nice Cream: Instead of a joke the wrapper says something nice." << endl;
                                                                                                    cout << "Buy? Y / N" << endl;
                                                                                                    getline(cin, c);
                                                                                                    confirm1 = stoc(c);
                                                                                                    if (confirm1 != 'N')
                                                                                                    {
                                                                                                        if (confirm1 == 'Y')
                                                                                                        {
                                                                                                            if (p.getGold() >= 15)
                                                                                                            {
                                                                                                                p.saveItem("C", 1);
                                                                                                                cout << "'Nice Cream' has been added to your inventory!" << endl;
                                                                                                                cout << endl;
                                                                                                            }
                                                                                                            else
                                                                                                            {
                                                                                                                cout << "You do not have enough Gold." << endl;
                                                                                                                cout << endl;
                                                                                                            }
                                                                                                        }
                                                                                                        else
                                                                                                        {
                                                                                                            while (confirm1 != 'N')
                                                                                                            {
                                                                                                                cout << "Invalid input." << endl;
                                                                                                                cout << "Buy? Y / N" << endl;
                                                                                                                getline(cin, c);
                                                                                                                confirm1 = stoc(c);
                                                                                                            }
                                                                                                        }
                                                                                                    }
                                                                                                    break;
                                                                                                }
                                                                                                case 2:
                                                                                                {
                                                                                                    cout << "25G - Bisicle: It is a two pronged popsicle so it is double the health!" << endl;
                                                                                                    cout << "Buy? Y / N" << endl;
                                                                                                    getline(cin, c);
                                                                                                    confirm1 = stoc(c);
                                                                                                    if (confirm1 != 'N')
                                                                                                    {
                                                                                                        if (confirm1 == 'Y')
                                                                                                        {
                                                                                                            if (p.getGold() >= 25)
                                                                                                            {
                                                                                                                p.saveItem("C", 2);
                                                                                                                cout << "'Bisicle' has been added to your inventory!" << endl;
                                                                                                                cout << endl;
                                                                                                            }
                                                                                                            else
                                                                                                            {
                                                                                                                cout << "You do not have enough Gold." << endl;
                                                                                                                cout << endl;
                                                                                                            }
                                                                                                        }
                                                                                                        else
                                                                                                        {
                                                                                                            while (confirm1 != 'N')
                                                                                                            {
                                                                                                                cout << "Invalid input." << endl;
                                                                                                                cout << "Buy? Y / N" << endl;
                                                                                                                getline(cin, c);
                                                                                                                confirm1 = stoc(c);
                                                                                                            }
                                                                                                        }
                                                                                                    }
                                                                                                    break;
                                                                                                }
                                                                                                case 3:
                                                                                                {
                                                                                                    cout << "15G - Unisicle: It is a SINGLE pronged popsicle. Wait thats just normal..." << endl;
                                                                                                    cout << "Buy? Y / N" << endl;
                                                                                                    getline(cin, c);
                                                                                                    confirm1 = stoc(c);
                                                                                                    if (confirm1 != 'N')
                                                                                                    {
                                                                                                        if (confirm1 == 'Y')
                                                                                                        {
                                                                                                            if (p.getGold() >= 15)
                                                                                                            {
                                                                                                                p.saveItem("C", 3);
                                                                                                                cout << "'Unisicle' has been added to your inventory!" << endl;
                                                                                                                cout << endl;
                                                                                                            }
                                                                                                            else
                                                                                                            {
                                                                                                                cout << "You do not have enough Gold." << endl;
                                                                                                                cout << endl;
                                                                                                            }
                                                                                                        }
                                                                                                        else
                                                                                                        {
                                                                                                            while (confirm1 != 'N')
                                                                                                            {
                                                                                                                cout << "Invalid input." << endl;
                                                                                                                cout << "Buy? Y / N" << endl;
                                                                                                                getline(cin, c);
                                                                                                                confirm1 = stoc(c);
                                                                                                            }
                                                                                                        }
                                                                                                    }
                                                                                                    break;
                                                                                                }
                                                                                                case 4:
                                                                                                {
                                                                                                    cout << "25G - Cinnamon Bunny: A cinnamon roll in the shape of a bunny." << endl;
                                                                                                    cout << "Buy? Y / N" << endl;
                                                                                                    getline(cin, c);
                                                                                                    confirm1 = stoc(c);
                                                                                                    if (confirm1 != 'N')
                                                                                                    {
                                                                                                        if (confirm1 == 'Y')
                                                                                                        {
                                                                                                            if (p.getGold() >= 25)
                                                                                                            {
                                                                                                                p.saveItem("C", 4);
                                                                                                                cout << "'Cinnamon Bunny' has been added to your inventory!" << endl;
                                                                                                                cout << endl;
                                                                                                            }
                                                                                                            else
                                                                                                            {
                                                                                                                cout << "You do not have enough Gold." << endl;
                                                                                                                cout << endl;
                                                                                                            }
                                                                                                        }
                                                                                                        else
                                                                                                        {
                                                                                                            while (confirm1 != 'N')
                                                                                                            {
                                                                                                                cout << "Invalid input." << endl;
                                                                                                                cout << "Buy? Y / N" << endl;
                                                                                                                getline(cin, c);
                                                                                                                confirm1 = stoc(c);
                                                                                                            }
                                                                                                        }
                                                                                                    }
                                                                                                    break;
                                                                                                }
                                                                                                default:
                                                                                                {
                                                                                                    cout << "Invalid input." << endl;
                                                                                                    break;
                                                                                                }
                                                                                            }
                                                                                            cout << "Select one:" << endl;
                                                                                            cout << "1. Nice Cream" << endl;
                                                                                            cout << "2. Bisicle" << endl;
                                                                                            cout << "3. Unisicle" << endl;
                                                                                            cout << "4. Cinnamon Bunny" << endl;
                                                                                            cout << "5. Exit" << endl;
                                                                                            cout << endl;
                                                                                            getline(cin,c);
                                                                                            idx = stoi(c);
                                                                                        }
                                                                                        
                                                                                        break;
                                                                                    }
                                                                                    case 'W':
                                                                                    {
                                                                                        cout << "Select one:" << endl;
                                                                                        cout << "1. Tough Glove" << endl;
                                                                                        cout << "2. Ballet Shoes" << endl;
                                                                                        cout << "3. Torn Notebook" << endl;
                                                                                        cout << "4. Burnt Pan" << endl;
                                                                                        cout << "5. Exit" << endl;
                                                                                        cout << endl;
                                                                                        getline(cin,c);
                                                                                        idx = stoi(c);
                                                                                        while (idx != 5)
                                                                                        {
                                                                                            switch (idx)
                                                                                            {
                                                                                                case 1:
                                                                                                {
                                                                                                    
                                                                                                    cout << "20G - Tough Glove: A worn pink leather glove. For five fingered folk." << endl;
                                                                                                    cout << "Buy? Y / N" << endl;
                                                                                                    getline(cin, c);
                                                                                                    confirm1 = stoc(c);
                                                                                                    if (confirm1 != 'N')
                                                                                                    {
                                                                                                        if (confirm1 == 'Y')
                                                                                                        {
                                                                                                            if (p.getGold() >= 20)
                                                                                                            {
                                                                                                                p.saveItem("W", 1);
                                                                                                                cout << "'Tough Glove' has been added to your inventory!" << endl;
                                                                                                                cout << endl;
                                                                                                            }
                                                                                                            else
                                                                                                            {
                                                                                                                cout << "You do not have enough Gold." << endl;
                                                                                                                cout << endl;
                                                                                                            }
                                                                                                        }
                                                                                                        else
                                                                                                        {
                                                                                                            while (confirm1 != 'N')
                                                                                                            {
                                                                                                                cout << "Invalid input." << endl;
                                                                                                                cout << "Buy? Y / N" << endl;
                                                                                                                getline(cin, c);
                                                                                                                confirm1 = stoc(c);
                                                                                                            }
                                                                                                        }
                                                                                                    }
                                                                                                    break;
                                                                                                }
                                                                                                case 2:
                                                                                                {
                                                                                                    cout << "50G - Ballet Shoes: These used shoes make you feel incredibly dangerous." << endl;
                                                                                                    cout << "Buy? Y / N" << endl;
                                                                                                    getline(cin, c);
                                                                                                    confirm1 = stoc(c);
                                                                                                    if (confirm1 != 'N')
                                                                                                    {
                                                                                                        if (confirm1 == 'Y')
                                                                                                        {
                                                                                                            if (p.getGold() >= 50)
                                                                                                            {
                                                                                                                p.saveItem("W", 2);
                                                                                                                cout << "'Ballet Shoes' has been added to your inventory!" << endl;
                                                                                                                cout << endl;
                                                                                                            }
                                                                                                            else
                                                                                                            {
                                                                                                                cout << "You do not have enough Gold." << endl;
                                                                                                                cout << endl;
                                                                                                            }
                                                                                                        }
                                                                                                        else
                                                                                                        {
                                                                                                            while (confirm1 != 'N')
                                                                                                            {
                                                                                                                cout << "Invalid input." << endl;
                                                                                                                cout << "Buy? Y / N" << endl;
                                                                                                                getline(cin, c);
                                                                                                                confirm1 = stoc(c);
                                                                                                            }
                                                                                                        }
                                                                                                    }
                                                                                                    break;
                                                                                                }
                                                                                                case 3:
                                                                                                {
                                                                                                    cout << "55G - Torn Notebook: Contains illegible scrawls. Increases DEF by 6." << endl;
                                                                                                    cout << "Buy? Y / N" << endl;
                                                                                                    getline(cin, c);
                                                                                                    confirm1 = stoc(c);
                                                                                                    if (confirm1 != 'N')
                                                                                                    {
                                                                                                        if (confirm1 == 'Y')
                                                                                                        {
                                                                                                            if (p.getGold() >= 55)
                                                                                                            {
                                                                                                                p.saveItem("W", 3);
                                                                                                                cout << "'Torn Notebook' has been added to your inventory!" << endl;
                                                                                                                cout << endl;
                                                                                                            }
                                                                                                            else
                                                                                                            {
                                                                                                                cout << "You do not have enough Gold." << endl;
                                                                                                                cout << endl;
                                                                                                            }
                                                                                                        }
                                                                                                        else
                                                                                                        {
                                                                                                            while (confirm1 != 'N')
                                                                                                            {
                                                                                                                cout << "Invalid input." << endl;
                                                                                                                cout << "Buy? Y / N" << endl;
                                                                                                                getline(cin, c);
                                                                                                                confirm1 = stoc(c);
                                                                                                            }
                                                                                                        }
                                                                                                    }
                                                                                                    break;
                                                                                                }
                                                                                                case 4:
                                                                                                {
                                                                                                    cout << "70G - Burnt Pan: Damage is rather consistent." << endl;
                                                                                                    cout << "Buy? Y / N" << endl;
                                                                                                    getline(cin, c);
                                                                                                    confirm1 = stoc(c);
                                                                                                    if (confirm1 != 'N')
                                                                                                    {
                                                                                                        if (confirm1 == 'Y')
                                                                                                        {
                                                                                                            if (p.getGold() >= 70)
                                                                                                            {
                                                                                                                p.saveItem("W", 4);
                                                                                                                cout << "'Burnt Pan' has been added to your inventory!" << endl;
                                                                                                                cout << endl;
                                                                                                            }
                                                                                                            else
                                                                                                            {
                                                                                                                cout << "You do not have enough Gold." << endl;
                                                                                                                cout << endl;
                                                                                                            }
                                                                                                        }
                                                                                                        else
                                                                                                        {
                                                                                                            while (confirm1 != 'N')
                                                                                                            {
                                                                                                                cout << "Invalid input." << endl;
                                                                                                                cout << "Buy? Y / N" << endl;
                                                                                                                getline(cin, c);
                                                                                                                confirm1 = stoc(c);
                                                                                                            }
                                                                                                        }
                                                                                                    }
                                                                                                    break;
                                                                                                }
                                                                                                default:
                                                                                                {
                                                                                                    cout << "Invalid input." << endl;
                                                                                                    break;
                                                                                                }
                                                                                                
                                                                                            }
                                                                                            cout << "Select one:" << endl;
                                                                                            cout << "1. Tough Glove" << endl;
                                                                                            cout << "2. Ballet Shoes" << endl;
                                                                                            cout << "3. Torn Notebook" << endl;
                                                                                            cout << "4. Burnt Pan" << endl;
                                                                                            cout << "5. Exit" << endl;
                                                                                            cout << endl;
                                                                                            getline(cin,c);
                                                                                            idx = stoi(c);
                                                                                        }
                                                                                    break;
                                                                                    
                                                                                    }
                                                                                    case 'A':
                                                                                    {
                                                                                        cout << "Select one:" << endl;
                                                                                        cout << "1. Faded Ribbon" << endl;
                                                                                        cout << "2. Manly Bandana" << endl;
                                                                                        cout << "3. Old Tutu" << endl;
                                                                                        cout << "4. Cloudy Glasses" << endl;
                                                                                        cout << "5. Exit" << endl;
                                                                                        cout << endl;
                                                                                        getline(cin,c);
                                                                                        idx = stoi(c);
                                                                                        while (idx != 5)
                                                                                        {
                                                                                            switch (idx)
                                                                                            {
                                                                                                case 1:
                                                                                                {
                                                                                                    
                                                                                                    cout << "10G - Faded Ribbon: Monsters will not hit you as hard if you are cuter." << endl;
                                                                                                    cout << "Buy? Y / N" << endl;
                                                                                                    getline(cin, c);
                                                                                                    confirm1 = stoc(c);
                                                                                                    if (confirm1 != 'N')
                                                                                                    {
                                                                                                        if (confirm1 == 'Y')
                                                                                                        {
                                                                                                            if (p.getGold() >= 10)
                                                                                                            {
                                                                                                                p.saveItem("A", 1);
                                                                                                                cout << "'Faded Ribbon' has been added to your inventory!" << endl;
                                                                                                                cout << endl;
                                                                                                            }
                                                                                                            else
                                                                                                            {
                                                                                                                cout << "You do not have enough Gold." << endl;
                                                                                                                cout << endl;
                                                                                                            }
                                                                                                            
                                                                                                        }
                                                                                                        else
                                                                                                        {
                                                                                                            while (confirm1 != 'N')
                                                                                                            {
                                                                                                                cout << "Invalid input." << endl;
                                                                                                                cout << "Buy? Y / N" << endl;
                                                                                                                getline(cin, c);
                                                                                                                confirm1 = stoc(c);
                                                                                                            }
                                                                                                        }
                                                                                                    }
                                                                                                    break;
                                                                                                }
                                                                                                case 2:
                                                                                                {
                                                                                                    cout << "50G - Manly Bandana: It has seen some wear. It has abs drawn on it." << endl;
                                                                                                    cout << "Buy? Y / N" << endl;
                                                                                                    getline(cin, c);
                                                                                                    confirm1 = stoc(c);
                                                                                                    if (confirm1 != 'N')
                                                                                                    {
                                                                                                        if (confirm1 == 'Y')
                                                                                                        {
                                                                                                            if (p.getGold() >= 50)
                                                                                                            {
                                                                                                                p.saveItem("A", 2);
                                                                                                                cout << "'Manly Bandana' has been added to your inventory!" << endl;
                                                                                                                cout << endl;
                                                                                                            }
                                                                                                            else
                                                                                                            {
                                                                                                                cout << "You do not have enough Gold." << endl;
                                                                                                                cout << endl;
                                                                                                            }
                                                                                                            
                                                                                                        }
                                                                                                        else
                                                                                                        {
                                                                                                            while (confirm1 != 'N')
                                                                                                            {
                                                                                                                cout << "Invalid input." << endl;
                                                                                                                cout << "Buy? Y / N" << endl;
                                                                                                                getline(cin, c);
                                                                                                                confirm1 = stoc(c);
                                                                                                            }
                                                                                                        }
                                                                                                    }
                                                                                                    break;
                                                                                                }
                                                                                                case 3:
                                                                                                {
                                                                                                    cout << "65G - Old Tutu: Finally a protective piece of armor." << endl;
                                                                                                    cout << "Buy? Y / N" << endl;
                                                                                                    getline(cin, c);
                                                                                                    confirm1 = stoc(c);
                                                                                                    if (confirm1 != 'N')
                                                                                                    {
                                                                                                        if (confirm1 == 'Y')
                                                                                                        {
                                                                                                            if (p.getGold() >= 65)
                                                                                                            {
                                                                                                                p.saveItem("A", 3);
                                                                                                                cout << "'Old Tutu' has been added to your inventory!" << endl;
                                                                                                                cout << endl;
                                                                                                            }
                                                                                                            else
                                                                                                            {
                                                                                                                cout << "You do not have enough Gold." << endl;
                                                                                                                cout << endl;
                                                                                                            }
                                                                                                        }
                                                                                                        else
                                                                                                        {
                                                                                                            while (confirm1 != 'N')
                                                                                                            {
                                                                                                                cout << "Invalid input." << endl;
                                                                                                                cout << "Buy? Y / N" << endl;
                                                                                                                getline(cin, c);
                                                                                                                confirm1 = stoc(c);
                                                                                                            }
                                                                                                        }
                                                                                                    }
                                                                                                    break;
                                                                                                }
                                                                                                case 4:
                                                                                                {
                                                                                                    cout << "65G - Cloudy Glasses: Glasses marred with wear." << endl;
                                                                                                    cout << "Buy? Y / N" << endl;
                                                                                                    getline(cin, c);
                                                                                                    confirm1 = stoc(c);
                                                                                                    if (confirm1 != 'N')
                                                                                                    {
                                                                                                        if (confirm1 == 'Y')
                                                                                                        {
                                                                                                            if (p.getGold() >= 65)
                                                                                                            {
                                                                                                                p.saveItem("A", 4);
                                                                                                                cout << "'Cloudy Glasses' has been added to your inventory!" << endl;
                                                                                                                cout << endl;
                                                                                                            }
                                                                                                            else
                                                                                                            {
                                                                                                                cout << "You do not have enough Gold." << endl;
                                                                                                                cout << endl;
                                                                                                            }
                                                                                                        }
                                                                                                        else
                                                                                                        {
                                                                                                            while (confirm1 != 'N')
                                                                                                            {
                                                                                                                cout << "Invalid input." << endl;
                                                                                                                cout << "Buy? Y / N" << endl;
                                                                                                                getline(cin, c);
                                                                                                                confirm1 = stoc(c);
                                                                                                            }
                                                                                                        }
                                                                                                    }
                                                                                                    break;
                                                                                                }
                                                                                                default:
                                                                                                {
                                                                                                    cout << "Invalid input." << endl;
                                                                                                    break;
                                                                                                }
                                                                                            }
                                                                                            cout << "Select one:" << endl;
                                                                                            cout << "1. Faded Ribbon" << endl;
                                                                                            cout << "2. Manly Bandana" << endl;
                                                                                            cout << "3. Old Tutu" << endl;
                                                                                            cout << "4. Cloudy Glasses" << endl;
                                                                                            cout << "5. Exit" << endl;
                                                                                            cout << endl;
                                                                                            getline(cin,c);
                                                                                            idx = stoi(c);
                                                                                        }
                                                                                        break;
                                                                                    }
                                                                                    default:
                                                                                    {
                                                                                        cout << "Invalid input." << endl;
                                                                                        break;
                                                                                    }
                                                                                    break;
                                                                                }
                                                                                cout << "Select one:" << endl;
                                                                                cout << "C. Consumables" << endl;
                                                                                cout << "W. Weapons" << endl;
                                                                                cout << "A. Armor" << endl;
                                                                                cout << "E. Exit" << endl;
                                                                                cout << endl;
                                                                                getline(cin, c);
                                                                                i = stoc(c);
                                                                            }
                                                                            if (confirm == 'E')
                                                                            {
                                                                                cout << "Thanks for stopping by! Safe travels." << endl;
                                                                            }
                                                                        }
                                                                        else
                                                                        {
                                                                            while (confirm != 'N')
                                                                            {
                                                                                cout << "Invalid input." << endl;
                                                                                cout << "You have come across a SHOP. Do you want to enter?" << endl;
                                                                                cout << "Y / N" << endl;
                                                                                getline(cin, c);
                                                                                confirm = stoc(c);
                                                                                cout << endl;
                                                                            }
                                                                        }
                                                                    }
                                                                }
                                                                else if (map.isPuzzleLocation() == true)
                                                                {
                                                                    type = rand() % 84;
                                                                    cout << endl;
                                                                    cout << "You must solve this puzzle to continue." << endl;
                                                                    map.printPuzzle(type);
                                                                    getline(cin, c);
                                                                    choice = stoi(c);
                                                                    int s = map.correctAnswer(choice, type);
                                                                    while (s == -1)
                                                                        {
                                                                            p.updateHP(-5);
                                                                            map.printPuzzle(type);
                                                                            getline(cin, c);
                                                                            choice = stoi(c);
                                                                            s = map.correctAnswer(choice, type);
                                                                        }
                                                                    
                                                                    if (s != -1)
                                                                    {
                                                                        pComplete++;
                                                                        p.updateHP(10);
                                                                    }
                                                                }
                                                            }
                                                            else
                                                            {
                                                                cout << "Invalid input." << endl;
                                                            }
                                                            cout << endl;
                                                            cout << "Puzzles: " << pComplete << "/" << npuzzles << endl;
                                                            map.displayMap();
                                                            cout << "Select one: w. up s. down d. right a. left m. main menu" << endl;
                                                            getline(cin, c);
                                                            move = stoc(c);
                                                        }
                                                        break;
                                                    }
                                                    // if choice is 2
                                                    case 2:
                                                    {
                                                        // print player's stats
                                                        cout << endl;
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
                                                        cout << "Determination: 1000000000000000000000 :)" << endl;
                                                        cout << endl;
                                                        break;
                                                    }
                                                    // if choice is 3
                                                    case 3:
                                                    {
                                                        // print player's inventory
                                                        cout << endl;
                                                        p.printInventory();
                                                        cout << endl;
                                                        break;
                                                    }
                                                    case 4:
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
                                                            npc = (random(0, 100) % 2);
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
                                                            // if npc is odd number between 0 and 100
                                                            if (npc == 1)
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
                                                        break;
                                                    }
                                                    default:
                                                    {
                                                        cout << "Invalid input." << endl;
                                                        break;
                                                    }
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
                                                    cout << "5. Quit Game" << endl;
                                                    getline(cin, c);
                                                    choice = stoi(c);
                                                    cout << endl;
                                                }
                                            }
                                        }
                                    }
                                    // // final room
                                    //                                 else if (room >= 9)
                                    //                                 {
                                    //                                     // genocide route
                                    //                                     if (p.getLV() == totalMonsters)
                                    //                                     {
                                                                            
                                    //                                     }
                                    //                                     // neutral route
                                    //                                     else if (p.getLV() < totalMonsters && p.getLV() > 0)
                                    //                                     {

                                    //                                     }
                                    //                                     // pacifist route
                                    //                                     else
                                    //                                     {

                                    //                                     }
                                    //                                 }
                                
                                






                                }
                            }
                        }
                    }
                }
                











                break;
            }
            // if user input is not valid
            default:
            {
                cout << "Invalid input." << endl;
                break;
            }
        }
        cout << "UNDERTALE" << endl;
        cout << endl;
        cout << "press 'u' to start" << endl;
        cout << "press 'q' to quit" << endl;
        getline(cin, c);
        input = stoc(c);
    }
    if (input == 'q')
    {
        cout << "Bye!" << endl;
        return 0;
    }
}