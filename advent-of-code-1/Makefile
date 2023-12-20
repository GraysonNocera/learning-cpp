GPP = g++

CFLAGS = -std=c++11 -pedantic -Wvla -Wall -Wshadow -O3
EXEC = advent1

all:
	$(GPP) $(CFLAGS) advent-of-code-1.cpp -o $(EXEC) -lm

run: all
	./$(EXEC)