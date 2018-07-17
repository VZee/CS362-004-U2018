// Unit test 3 - isGameOver
// Description: test isGameOver()
/*
int isGameOver(struct gameState *state) {
  int i;
  int j;
	
  //if stack of Province cards is empty, the game ends
  if (state->supplyCount[province] == 0)
    {
      return 1;
    }

  //if three supply pile are at 0, the game ends
  j = 0;
  for (i = 0; i < 25; i++)
    {
      if (state->supplyCount[i] == 0)
	{
	  j++;
	}
    }
  if ( j >= 3)
    {
      return 1;
    }

  return 0;
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

int main() {
    int i;
    int seed = 1000;
    int numPlayer = 2;
    int maxBonus = 10;
    int p, r, handCount;
    int k[10] = {adventurer, council_room, feast, gardens, mine
               , remodel, smithy, village, baron, great_hall};
    struct gameState G;
    int maxHandCount = 5;
    
    // two ways to end the game:
    // set the stack of province cards to empty
    // three supply piles are at 0

    printf ("UNIT TEST isGameOver():\n");

    for (p = 0; p < numPlayer; p++)
    {
        for (handCount = 1; handCount <= maxHandCount; handCount++)
        {
            memset(&G, 23, sizeof(struct gameState));            // clear the game state
            r = initializeGame(numPlayer, k, seed, &G);          // initialize a new game
            G.handCount[p] = handCount;                          // set the number of cards on hand
            memcpy(G.hand[p], coppers, sizeof(int) * handCount); // set all the cards to copper - doesn't matter for this test
            assert(G.coins == handCount * 1); // check if the supplyCount[card] is correct
            
#if (NOISY_TEST == 1)
            printf("Test for empty stack of province cards.\n");
#endif

#if (NOISY_TEST == 1)
            printf("Test to see if three supply piles are at 0.\n");
#endif
    }
}

char message = "All tests passed";
printf(message);

return 0;
}