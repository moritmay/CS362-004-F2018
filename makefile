CFLAGS= -Wall -fpic -coverage -lm -std=c99

testme.o: testme.c
	gcc -c testme.c -g $(CFLAGS)

testme: testme.o
	gcc -o testme testme.c -g $(CFLAGS)

clean:
	rm -f *.o testme.gcno testme
