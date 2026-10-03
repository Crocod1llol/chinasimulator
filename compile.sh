#!/bin/bash

if [[ $1 == "--debug" ]]; then

    g++ -Wunused-macros -Wall -Wextra -o game main.cpp ./src/*.cpp -L./lib_lin64/ -lraylib -lm -lpthread -ldl -lrt -lX11 -g -fsanitize=address,undefined -fno-omit-frame-pointer

else

    g++ -Wunused-macros -Wall -Wextra -o game main.cpp ./src/*.cpp -L./lib_lin64/ -lraylib -lm -lpthread -ldl -lrt -lX11
fi
