CC=gcc
CPPFLAGS=-g -static

SRC = main.c
BIN = main
TESTDIR = TestDir

$(BIN): $(SRC)

test: $(BIN)
	cat 1.test | ./$(BIN)

run: $(BIN)
	./$(BIN)

clean:
	rm -f $(BIN)

.PHONY: clean test
