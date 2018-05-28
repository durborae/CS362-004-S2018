//This Program will implement a test of the Village card

#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "assert.h"

int main() {
	//initialize the pretest stuff
	struct gameState game_test;
	int retval = 0;
	int actioncount = 0;
	int cardcount = 0;
	int k[10] = { adventurer, gardens, embargo, village, minion, mine, cutpurse,
		sea_hag, tribute, smithy };
	int seed = time(NULL);
	int token = 0;

	printf("Initializing game...\n");
	//initialize game
	retval = initializeGame(2, k, seed, &game_test);
	assert(retval == 0);
	printf("Initialization Complete...\n");
	printf("#################################################\n\n");
	printf("Testing Card: Village...\n");

	//preserve game state
	actioncount = game_test.numActions;
	cardcount = numHandCards(&game_test);

	//put Village into hand and play
	game_test.hand[0][0] = village;
	retval = playCard(0, 0, 0, 0, &game_test);
	if (retval == -1) {
		printf("Test Village Failed. Playcard Failed\n");
		token = 1;
	}

	//check new status
	int newcards = numHandCards(&game_test);
	//assert(newcards == cardcount ); //Gain 1 after playing 1 for net 0
	if (newcards != cardcount) {
		printf("Test Village Failed! Card-In-Hand count not as expected\n");
		token = 1;
	}

	//Check action count
	int newaction = game_test.numActions;
	//assert(newaction == (actioncount + 2));
	if (newaction != (actioncount + 1) && token != 1) {
		printf("Test Village Failed! Action Count not as Expected\n");
		token = 1;
	}

	if (token == 0) {
		printf("Test Village Passed!\n");
	}

	return 0;
}