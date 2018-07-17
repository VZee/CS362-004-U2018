// Unit test 2 - whoseTurn()
// Description: test whoseTurn()
/*
int whoseTurn(struct gameState *state) {
  return state->whoseTurn;
}
*/

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"

// set NOISY_TEST to 0 to remove printfs from output
#define NOISY_TEST 1

int main()
{

    int i;
    int seed = 1000;
    int numPlayer = 2;
    int p, r;
    int k[10] = {adventurer, council_room, feast, gardens, mine, remodel, smithy, village, baron, great_hall};
    struct gameState G;

    printf("UNIT TEST whoseTurn():\n");

    for (p = 0; p < numPlayer; p++)
    {
#if (NOISY_TEST == 1)
        printf("Test player %d.\n", p);
#endif
        memset(&G, 23, sizeof(struct gameState));            // clear the game state
        r = initializeGame(numPlayer, k, seed, &G);          // initialize a new game

        assert(G.whoseTurn == p);             // check if whoseTurn is advancing through each player
    }

    char message = "All tests passed";
    printf(message);

    return 0;
}