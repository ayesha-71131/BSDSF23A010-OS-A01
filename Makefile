# Makefile for Dynamic Library Only
CC = gcc
CFLAGS = -I./include -Wall -Wextra -fPIC

# Directories
SRC_DIR = src
OBJ_DIR = obj
LIB_DIR = lib
BIN_DIR = bin

# Library files
LIB_SOURCES = $(SRC_DIR)/mystrfunctions.c $(SRC_DIR)/myfilefunctions.c
LIB_OBJECTS = $(OBJ_DIR)/mystrfunctions.o $(OBJ_DIR)/myfilefunctions.o

# Dynamic library
DYNAMIC_LIB = $(LIB_DIR)/libmputils.so
TARGET = $(BIN_DIR)/client_dynamic

# Main program
MAIN_SOURCE = $(SRC_DIR)/main.c

.PHONY: all clean run

# Default target
all: $(TARGET)

# Create directories
$(OBJ_DIR) $(LIB_DIR) $(BIN_DIR):
	mkdir -p $@

# Compile object files with -fPIC (for dynamic library)
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Create dynamic library
$(DYNAMIC_LIB): $(LIB_OBJECTS) | $(LIB_DIR)
	$(CC) -shared $^ -o $@

# Link main program with dynamic library
$(TARGET): $(MAIN_SOURCE) $(DYNAMIC_LIB) | $(BIN_DIR)
	$(CC) $(CFLAGS) $< -L$(LIB_DIR) -lmputils -o $@

# Run the program (will need LD_LIBRARY_PATH)
run: $(TARGET)
	LD_LIBRARY_PATH=./lib ./$(TARGET)

# Clean everything
clean:
	rm -rf $(OBJ_DIR) $(LIB_DIR) $(BIN_DIR)
