CFLAGS = -Wall -fpic -coverage -lm

rngs.o: rngs.h rngs.c
	gcc -c rngs.c -g  $(CFLAGS)

dominion.o: dominion.h dominion.c rngs.o
	gcc -c dominion.c -g  $(CFLAGS)

playdom: dominion.o playdom.c
	gcc -o playdom playdom.c -g dominion.o rngs.o $(CFLAGS)
#To run playdom you need to entere: ./playdom <any integer number> like ./playdom 10*/
testDrawCard: testDrawCard.c dominion.o rngs.o
	gcc  -o testDrawCard -g  testDrawCard.c dominion.o rngs.o $(CFLAGS)

badTestDrawCard: badTestDrawCard.c dominion.o rngs.o
	gcc -o badTestDrawCard -g  badTestDrawCard.c dominion.o rngs.o $(CFLAGS)

testBuyCard: testDrawCard.c dominion.o rngs.o
	gcc -o testDrawCard -g  testDrawCard.c dominion.o rngs.o $(CFLAGS)

testAll: dominion.o testSuite.c
	gcc -o testSuite testSuite.c -g  dominion.o rngs.o $(CFLAGS)

interface.o: interface.h interface.c
	gcc -c interface.c -g  $(CFLAGS)

unit1:
	gcc -fprofile-arcs -ftest-coverage -Wall -std=c99 dominion.c unittest1.c rngs.c -o unittest1 -lm -g

unit2:
	gcc -fprofile-arcs -ftest-coverage -Wall -std=c99 dominion.c unittest2.c rngs.c -o unittest2 -lm -g

unit3:
	gcc -fprofile-arcs -ftest-coverage -Wall -std=c99 dominion.c unittest3.c rngs.c -o unittest3 -lm -g

unit4:
	gcc -fprofile-arcs -ftest-coverage -Wall -std=c99 dominion.c unittest4.c rngs.c -o unittest4 -lm -g

card1:
	gcc -fprofile-arcs -ftest-coverage -Wall -std=c99 dominion.c cardtest1.c rngs.c -o cardtest1 -lm -g

card2:
	gcc -fprofile-arcs -ftest-coverage -Wall -std=c99 dominion.c cardtest2.c rngs.c -o cardtest2 -lm -g

card3:
	gcc -fprofile-arcs -ftest-coverage -Wall -std=c99 dominion.c cardtest3.c rngs.c -o cardtest3 -lm -g

card4:
	gcc -fprofile-arcs -ftest-coverage -Wall -std=c99 dominion.c cardtest4.c rngs.c -o cardtest4 -lm -g

radvtest:
	gcc -fprofile-arcs -ftest-coverage -Wall -std=c99 dominion.c randomtestadventurer.c rngs.c -o randomtestadventurer -lm -g

randtest1:
	gcc -fprofile-arcs -ftest-coverage -Wall -std=c99 dominion.c randomtestcard1.c rngs.c -o randomtestcard1 -lm -g

randtest2:
	gcc -fprofile-arcs -ftest-coverage -Wall -std=c99 dominion.c randomtestcard2.c rngs.c -o randomtestcard2 -lm -g

runtests: testDrawCard 
	./testDrawCard &> unittestresult.out
	./unittest1 &> unittestresult.out
	gcov unittest1.c -b >> unittestresult.out
	./unittest2 >> unittestresult.out
	gcov unittest2.c -b >> unittestresult.out
	./unittest3 >> unittestresult.out
	gcov unittest3.c -b >> unittestresult.out
	./unittest4 >> unittestresult.out
	gcov unittest4.c -b >> unittestresult.out
	./cardtest1 >> unittestresult.out
	gcov cardtest1.c -b >> unittestresult.out
	./cardtest2 >> unittestresult.out
	gcov cardtest2.c -b >> unittestresult.out
	./cardtest3 >> unittestresult.out
	gcov cardtest3.c -b >> unittestresult.out
	./cardtest4 >> unittestresult.out
	gcov cardtest4.c -b >> unittestresult.out
##	gcov dominion.c -b>> unittestresult.out
##	cat dominion.c.gcov >> unittestresult.out
	./randomtestadventurer &> randomtestadventurer.out
	./randomtestcard1 &> randomtestcard1.out
	./randomtestcard2 &> randomtestcard2.out
	gcov randomtestadventurer -b >> randomtestadventurer.out
	cat randomtestadventurer.c.gcov >> randomtestadventurer.out
	gcov randomtestcard1 -b >> randomtestcard1.out
	cat randomtestcard1.c.gcov >> randomtestcard1.out
	gcov randomtestcard2 -b >> randomtestcard2.out
	cat randomtestcard2.c.gcov >> randomtestcard2.out



player: player.c interface.o
	gcc -o player player.c -g  dominion.o rngs.o interface.o $(CFLAGS)

all: playdom player 

clean:
	rm -f *.o playdom.exe playdom player player.exe  *.gcov *.gcda *.gcno *.so *.out testDrawCard testDrawCard.exe
