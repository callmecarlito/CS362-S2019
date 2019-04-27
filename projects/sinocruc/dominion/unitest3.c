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

// set NOISY_TEST to 0 to remove printfs from output
#define NOISY_TEST 1

int main(){

#if (NOISY_TEST == 1)
    //printf("G.coins = %d, expected = %d\n", G.coins, handCount * 1 + bonus);
#endif 

	printf("unittest3 result\n")

	return 0;
}