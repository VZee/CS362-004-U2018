// Card test 1 - smithy
// Source: cardtest4.c
/*
The requirements for the smithy card are: 
1.	Current player should receive exactly 3 cards.
2.	3 cards should come from the player’s own pile.
3.	No state change should occur for other players.
4.	No state change should occur to the victory card piles and kingdom card piles
*/

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"

// set NOISY_TEST to 0 to remove printfs from output
#define NOISY_TEST 1

#define TESTCARD "smithy"

int main()
{
    int newCards = 0;
    int discarded = 1;
    int xtraCoins = 0;
    int shuffledCards = 0;

    int i, j, m;
    int handpos = 0, choice1 = 0, choice2 = 0, choice3 = 0, bonus = 0;
    int remove1, remove2;
    int seed = 1000;
    int numPlayers = 2;
    int thisPlayer = 0;
    struct gameState G, testG;
    int k[10] = {adventurer, embargo, village, minion, mine, cutpurse,
                 sea_hag, tribute, smithy, council_room};

    // initialize a game state and player cards
    initializeGame(numPlayers, k, seed, &G);

    printf("----------------- Testing Card: %s ----------------\n", TESTCARD);

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    // The requirements for the smithy card are:
    //1.	Current player should receive exactly 3 cards.
    printf("TEST 1: Current player should receive exactly 3 cards\n");
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //2.	3 cards should come from the player’s own pile.
    printf("TEST 2: 3 cards should come from the player’s own pile\n");
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //3.	No state change should occur for other players.
    printf("TEST 3: No state change should occur for other players\n");

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //4.	No state change should occur to the victory card piles and kingdom card piles
    printf("TEST 4: No state change should occur to the victory card piles and kingdom card piles\n");

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    // Call Smithy using cardEffect()
    // int cardEffect(int card, int choice1, int choice2, int choice3, struct gameState *state, int handPos, int *bonus)
    testResult = cardEffect(k[6], k[0], k[1], k[2], struct gameState * G, int handPos, *bonus);

    printf("\n >>>>> SUCCESS: Testing complete %s <<<<<\n\n", TESTCARD);

    return 0;
}