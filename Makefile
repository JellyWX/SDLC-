OBJS = SDL2_helloworld.cpp

CC = g++

FLAGS = -std=c++11 -w
LFLAGS = -lSDL2

OBJ_NAME = a.out

all : $(OBJS)
	$(CC) $(OBJS) $(FLAGS) $(LFLAGS) -o $(OBJ_NAME)
