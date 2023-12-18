CC=gcc
CXX=g++
CFLAGS=-g -Wall
LDLIBS= -lglfw -lGL -lX11 -lpthread -lXrandr -lXi -ldl
LAP_LDLIBS= -lglfw3 -lGL -lX11 -lpthread -lXrandr -lXi -ldl
BIN=out

SRC_DIR := src
GL_DIR := $(SRC_DIR)/opengl
BUILD_DIR := build

SOURCES := $(wildcard $(SRC_DIR)/*.cpp) $(wildcard $(SRC_DIR)/*/*.cpp)
OBJECTS := $(patsubst %.cpp, $(BUILD_DIR)/%.o, $(notdir $(SOURCES)))
VPATH = $(sort $(dir $(SOURCES)))

all: $(BIN)

$(BIN): $(OBJECTS) $(BUILD_DIR)/glad.o
	$(CXX) $^ $(CFLAGS) $(LDLIBS) -o $@

$(BUILD_DIR)/%.o: %.cpp
	$(CXX) -c $< -o $@

$(BUILD_DIR)/glad.o: $(SRC_DIR)/opengl/glad.c
	$(CC) -c $< -o $@

clean:
	rm build/*
	rm out