//This will test buycard
#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <math.h>
#include <assert.h>

int main() {
	struct gameState game_test;
	int i;
	int player = 1;
	int retval = 0;
	int k[10] = { adventurer, gardens, embargo, village, minion, mine, cutpurse,
		sea_hag, tribute, smithy };
	int seed = time(NULL);

	printf("Initializing game...\n");
	//initialize game
	retval = initializeGame(2, k, seed, &game_test);
	assert(retval == 0);
	printf("Initialization Complete...\n");
	printf("#################################################\n\n");

	assert(retval == 0);

	game_test.coins = 5;
	game_test.numBuys = 2;

	printf("Test 1: Handling of bad value\n");
	//Fail
	retval = buyCard(-2, &game_test);
	assert(retval == -1);
	if (retval == -1) {
		printf("Test 1 Passed!\n");
	}
	else {
		printf("Test 1 Failed!\n");
	}
	printf("#################################################\n\n");

	printf("Test 2: Valid inputs\n");
	//testing valid inputs
	retval = buyCard(2, &game_test);
	assert(retval == 0);
	if (retval == 0) {
		printf("Test 2 Passed!\n");
	}
	else {
		printf("Test 2 Failed!\n");
	}
	printf("#################################################\n\n");
	printf("Exit Unit Test 4\n");
	
	return 0;
}