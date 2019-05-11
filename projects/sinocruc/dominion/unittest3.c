/* -----------------------------------------------------------------------
 * This is a unit test for function isGameOver() found in the file
 * dominion.c. When called the function first checks if there are any
 * provinces available then checks to see if there are three supply piles
 * that have been emptied.
 *
 * Include the following lines in your makefile:
 *
 * unittest3: unittest3.c dominion.o rngs.o
 *      gcc -o unittest3 -g  unittest3.c dominion.o rngs.o $(CFLAGS)
 * -----------------------------------------------------------------------
 */

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"

int checkIsGameOver(struct gameState *state);

// set NOISY_TEST to 0 to remove printfs from output
#define NOISY_TEST 1

int main(){

	int seed = 1000;
    int numPlayer = 2;
    int nunmTests = 100;

    int k[10] = {adventurer, council_room, feast, gardens, mine
               , remodel, smithy, village, baron, great_hall};
    struct gameState G, testG; 
    int i, r, s, t;
    int numProvince;
    int numSupply = 10, numEmptySupply = 0;


    memset(&G, 23, sizeof(struct gameState));   // clear the game state
    r = initializeGame(numPlayer, k, seed, &G); // initialize a new game
    assert(r==0);
    

    if (numPlayer < 3){
    	numProvince = 8;
    }
    else numProvince = 12;

    for (i = 0; i < nunmTests; i++){
    	G->supplyCount[province] = random()/numProvince;
    	for(i = 0; i < 25; i++){
    		G->supplyCount[i] = random()/numSupply;
    	}
#if (NOISY_TEST == 1)
    printf("Before:\n");
    printf("\t[province] = %d\n", G->supplyCount[province]);
    for(i = 0; i < 25; i = i + 5){
    	printf("\t[%d] = %d, [%d] = %d, [%d] = %d, [%d] = %d, [%d] = %d\n", i, G->supplyCount[i], i+1, G->supplyCount[i+1], i+2, G->supplyCount[i+2], i+3, G->supplyCount[i+3], i+4, G->supplyCount[i+4]);
    }
#endif
	}

	memcpy(&testG, &G, sizeof(struct gameState)); //make a copy of the current game state
	s = isGameOver(&G);
	t = checkIsGameOver(&testG);
	assert(s==t);

	printf("Unit Test 3 Complete...\n")

	return 0;
}

int checkIsGameOver(struct gameState *state){
	int i, emptyCount;
	if (state->supplyCount[province] == 0){
		return 1;
	}
	for (i = 0; i < 25; i++){
		if (state->supplyCount[i] == 0){
			emptyCount++;
		}
	}
	if (emptyCount >= 3){
		return 1;
	}
	else {
		return 0;
	}

}
//set random quantities for province 
//set random quantities for supply piles 
//quantites for 1-2 players:
//	MAX_PROVINCES: 8/ea
//	MAX_SUPPLY_PILES: 10/ea (10 of the 25 kingdom cards)
//quantitie for 3-4 players:
//	MAX_PROVINCES: 12/ea
//	MAX_SUPPLY_PILES: 10/ea (10 of the 25 kingdom cards)
