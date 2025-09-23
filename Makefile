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

.PHONY: all clean run install

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

# Install target
install: $(TARGET)
	# Install the executable
	sudo cp $(TARGET) /usr/local/bin/client
	# Install man pages
	sudo mkdir -p /usr/local/man/man3
	sudo cp man/man3/*.3 /usr/local/man/man3/
	# Update man database
	sudo mandb
	@echo "Installation completed successfully!"

# Clean up
clean:
	rm -rf $(OBJ_DIR) $(LIB_DIR) $(BIN_DIR)
