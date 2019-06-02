#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
//#include "dominion_refactored.h"

// set NOISY_TEST to 0 to remove printfs from output
#define NOISY_TEST 1

int main(){

  	int seed = 1000;
    int numPlayer = 2;
    int k[10] = {adventurer, council_room, feast, gardens, mine
               , remodel, smithy, village, baron, great_hall};
    struct gameState G; 
    int r, n, i, s;
    int handPos = 0, currentPlayer = 0, drawnTreasure = 0, cardDrawn = 0, z = 0;

  	for (n = 0; n < 2000; n++) {
      memset(&G, 23, sizeof(struct gameState));   // clear the game state
      r = initializeGame(numPlayer, k, seed, &G); // initialize a new game
      assert(r==0);
    	//for (i = 0; i < sizeof(struct gameState); i++) {
      //	((char*)&G)[i] = floor(Random() * 256);
    	//}
    	G.deckCount[currentPlayer] = floor(Random() * MAX_DECK);
    	G.discardCount[currentPlayer] = floor(Random() * MAX_DECK);
    	G.handCount[currentPlayer] = floor(Random() * MAX_HAND);

#if (NOISY_TEST == 1)
    printf("Before function call:\n G.deckCount: %d \n", G.deckCount[currentPlayer]);
    printf("G.discardCount: %d \n", G.discardCount[currentPlayer]);
    printf("G.handCount: %d \n", G.handCount[currentPlayer]);
    printf("drawnTreasure: %d \n", drawnTreasure);
    printf("cardDrawn: %d \n", cardDrawn);
#endif

    	s = adventurer_call(handPos, currentPlayer, &G, &drawnTreasure, &cardDrawn, &z);
      assert (s == 0);

#if (NOISY_TEST == 1)
    printf("After function call:\n G.deckCount: %d \n", G.deckCount[currentPlayer]);
    printf("G.discardCount: %d \n", G.discardCount[currentPlayer]);
    printf("G.handCount: %d \n", G.handCount[currentPlayer]);
    printf("drawnTreasure: %d \n", drawnTreasure);
    printf("cardDrawn: %d \n", cardDrawn);
#endif

    drawnTreasure = 0;
    cardDrawn = 0;
    z = 0;
  	}

  	exit(0);

	return 0;
}
