OBJS	= treetester.o BST.o
SOURCE	= treetester.cpp BST.cpp
HEADER	= BST.h
OUT	= treetester
CC	 = g++
FLAGS	 = -g -c -Wall
LFLAGS	 = 

all: $(OBJS)
	$(CC) -g $(OBJS) -o $(OUT) $(LFLAGS)

treetester.o: treetester.cpp
	$(CC) $(FLAGS) treetester.cpp 

BST.o: BST.cpp
	$(CC) $(FLAGS) BST.cpp 


clean:
	rm -f $(OBJS) $(OUT)
