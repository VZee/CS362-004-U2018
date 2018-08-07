// Unit test 3 - isGameOver
// Description: test isGameOver()
// copy of unit test for testing clarkni code
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

int main() {
    int i;
    int seed = 1000;
    int numPlayers = 2;
    int maxBonus = 10;
    int p, r, handCount;
    int k[10] = {adventurer, council_room, feast, gardens, mine
               , remodel, smithy, village, baron, great_hall};
               
    struct gameState G, testG;
    int maxHandCount = 5;
    int choice1 = 0, choice2 = 0, choice3 = 0, handpos = 0, bonus = 0;
    
    // two ways to end the game:
    // set the stack of province cards to empty
    // three supply piles are at 0

    printf ("UNIT TEST isGameOver():\n");

    // initialize a game state and player cards
    initializeGame(numPlayers, k, seed, &G);
    memset(&G, 23, sizeof(struct gameState));   // clear the game state
    r = initializeGame(numPlayers, k, seed, &G); // initialize a new game

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    printf("Test 1 - initial game state\n");
    // copy the game state to a test case
    memcpy(&testG, &G, sizeof(struct gameState));

    assert(isGameOver(&G) == isGameOver(&testG));
    memset(&G, 23, sizeof(struct gameState));   // clear the game state
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    printf("Test 2 - stack of province cards in empty\n");
    r = initializeGame(numPlayers, k, seed, &G); // initialize a new game
    // set province cards to empty - 8 province cards for a two person game
    printf("%d", G.supplyCount[province]);
    memset(&G.supplyCount[province], 0, sizeof(int) * 1); 

    // copy the game state to a test case
    memcpy(&testG, &G, sizeof(struct gameState));

    assert(isGameOver(&G) == isGameOver(&testG));
    memset(&G, 23, sizeof(struct gameState));   // clear the game state
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

     ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    printf("Test 3 - three supply piles are empty\n");
    r = initializeGame(numPlayers, k, seed, &G); // initialize a new game
    // set province cards to empty - 8 victory cards for a two person game - great_hall is considered a victory card
    memset(&G.supplyCount[estate], 0, sizeof(int) * 1);
    memset(&G.supplyCount[duchy], 0, sizeof(int) * 1); 
    memset(&G.supplyCount[great_hall], 0, sizeof(int) * 1); 

    // copy the game state to a test case
    memcpy(&testG, &G, sizeof(struct gameState));

    assert(isGameOver(&G) == isGameOver(&testG));
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    printf("All tests passed\n");

return 0;
}