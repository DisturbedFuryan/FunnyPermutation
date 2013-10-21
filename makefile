CC=g++
CFLAGS=-c -Wall


all: FunnyPermutation

FunnyPermutation: main.o App.o Sequence.o Algorithm.o SteinhausJohnsonTrotter.o Array.o Utility.o
	$(CC) main.o App.o Sequence.o Algorithm.o SteinhausJohnsonTrotter.o Array.o Utility.o -o FunnyPermutation

main.o: main.cpp
	$(CC) $(CFLAGS) main.cpp

App.o: App.cpp
	$(CC) $(CFLAGS) App.cpp

Sequence.o: Sequence.cpp
	$(CC) $(CFLAGS) Sequence.cpp

Algorithm.o: Algorithm.cpp
	$(CC) $(CFLAGS) Algorithm.cpp

SteinhausJohnsonTrotter.o: SteinhausJohnsonTrotter.cpp
	$(CC) $(CFLAGS) SteinhausJohnsonTrotter.cpp

Array.o: Array.cpp
	$(CC) $(CFLAGS) Array.cpp

Utility.o: Utility.cpp
	$(CC) $(CFLAGS) Utility.cpp

clean:
	rm -rf *.o FunnyPermutation
