CC = gcc
CFLAGS = -Wall -std=c11
LDFLAGS = -lraylib -lm -lpthread -ldl -lrt -lX11

INCLUDE = include
SRC = src

OBJ = main.o game.o ui.o scores.o

%.o: $(SRC)/%.c
	$(CC) $(CFLAGS) -I$(INCLUDE) -c $<

all: juego

juego: $(OBJ)
	$(CC) $(OBJ) -o juego $(LDFLAGS)

clean:
	rm -f *.o juego

