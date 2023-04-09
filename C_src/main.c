// Created by KM 04/08/23
// main.c

#include "game/game.h"

int main() {
    Grid grid;
    initGrid(&grid, 6, 7);
    Game game;
    initGame(&game, &grid, 4, 2);
    play(&game);
    freeGrid(&grid);
    return 0;
}

/*
In terminal compile and run:
gcc main.c game/game.c grid/grid.c player/player.c -o ConnectFour
.\ConnectFour.exe 

The C project consists of multiple source files that need to be 
compiled together before the program can be run.

.json files were added to the project to allow for the use of VSCode's
run code feature. This feature allows for the program to be run without 
having to manually compile it first in terminal.
*/