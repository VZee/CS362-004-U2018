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

// set NOISY_TEST to 0 to remove printfs from output
#define NOISY_TEST 1

int main()
{
    int i;
    int seed = 1000;
    int numPlayer = 2;
    int maxBonus = 10;
    int testCard = 0;
    int cardCount = 10;
    int p, r;
    int k[10] = {adventurer, council_room, feast, gardens, mine, remodel, smithy, village, baron, great_hall};
    struct gameState G;
    int maxHandCount = 5;
    int handCount;

    // Arrays of hands
    int someOfEach[MAX_HAND];   // different cards
    int allAdventure[MAX_HAND]; // all the same card
    int halves[MAX_HAND];       // two cards

    // Initialize the hands
    for (i = 0; i < MAX_HAND; i++){
        int nextCard = i % 10;

        someOfEach[i] = k[nextCard]; 
        allAdventure[i] = adventurer;

        if (i < MAX_HAND/2) {halves[i] = adventurer;}
        else {halves[i] = council_room;}
    }

    printf("UNIT TEST supplyCount():\n");

    for (p = 0; p < numPlayer; p++)
    {
        for (testCard = 0; testCard < cardCount; testCard++)
        {
            for (handCount = 1; handCount <= maxHandCount; handCount++)
            {
#if (NOISY_TEST == 1)
            printf("Test card %d.\n", testCard);
#endif
                memset(&G, 23, sizeof(struct gameState));           // clear the game state
                r = initializeGame(numPlayer, k, seed, &G);         // initialize a new game
                G.handCount[p] = handCount;                         // set the number of cards on hand
                memcpy(G.supplyCount[p], coppers, sizeof(int) * handCount); // set all the cards to adventure
                updateCoins(p, &G, bonus);

                // test the different cards
                assert(G.supplyCount[testCard] == );                   // check if the supplyCount[card] is correct
            }
        }
    }

char message = "All tests passed";
printf(message);

return 0;
}