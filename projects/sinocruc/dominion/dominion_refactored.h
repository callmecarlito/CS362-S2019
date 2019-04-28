#ifndef _DOMINION_REFACTORED_H
#define _DOMINION_REFACTORED_H

#include "dominion.h"

int smithy_call(int handPos, int currentPlayer, struct gameState *state);
int adventurer_call(int handPos, int currentPlayer, struct gameState *state, int *drawntreasure, int *cardDrawn, int *z);
int council_room_call(int handPos, int currentPlayer, struct gameState *state);
int cutpurse_call(int handPos,int currentPlayer, struct gameState *state);
int village_call(int handPos, int currentPlayer, struct gameState *state);

#endif
