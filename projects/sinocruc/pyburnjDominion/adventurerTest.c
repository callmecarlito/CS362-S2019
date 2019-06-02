include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
//#include "dominion_refactored.h"

#define DEBUG 0
#define NOISY_TEST 1

int checkAdventurerCard(int p, struct gameState *post) {
 

  assert (r == 0);
}

int main(){

  	int i, n, r, p, deckCount, discardCount, handCount;

  	int drawnTreasure = 0;

  	int cardDrawn;

  	int z;

  	int k[10] = {adventurer, council_room, feast, gardens, mine,
	       	remodel, smithy, village, baron, great_hall};

  	struct gameState G;

  	printf ("Testing drawCard.\n");

  	printf ("RANDOM TESTS.\n");

  	SelectStream(2);
  	PutSeed(3);

  	for (n = 0; n < 2000; n++) {
    	for (i = 0; i < sizeof(struct gameState); i++) {
      	((char*)&G)[i] = floor(Random() * 256);
    	}
    	p = floor(Random() * 2);
    	G.deckCount[p] = floor(Random() * MAX_DECK);
    	G.discardCount[p] = floor(Random() * MAX_DECK);
    	G.handCount[p] = floor(Random() * MAX_HAND);
    	checkDrawCard(p, &G);
  	}

  	printf ("ALL TESTS OK\n");

  	exit(0);

	return 0;
}
