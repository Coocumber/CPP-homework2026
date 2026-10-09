#!/bin/bash

set -e

echo conpiling start

# g++ \
# main.cpp \
# shape.cpp \
# triangle.cpp \
# -o run.out

g++ \
*.cpp \
-o run.out

echo -e "conpiling complete\n"

./run.out