OBJS	= build/main.o build/MainWindow.o build/Game.o build/Map.o build/Player.o build/GameRenderer.o build/GameController.o build/SideWalk.o build/Water.o build/Log.o build/Prop.o build/LilyPad.o
SOURCE	= src/main.cpp src/MainWindow.cpp src/Model/Game.cpp src/Model/Map.cpp src/Model/Player.cpp src/View/GameRenderer.cpp src/Controller/GameController.cpp src/Model/Environments/SideWalk.cpp src/Model/Environments/Water.cpp src/Model/Environments/Props/Log.cpp src/Model/Environments/Props/Prop.cpp src/Model/Environments/Props/LilyPad.cpp
HEADER	= src/MainWindow.h src/Model/Direction.h src/Model/Game.h src/Model/Map.h src/Model/Player.h src/Model/Position.h src/View/GameRenderer.h src/Controller/GameController.h src/Model/Environment.h src/Model/Environments/SideWalk.h src/Model/Environments/Water.h src/Model/Environments/Props/Log.h src/Model/Environments/Props/Prop.h src/Model/Environments/Props/LilyPad.h
OUT	= build/frogger
CC	 = g++
FLAGS	 = -g -c -Wall -Wextra -lfltk
LFLAGS	 = -lfltk
OOUT = -o build/

all: $(OBJS)
	$(CC) -g $(OBJS) -o $(OUT) $(LFLAGS)

build/main.o: src/main.cpp
	$(CC) $(FLAGS) src/main.cpp -std=c++17 $(OOUT)main.o

build/MainWindow.o: src/MainWindow.cpp
	$(CC) $(FLAGS) src/MainWindow.cpp -std=c++17 $(OOUT)MainWindow.o

build/Game.o: src/Model/Game.cpp
	$(CC) $(FLAGS) src/Model/Game.cpp -std=c++17 $(OOUT)Game.o

build/Map.o: src/Model/Map.cpp
	$(CC) $(FLAGS) src/Model/Map.cpp -std=c++17 $(OOUT)Map.o

build/Player.o: src/Model/Player.cpp
	$(CC) $(FLAGS) src/Model/Player.cpp -std=c++17 $(OOUT)Player.o

build/GameRenderer.o: src/View/GameRenderer.cpp
	$(CC) $(FLAGS) src/View/GameRenderer.cpp -std=c++17 $(OOUT)GameRenderer.o

build/GameController.o: src/Controller/GameController.cpp
	$(CC) $(FLAGS) src/Controller/GameController.cpp -std=c++17 $(OOUT)GameController.o

build/SideWalk.o: src/Model/Environments/SideWalk.cpp
	$(CC) $(FLAGS) src/Model/Environments/SideWalk.cpp -std=c++17 $(OOUT)SideWalk.o

build/Water.o: src/Model/Environments/Water.cpp
	$(CC) $(FLAGS) src/Model/Environments/Water.cpp -std=c++17 $(OOUT)Water.o

build/Prop.o : src/Model/Environments/Props/Prop.cpp
	$(CC) $(FLAGS) src/Model/Environments/Props/Prop.cpp -std=c++17 $(OOUT)Prop.o

build/Log.o: src/Model/Environments/Props/Log.cpp
	$(CC) $(FLAGS) src/Model/Environments/Props/Log.cpp -std=c++17 $(OOUT)Log.o

build/LilyPad.o: src/Model/Environments/Props/LilyPad.cpp
	$(CC) $(FLAGS) src/Model/Environments/Props/LilyPad.cpp -std=c++17 $(OOUT)LilyPad.o

clean:
	rm -f $(OBJS) $(OUT)
