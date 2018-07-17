// Card test 4 - great hall
// Source: cardtest4.c
/*
The requirements for the village card are:
1.	Current player should receive exactly 1 card.
2.	1 card should come from the player’s own pile.
3.	No state change should occur for other players.
4.	No state change should occur to the victory card piles and kingdom card piles.
5.	Current player receives 2 additional actions. 
*/

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"

// set NOISY_TEST to 0 to remove printfs from output
#define NOISY_TEST 1
#define TESTCARD "great hall"

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
    // The requirements for the village card are:
    //1.	Current player should receive exactly 1 card.
    printf("TEST 1: Current player should receive exactly 1 card.\n");
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //2.	1 card should come from the player’s own pile.
    printf("TEST 2: 1 card should come from the player’s own pile.\n");
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //3.	No state change should occur for other players.
    printf("TEST 3: No state change should occur for other players.\n");
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //4.	No state change should occur to the victory card piles and kingdom card piles.
    printf("TEST 4: No state change should occur to the victory card piles and kingdom card piles.\n");
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //5.	Current player receives 2 additional actions.
    printf("TEST 5: Current player receives 2 additional actions.\n");
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    // Call Great Hall using cardEffect()
    testResult = cardEffect(k[9], k[0], k[1], k[2], struct gameState * G, handPos, &bonus);

    printf("\n >>>>> SUCCESS: Testing complete %s <<<<<\n\n", TESTCARD);

    return 0;
}