#!/bin/bash

set -e

echo compiling start

# g++ \
# main.cpp \
# shape.cpp \
# triangle.cpp \
# -o run.out

g++ \
*.cpp \
-o run.out

echo -e "compiling complete\n"

./run.out