/**
 * @file Game.h
 * @author Michelle Tran
 * @brief 
 * @version 0.1
 * @date 2023-04-09
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include <iostream>
#include <vector>
#include <unordered_map>
#include <stdexcept>
#include <algorithm>
#include <string>
#include <utility>
// #include "Grid.h"
#include "Player.cpp"

class Game {
public:
    /// @brief constructor
    /// @param grid 
    /// @param connectN number of consecutive game pieces in a row in any orientation to win
    /// @param targetScore the number of wins to recieve before the program ends
    Game(Grid grid, int connectN, int targetScore);

    /// @brief display game board on terminal
    void printBoard() const;

    /// @brief User selects column to place game piece
    /// @param player 
    /// @return coordinate of where the piece landed
    std::pair<int, int> playMove(const Player& player);

    /// @brief main game loop
    /// @return the winning player
    const Player& playRound();

    /// @brief  Function to call in the main function to call the game loop
    void play();

private:
    Grid _grid;
    int _connectN;
    int _targetScore;
    std::vector<Player> _players;
    std::unordered_map<std::string, int> _score;
};