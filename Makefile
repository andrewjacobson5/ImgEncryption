CC = g++
CFLAGS = --std=c++17 -Wall -Werror -pedantic -O3
LIB = -lboost_unit_test_framework -lsfml-graphics -lsfml-window -lsfml-system
PROG = ImgEncryption test
OBJ = FibLFSR.o test.o ImgEncryption.o
DEPS = FibLFSR.cpp FibLFSR.hpp test.cpp ImgEncryption.cpp

.PHONY: all clean lint 

all: $(PROG)

%.o: %.cpp $(DEPS)
	$(CC) $(CFLAGS) -c $< $(LIB)

PhotoMagic: FibLFSR.o ImgEncryption.o
	$(CC) $(CFLAGS) -o $@ $^ $(LIB)

test: FibLFSR.o test.o
	$(CC) $(CFLAGS) -o $@ $^ $(LIB)

clean:
	rm *.o $(PROG)

lint:
	cpplint *.cpp *.hpp
	
