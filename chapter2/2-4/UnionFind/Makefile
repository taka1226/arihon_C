CC=g++
CPPFLAGS=-g -static

SRC = main.cpp
BIN = main
TESTDIR = TestDir

$(BIN): $(SRC)

run: $(BIN)
	./$(BIN)

clean:
	rm -f $(BIN)

.PHONY: clean test
