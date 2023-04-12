/**
 * @file Grid.cpp
 * @author Michelle Tran
 * @brief Grid class implementation
 * @version 0.1
 * @date 2023-04-09
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include "Grid.h"

/**
 * @brief Construct a new Grid object
 * 
 * @param rows 
 * @param columns 
 */
Grid::Grid(int rows, int columns)
    : _rows(rows), _columns(columns), _grid(rows, std::vector<GridPosition>(columns, GridPosition::EMPTY)) {}

/**
 * @brief Create the Connect 4 board based on user's desired parameter.
 *        The game board stores the state of each slot as enumerator values. 
 */
void Grid::initGrid() {
    for (auto &row : _grid)
        std::fill(row.begin(), row.end(), GridPosition::EMPTY);
}

/**
 * @brief Game board's state 
 * 
 * @return const std::vector<std::vector<GridPosition>>&
 */
const std::vector<std::vector<GridPosition>>& Grid::getGrid() const {
    return _grid;
}

/**
 * @brief The column number
 * 
 * @return int
 */
int Grid::getColumnCount() const {
    return _columns;
}

/**
 * @brief The player's piece is placed at their desired column choice
 * 
 * @param column selected column to place game piece
 * @param piece associated enum value
 * @return int 
 */
int Grid::placePiece(int column, GridPosition piece) {
    if (column < 0 || column >= _columns)
        throw std::invalid_argument("Invalid column");
    if (piece == GridPosition::EMPTY)
        throw std::invalid_argument("Invalid piece");
    for (int row = _rows - 1; row >= 0; --row) {
        if (_grid[row][column] == GridPosition::EMPTY) {
            _grid[row][column] = piece;
            return row;
        }
    }
    throw std::runtime_error("Column is full");
}

/**
 * @brief A loop to check if there are any consecutive game pieces 
 *        in a row that matches the game's parameters
 * 
 * @param connectN how many consecutive pieces to win in any orientation
 * @param row 
 * @param col 
 * @param piece enum value
 * @return true 
 * @return false 
 */
bool Grid::checkWin(int connectN, int row, int col, GridPosition piece) const {
    // Check horizontal, vertical, diagonal, and anti-diagonal
    int directions[4][2] = {{0, 1}, {1, 0}, {1, 1}, {1, -1}};
    for (const auto& dir : directions) {
        int count = 0;
        for (int i = -connectN + 1; i < connectN; ++i) {
            int r = row + i * dir[0];
            int c = col + i * dir[1];
            if (r >= 0 && r < _rows && c >= 0 && c < _columns && _grid[r][c] == piece)
                ++count;
            else
                count = 0;
            if (count == connectN)
                return true;
        }
    }
    return false;
}


