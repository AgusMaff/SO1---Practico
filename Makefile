CFLAGS = -Wall -pedantic -Werror -Wextra -Wconversion -std=gnu11

all: mycat clear

mycat: main.o
	gcc $(CFLAGS) -o mycat main.o

main.o: main.c
	gcc -c main.c main.h

clear:
	rm -f *.o *.h.gch

clean:
	rm -f mycat *.o *.h.gch

