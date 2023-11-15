CC=g++
FLAGS=-Wall -Wextra -O2 -std=c++17 -Wpedantic
SOURCEPATH=src/
BUILDPATH=build/
OBJS=

all: frogger

frogger: $(SOURCEPATH)main.cpp
	$(CC) $(FLAGS) $(SOURCEPATH)main.cpp -o $(BUILDPATH)frogger
