//This Program will implement a test of the isgameover function
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

	printf("Begin Unit Test 2\n");
	printf("Initializing game...\n");
	//initialize game
	retval = initializeGame(2, k, seed, &game_test);
	assert(retval == 0);
	printf("Initialization Complete...\n");
	printf("#################################################\n\n");

	printf("isgameover test 1: Game Ends by Running Out of Province Cards\n");
	game_test.supplyCount[province] = 0;//setting it to win criteria
	retval = isGameOver(&game_test);

	if (retval == 1) {
		printf("Test 1 Passed!\n");
	}
	else {
		printf("Test 1 Failed!\n");
	}
	
	retval = 0;
	printf("#################################################\n\n");

	//Initializing three supply stacks to 0
	game_test.supplyCount[0] = game_test.supplyCount[1] = game_test.supplyCount[24] = 0;
	printf("isgameover test 2: Game Ends By Running Out of Supply Cards in Three Stacks\n");
	retval = isGameOver(&game_test);
	if (retval == 1) {
		printf("Test 2 Passed!\n");
	}
	else {
		printf("Test 2 Failed!\n");
	}
	retval = 0;
	printf("#################################################\n\n");

	game_test.supplyCount[1] = -1;
	printf("Test 4: Game Ends By Running Out of Supply Cards in Three Stacks but with one outside of range\n");
	retval = isGameOver(&game_test);
	if (retval != 1) {
		printf("Test 4 Passed!\n");
	}
	else {
		printf("Test 4 Failed!\n");
	}
	retval = 0;
	game_test.supplyCount[0] = game_test.supplyCount[1] = game_test.supplyCount[24] = 3;
	printf("#################################################\n\n");
	printf("Exit Unit Test 2\n");

	return 0;
}