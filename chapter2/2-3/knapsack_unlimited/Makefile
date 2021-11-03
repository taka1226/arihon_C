CC=gcc
CFLAGS=-g -static

SRC = knapsack_unlimited.c
BIN = knapsack_unlimited
TESTDIR = TestDir

$(BIN): $(SRC)

test: $(BIN)
	@for testfile in $(wildcard $(TESTDIR)/*.test) ; \
    do \
        if [ -s $$testfile ]; then \
            echo ---------------------- ;\
            echo "exec $$testfile " ;\
            echo "input: "; \
            cat $$testfile ; \
            echo "" ;\
            echo "output: " ;\
            cat $$testfile | ./$(BIN) ;\
        fi \
    done

run: $(BIN)
	./$(BIN)

clean:
	rm -f $(BIN)

.PHONY: clean test
