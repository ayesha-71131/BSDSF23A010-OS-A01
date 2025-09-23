# src/Makefile
CC = gcc
CFLAGS = -I../include -Wall -Wextra -g
OBJ_DIR = ../obj
BIN_DIR = ../bin

SRCS = main.c mystrfunctions.c myfilefunctions.c
OBJS = $(SRCS:%.c=$(OBJ_DIR)/%.o)
TARGET = $(BIN_DIR)/client

.PHONY: all clean

all: $(TARGET)

# Link step
$(TARGET): $(OBJS)
	@mkdir -p $(BIN_DIR)
	$(CC) $(CFLAGS) -o $@ $^

# Pattern rule: compile each src/XYZ.c → obj/XYZ.o
$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Remove only the object files (child responsibility)
clean:
	rm -f $(OBJ_DIR)/*.o

