CFLAGS = -Wall -fpic -coverage -lm -std=c99

rngs.o:
	gcc -c rngs.c -g  $(CFLAGS)

dominion.o:
	gcc -c dominion.c -g  $(CFLAGS)
	
default: randomtestsresults.out

# tests

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
	
randomtestsresults: cleanall rngs.o dominion.o randomtestcard1 randomtestcard2 randomtestadventurer

clean:
	rm randomtestcard1.out randomtestcard2.out randomtestadventurer.out

cleanall: 
	rm -f *.o randomtestcard1.out randomtestcard2.out randomtestadventurer.out randomtestcard1 randomtestcard2 randomtestadventurer *.gcda *.gcno *.gcov