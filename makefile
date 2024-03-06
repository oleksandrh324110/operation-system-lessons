default-target: all
.PHONY: default-target

ifndef target
$(error target is NOT defined)
endif

CFLAGS = -std=c11 -O0 -Wall -Wextra -Wpedantic
CFLAGS +=
LDFLAGS =

CMAKEFLAGS =

ifeq ($(target), linux)
	CC = x86_64-w64-mingw32-gcc
	CFLAGS +=
	LDFLAGS +=
else ifeq ($(target), windows)
	CC = gcc
	CFLAGS +=
	LDFLAGS +=
else ifeq ($(target), darwin)
	CC = clang
	CFLAGS +=
	LDFLAGS +=
else ifeq ($(target), wsl)
	CC = gcc
	CFLAGS +=
	LDFLAGS +=
endif

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
	export WINEDEBUG=-all,+randr
	wine ./bin/main.exe

clean:
	rm $(OBJ)
