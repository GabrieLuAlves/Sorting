CC=gcc
SRCs=(wildcard *.c)
OBJs=main.o sort.o
TARGET=sorter
FLAGS=-Wall -Werror -ansi

all: compile clean

compile: $(OBJs)
	$(CC) -o $(TARGET) -g $(OBJs)

%.o: %.c	
	$(CC) -c -o $@ -g $< $(FLAGS)

clean:
	rm *.o

