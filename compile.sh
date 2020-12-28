#!/bin/sh

mkdir -p obj
mv ./obj/*.o ./
g++ -c src/*.cpp src/*/*.cpp -std=c++14 -m64 -g -Wall -I include
g++ *.o -o bin/debug/main -lsfml-graphics -lsfml-window -lsfml-system
mv *.o ./obj
./bin/debug/main
