#!/bin/bash

g++  -Wunused-macros -Wall -Wextra -o game main.cpp ./src/*.cpp -L./lib_lin64/ -lraylib -lm -lpthread -ldl -lrt -lX11
