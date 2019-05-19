include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include "dominion_refactored.h"

#define DEBUG 0
#define NOISY_TEST 1

int checkSmithyCard(int handPos, int player, struct gameState *testG) {
 
  int r;

  r = smithy_call(handPos, player, testG);

  assert (r == 0);
}

int main(){

  	int i, n, p, handPosition;

  	int k[10] = {adventurer, council_room, feast, gardens, mine,
	       	remodel, smithy, village, baron, great_hall};

  	struct gameState G;

  	printf ("Testing smithy_call.\n");

  	printf ("RANDOM TESTS.\n");

  	SelectStream(2);
  	PutSeed(3);

  	for (n = 0; n < 100; n++) {
    	for (i = 0; i < sizeof(struct gameState); i++) {
      	((char*)&G)[i] = floor(Random() * 256);
    	}
    	p = floor(Random() * 2);
      G.handCount[p] = floor(Random() * MAX_HAND);
    	G.deckCount[p] = floor(Random() * MAX_DECK);
    	G.discardCount[p] = floor(Random() * MAX_DECK);
    	
    	checkSmithyCard(handPosition, p, &G);
  	}

  	printf ("ALL TESTS OK\n");

  	exit(0);

	return 0;
}