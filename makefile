default-target: all
.PHONY: default-target

export WINEDEBUG=-all

CC = x86_64-w64-mingw32-gcc
CFLAGS = -std=c11 -O0 -Wall -Wextra -Wpedantic
CFLAGS +=
LDFLAGS =

SRC := $(wildcard src/*.c) $(wildcard src/**/*.c) $(wildcard src/**/**/*.c) $(wildcard src/**/**/**/*.c)
OBJ := $(SRC:.c=.o)

all: compile link run

compile: $(OBJ)

test:
	echo $(OS)

%.o: %.c
	$(CC) -c $< -o $@ $(CFLAGS)

link:
	$(CC) $(OBJ) -o bin/main.exe $(LDFLAGS)

run:
	wine ./bin/main.exe

clean:
	rm $(OBJ)
