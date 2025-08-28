# Undertale (Terminal Edition) — C++ Clone

A freshman-year project: a lightweight, text-based tribute to **Undertale**, written entirely in C++ and rendered in the terminal.  
The game recreates the feel of Undertale with ASCII graphics, canonical dialogue, combat, puzzles, and exploration.

> **Disclaimer**: Undertale is owned by Toby Fox. This project was built for academic/learning purposes only and is non-commercial.

---

## How the Game Works

The game runs fully in the **terminal** and aims to be immersive, recreating the feel of the original Undertale experience:

- **Exploration**  
  You navigate a 2D ASCII **map of rooms** using **W/A/S/D**.  
  Symbols on the map:
  - `X` → Player (you!)
  - `M` → Monster (triggers encounters)  
  - `P` → Puzzle (trivia-style questions)  
  - `S` → Shop (buy items)  
  - `*` → Checkpoint/save point (The shadow of the ruins looms above, filling you with determination. HP fully restored.) 

```
X-----------
--*---------
P-----------
------------
------P-SP--
------------
--------P---
-P----------
------------
----P-------
-----P------
------------
```

- **Encounters**  
  Running into monsters triggers a battle where you can:
  - **Fight** → Attack the monster
  - **Act** → Interact/convince, with canonical-style dialogue
  - **Spare** → End the fight peacefully if conditions are met
  - **Use Item** → Heal or equip items from your inventory  

- **Dialogue**  
  The game includes **canonical Undertale conversations** (e.g., with Flowey, Toriel, and others) to capture the original feel.

- **Puzzles**  
  Squares marked `P` on the map present trivia-style questions.  
  You must pass a certain number of puzzles to advance to the next room.

- **Shops**  
  Marked with `S`. Buy consumables, weapons, and armor just like in the real game.

- **Checkpoints**  
  Marked with `*`. Work like save points in Undertale.

- **Stats & Inventory**  
  Players have HP, ATK, DEF, LV, Gold, and Souls, plus an inventory system for items, modeled on Undertale’s setup.

---

## Features
- 2D ASCII room-based map
- Canonical Undertale-style conversations
- Combat loop with Fight / Act / Spare / Item
- Trivia-style puzzles that gate room progression
- Shops for items and equipment
- Checkpoints/save stars
- Class-based design: `Player`, `Monster`, `Item`, `Map`, `Puzzle`, `Encounter`

---

## File Structure
```
Player.cpp / Player.h # Player stats, inventory, actions
Monster.cpp / Monster.h # Monster stats and phrases
Item.cpp / Item.h # Item system
Map.cpp / Map.h # Map grid and movement
Puzzle.cpp / Puzzle.h # Puzzle mechanics
Encounter.cpp / Encounter.h # Encounters + combat system
Undertale.cpp # Main game loop
Item.txt / Monsters.txt # Data files
game.txt / questions.txt # Supporting text/dialogue
```

---

## Build & Run

### Compile
```bash
g++ -std=c++17 Player.cpp Item.cpp Monster.cpp Encounter.cpp Map.cpp Puzzle.cpp Undertale.cpp -o proj3
```

### Run
```bash
./proj3
```

### Controls
- W / A / S / D → Move on the map
- Enter → Confirm actions

Have fun! 