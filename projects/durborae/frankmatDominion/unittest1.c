//This Program will implement a test of the numHandCards function

#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "assert.h"
#include <time.h>

int main() {
	struct gameState game_test;
	srand(time(NULL)); 
	int numPlayers = rand() % 3 + 2;
	int retval = 0;
	int token = 0;
	int randomSeed = rand();
	int k[10] = { adventurer, gardens, embargo, village, minion,
		mine, cutpurse, sea_hag, tribute, smithy };

	printf("#################################################\n\n");
	printf("Initializing game...\n");
	//initialize game
	retval = initializeGame(numPlayers, k, randomSeed, &game_test);
	assert(retval == 0);
	printf("Initialization Complete...\n");
	printf("#################################################\n\n");

	printf("Testing numHandCards...\n");
	printf("#################################################\n\n");

	game_test.whoseTurn = 0;
	retval = numHandCards(&game_test);
	assert(retval == game_test.handCount[0]);
	/*
	if (retval != game_test.handCount[0] && token != 1) {
		token = 1;
		printf("Test numHandCards Failed!\n");
		printf("Expected: 0, Actual:%d\n", retval);
	}
	*/
	game_test.whoseTurn = 3;
	retval = numHandCards(&game_test);
	assert(retval == game_test.handCount[3]);
	/*
	if (retval != game_test.handCount[0]) {
		token = 1;
		printf("Test numHandCards Failed!\n");
		printf("Expected: 3, Actual:%d\n", retval);
	}
	*/
	game_test.whoseTurn = 2;
	retval = numHandCards(&game_test);
	assert(retval == game_test.handCount[2]);
	/*
	if (retval != game_test.handCount[0]) {
		token = 1;
		printf("Test numHandCards Failed!\n");
		printf("Expected: 2, Actual:%d\n", retval);
	}
	*/
	game_test.whoseTurn = 1;
	retval = numHandCards(&game_test);
	assert(retval == game_test.handCount[1]);
	/*
	if (retval != game_test.handCount[0]) {
		token = 1;
		printf("Test numHandCards Failed!\n");
		printf("Expected: 1, Actual:%d\n", retval);
	}

	if (token == 0) {
		printf("Test numHandCards Passed!\n");
	}
	*/
	printf("Testing numHandCards Complete\n");
	printf("#################################################\n\n");

	return 0;
}
