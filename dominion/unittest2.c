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

int main()
{
    // variable setup
    int i;
    int seed = 1000;
    int numPlayers = 2;
    int p, r;
    int k[10] = {adventurer, council_room, feast, gardens, mine, remodel, smithy, village, baron, great_hall};
    struct gameState G, testG;
    int choice1 = 0, choice2 = 0, choice3 = 0, handpos = 0, bonus = 0;

    printf("UNIT TEST whoseTurn():\n");

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    printf("Test 1 - whose turn at beginning of game\n");
    // copy the game state to a test case
    memcpy(&testG, &G, sizeof(struct gameState));
    assert(G.whoseTurn == testG.whoseTurn);
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    for (i = 0; i < 10; i++)
    {
        printf("Test %d - whose turn after each kingdom card %d, called using cardEffect()\n", i, i);
        // copy the game state to a test case
        memcpy(&testG, &G, sizeof(struct gameState));
        cardEffect(k[i], choice1, choice2, choice3, &testG, handpos, &bonus);
        assert(G.whoseTurn == testG.whoseTurn);
    }
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    char message = "All tests passed";
    printf(message);

    return 0;
}