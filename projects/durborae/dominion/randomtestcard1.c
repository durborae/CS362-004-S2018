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
	int success, fail, x, i, token;
	success = fail = x = i = token = 0;
	//srand(time(NULL));
	int seed = time(NULL);
	int retval, actioncount, cardcount;
	int k[10] = { adventurer, gardens, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy };

	for (x = 0; x < NUMTESTS; x++) {
		int numplayers = rand() % MAX_PLAYERS + 1;
		for (i = 0; i < numplayers; i++) {
			initializeGame(numplayers, k, seed, &game_test);
			int currplayer = whoseTurn(&game_test);
			actioncount = game_test.numActions;
			cardcount = numHandCards(&game_test);

			//preserve game state
			actioncount = game_test.numActions;
			cardcount = numHandCards(&game_test);

			//put Smithy into hand and play
			game_test.hand[currplayer][0] = smithy;

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
			if (retval == -1) {
				token = 1;
				//printf("Failed cond 1\n");
			}

			//check new status
			int newcards = numHandCards(&game_test);
			//assert(newcards == (cardcount - 2)); //add 3 after playing one for net 2
			if ((newcards - 2) != cardcount ) {
				token = 1;
				//printf("Failed cond 2\n");
			}

			//Check action count
			int newaction = game_test.numActions;
			//assert(newaction == (actioncount - 1));
			if (newaction != actioncount) {
				token = 1;
				//printf("Failed cond 3\n");
				//printf("NewAction: %d AcountCount: %d\n", newaction, actioncount);
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
