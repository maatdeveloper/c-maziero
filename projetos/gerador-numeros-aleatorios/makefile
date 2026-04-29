# compiler flags
CFLAGS = -Wall -Wextra -g -std=c99
CC = gcc

# file flags
LCRANDOM_F 		:= src/lcrandom/lcrandom.c 		src/lcrandom/lcrandom.h
HISTOGRAMA_F 	:= src/histograma/histograma.c 	src/histograma/histograma.h
PERIODO_F		:= src/periodo/periodo.c 		src/periodo/periodo.h

all: main.o lcrandom.o histograma.o periodo.o
	$(CC) -o lcr $^

main.o: main.c
	$(CC) -c $(CFLAGS) main.c

lcrandom.o: $(LCRANDOM_F)
	$(CC) -c $(CFLAGS) src/lcrandom/lcrandom.c

histograma.o: $(HISTOGRAMA_F)
	$(CC) -c $(CFLAGS) src/histograma/histograma.c

periodo.o: $(PERIODO_F)
	$(CC) -c $(CFLAGS) src/periodo/periodo.c

clean:
	rm -f *.o lcr