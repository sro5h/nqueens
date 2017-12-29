CC=gcc
RM=rm
CFLAGS=-I.

PROJECT = nqueens

HEADERS = alloc.h print.h solve.h util.h
SOURCES = main.c alloc.c print.c solve.c util.c
OBJECTS = $(subst .c,.o,$(SOURCES))

all: $(PROJECT)

$(PROJECT): $(OBJECTS)
	$(CC) -o $(PROJECT) $(OBJECTS) $(CFLAGS)

$(OBJECTS): $(SOURCES) $(HEADERS)
	$(CC) -c $(SOURCES) $(CFLAGS)

clean:
	$(RM) $(OBJECTS)
	$(RM) $(PROJECT)

.PHONY: clean all
