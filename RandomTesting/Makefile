CFLAGS = -Wall -fpic -coverage -lm -std=c99
	
default: results.out

testme:
	gcc -o testme testme.c -g $(CFLAGS)
	./testme >> results.out
	gcov testme.c >> results.out
	cat testme.c.gcov >> results.out
	
results: cleanall testme 

clean:
	rm results.out

cleanall: 
	rm -f *.o results.out testme *.gcda *.gcno *.gcov