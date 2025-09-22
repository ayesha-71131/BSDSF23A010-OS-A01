# Top-level Makefile
# Macros
CC = gcc
CFLAGS = -Iinclude -Wall -Wextra
SRC_DIR = src
OBJ_DIR = obj
BIN_DIR = bin
TARGET = $(BIN_DIR)/client

.PHONY: all clean run

# Default
all: $(TARGET)

# Delegate to src/Makefile to build target
$(TARGET):
	$(MAKE) -C $(SRC_DIR) all

# Clean via recursive call and remove final binary
clean:
	$(MAKE) -C $(SRC_DIR) clean
	rm -f $(TARGET)

# Run the built binary
run: $(TARGET)
	./$(TARGET)

