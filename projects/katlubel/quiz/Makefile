CFLAGS = -Wall -lm -std=c99
	
testme: testme.c
	gcc -o testme testme.c $(CFLAGS)

results: testme 
	./testme

clean:
	rm -f *.o testme.exe testme