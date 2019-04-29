/* -----------------------------------------------------------------------
 * *******This is a unit test for function drawCard() found in the file
 * *******dominion.c
 *
 * *******Include the following lines in your makefile:
 *
 * *******testUpdateCoins: testUpdateCoins.c dominion.o rngs.o
 * *******     gcc -o testUpdateCoins -g  testUpdateCoins.c dominion.o rngs.o $(CFLAGS)
 * -----------------------------------------------------------------------
 */

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include "dominion_refactored.h"
#include "interface.h"

#define assertrue(bool) if(bool) printf("TEST SUCCESSFULLY COMPLETED.\n"); else printf("TEST FAILED: '");

int main(){

	int seed = 1000;
    int numPlayer = 2;
    int k[10] = {adventurer, council_room, feast, gardens, mine
               , remodel, smithy, village, baron, great_hall};
    struct gameState G;
    int r;

    memset(&G, 23, sizeof(struct gameState));   // clear the game state
    r = initializeGame(numPlayer, k, seed, &G); // initialize a new game
    asserttrue(r==0);

    printGameState(G);

	printf("unittest1 result\n")

	return 0;
}

// set NOISY_TEST to 0 to remove printfs from output
//#define NOISY_TEST 1

//#define assertrue(bool)


//#if (NOISY_TEST == 1)
    //printf("G.coins = %d, expected = %d\n", G.coins, handCount * 1 + bonus);
//#endif 