# Directories
PATHS = ./src/
PATHT = ./test/
PATHB = ./build/
PATHO = $(PATHB)objs/
PATHR = $(PATHB)results/
PATHU = ./unity/src/

# Library path
LIBFTPRINTF = $(PATHS)libftprintf.a

# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -Werror -I$(PATHS) -I$(PATHU) -L$(PATHS) -lftprintf

# Find all test .c files dynamically in test/ folder
TEST_SRCS = $(wildcard $(PATHT)*.c)

# Test object files
TEST_OBJS = $(patsubst $(PATHT)%.c, $(PATHO)%.o, $(TEST_SRCS))

# Test result files
TEST_RESULTS = $(patsubst $(PATHT)%.c, $(PATHR)%.txt, $(TEST_SRCS))

# Unity test runner source
UNITY_SRC = unity.c
UNITY_OBJ = $(PATHO)unity.o

# Directories to create
DIRS = $(PATHB) $(PATHO) $(PATHR)

# Default target
all: $(LIBFTPRINTF) test

# Run the existing Makefile in src/ to build libftprintf.a
$(LIBFTPRINTF):
	$(MAKE) -C $(PATHS)

# Ensure all necessary directories are created
$(DIRS):
	@mkdir -p $(DIRS)

# Compile test object files dynamically
$(PATHO)%.o: $(PATHT)%.c | $(DIRS)
	$(CC) $(CFLAGS) -c $< -o $@

# Compile Unity object file
$(UNITY_OBJ): $(PATHU)$(UNITY_SRC) | $(DIRS)
	$(CC) $(CFLAGS) -c $< -o $@

# Test target (run all test files in the test/ folder)
test: $(TEST_RESULTS)
	@echo "-----------------------"
	@echo "TEST RESULTS:"
	@cat $(PATHR)*.txt
	@echo "-----------------------"

# Run the test and save results for each test file
$(PATHR)%.txt: $(PATHO)%.o $(LIBFTPRINTF) $(UNITY_OBJ)
	$(CC) $(CFLAGS) $^ -o $(PATHB)$*
	./$(PATHB)$* > $@ 2>&1

# Clean build files and results
clean:
	@rm -rf $(PATHO) $(PATHB)
	@$(MAKE) -C $(PATHS) clean
	@echo "Cleaned."

.PHONY: all test clean
