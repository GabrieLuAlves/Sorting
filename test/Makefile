CC=gcc
TARGET=test
SRCs=test.c
OBJs=test.o
FLAGS=-Wall -Werror -ansi

all: $(OBJs)
	$(CC) -g -o $(TARGET) $(OBJs)

%.o: %.c
	$(CC) -c -o $@ $< $(FLAGS)

clean:
	rm *.o
	rm *.txt
