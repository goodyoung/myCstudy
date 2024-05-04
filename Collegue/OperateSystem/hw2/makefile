CC=gcc
CFLAGS=-Wall -pthread

all: sumfact launch

sumfact: sumfact.c
	$(CC) $(CFLAGS) -o sumfact sumfact.c

launch: launch.c
	$(CC) $(CFLAGS) -o launch launch.c

clean:
	rm -f sumfact launch