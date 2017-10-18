all:bstsystem

CFLAGS=-g -O3

bstsystem: bst.o bstsystem.o
	cc -o $@ $^

bst.o: bst.c bst.h
	cc -c $(CFLAGS) bst.c

bstsystem.o: bstsystem.c bst.c
	cc -c $(CFLAGS) bstsystem.c

clean:
	rm -f *.o bstsystem

demo: bstsystem
	(echo first; echo "second line"; echo "third and last") | ./bstsystem
