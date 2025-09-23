# Simple Makefile for Static Library
CC = gcc
CFLAGS = -I./include -Wall -Wextra

# Directories
SRC_DIR = src
OBJ_DIR = obj
LIB_DIR = lib
BIN_DIR = bin

# Library files
LIB_SOURCES = $(SRC_DIR)/mystrfunctions.c $(SRC_DIR)/myfilefunctions.c
LIB_OBJECTS = $(OBJ_DIR)/mystrfunctions.o $(OBJ_DIR)/myfilefunctions.o
LIBRARY = $(LIB_DIR)/libmputils.a

# Main program
MAIN_SOURCE = $(SRC_DIR)/main.c
TARGET = $(BIN_DIR)/client_static

.PHONY: all clean run

# Default target
all: $(TARGET)

# Create directories if they don't exist
$(OBJ_DIR) $(LIB_DIR) $(BIN_DIR):
	mkdir -p $@

# Compile library object files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Create static library
$(LIBRARY): $(LIB_OBJECTS) | $(LIB_DIR)
	ar rcs $@ $^

# Link main program with static library
$(TARGET): $(MAIN_SOURCE) $(LIBRARY) | $(BIN_DIR)
	$(CC) $(CFLAGS) $< -L$(LIB_DIR) -lmputils -o $@

# Run the program
run: $(TARGET)
	./$(TARGET)

# Clean up
clean:
	rm -rf $(OBJ_DIR) $(LIB_DIR) $(BIN_DIR)
