OBJS	= main.o MainWindow.o Game.o Map.o Player.o GameRenderer.o GameController.o SideWalk.o Water.o Log.o Prop.o LilyPad.o
SOURCE	= src/main.cpp src/MainWindow.cpp src/Model/Game.cpp src/Model/Map.cpp src/Model/Player.cpp src/View/GameRenderer.cpp src/Controller/GameController.cpp src/Model/Environments/SideWalk.cpp src/Model/Environments/Water.cpp src/Model/Environments/Props/Log.cpp src/Model/Environments/Props/Prop.cpp src/Model/Environments/Props/LilyPad.cpp
HEADER	= src/MainWindow.h src/Model/Direction.h src/Model/Game.h src/Model/Map.h src/Model/Player.h src/Model/Position.h src/View/GameRenderer.h src/Controller/GameController.h src/Model/Environment.h src/Model/Environments/SideWalk.h src/Model/Environments/Water.h src/Model/Environments/Props/Log.h src/Model/Environments/Props/Prop.h src/Model/Environments/Props/LilyPad.h
OUT	= build/frogger
CC	 = g++
FLAGS	 = -g -c -Wall -Wextra -lfltk
LFLAGS	 = -lfltk

all: $(OBJS)
	$(CC) -g $(OBJS) -o $(OUT) $(LFLAGS)
	rm -f $(OBJS)

main.o: src/main.cpp
	$(CC) $(FLAGS) src/main.cpp -std=c++17

MainWindow.o: src/MainWindow.cpp
	$(CC) $(FLAGS) src/MainWindow.cpp -std=c++17

Game.o: src/Model/Game.cpp
	$(CC) $(FLAGS) src/Model/Game.cpp -std=c++17

Map.o: src/Model/Map.cpp
	$(CC) $(FLAGS) src/Model/Map.cpp -std=c++17

Player.o: src/Model/Player.cpp
	$(CC) $(FLAGS) src/Model/Player.cpp -std=c++17

GameRenderer.o: src/View/GameRenderer.cpp
	$(CC) $(FLAGS) src/View/GameRenderer.cpp -std=c++17

GameController.o: src/Controller/GameController.cpp
	$(CC) $(FLAGS) src/Controller/GameController.cpp -std=c++17

SideWalk.o: src/Model/Environments/SideWalk.cpp
	$(CC) $(FLAGS) src/Model/Environments/SideWalk.cpp -std=c++17

Water.o: src/Model/Environments/Water.cpp
	$(CC) $(FLAGS) src/Model/Environments/Water.cpp -std=c++17

Prop.o : src/Model/Environments/Props/Prop.cpp
	$(CC) $(FLAGS) src/Model/Environments/Props/Prop.cpp -std=c++17

Log.o: src/Model/Environments/Props/Log.cpp
	$(CC) $(FLAGS) src/Model/Environments/Props/Log.cpp -std=c++17

LilyPad.o: src/Model/Environments/Props/LilyPad.cpp
	$(CC) $(FLAGS) src/Model/Environments/Props/LilyPad.cpp -std=c++17

clean:
	rm -f $(OBJS) $(OUT)
