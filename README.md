CONTENTS OF THIS FILE
--------------------------------
* Game Description
* Introduction
* Design Decisions
* Installation
* Configuration
* Authors


Game Description
--------------------------------
Battleship is a classic two player game where players try to sink their opponent’s navy ships. The basic object of the game of Battleship is to hide your ship fleet somewhere on your ocean and by calling out basic coordinates, find your opponent’s fleet before they find yours. To play Choose a player who will go first. That player begins the game by calling out a letter and number position from the grid (i.e. “C4”), and the other player responds by determining if the shot was shot was a hit or a miss. Hits occur when the called shot hits any part of an enemy vessel. A miss occurs when the shot misses all enemy vessels. After a hit or miss has been determined, play passes to the other player who then calls their shot in the same manner and the first player to sink the entire enemy fleet wins the game.


Introduction
--------------------------------
This project is designed using C++ and creates a game of battleship that can be played by two players by following the rules mentioned above. To play each player establishes their roles as player 1 or player 2 and decides who goes first. To play, both players need to run the application, it would be better to play the game on separate computers otherwise players could cheat.


Design Decisions
--------------------------------
This battleship project uses Grids and Cells to keep track of the game. A Grid class is created to build and display the board, keep track of your board (which is referred to as primary grid for the both players), and keep track of the opponents board (which will show as tracking grid for each player). The Grid class is designed in way to allow players to play with more of fewer ships if they desire, but to do so they will have to edit the ship_type and ship_size vectors in main.cpp. Characters (i.e. 'A' or 'B') are used to represent the ships in the grid to keep things simple and because this is a simpler version of the game the battleships are set randomly within the grid, instead of allowing players to place their ships anywhere. In the project a cell struct is created to use information from input. Cells are used to get coordinates from users that should be within range of the grid since the input will come as a char and integer that represents the col and row.


Installation
--------------------------------
Download or clone this repository to a folder of your choice.
All you need to play the game is the Battleship application (it is in the folder) and someone to play it with, however if you would like to make changes you will need at least a code editor or a C++ IDE to edit, compile, and run the code.

Configuration
--------------------------------
As I mentioned earlier in design decisions changes can be made to the number of ships in-game. The ship_size and ship_type vectors can be edited to include as many ships as desired. To add a ship to the game, you would need to add the character that you want to use  for the ship and the size of the ship in the correct location for both vectors. For example if you had:

ship_type = { 'A', 'B', 'C', 'S', 'P'  };
ship_size = { 5, 4, 3, 2, 2 };

If you wanted to add another battleship('B') to the game you have to add the char to the ship_type and wherever the char is in the vector the size of the ship has to be in the exact same location in the ship_size vector. It would look like this:

ship_type = { 'A', 'B', 'C', 'S', 'P', 'B'  };
ship_size = { 5, 4, 3, 2, 2, 4 };

Authors
--------------------------------
Edited by Earl Moss.
