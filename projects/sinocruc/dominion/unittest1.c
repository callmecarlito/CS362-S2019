/* -----------------------------------------------------------------------
 * This is a unit test for function call of smithy_call() within cardEffect()
 * of the dominion.c soure file. When this function is called, subroutine 
 * drawCard() should be called three times, followed by discardCard(), and if
 * no error occurs, a value of 0 should be returned. This unit test checks 
 * to make sure the handCount for the currentPlayer changes according to the 
 * requirements.
 *
 * Include the following lines in your makefile:
 *
 * unittest1: unittest1.c dominion.o rngs.o
 *      gcc -o unittest1 -g  unittest1.c dominion.o rngs.o $(CFLAGS)
 * -----------------------------------------------------------------------
 */

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include "dominion_refactored.h"

// set NOISY_TEST to 0 to remove printfs from output
#define NOISY_TEST 1

#define assertrue(bool) if(bool) printf("TEST SUCCESSFULLY COMPLETED.\n"); else printf("TEST FAILED:' " #bool " ' on line %d.\n", __LINE__);

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
  
#if asserttrue(G.handCount[currentPlayer] == (testG.handCount[currentPlayer] + drawnCards - discardedCards));
#endif
    
	printf("Unit Test 1 complete...\n");

	return 0;
}

