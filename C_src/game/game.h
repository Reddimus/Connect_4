// Created by KM 04/08/23
// game.h

#ifndef GAME_H
#define GAME_H

#include "../grid/grid.h"
#include "../player/player.h"

typedef struct {
    Grid grid;
    int connectN;
    int targetScore;
    Player players[2];
} Game;

void initGame(Game* game, Grid* grid, int connectN, int targetScore);
void play(Game* game);

#endif // GAME_H
