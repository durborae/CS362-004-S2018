#include "dominion.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>
#include <time.h>

#define NUMTESTS 100

int main() {
	struct gameState G;
	int success, fail, x, i;
	success = fail = x = i = 0;
	srand(time(NULL));
	int seed;
	int result, rando = 0, player = 1, handCount, deckCount, good = 0, bad = 0;
	int k[10] = { adventurer, gardens, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy };
	printf("Begin Adventurer Test\n");

	for (x = 0; x < NUMTESTS; x++) {
		int numplayers = rand() % MAX_PLAYERS + 1;
		initializeGame(numplayers, k, seed, &G);
		for (i = 0; i < numplayers; i++) {
			G.deckCount[i] = rand() % MAX_DECK;
			int startdcount = G.deckCount[i];
			G.discardCount[i] = rand() % MAX_DECK;
			int startdccount = G.discardCount[i];
			G.handCount[i] = rand() % MAX_HAND;
			int starthcount = G.handCount[i];
			result = cardEffect(adventurer, 1, 1, 1, &G);

			if (ressult == 0 && G.deckCount[i] < startdcount && startdccount < G.discardCount[i] && starthcount > G.handCount[i]) {
				success++
			}
			else {
				fail++
			}
		}
		
	}
	printf("Success: %d, Failed: %d\n", success, fail);

	return 0;
}