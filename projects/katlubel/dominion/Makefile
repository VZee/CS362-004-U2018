CFLAGS = -Wall -fpic -coverage -lm -std=c99
rngs.o:
	gcc -c rngs.c -g  $(CFLAGS)

dominion.o:
	gcc -c dominion.c -g  $(CFLAGS)
	
default: randomtestsresults.out

# tests

randomtestcard1:
	gcc -o randomtestcard1 randomtestcard1.c -g dominion.o rngs.o $(CFLAGS)
	echo "randomtestcard1.c:" >> randomtestsresults.out
	./randomtestcard1 >> randomtestsresults.out
	gcov dominion.c >> randomtestsresults.out
	cat dominion.c.gcov >> randomtestsresults.out
	
randomtestcard2:
	gcc -o randomtestcard2 randomtestcard2.c -g dominion.o rngs.o $(CFLAGS)
	echo "randomtestcard2.c:" >> randomtestsresults.out
	./randomtestcard2 >> randomtestsresults.out
	gcov dominion.c >> randomtestsresults.out
	cat dominion.c.gcov >> randomtestsresults.out
	
randomtestadventurer:
	gcc -o randomtestadventurer randomtestadventurer.c -g dominion.o rngs.o $(CFLAGS)
	echo "randomtestadventurer.c:" >> randomtestsresults.out
	./randomtestadventurer >> randomtestsresults.out
	gcov dominion.c >> randomtestsresults.out
	cat dominion.c.gcov >> randomtestsresults.out
	

randomtestsresults: cleanall rngs.o dominion.o randomtestcard1 randomtestcard2 randomtestadventurer

clean:
	rm randomtestsresults.out

cleanall: 
	rm -f *.o randomtestsresults.out randomtestcard1 randomtestcard2 randomtestadventurer *.gcda *.gcno *.gcov