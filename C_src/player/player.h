// Created by KM 04/08/23
// player.h

#ifndef PLAYER_H
#define PLAYER_H

#include "../grid/grid_position.h"
#include <string.h>

typedef struct {
    char name[32];
    GridPosition pieceColor;
} Player;

void initPlayer(Player* player, const char* name, GridPosition pieceColor);
const char* getPlayerName(Player* player);
GridPosition getPlayerPieceColor(Player* player);

#endif // PLAYER_H
