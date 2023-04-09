// Created by KM 04/08/23
// game.c

#include <stdio.h>
#include "game.h"

void initGame(Game* game, Grid* grid, int connectN, int targetScore) {
    game->grid = *grid;
    game->connectN = connectN;
    game->targetScore = targetScore;

    initPlayer(&game->players[0], "Player 1", YELLOW);
    initPlayer(&game->players[1], "Player 2", RED);
}

void printBoard(Game* game) {
    printf("Board:\n\n");
    for (int i = 0; i < game->grid.rows; ++i) {
        for (int j = 0; j < game->grid.columns; ++j) {
            char c;
            switch (game->grid.grid[i][j]) {
                case EMPTY:
                    c = '0';
                    break;
                case YELLOW:
                    c = 'Y';
                    break;
                case RED:
                    c = 'R';
                    break;
            }
            printf("%c ", c);
        }
        printf("\n");
    }
    printf("\n");
}

int playMove(Game* game, Player* player) {
    printBoard(game);
    printf("%s's turn\n", getPlayerName(player));
    int colCnt = game->grid.columns;
    int moveColumn;
    printf("Enter column between %d and %d to add piece: ", 0, colCnt - 1);
    scanf("%d", &moveColumn);
    int moveRow;
    placePiece(&game->grid, moveColumn, getPlayerPieceColor(player), &moveRow);
    return checkWin(&game->grid, game->connectN, moveRow, moveColumn, getPlayerPieceColor(player));
}

void play(Game* game) {
    int score[2] = {0, 0};
    int maxScore = 0;
    while (maxScore < game->targetScore) {
        for (int i = 0; i < 2; ++i) {
            if (playMove(game, &game->players[i])) {
                printBoard(game); // Print the winning board
                printf("%s won the round\n", getPlayerName(&game->players[i]));
                maxScore = ++score[i];
                resetGrid(&game->grid); // Reset the board after a round is won
                break;
            }
        }
    }
    printf("%s won the game\n", getPlayerName(&game->players[maxScore == score[0] ? 0 : 1]));
}

