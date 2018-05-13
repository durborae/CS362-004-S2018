#include "dominion.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>
#include <time.h>

#define NUMTESTS 100000

int main() {
	srand(time(NULL));
	struct gameState game_test;
	int retval = 0;
	int actioncount = 0, i = 0, success = 0, fail = 0, x = 0;
	int cardcount = 0;
	int k[10] = { adventurer, gardens, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy };
	int seed = time(NULL);
	int token = 0;

	for (x = 0; x < NUMTESTS; x++) {
		int numplayers = rand() % MAX_PLAYERS + 1;
		for (i = 0; i < numplayers; i++) {
			initializeGame(numplayers, k, seed, &game_test);
			int currplayer = whoseTurn(&game_test);
			actioncount = game_test.numActions;
			cardcount = numHandCards(&game_test);

			//put great hall into hand and play
			game_test.hand[currplayer][0] = great_hall;

			int randomnum = rand() % 100;
			if (randomnum >= 0 && randomnum < 5) {
				game_test.deckCount[i] = 0;
			}
			else if (randomnum >= 5 && randomnum < 10) {
				game_test.handCount[i] = 0;
			}
			else if (randomnum >= 10 && randomnum < 15) {
				game_test.numActions = 0;
			}

			retval = playCard(0, 0, 0, 0, &game_test);

			if (retval != 0) {
				printf("failed cond 1\n");
				token = 1;
			}

			int newactioncount = game_test.numActions;
			int newcardcount = numHandCards(&game_test);

			if (newactioncount != (actioncount + 1)) {
				token = 1;
//				printf("Failed Cond 2\n");
//				printf("New Actions: %d, Original Actions: %d\n", newactioncount, actioncount);
			}

			if (newcardcount != (cardcount-1)) {
//				printf("failed cond 3\n");
//				printf("New card count: %d, Original Card Count: %d\n", newcardcount, cardcount);
				token = 1;
			}

			if (token == 0) {
				success++;
			}
			else {
				fail++;
			}
			token = 0;//reset token
		}

	}
	printf("Success: %d, Failed: %d\n", success, fail);

	return 0;
}
