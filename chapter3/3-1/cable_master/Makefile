CC=g++
CPPFLAGS=-g -static

SRC = cable_master.cpp
BIN = cable_master

$(BIN): $(SRC)
	$(CC) $(CPPFLAGS) -o $(BIN) $(SRC)

run: $(BIN)
	./$(BIN)

clean:
	rm -f $(BIN)

test: $(BIN)
	cat 1.test | ./$(BIN)

.PHONY: clean test
