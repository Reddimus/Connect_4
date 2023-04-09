// Created by KM 04/08/23
// grid.c

#include "grid.h"

void initGrid(Grid* grid, int rows, int columns) {
    grid->rows = rows;
    grid->columns = columns;
    grid->grid = (GridPosition**)malloc(rows * sizeof(GridPosition*));

    for (int i = 0; i < rows; ++i) 
        grid->grid[i] = (GridPosition*)calloc(columns, sizeof(GridPosition));
}

void freeGrid(Grid* grid) {
    for (int i = 0; i < grid->rows; ++i) 
        free(grid->grid[i]);
    free(grid->grid);
}

void resetGrid(Grid* grid) {
    for (int i = 0; i < grid->rows; ++i) {
        for (int j = 0; j < grid->columns; ++j)
            grid->grid[i][j] = EMPTY;
    }
}

void placePiece(Grid* grid, int column, GridPosition piece, int* row) {
    // Error handling for invalid column and piece
    if (column < 0 || column >= grid->columns) printf("Invalid column\n");
    if (piece == EMPTY) printf("Invalid piece\n");

    for (int r = grid->rows - 1; r >= 0; --r) {
        if (grid->grid[r][column] == EMPTY) {
            grid->grid[r][column] = piece;
            *row = r;
            break;
        }
    }
}

char checkWin(Grid* grid, int connectN, int row, int col, GridPosition piece) {
    // Check horizontal, vertical, diagonal, and anti-diagonal
    char directions[4][2] = {{0, 1}, {1, 0}, {1, 1}, {1, -1}};
    for (char d = 0; d < 4; ++d) {
        int count = 0;
        for (int i = -connectN + 1; i < connectN; ++i) {
            int r = row + i * directions[d][0];
            int c = col + i * directions[d][1];
            if (r >= 0 && r < grid->rows && c >= 0 && c < grid->columns && grid->grid[r][c] == piece) 
                ++count;
            else 
                count = 0;
            if (count == connectN) 
                return 1;   // True
        }
    }
    return 0;   // False
}
