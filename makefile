CC = g++
CFLAGS = -Wall -g -std=c++17

SRC_DIR = src
INCLUDE_DIR = includes
OBJ_DIR = obj
BIN_DIR = bin
SHARED_DIR = shared

LIBS =
INCLUDES = -I${INCLUDE_DIR}
LFLAGS = -lncursesw

ifeq ($(OS), Windows_NT)
    # MSYS2/Windows settings
    LIBS = -LC:/msys64/mingw64/lib
    INCLUDES += -IC:/msys64/mingw64/include/ncursesw
else
    # Arch Linux settings
    LIBS = -L/usr/lib
    INCLUDES += -I/usr/include
endif

PROGRAM = main
OBJECTS = $(patsubst $(SRC_DIR)/%.cpp, $(OBJ_DIR)/%.o, $(wildcard $(SRC_DIR)/*.cpp))

# $@ - target
# $< - first prerequisite
# $^ - all dependencies

${PROGRAM}: ${OBJECTS} | bin
	${CC} ${CFLAGS} $^ -o ${BIN_DIR}/$@ ${LIBS} ${LFLAGS}

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp | obj
	${CC} ${CFLAGS} ${INCLUDES} -c $< -o $@

obj:
	mkdir ${OBJ_DIR}

bin:
	mkdir ${BIN_DIR}

clean: 
	rm -rf ${OBJ_DIR} ${BIN_DIR}

run:
	./${BIN_DIR}/${PROGRAM}
