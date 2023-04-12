/**
 * @file Player.cpp
 * @author Michelle Tran
 * @brief Player's basic information
 * @version 0.1
 * @date 2023-04-09
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include <string.h>
#include "Grid.h"

class Player {
public:
    /// @brief Constructor
    /// @param name 
    /// @param pieceColor 
    Player(const std::string& name, GridPosition pieceColor)
        : _name(name), _pieceColor(pieceColor) {}

    /// @return player name 
    const std::string& getName() const {
        return _name;
    }

    /// @return enumerator representing game piece color
    GridPosition getPieceColor() const {
        return _pieceColor;
    }

private:
    // holds player name
    std::string _name; 

    // holds player's piece enum value
    GridPosition _pieceColor; 
};