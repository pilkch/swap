#DEBUG = -g -O0
DEBUG = -O3
CC = gcc
INCLUDE	= -I/usr/local/include
CFLAGS = $(DEBUG) -Wall $(INCLUDE)

LDFLAGS	= -L/usr/local/lib
LDLIBS =

SRC=main.c

OBJ	= $(SRC:.c=.o)

all: swap

swap: main.o
	@echo [link]
	@$(CC) -o $@ main.o $(LDFLAGS) $(LDLIBS)

.c.o:
	@echo [CC] $<
	@$(CC) -c $(CFLAGS) $< -o $@

clean:
	@echo "[Clean]"
	@rm -f *.o swap

depend:
	makedepend -Y $(SRC)
