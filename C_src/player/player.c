// Created by KM 04/08/23
// player.c

#include "player.h"

void initPlayer(Player* player, const char* name, GridPosition pieceColor) {
    strncpy(player->name, name, sizeof(player->name) - 1);
    player->name[sizeof(player->name) - 1] = '\0';
    player->pieceColor = pieceColor;
}

const char* getPlayerName(Player* player) {
    return player->name;
}

GridPosition getPlayerPieceColor(Player* player) {
    return player->pieceColor;
}
