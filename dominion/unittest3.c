//This Program will implement a test of the getcost function

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
	int retval = -1;
	int player = 1;
	int token = 0;
	int testlist[27] = { curse, estate, duchy, province, copper, silver, gold, adventurer, council_room, feast,
		gardens, mine, remodel, smithy, village, baron, great_hall, minion, steward, tribute, ambassador, cutpurse,
		embargo, outpost, salvager, sea_hag, treasure_map };
	int known_results[27] = { 0, 2, 5, 8, 0, 3, 6, 6, 5, 4, 4, 5, 4,
		4, 3, 4, 3, 5, 3, 5, 3, 4, 2, 5, 4, 4, 4 };

	printf("UT 3 Test 1: Testing valid Card\n");

	for (i = 0; i < 27; i++) {
		retval = getCost(testlist[i]);
		if (known_results[i] != retval && token == 0/*only prints once*/) {
			printf("Test 1 Failed\n");
			token++;
		}
	}
	if (token == 0) {
		printf("Test 1 Passed\n");
	}
	
	printf(" UT3 Test 2: Testing invalid Card\n");
	retval = getCost(-1000);
	assert(retval == -1);
	if (retval == -1) {
		printf("Test 2 Passed!\n");
	}
	else {
		printf("Test 2 Failed!\n");
	}
	printf("#################################################\n\n");
	printf("Exit Unit Test 3\n");

	return 0;
}