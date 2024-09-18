INCLUDE_PATH=./include/
SOURCE_PATH=./src/
TARGET=main

CC=g++
CFLAGS= -O3 -std=c++17 -I$(INCLUDE_PATH) -B$(SOURCE_PATH)

SRCS:=$(shell find $(SRC_DIRS) -name '*.cpp' -or -name '*.c' -or -name '*.s')

.PHONY: clean all build

all: clean build

$(TARGET): $(SRCS)
	$(CC) $(CFLAGS) -o $@ $<

build: $(TARGET)

clean:
	rm -rf build/ main
