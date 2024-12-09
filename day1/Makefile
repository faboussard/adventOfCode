# Variables
CC = g++
SRC = part1.cpp
EXEC = advent

# Règles
all: $(EXEC)

$(EXEC): $(SRC)
	$(CC) -o $@ $^

clean:
	rm -f $(EXEC)

.PHONY: clean
