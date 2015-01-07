CC=gcc
CFLAGS=-Wall -std=c99 -O3
OBJ1=main.o hash.o corpus.o correct.o

spellCheck: $(OBJ1)
	$(CC) $(CFLAGS) -o spellCheck $(OBJ1)

$(OBJ1): hash.h corpus.h correct.h

clean:
	rm -fv $(OBJ1) spellCheck
