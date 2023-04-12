/**
 * @file Grid.h
 * @author Michelle Tran
 * @brief Connect 4 game board class
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

enum class GridPosition { EMPTY, YELLOW, RED };

class Grid {
public:
    /// @brief Construct a new Grid object 
    /// @param rows 
    /// @param columns  
    Grid(int rows, int columns);

    /// @brief Create the Connect 4 board based on user's desired parameter. 
    ///        The game board stores the state of each slot as enumerator values. 
    void initGrid(); 

    /// @return game board
    const std::vector<std::vector<GridPosition>>& getGrid() const; 

    /// @return column number
    int getColumnCount() const;

    /// @brief The player's piece is placed at their desired column choice
    /// @param column selected column to place game piece
    /// @param piece associated enum value
    /// @return row number
    int placePiece(int column, GridPosition piece);

    /// @brief A loop to check if there are any consecutive game pieces in a row that matches the game's parameter
    /// @param connectN how many consecutive pieces to win in any orientation
    /// @param row 
    /// @param col 
    /// @param piece enum value
    /// @return true if there is a winner, false otherwise
    bool checkWin(int connectN, int row, int col, GridPosition piece) const;

private:
    int _rows;
    int _columns;
    std::vector<std::vector<GridPosition>> _grid;
};