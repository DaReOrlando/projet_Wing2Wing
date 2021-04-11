CC=gcc

UNAME_S := $(shell uname -s)
ifeq ($(UNAME_S), Linux)
FLAGGLUT=-lglut -lGL -lGLU
endif
ifeq ($(UNAME_S), Darwin)
FLAGGLUT=-Wno-deprecated-declarations -framework OpenGL -framework GLUT
endif


FLAG=-Wall -std=c99
SRCS=*.c
OBJETS=$(SRCS:.c=.o)
EXEC=program

all:$(EXEC)

$(EXEC): $(SRCS)
		$(CC) -c $(SRCS) $(FLAG) $(FLAGGLUT)
		$(CC) -o $(EXEC) $(OBJETS) $(FLAG) $(FLAGGLUT)

clean:
		rm -rf $(EXEC)
		rm -rf *.o