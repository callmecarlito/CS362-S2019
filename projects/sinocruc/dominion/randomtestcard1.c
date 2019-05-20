#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include "dominion_refactored.h"

#define NOISY_TEST 0

int main(){

  int seed = 1000;
    int numPlayer = 2;
    int k[10] = {adventurer, council_room, feast, gardens, mine
               , remodel, smithy, village, baron, great_hall};
    struct gameState G, testG; 
    int r, s;
    int drawnCards = 3, discardedCards = 1;
    int handPos = 0, currentPlayer = 0;

    memset(&G, 23, sizeof(struct gameState));   // clear the game state
    r = initializeGame(numPlayer, k, seed, &G); // initialize a new game
    assert(r==0);
    memcpy(&testG, &G, sizeof(struct gameState)); //make a copy of the current game state

#if (NOISY_TEST == 1)
    printf("Before function call:\n G.handCount: %d ,testG.handCount: %d \n", G.handCount[currentPlayer], testG.handCount[currentPlayer]);
#endif
    
    s = smithy_call(handPos, currentPlayer, &G);
    assert(s==0);
    
#if (NOISY_TEST == 1)
    printf("After function call:\n G.handCount: %d ,testG.handCount: %d \n", G.handCount[currentPlayer], testG.handCount[currentPlayer]);
#endif
  
    //assert(G.handCount[currentPlayer] == (testG.handCount[currentPlayer] + drawnCards - discardedCards));
    
    if (G.handCount[currentPlayer] == (testG.handCount[currentPlayer] + drawnCards - discardedCards))
        printf("TEST SUCCESSFULL.\n");
    else
        printf("TEST FAILED.\n");
  printf("Test 1 complete...\n");

  return 0;
}