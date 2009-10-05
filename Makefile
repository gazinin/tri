CC = gcc
CFLAGS = -g -c -Wall
LDFLAGS = -lncurses
SOURCES = main.c
OBJECTS = $(SOURCES:.c=.o)
PROGS = main

all: $(SOURCES) $(PROGS)

$(PROGS): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.c.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -rf $(PROGS) $(OBJECTS) *~
