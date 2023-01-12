# Variables
CXX=g++
CXXFLAGS=-std=c++11 -w

build: main.cpp local_header.hpp includes/external_lib.hpp 
    @echo "\n\nmain.cpp: Building..."
    $(CXX) $(CXXFLAGS) -o main.out main.cpp

run: main.out
    @echo "\n\nmain.cpp: Executing..."
    ./main.out

clean: main.out
    @echo "\n\nmain.cpp: Cleaning..."
    rm main.out

all: build run clean
