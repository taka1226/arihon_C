CC=gcc
CFLAGS=-g -static

SRC = knapsack_big_w.c
BIN = knapsack_big_w
TESTDIR = TestDir

$(BIN): $(SRC)

test: $(BIN)
	cat 1.test | ./$(BIN)

run: $(BIN)
	./$(BIN)

clean:
	rm -f $(BIN)

.PHONY: clean test
