# Gobode-Labs Makefile
# Purpose: Build symbolic C/C++ modules (TRECEpoint, Symbolic Engine)
# Philosophy: Code is art. This Makefile orchestrates the compilation symphony.

# === Compiler and Flags ===
CC := gcc
CFLAGS := -Wall -Wextra -std=c11 -g -I./trecepoint/include -I./symbolic-engine/include

# === Directories ===
TRECE_SRC := trecepoint/src
TRECE_OBJ := trecepoint/build
TRECE_BIN := trecepoint/bin

SYMB_SRC := symbolic-engine/src
SYMB_OBJ := symbolic-engine/build
SYMB_BIN := symbolic-engine/bin

# === Targets ===
TRECE_OBJS := $(TRECE_OBJ)/trecepoint.o $(TRECE_OBJ)/memory.o $(TRECE_OBJ)/registers.o $(TRECE_OBJ)/symbolic.o $(TRECE_OBJ)/mitre.o
SYMB_OBJS := $(SYMB_OBJ)/summation.o $(SYMB_OBJ)/classifier.o $(SYMB_OBJ)/pattern.o

# === Executables ===
TRECE_EXE := $(TRECE_BIN)/trecepoint
SYMB_EXE := $(SYMB_BIN)/symbolic_engine

# === Default Target ===
all: prep $(TRECE_EXE) $(SYMB_EXE)

# === Directory Setup ===
prep:
	@mkdir -p $(TRECE_OBJ) $(TRECE_BIN) $(SYMB_OBJ) $(SYMB_BIN)

# === TRECEpoint Build ===
$(TRECE_OBJ)/%.o: $(TRECE_SRC)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(TRECE_EXE): $(TRECE_OBJS)
	$(CC) $(CFLAGS) $^ -o $@

# === Symbolic Engine Build ===
$(SYMB_OBJ)/%.o: $(SYMB_SRC)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(SYMB_EXE): $(SYMB_OBJS)
	$(CC) $(CFLAGS) $^ -o $@

# === Clean ===
clean:
	rm -rf $(TRECE_OBJ) $(TRECE_BIN) $(SYMB_OBJ) $(SYMB_BIN)

# === Help ===
help:
	@echo "Project-Kairos Build System"
	@echo "Usage:"
	@echo "  make all    - Setup directories and build all binaries"
	@echo "  make clean  - Remove all build artifacts"
	@echo "  make help   - Show this help message"

# === Phony Targets ===
.PHONY: all clean prep help
