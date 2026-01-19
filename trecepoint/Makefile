    #-------------------------------
# Compiler and Build Settings
#-------------------------------

CC = gcc
CFLAGS = -Wall -Wextra -Iinclude -g

SRC_DIR = src
OBJ_DIR = build
TEST_DIR = tests
EXAMPLES_DIR = examples

# Collect all .c files in src/
SRCS = $(wildcard $(SRC_DIR)/*.c)

# Convert src/foo.c → build/foo.o
OBJS = $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRCS))

# Example binaries
EXAMPLES = heap_demo trigger_demo attach

# Unit test binaries
TESTS = test_lexical test_memory test_mitre test_symbolic

# -------------------------------
#	Default Target
# -------------------------------

all: $(OBJ_DIR) $(EXAMPLES)

# -------------------------------
# 	Object File Compilation
# -------------------------------

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
    $(CC) $(CFLAGS) -c $< -o $@

# -------------------------------
# 	Example Programs
# -------------------------------

heap_demo: $(EXAMPLES_DIR)/heap-dump-demo.c $(OBJS)
    $(CC) $(CFLAGS) -o $@ $^

trigger_demo: $(EXAMPLES_DIR)/symbolic-trigger-demo.c $(OBJS)
    $(CC) $(CFLAGS) -o $@ $^

attach: $(EXAMPLES_DIR)/simple-attach.c $(OBJS)
    $(CC) $(CFLAGS) -o $@ $^

# -------------------------------
# Unit Tests
# -------------------------------

test: $(TESTS)

test_lexical: $(TEST_DIR)/test_lexical.c $(OBJS)
    $(CC) $(CFLAGS) -o $@ $^ && ./test_lexical

test_memory: $(TEST_DIR)/test_memory.c $(OBJS)
    $(CC) $(CFLAGS) -o $@ $^ && ./test_memory

test_mitre: $(TEST_DIR)/test_mitre.c $(OBJS)
    $(CC) $(CFLAGS) -o $@ $^ && ./test_mitre

test_symbolic: $(TEST_DIR)/test_symbolic.c $(OBJS)
    $(CC) $(CFLAGS) -o $@ $^ && ./test_symbolic

# -------------------------------
# Utilities
# -------------------------------

$(OBJ_DIR):
    mkdir -p $(OBJ_DIR)

clean:
    rm -rf $(OBJ_DIR) *.o $(EXAMPLES) $(TESTS)

