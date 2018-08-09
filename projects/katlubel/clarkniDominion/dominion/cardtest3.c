// Card test 3 - village
// Source: cardtest4.c
// Updated card test to test team member's code
// Village was not refactored in that code, so this test remains as written
/*
The requirements for the great hall card are:
1.	Current player should receive exactly 1 card.
2.	1 card should come from the player’s own pile.
3.	No state change should occur for other players.
4.	No state change should occur to the kingdom card piles.
5.	Current player receives 1 additional action. 
*/

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"

#define TESTCARD "village"

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
    int otherPlayer = 1;
    int increaseActions = 2;
    struct gameState G, testG;
    int k[10] = {adventurer, embargo, village, minion, cutpurse,
                 sea_hag, tribute, smithy, council_room, great_hall};

    // initialize a game state and player cards
    initializeGame(numPlayers, k, seed, &G);

    printf("----------------- Testing Card: %s ----------------\n", TESTCARD);

    // int cardEffect(int card, int choice1, int choice2, int choice3, struct gameState *state, int handPos, int *bonus
    // use_village(currentPlayer, state, handPos);

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    // The requirements for the great hall card are:
    //1.	Current player should receive exactly 1 card - expect hand count to increase
    printf("TEST 1: Current player should receive exactly 1 card.\n");
    // initialize a game state and player cards
    initializeGame(numPlayers, k, seed, &G);

    // copy the game state to a test case
	memcpy(&testG, &G, sizeof(struct gameState));
	choice1 = 1;
	cardEffect(village, choice1, choice2, choice3, &testG, handpos, &bonus);

    newCards = 1;
	xtraCoins = 0;
	printf("hand count = %d, expected = %d\n", testG.handCount[thisPlayer], G.handCount[thisPlayer] + newCards - discarded);
	printf("deck count = %d, expected = %d\n", testG.deckCount[thisPlayer], G.deckCount[thisPlayer] - newCards + shuffledCards);
	if(!(testG.handCount[thisPlayer] == G.handCount[thisPlayer] + newCards - discarded)){printf("hand count failed\n");}
	if(!(testG.deckCount[thisPlayer] == G.deckCount[thisPlayer] - newCards + shuffledCards)){printf("deck count failed\n");}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //2.	1 card should come from the player’s own pile - expect deck count to decrease
    printf("TEST 2: 1 card should come from the player’s own pile\n");
    // initialize a game state and player cards
    initializeGame(numPlayers, k, seed, &G);

    // copy the game state to a test case
	memcpy(&testG, &G, sizeof(struct gameState));
	choice1 = 1;
	cardEffect(village, choice1, choice2, choice3, &testG, handpos, &bonus);

	newCards = 1;
	xtraCoins = 0;
	printf("hand count = %d, expected = %d\n", testG.handCount[thisPlayer], G.handCount[thisPlayer] + newCards - discarded);
	printf("deck count = %d, expected = %d\n", testG.deckCount[thisPlayer], G.deckCount[thisPlayer] - newCards + shuffledCards);
	if(!(testG.handCount[thisPlayer] == G.handCount[thisPlayer] + newCards - discarded)){printf("hand count failed\n");}
	if(!(testG.deckCount[thisPlayer] == G.deckCount[thisPlayer] - newCards + shuffledCards)){printf("deck count failed\n");}
    memset(&G, 23, sizeof(struct gameState));   // clear the game state
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //3.	No state change should occur for other players.
    printf("TEST 3: No state change should occur for other players.\n");
    // initialize a game state and player cards
    initializeGame(numPlayers, k, seed, &G);

    // copy the game state to a test case
	memcpy(&testG, &G, sizeof(struct gameState));
	choice1 = 1;
	cardEffect(village, choice1, choice2, choice3, &testG, handpos, &bonus);

    printf("hand count = %d, expected = %d\n", testG.handCount[otherPlayer], G.handCount[otherPlayer]);
	printf("deck count = %d, expected = %d\n", testG.deckCount[otherPlayer], G.deckCount[otherPlayer]);
	if(!(testG.handCount[otherPlayer] == G.handCount[otherPlayer])){printf("hand count failed\n");}
	if(!(testG.deckCount[otherPlayer] == G.deckCount[otherPlayer])){printf("deck count failed\n");}
    memset(&G, 23, sizeof(struct gameState));   // clear the game state
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //4.	No state change should occur to the kingdom card piles - victory cards are estate, duchy, and province
    printf("TEST 4: No state change should occur to the kingdom card piles.\n");
    // initialize a game state and player cards
    initializeGame(numPlayers, k, seed, &G);

    // copy the game state to a test case
	memcpy(&testG, &G, sizeof(struct gameState));
	choice1 = 1;
	cardEffect(village, choice1, choice2, choice3, &testG, handpos, &bonus);

    // test the kingdom cards
    printf("Test the kingdom cards\n");
    j = 0;
    for(j = 0; j < 10; j++){
        if(testG.supplyCount[k[j]] != G.supplyCount[k[j]]) printf("Supply count for card %d failed\n", j);
    }

    // test the victory cards - since we have two players, there should be 8 of each victory card
    printf("there should be 8 of each victory card - estate, duchy, and province\n");
    if(!(testG.supplyCount[estate] == G.supplyCount[estate])){printf("supply count estate failed\n");}
    if(!(testG.supplyCount[duchy] == G.supplyCount[duchy])){printf("supply count duchy failed\n");}
    if(!(testG.supplyCount[province] == G.supplyCount[province])){printf("supply count province failed\n");}
    memset(&G, 23, sizeof(struct gameState));   // clear the game state
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //5.	Current player receives 1 additional action.
    printf("TEST 5: Current player receives 1 additional action.\n");
    // initialize a game state and player cards
    initializeGame(numPlayers, k, seed, &G);

    // copy the game state to a test case
	memcpy(&testG, &G, sizeof(struct gameState));
	choice1 = 1;
	cardEffect(village, choice1, choice2, choice3, &testG, handpos, &bonus);

    printf("actions = %d, expected = %d\n", testG.numActions, G.numActions + increaseActions);
	if(testG.numActions != G.numActions + increaseActions) printf("Num actions failed\n");
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    printf("\n >>>>> SUCCESS: Testing complete %s <<<<<\n\n", TESTCARD);

    return 0;
}