CC = g++
CCMAC = gcc
CFLAGS= -c -ansi -pedantic -std=c++0x -Weffc++ -g -I./include
#INCLUDE =-I../
#MOVE = /bin/mv -f
#RM = /bin/rm -f
#BIN = ./bin


EXE=main
LIBSLINUX=  -L./libLinux -lEngine -lGL -lglut -lm -lGLU
LDFLAGS= -lm -g -lstdc++

SOURCES = $(wildcard src/*.cpp src/*/*.cpp src/*/*/*.cpp )
ENTETES = $(wildcard src/*.h src/*/*.h src/*/*/*.h)

OBJS = ${SOURCES:.cpp=.o}
includes = $(wildcard src/*.h)



ifdef DEBUG
	CFLAGS += -g
endif


all:	${OBJS}
	${CC}  ${OBJS} -o ${EXE} ${LDFLAGS} ${LIBSLINUX}

%.o:%.cpp ${includes}
	${CC} -o $@ -c $< ${INCLUDE} $(CFLAGS) 

run:
	./main

clean :
	/bin/rm -f *.o *.gch  *~ src/*.o src/*/*.o src/*/*/*.o main
