CFLAGS = -Wall -pedantic -Werror -Wextra -Wconversion -std=gnu11

all: mycat clear

mycat: main.o mycat.o
	gcc $(CFLAGS) -o mycat main.o mycat.o

main.o: main.c mycat.h
	gcc -c main.c mycat.h

mycat.o: mycat.c mycat.h
	gcc -c mycat.c mycat.h

clear:
	rm -f *.o *.h.gch

clean:
	rm -f mycat *.o *.h.gch

