CC=gcc
CFLAGS=-g -static

SRC = maximize_average.c
BIN = maximize_average

$(BIN): $(SRC)

run: $(BIN)
	./$(BIN)

clean:
	rm -f $(BIN)

test: $(BIN)
	cat 1.test | ./$(BIN)

.PHONY: clean test
