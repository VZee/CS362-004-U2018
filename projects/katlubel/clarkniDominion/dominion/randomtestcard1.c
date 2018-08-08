// Author: Louisa Katlubeck
// Description: Random test for Great Hall card
// Updated card test to test team member's code
// Great_hall was not refactored in that code, so this test remains as written

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
#include <time.h>
#include "rngs.h"

#define TESTCARD "great hall"

int main()
{
    srand(time(NULL));

    // start the timer
    clock_t before = clock();
    
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
        int increaseActions = 1;

        int i, j, m, z;
        int handpos = 0, choice1 = 0, choice2 = 0, choice3 = 0, bonus = 0;
        int remove1, remove2;
        int seed = 1000;

        // get a random number of players between two and 5
        int numPlayers = rand() % 5 + 1;
        int thisPlayer = 0;
        int otherPlayer; // all the other players

        struct gameState G, testG;
        int nextNum;

        int cards[22] = {estate, duchy, province, adventurer, council_room,
            feast, gardens, mine, remodel, smithy, village, baron,
            minion, steward, tribute, ambassador, cutpurse, embargo, outpost,
            salvager, sea_hag, treasure_map};
        
        int k[10];
        k[0] = great_hall;

        // set up the deck
        for(z = 1; z < 10; z++){
            // get the next card
            nextNum = rand() % 22;

            // check to make sure that card is valid
            while(cards[nextNum] == 0){
                nextNum = rand() % 22;
            }

            // add that card to the deck
            k[z] = cards[nextNum];

            // and set that card equal to 0
            cards[nextNum] = 0;
        }

        // initialize a game state and player cards
        initializeGame(numPlayers, k, seed, &G);

        // int cardEffect(int card, int choice1, int choice2, int choice3, struct gameState *state, int handPos, int *bonus
        // use_great_hall(currentPlayer, state, handPos);

        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        // The requirements for the village card are:
        //1.	Current player should receive exactly 1 card - expect hand count to increase
        //printf("TEST 1: Current player should receive exactly 1 card.\n");
        // initialize a game state and player cards
        initializeGame(numPlayers, k, seed, &G);

        // copy the game state to a test case
        memcpy(&testG, &G, sizeof(struct gameState));
        choice1 = 1;
        cardEffect(great_hall, choice1, choice2, choice3, &testG, handpos, &bonus);
        newCards = 1;
        xtraCoins = 0;

        //printf("hand count = %d, expected = %d\n", testG.handCount[thisPlayer], G.handCount[thisPlayer] + newCards - discarded);
        //printf("deck count = %d, expected = %d\n", testG.deckCount[thisPlayer], G.deckCount[thisPlayer] - newCards + shuffledCards);
        if (!(testG.handCount[thisPlayer] == G.handCount[thisPlayer] + newCards - discarded))
        {
            printf("hand count failed - test 1\n");
        }
        if (!(testG.deckCount[thisPlayer] == G.deckCount[thisPlayer] - newCards + shuffledCards))
        {
            printf("deck count failed - test 1\n");
        }
        
        //memset(&G, 23, sizeof(struct gameState)); // clear the game state
                                                  ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        //2.	1 card should come from the player’s own pile. - expect deck count to decrease
        //printf("TEST 2: 1 card should come from the player’s own pile.\n");
        // initialize a game state and player cards
        initializeGame(numPlayers, k, seed, &G);

        // copy the game state to a test case
        memcpy(&testG, &G, sizeof(struct gameState));
        choice1 = 1;
        cardEffect(great_hall, choice1, choice2, choice3, &testG, handpos, &bonus);
        newCards = 1;
        xtraCoins = 0;

        //printf("hand count = %d, expected = %d\n", testG.handCount[thisPlayer], G.handCount[thisPlayer] + newCards - discarded);
        //printf("deck count = %d, expected = %d\n", testG.deckCount[thisPlayer], G.deckCount[thisPlayer] - newCards + shuffledCards);
        if (!(testG.handCount[thisPlayer] == G.handCount[thisPlayer] + newCards - discarded))
        {
            printf("hand count failed - test 2\n");
        }
        if (!(testG.deckCount[thisPlayer] == G.deckCount[thisPlayer] - newCards + shuffledCards))
        {
            printf("deck count failed - test 2\n");
        }
        //memset(&G, 23, sizeof(struct gameState)); // clear the game state
        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        //3.	No state change should occur for other players - expect hand count and deck count to remain the same
        //printf("TEST 3: No state change should occur for other players.\n");
        // initialize a game state and player cards
        initializeGame(numPlayers, k, seed, &G);

        // copy the game state to a test case
        memcpy(&testG, &G, sizeof(struct gameState));
        choice1 = 1;
        cardEffect(great_hall, choice1, choice2, choice3, &testG, handpos, &bonus);

        //printf("hand count = %d, expected = %d\n", testG.handCount[otherPlayer], G.handCount[otherPlayer]);
        //printf("deck count = %d, expected = %d\n", testG.deckCount[otherPlayer], G.deckCount[otherPlayer]);
        for (z = 1; z < numPlayers; z++)
        {
            if (!(testG.handCount[z] == G.handCount[z]))
            {
                printf("hand count failed for player %d\n", z);
            }
            if (!(testG.deckCount[z] == G.deckCount[z]))
            {
                printf("deck count failed for player %d\n", z);
            }
        }
        //memset(&G, 23, sizeof(struct gameState)); // clear the game state
        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        //4.	No state change should occur to the victory card piles and kingdom card piles - victory cards are estate, duchy, and province
        //printf("TEST 4: No state change should occur to the victory card piles and kingdom card piles.\n");
        // initialize a game state and player cards
        initializeGame(numPlayers, k, seed, &G);

        // copy the game state to a test case
        memcpy(&testG, &G, sizeof(struct gameState));
        choice1 = 1;
        cardEffect(great_hall, choice1, choice2, choice3, &testG, handpos, &bonus);

        // test the kingdom cards
        j = 0;
        for (j = 0; j < 10; j++)
        {
            if(testG.supplyCount[k[j]] != G.supplyCount[k[j]]) printf("Kingdom supply count failed\n");
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
        //memset(&G, 23, sizeof(struct gameState)); // clear the game state
        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        //5.	Current player receives 2 additional actions.
        //printf("TEST 5: Current player receives 2 additional actions.\n");
        // initialize a game state and player cards
        initializeGame(numPlayers, k, seed, &G);

        // copy the game state to a test case
        memcpy(&testG, &G, sizeof(struct gameState));
        choice1 = 1;
        cardEffect(great_hall, choice1, choice2, choice3, &testG, handpos, &bonus);

        //printf("actions = %d, expected = %d\n", testG.numActions, G.numActions + increaseActions);
        if (!(testG.numActions == G.numActions + increaseActions))
        {
            printf("num actions failed\n");
        }
        //memset(&G, 23, sizeof(struct gameState)); // clear the game state
        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    }
    printf("\n >>>>> SUCCESS: Testing complete %s <<<<<\n\n", TESTCARD);

    // stop the timer
    clock_t stop_time = clock() - before;

    double total_time = ((double)stop_time)/CLOCKS_PER_SEC;

    // print the time
    printf("The program took %f ns to run\n", 1000000.*total_time);

    return 0;
}
