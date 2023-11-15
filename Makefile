CC=g++
FLAGS=-Wall -Wextra -O2 -std=c++17 -Wpedantic
SOURCEPATH=src/
TESTPATH=test/
BUILDPATH=build/
OBJS=

all: frogger test

frogger: $(SOURCEPATH)main.cpp
	$(CC) $(FLAGS) $(SOURCEPATH)main.cpp -o $(BUILDPATH)frogger

test: $(TESTPATH)main.cpp
	$(CC) $(FLAGS) $(TESTPATH)main.cpp -o $(BUILDPATH)test
