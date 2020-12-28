#!/bin/sh

g++ -c src/*.cpp src/*/*.cpp -std=c++14 -m64 -g -Wall -I include
g++ *.o -o bin/debug/main -lsfml-graphics -lsfml-window -lsfml-system
./bin/debug/main
