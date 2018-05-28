#include "dominion.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>
#include <time.h>

#define NUMTESTS 10000

int main() {
	struct gameState G;
	int success, fail, x, i, token;
	success = fail = x = i = token = 0;
	//srand(time(NULL));
	int seed = time(NULL);
	int result = 0, cond1 = 0, cond2 = 0, cond3 = 0, cond4 = 0;
	int k[10] = { adventurer, gardens, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy };
	printf("Begin Adventurer Test\n");

	for (x = 0; x < NUMTESTS; x++) {
		//printf("Turn: %d\n", x);
		int numplayers = rand() % MAX_PLAYERS + 1;
		for (i = 0; i < numplayers; i++) {
			int currplayer = whoseTurn(&G);
			initializeGame(numplayers, k, seed, &G);
			G.deckCount[i] = rand() % MAX_DECK;
			int startdcount = G.deckCount[i];
			G.discardCount[i] = rand() % MAX_DECK;
			int startdccount = G.discardCount[i];
			G.handCount[i] = rand() % MAX_HAND;
			int starthcount = G.handCount[i];
			//printf("before\n");
			G.hand[currplayer][0] = adventurer;//put adventurer in hand
			
			int randomnum = rand() % 100;
			if (randomnum >= 0 && randomnum < 5) {
				G.deckCount[i] = 0;
			}
			else if (randomnum >= 5 && randomnum < 10) {
				G.handCount[i] = 0;
			}
			else if (randomnum >= 10 && randomnum < 15) {
				G.numActions = 0;
			}

			result = playCard(0, 0, 0, 0, &G);
			//printf("after\n");
			
			if (result != 0) {
				token = 1;
				//printf("cond1\n");
				//printf("%d\n", result);
				cond1++;
			}
			if (G.deckCount[i] > startdcount) {
				token = 1;
				//printf("cond2\n");
				cond2++;
			}
			if (startdccount < G.discardCount[i]) {
				token = 1;
				//printf("cond3\n");
				cond3++;
			}
			if(starthcount > G.handCount[i]){
				token = 1;
				//printf("cond4\n");
				cond4++;
			}
			//printf("Token: %d\n", token);
			if (token == 0) {
				//printf("A\n");
				success++;
			}
			else {
				//printf("B\n");
				fail++;
			}
			token = 0;//reset token
		}
		
	}
	printf("Success: %d, Failed: %d\n", success, fail);
	printf("Cond 1: %d, Cond2: %d, Cond3 %d, Cond4 %d\n", cond1, cond2, cond3, cond4);

	return 0;
}
