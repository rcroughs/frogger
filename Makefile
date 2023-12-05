SRC_DIR = src/
BUILD_DIR = build/

OBJS    = $(patsubst ${SRC_DIR}%.cpp,${BUILD_DIR}%.o,${SOURCES})
HEADERS = $(shell find ${SRC_DIR} -name '*.h')
SOURCES = $(shell find ${SRC_DIR} -name '*.cpp')
OUT	= frogger
CC	 = g++
FLAGS	 = -g -c -Wall -Wextra
FLAGOSX1 = `fltk-config --cxxflags`
FLAGOSX2 = `fltk-config --ldflags`
LFLAGS	 = -lfltk -lfltk_images
OOUT = -o build/

default: frogger

frogger: ${OBJS}
	${CC} -g ${LDFLAGS} $^ -o $@ ${LFLAGS}

${BUILD_DIR}%.o: ${SRC_DIR}%.cpp Makefile
	@mkdir -p $(dir $@)
	${CC} ${FLAGS} -c $< -o $@ ${LFLAGS}


# Target with Flag 1
osx: FLAGS = -g -c -Wall -Wextra `fltk-config --cxxflags`
osx: LFLAGS = `fltk-config --ldflags` -lfltk_images
osx: frogger

clean:
	rm -f $(OBJS) $(OUT)
