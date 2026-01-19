# DAC Module Makefile
# Purpose: Build DAC C components for symbolic-to-analog conversion

CC := gcc
CFLAGS := -Wall -Wextra -std=c11 -g -Idac-module/c

DAC_SRC := dac-module/c
DAC_OBJ := dac-module/build
DAC_BIN := dac-module/bin

DAC_OBJS := $(DAC_OBJ)/dac.o
DAC_EXE := $(DAC_BIN)/dac_demo

all: prep $(DAC_EXE)

prep:
    @mkdir -p $(DAC_OBJ) $(DAC_BIN)

$(DAC_OBJ)/%.o: $(DAC_SRC)/%.c
    $(CC) $(CFLAGS) -c $< -o $@

$(DAC_EXE): $(DAC_OBJS)
    $(CC) $(CFLAGS) $^ -o $@

clean:
    rm -rf $(DAC_OBJ) $(DAC_BIN)

.PHONY: all clean prep

