CC=gcc
CFLAGS=-O3 -Wall -Wrestrict

SRC=.
BUILD=.

SRCS=$(wildcard $(SRC)/*.c)
OBJECTS=$(patsubst $(SRC)/%.c,$(BUILD)/%.o,$(SRCS))

shortest_path: $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS)
$(BUILD)/%.o: %(SRC)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJECTS) a.out