CFLAGS = -Wall -fpic -coverage -lm -std=c99
rngs.o:
	gcc -c rngs.c -g  $(CFLAGS)

dominion.o:
	gcc -c dominion.c -g  $(CFLAGS)
	
default: unittestresults.out

# tests

unittest1:
	gcc -o unittest1 unittest1.c -g dominion.o rngs.o $(CFLAGS)
	echo "unittest1.c:" >> unittestresults.out
	./unittest1 >> unittestresults.out
	gcov dominion.c >> unittestresults.out
	cat dominion.c.gcov >> unittestresults.out
	
unittest2:
	gcc -o unittest2 unittest2.c -g dominion.o rngs.o $(CFLAGS)
	echo "unittest2.c:" >> unittestresults.out
	./unittest2 >> unittestresults.out
	gcov dominion.c >> unittestresults.out
	cat dominion.c.gcov >> unittestresults.out
	
unittest3:
	gcc -o unittest3 unittest3.c -g dominion.o rngs.o $(CFLAGS)
	echo "unittest3.c:" >> unittestresults.out
	./unittest3 >> unittestresults.out
	gcov dominion.c >> unittestresults.out
	cat dominion.c.gcov >> unittestresults.out
	
unittest4:
	gcc -o unittest4 unittest4.c -g dominion.o rngs.o $(CFLAGS)
	echo "unittest4.c:" >> unittestresults.out
	./unittest4 >> unittestresults.out
	gcov dominion.c >> unittestresults.out
	cat dominion.c.gcov >> unittestresults.out
	
cardtest1:
	gcc -o cardtest1 cardtest1.c -g dominion.o rngs.o $(CFLAGS)
	echo "cardtest1.c:" >> unittestresults.out
	./cardtest1 >> unittestresults.out
	gcov dominion.c >> unittestresults.out
	cat dominion.c.gcov >> unittestresults.out
	
cardtest2:
	gcc -o cardtest2 cardtest2.c -g dominion.o rngs.o $(CFLAGS)
	echo "cardtest2.c:" >> unittestresults.out
	./cardtest2 >> unittestresults.out
	gcov dominion.c >> unittestresults.out
	cat dominion.c.gcov >> unittestresults.out
	
cardtest3:
	gcc -o cardtest3 cardtest3.c -g dominion.o rngs.o $(CFLAGS)
	echo "cardtest3.c:" >> unittestresults.out
	./cardtest3 >> unittestresults.out
	gcov dominion.c >> unittestresults.out
	cat dominion.c.gcov >> unittestresults.out
	
cardtest4:
	gcc -o cardtest4 cardtest4.c -g dominion.o rngs.o $(CFLAGS)
	echo "cardtest4.c:" >> unittestresults.out
	./cardtest4 >> unittestresults.out
	gcov dominion.c >> unittestresults.out
	cat dominion.c.gcov >> unittestresults.out

randomtestcard1:
	gcc -o randomtestcard1 randomtestcard1.c -g dominion.o rngs.o $(CFLAGS)
	echo "randomtestcard1.c:" >> randomtestcard1.out
	./randomtestcard1 >> randomtestcard1.out
	gcov dominion.c >> randomtestcard1.out
	cat dominion.c.gcov >> randomtestcard1.out
	
randomtestcard2:
	gcc -o randomtestcard2 randomtestcard2.c -g dominion.o rngs.o $(CFLAGS)
	echo "randomtestcard2.c:" >> randomtestcard2.out
	./randomtestcard2 >> randomtestcard2.out
	gcov dominion.c >> randomtestcard2.out
	cat dominion.c.gcov >> randomtestcard2.out
	
randomtestadventurer:
	gcc -o randomtestadventurer randomtestadventurer.c -g dominion.o rngs.o $(CFLAGS)
	echo "randomtestadventurer.c:" >> randomtestadventurer.out
	./randomtestadventurer >> randomtestadventurer.out
	gcov dominion.c >> randomtestadventurer.out
	cat dominion.c.gcov >> randomtestadventurer.out

unittestresults: cleanall rngs.o dominion.o unittest1 unittest2 unittest3 unittest4 cardtest1 cardtest2 cardtest3 cardtest4 randomtestcard1 randomtestcard2 randomtestadventurer

cleanall: 
	rm -f *.o unittestresults.out randomtestcard1.out randomtestcard2.out randomtestadventurer.out unittest1 unittest2 unittest3 unittest4 cardtest1 cardtest2 cardtest3 cardtest4 *.gcda *.gcno *.gcov