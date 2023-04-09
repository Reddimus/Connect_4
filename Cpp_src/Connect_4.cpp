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
    Grid(int rows, int columns)
        : _rows(rows), _columns(columns), _grid(rows, std::vector<GridPosition>(columns, GridPosition::EMPTY)) {}

    void initGrid() {
        for (auto &row : _grid)
            std::fill(row.begin(), row.end(), GridPosition::EMPTY);
    }

    const std::vector<std::vector<GridPosition>>& getGrid() const {
        return _grid;
    }

    int getColumnCount() const {
        return _columns;
    }

    int placePiece(int column, GridPosition piece) {
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

    bool checkWin(int connectN, int row, int col, GridPosition piece) const {
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

private:
    int _rows;
    int _columns;
    std::vector<std::vector<GridPosition>> _grid;
};

class Player {
public:
    Player(const std::string& name, GridPosition pieceColor)
        : _name(name), _pieceColor(pieceColor) {}

    const std::string& getName() const {
        return _name;
    }

    GridPosition getPieceColor() const {
        return _pieceColor;
    }

private:
    std::string _name;
    GridPosition _pieceColor;
};

class Game {
public:
    Game(Grid grid, int connectN, int targetScore)
        : _grid(std::move(grid)), _connectN(connectN), _targetScore(targetScore), _players{
              Player("Player 1", GridPosition::YELLOW),
              Player("Player 2", GridPosition::RED)} {
        _score[_players[0].getName()] = 0;
        _score[_players[1].getName()] = 0;
    }

    void printBoard() const {
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

    std::pair<int, int> playMove(const Player& player) {
        printBoard();
        std::cout << player.getName() << "'s turn\n";
        int colCnt = _grid.getColumnCount();
        std::cout << "Enter column between " << 0 << " and " << colCnt - 1 << " to add piece: ";
        int moveColumn;
        std::cin >> moveColumn;
        int moveRow = _grid.placePiece(moveColumn, player.getPieceColor());
        return {moveRow, moveColumn};
    }

    const Player& playRound() {
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

    void play() {
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

private:
    Grid _grid;
    int _connectN;
    int _targetScore;
    std::vector<Player> _players;
    std::unordered_map<std::string, int> _score;
};

int main() {
    Grid grid(6, 7);
    Game game(grid, 4, 2);
    game.play();

    return 0;
}
