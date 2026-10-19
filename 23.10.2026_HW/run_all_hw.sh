#!/bin/bash

set -e

echo  sum_functor compiling start

g++ sum_functor.cpp -o sum_functor.out

echo -e "compiling complete\n"

./sum_functor.out

echo -e "\n\n\n"
echo  main_hw compiling start

g++ main.cpp student.cpp -o student.out

echo -e "compiling complete\n"

./student.out