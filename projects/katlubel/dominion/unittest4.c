// Unit test 4 - fullDeckCount()
// Description: test fullDeckCount()
/*
int fullDeckCount(int player, int card, struct gameState *state)
{
  int i;
  int count = 0;

  for (i = 0; i < state->deckCount[player]; i++)
  {
    if (state->deck[player][i] == card)
      count++;
  }

  for (i = 0; i < state->handCount[player]; i++)
  {
    if (state->hand[player][i] == card)
      count++;
  }

  for (i = 0; i < state->discardCount[player]; i++)
  {
    if (state->discard[player][i] == card)
      count++;
  }

  return count;
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
    int i;
    int seed = 1000;
    int numPlayers = 2;
    int maxBonus = 10;
    int firstPlayer = 0;
    int secondPlayer = 1;
    int p, r, handCount;
    int k[10] = {adventurer, council_room, feast, gardens, mine, remodel, smithy, village, baron, great_hall};
    struct gameState G, testG;
    int maxHandCount = 5;
    int choice1 = 0, choice2 = 0, choice3 = 0, handpos = 0, bonus = 0;

    printf("UNIT TEST fullDeckCount():\n");

    // initialize a game state and player cards
    initializeGame(numPlayers, k, seed, &G);
    memset(&G, 23, sizeof(struct gameState));    // clear the game state
    r = initializeGame(numPlayers, k, seed, &G); // initialize a new game

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    printf("Test 1 - player 1 and each kingdom card\n");

    for (i = 0; i < 10; i++)
    {
        // copy the game state to a test case
        memcpy(&testG, &G, sizeof(struct gameState));

        assert(fullDeckCount(firstPlayer, k[i], &G) == fullDeckCount(firstPlayer, k[i], &testG));
    }
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    printf("Test 2 - player 2 and each kingdom card\n");

    for (i = 0; i < 10; i++)
    {
        // copy the game state to a test case
        memcpy(&testG, &G, sizeof(struct gameState));

        assert(fullDeckCount(secondPlayer, k[i], &G) == fullDeckCount(secondPlayer, k[i], &testG));
    }
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    printf("All tests passed!\n");

    return 0;
}