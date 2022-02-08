.PHONY: all clean

CC=gcc

TARGET=demo

CFLAGS=-I.
CXXFLAGS=-I.
LDFLAGS=

SRC=$(wildcard *.c \
	ab_base/*.c \
	ab_net/*.c)
OBJ=$(patsubst %.c,%.o,$(patsubst %.cpp,%.o,$(SRC)))

all:$(TARGET)

$(TARGET):$(OBJ)
	$(CC) -o $@ $^ $(LDFLAGS)

%.o:%.c
	$(CC) -c $< -o $@ $(CFLAGS)

clean:
	rm -f $(TARGET) $(OBJ)
