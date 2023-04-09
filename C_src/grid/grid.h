// Created by KM 04/08/23
// grid.h

#ifndef GRID_H
#define GRID_H

#include "grid_position.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int rows;
    int columns;
    GridPosition** grid;
} Grid;

void initGrid(Grid* grid, int rows, int columns);
void freeGrid(Grid* grid);
void resetGrid(Grid* grid);
void placePiece(Grid* grid, int column, GridPosition piece, int* row);
char checkWin(Grid* grid, int connectN, int row, int col, GridPosition piece);

#endif // GRID_H
