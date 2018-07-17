// Card test 2 - adventurer
// Source: cardtest4.c
/*
The requirements for the adventurer card are:
1.	Current player reveals cards until they find two treasure cards. 
2.	The two treasure cards are placed in the player’s hand.
3.	The cards should come from the player’s own pile.
4.	If the player has to shuffle their discard pile and after shuffling and revealing the shuffled deck has less than two treasure cards, their turn is over.
5.	No state change should occur for other players.
6.	The other revealed cards are discarded.
7.	No state change should occur to the victory card piles and kingdom card piles. 
*/

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"

// set NOISY_TEST to 0 to remove printfs from output
#define NOISY_TEST 1

#define TESTCARD "adventurer"

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
    // The requirements for the adventurer card are:
    //1.	Current player reveals cards until they find two treasure cards.
    printf("TEST 1: Current player reveals cards until they find two treasure cards.\n");
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //2.	The two treasure cards are placed in the player’s hand.
    printf("TEST 2: The two treasure cards are placed in the player’s hand\n");
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //3.	The cards should come from the player’s own pile.
    printf("TEST 3: The cards should come from the player’s own pile.\n");
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //4.	If the player has to shuffle their discard pile and after shuffling and revealing the shuffled deck has less than two treasure cards, their turn is over.
    printf("TEST 4: If the player has to shuffle their discard pile and after shuffling and revealing the shuffled deck has less than two treasure cards, their turn is over.\n");
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //5.	No state change should occur for other players.
    printf("TEST 5: No state change should occur for other players\n");
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //6.	The other revealed cards are discarded.
    printf("TEST 6: The other revealed cards are discarded\n");
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //7.	No state change should occur to the victory card piles and kingdom card piles.
    printf("TEST 7: No state change should occur to the victory card piles and kingdom card piles\n");
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    // Call Adventurer using cardEffect()
    testResult = cardEffect(k[0], k[1], k[2], k[3], struct gameState * G, int handPos, *bonus);

    printf("\n >>>>> SUCCESS: Testing complete %s <<<<<\n\n", TESTCARD);

    return 0;
}