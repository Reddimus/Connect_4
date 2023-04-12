/**
 * @file main.cpp
 * @author Michelle Tran
 * @brief Execute file to play Connect 4
 * @version 0.1
 * @date 2023-04-09
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include "Game.h"
#include <iostream>

int main() {
    // create game board
    Grid grid(6, 7);
    
    /// decided how to win the game
    Game game(grid, 4, 2);

    // start Connect 4 game
    game.play();

    return 0;
}