CC=gcc
CFLAGS=-g -static

SRC = aggresive_cows.c
BIN = aggresive_cows

$(BIN): $(SRC)

run: $(BIN)
	./$(BIN)

clean:
	rm -f $(BIN)

test: $(BIN)
	cat 1.test | ./$(BIN)

.PHONY: clean test
