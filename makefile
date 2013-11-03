CC=g++
CFLAGS=-c -std=c++0x -Wall


all: FunnyPermutation

FunnyPermutation: main.o App.o Sequence.o Algorithm.o SteinhausJohnsonTrotter.o ReverseUse.o Bmu.o \
                  Array.o Utility.o Parameters.o Timer.o
	$(CC) main.o App.o Sequence.o Algorithm.o SteinhausJohnsonTrotter.o ReverseUse.o Bmu.o Array.o \
	Utility.o Parameters.o Timer.o -lrt -o FunnyPermutation

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

ReverseUse.o: ReverseUse.cpp
	$(CC) $(CFLAGS) ReverseUse.cpp

Bmu.o: Bmu.cpp
	$(CC) $(CFLAGS) Bmu.cpp

Array.o: Array.cpp
	$(CC) $(CFLAGS) Array.cpp

Utility.o: Utility.cpp
	$(CC) $(CFLAGS) Utility.cpp

Parameters.o: Parameters.cpp
	$(CC) $(CFLAGS) Parameters.cpp

Timer.o: Timer.cpp
	$(CC) $(CFLAGS) Timer.cpp

clean:
	rm -rf *.o FunnyPermutation
