// Author: Louisa Katlubeck
// Description: Random test for adventurer card

// Card test 2 - adventurer
// Source: cardtest4.c
/*
The requirements for the adventurer card are:
1.	Current player reveals cards until they find two treasure cards. 
2.	The two treasure cards are placed in the player’s hand.
3.	The cards should come from the player’s own pile.
4.	No state change should occur for other players.
5.	The other revealed cards are discarded.
6.	No state change should occur to the victory card piles and kingdom card piles. 
*/

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include <time.h>
#include "rngs.h"

#define TESTCARD "adventurer"

int main()
{
    srand(time(NULL));
    int loop = 200;
    int k;

    printf("----------------- Testing Card: %s ----------------\n", TESTCARD);
    // set up the loop
    for (k = 0; k < loop; k++)
    {
        int newCards = 0;
        int discarded = 1;
        int xtraCoins = 0;
        int shuffledCards = 0;

        int i, j, m, z;
        int handpos = 0, choice1 = 0, choice2 = 0, choice3 = 0, bonus = 0;
        int remove1, remove2;
        int seed = 1000;

        int upperNumber = 5;
        int lowerNumber = 2;

        // get a random number of players between two and 5
        int numPlayers = rand() % (upperNumber - lowerNumber) + 1;
        int thisPlayer = 0;
        int otherPlayer;

        struct gameState G, testG;
        int k[10] = {adventurer, embargo, village, minion, cutpurse,
                     sea_hag, tribute, smithy, council_room, great_hall};

        // initialize a game state and player cards
        initializeGame(numPlayers, k, seed, &G);
        // int cardEffect(int card, int choice1, int choice2, int choice3, struct gameState *state, int handPos, int *bonus
        // use_adventurer(drawntreasure, state, currentPlayer, cardDrawn, temphand, z);

        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        // The requirements for the adventurer card are:
        //1.	Current player reveals cards until they find two treasure cards.
        //printf("TEST 1: Current player reveals cards until they find two treasure cards.\n");
        // copy the game state to a test case
        memcpy(&testG, &G, sizeof(struct gameState));
        choice1 = 1;
        cardEffect(adventurer, choice1, choice2, choice3, &testG, handpos, &bonus);
        memset(&G, 23, sizeof(struct gameState)); // clear the game state
                                                  ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        //2.	The treasure cards are placed in the player’s hand. - expect hand count to increase
        //printf("TEST 2: The two treasure cards are placed in the player’s hand\n");
        // initialize a game state and player cards
        initializeGame(numPlayers, k, seed, &G);

        // copy the game state to a test case
        memcpy(&testG, &G, sizeof(struct gameState));
        choice1 = 1;
        cardEffect(adventurer, choice1, choice2, choice3, &testG, handpos, &bonus);

        //printf("hand count = %d, expected = %d\n", testG.handCount[thisPlayer], G.handCount[thisPlayer] + newCards - discarded);
        //printf("deck count = %d, expected = %d\n", testG.deckCount[thisPlayer], G.deckCount[thisPlayer] - newCards + shuffledCards);
        if (!(testG.handCount[thisPlayer] == G.handCount[thisPlayer] + newCards - discarded))
        {
            printf("hand count failed\n");
        }
        if (!(testG.deckCount[thisPlayer] == G.deckCount[thisPlayer] - newCards + shuffledCards))
        {
            printf("deck count failed\n");
        }
        memset(&G, 23, sizeof(struct gameState)); // clear the game state
                                                  ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        //3.	The cards should come from the player’s own pile. - expect deck count to decrease
        //printf("TEST 3: The cards should come from the player’s own pile.\n");
        // initialize a game state and player cards
        initializeGame(numPlayers, k, seed, &G);

        // copy the game state to a test case
        memcpy(&testG, &G, sizeof(struct gameState));
        choice1 = 1;
        cardEffect(adventurer, choice1, choice2, choice3, &testG, handpos, &bonus);

        //printf("hand count = %d, expected = %d\n", testG.handCount[thisPlayer], G.handCount[thisPlayer] + newCards - discarded);
        //printf("deck count = %d, expected = %d\n", testG.deckCount[thisPlayer], G.deckCount[thisPlayer] - newCards + shuffledCards);
        if (!(testG.handCount[thisPlayer] == G.handCount[thisPlayer] + newCards - discarded))
        {
            printf("hand count failed\n");
        }
        if (!(testG.deckCount[thisPlayer] == G.deckCount[thisPlayer] - newCards + shuffledCards))
        {
            printf("deck count failed\n");
        }
        memset(&G, 23, sizeof(struct gameState)); // clear the game state
                                                  ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        //4.	No state change should occur for other players.
        //printf("TEST 4: No state change should occur for other players\n");
        // initialize a game state and player cards
        initializeGame(numPlayers, k, seed, &G);

        // copy the game state to a test case
        memcpy(&testG, &G, sizeof(struct gameState));
        choice1 = 1;
        cardEffect(adventurer, choice1, choice2, choice3, &testG, handpos, &bonus);

        //printf("hand count = %d, expected = %d\n", testG.handCount[otherPlayer], G.handCount[otherPlayer]);
        //printf("deck count = %d, expected = %d\n", testG.deckCount[otherPlayer], G.deckCount[otherPlayer]);
        for (z = 1; z < numPlayers; z++)
        {
            if (!(testG.handCount[z] == G.handCount[z]))
            {
                printf("hand count failed\n");
            }
            if (!(testG.deckCount[z] == G.deckCount[z]))
            {
                printf("deck count failed\n");
            }
        }
        memset(&G, 23, sizeof(struct gameState)); // clear the game state
                                                  ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        //5.	The other revealed cards are discarded. - expect discard count to increase by the number of cards discarded
        //printf("TEST 5: The other revealed cards are discarded\n");
        // initialize a game state and player cards
        initializeGame(numPlayers, k, seed, &G);

        // copy the game state to a test case
        memcpy(&testG, &G, sizeof(struct gameState));
        choice1 = 1;
        cardEffect(adventurer, choice1, choice2, choice3, &testG, handpos, &bonus);

        //printf("discard count = %d, expected = %d\n", testG.discardCount[thisPlayer], G.discardCount[thisPlayer] + discarded);
        if (!(testG.discardCount[thisPlayer] == G.discardCount[thisPlayer] + discarded))
        {
            printf("discard count failed\n");
        }
        memset(&G, 23, sizeof(struct gameState)); // clear the game state
                                                  ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        //6.	No state change should occur to the victory card piles and kingdom card piles - victory cards are estate, duchy, and province
        //printf("TEST 6: No state change should occur to the victory card piles and kingdom card piles\n");
        // initialize a game state and player cards
        initializeGame(numPlayers, k, seed, &G);

        // copy the game state to a test case
        memcpy(&testG, &G, sizeof(struct gameState));
        choice1 = 1;
        cardEffect(adventurer, choice1, choice2, choice3, &testG, handpos, &bonus);

        // test the kingdom cards
        //printf("Test the kingdom cards\n");
        j = 0;
        for (j = 0; j < 10; j++)
        {
            if (testG.supplyCount[k[j]] != G.supplyCount[k[j]])
                printf("Kingdom card failed \n");
        }

        // test the victory cards - since we have two players, there should be 8 of each victory card
        //printf("there should be 8 of each victory card - estate, duchy, and province\n");
        if (!(testG.supplyCount[estate] == G.supplyCount[estate]))
        {
            printf("supply count estate failed\n");
        }
        if (!(testG.supplyCount[duchy] == G.supplyCount[duchy]))
        {
            printf("supply count duchy failed\n");
        }
        if (!(testG.supplyCount[province] == G.supplyCount[province]))
        {
            printf("supply count province failed\n");
        }
        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    }
    printf("\n >>>>> SUCCESS: Testing complete %s <<<<<\n\n", TESTCARD);

    return 0;
}