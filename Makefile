
#compiler
CC = gcc

#compiler flags
CFLAGS = -Wall -Wextra -Wpedantic -std=c11 -g

#executale name
TARGET = circular_buffer.exe

#source and object files
SRC = main.c ring_buffer.c
OBJ = $(SRC:.c=.o)

#default target
all: $(TARGET)

#link object files to create executable
$(TARGET): $(OBJ)
	$(CC) $(OBJ) -o $(TARGET)

#compile each C file into an object file
%.o: %.c ring_buffer.h
	$(CC) $(CFLAGS) -c $< -o $@

#run the program
run: $(TARGET)
	./$(TARGET)

#remove generated files
clean:
	rm -f $(OBJ) $(TARGET)

.PHONY: all run clean