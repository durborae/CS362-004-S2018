

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
	int currentdeck = 0;
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
	printf("Testing Card: Adventurer...\n");

	//preserve game state
	actioncount = game_test.numActions;
	cardcount = numHandCards(&game_test);
	currentdeck = fullDeckCount(game_test.whoseTurn, 0, &game_test);

	//put Adventurer into hand and play
	game_test.hand[0][0] = adventurer;
	retval = playCard(0, 0, 0, 0, &game_test);
	assert(retval != -1);

	//check new status
	int newcards = numHandCards(&game_test);
	//assert(newcards == (cardcount + 1)); //add one after playing one for net one
	if (newcards != (cardcount + 1)) {
		printf("Test Adventurer Failed! No net gain in cards in hand\n");
		token = 1;
	}

	//Check action count
	int newaction = game_test.numActions;
	//assert(newaction == (actioncount - 1));
	if (newaction != (actioncount - 1) && token != 1) {
		printf("Test Adventurer Failed! No loss in Action\n");
		token = 1;
	}

	int newdecksize = fullDeckCount(game_test.whoseTurn, 0, &game_test);
	//assert(currentdeck > newdecksize);
	if (currentdeck <= newdecksize) {
		printf("Test Adventurer Failed! No Net Loss in Deck Size\n");
		token = 1;
	}

	if (token == 0) {
		printf("Test Adventurer Passed!\n");
	}
	printf("#################################################\n\n");

	return 0;
}