CC = gcc
CFLAGS = -Wall -Wextra -I./include
SRC_DIR = src
TEST_DIR = tests
BIN_DIR = bin

SRCS = $(wildcard $(SRC_DIR)/*.c)
OBJS = $(patsubst $(SRC_DIR)/%.c,$(BIN_DIR)/%.o,$(SRCS))

TARGET = $(BIN_DIR)/text_to_hex

all: $(TARGET)

$(BIN_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $< -o $@

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@

test: $(TARGET)
	$(CC) $(CFLAGS) $(TEST_DIR)/test_converter.c $(SRC_DIR)/converter.c -o $(BIN_DIR)/test_converter
	$(BIN_DIR)/test_converter

clean:
	rm -rf $(BIN_DIR)

.PHONY: all clean test