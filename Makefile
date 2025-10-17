CC = gcc
CFLAGS = -Wall -Wextra -Iinclude

SRC = src/vector.c
OBJ = $(SRC:.c=.o)
TARGET = test

all: $(TARGET)

$(TARGET): $(OBJ) tests/test.c
	$(CC) $(CFLAGS) $^ -o $@

clean:
	rm -f $(OBJ) $(TARGET)

