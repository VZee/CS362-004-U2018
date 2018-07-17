// Unit test 1 - supplyCount()
// Description: test supplyCount()
/* 
int supplyCount(int card, struct gameState *state) {
  return state->supplyCount[card];
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
    // variable seetup
    int i, j;
    int seed = 1000;
    int numPlayer = 2;
    int maxBonus = 10;
    int testCard = 0;
    int cardCount = 10;
    int p, r;
    int k[10] = {adventurer, council_room, feast, gardens, mine, remodel, smithy, village, baron, great_hall};
    struct gameState G, testG;
    int maxHandCount = 5;
    int handCount;
    int numPlayers = 2;
    int choice1 = 0, choice2 = 0, choice3 = 0, handpos = 0, bonus = 0;

    // initialize a game state and player cards
    initializeGame(numPlayers, k, seed, &G);
    memset(&G, 23, sizeof(struct gameState));   // clear the game state
    r = initializeGame(numPlayer, k, seed, &G); // initialize a new game

    printf("UNIT TEST supplyCount():\n");

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    // do a test for each card
    for (j = 0; j < 10; j++)
    {
        printf("Test %d - after %d card\n", j, j);
        // copy the game state to a test state
        memcpy(&testG, &G, sizeof(struct gameState));

        cardEffect(adventurer, choice1, choice2, choice3, &testG, handpos, &bonus);

        // test for the victory cards - victory cards are estate, duchy, and province; great_hall is also considered a victory card
        printf("Test - there should be 8 of each victory card for a two player game\n");
        assert(G.supplyCount[estate] == testG.supplyCount[estate]);
        assert(G.supplyCount[duchy] == testG.supplyCount[duchy]);
        assert(G.supplyCount[province] == testG.supplyCount[province]);
        assert(G.supplyCount[great_hall] == testG.supplyCount[great_hall]);

        // test for kingdom cards - all but great_hall since that's a victory card
        printf("Test - number of kingdom cards\n");
        for (i = 0; i < 9; i++)
        {
            assert(G.supplyCount[k[i]] == testG.supplyCount[k[i]]);
        }
    }
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    char message = "All tests passed";
    printf(message);

    return 0;
}