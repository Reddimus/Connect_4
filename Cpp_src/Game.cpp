/**
 * @file Game.cpp
 * @author Michelle Tran
 * @brief 
 * @version 0.1
 * @date 2023-04-09
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include "Game.h"

/**
 * @brief Construct a new Game:: Game object
 * 
 * @param grid 
 * @param connectN number of consecutive game pieces in a row in any orientation to win
 * @param targetScore the number of wins to recieve before the program ends
 */
Game::Game(Grid grid, int connectN, int targetScore)
        : _grid(std::move(grid)), _connectN(connectN), _targetScore(targetScore), _players{
              Player("Player 1", GridPosition::YELLOW),
              Player("Player 2", GridPosition::RED)} {
        _score[_players[0].getName()] = 0;
        _score[_players[1].getName()] = 0;
}

/**
 * @brief display game board on terminal
 * 
 */
void Game::printBoard() const {
    std::cout << "Board:\n\n";
    const auto& grid = _grid.getGrid();
    for (const auto& row : grid) {
        for (const auto& piece : row) {
            switch (piece) {
                case GridPosition::EMPTY:
                    std::cout;
                    std::cout << "0 ";
                    break;
                case GridPosition::YELLOW:
                    std::cout << "Y ";
                    break;
                case GridPosition::RED:
                    std::cout << "R ";
                    break;
            }
        }
        std::cout << '\n';
    }
    std::cout << '\n';
}

/**
 * @brief User selects column to place game piece
 * 
 * @param player 
 * @return std::pair<int, int> 
 */
std::pair<int, int> Game::playMove(const Player& player) {
    printBoard();
    std::cout << player.getName() << "'s turn\n";
    int colCnt = _grid.getColumnCount();
    std::cout << "Enter column between " << 0 << " and " << colCnt - 1 << " to add piece: ";
    int moveColumn;
    std::cin >> moveColumn;
    int moveRow = _grid.placePiece(moveColumn, player.getPieceColor());
    return {moveRow, moveColumn};
}

/**
 * @brief Main game loop
 * 
 * @return const Player& 
 */
const Player& Game::playRound() {
    while (true) {
        for (const auto& player : _players) {
            auto [row, col] = playMove(player);
            GridPosition pieceColor = player.getPieceColor();
            if (_grid.checkWin(_connectN, row, col, pieceColor)) {
                printBoard();
                _score[player.getName()] += 1;
                return player;
            }
        }
    }
}

/**
 * @brief Function to call in the main function to call the game loop
 * 
 */
void Game::play() {
    int maxScore = 0;
    const Player* winner = nullptr;
    while (maxScore < _targetScore) {
        winner = &playRound();
        std::cout << winner->getName() << " won the round\n";
        maxScore = std::max(_score[winner->getName()], maxScore);
        _grid.initGrid();  // reset grid
    }
    std::cout << winner->getName() << " won the game\n";
}
