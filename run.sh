#!/bin/bash

# shell script for specifying compile directives to test STL container iterators against
# Author: Sean Cassero

# call with argument 1
# ie ./compile.sh 1


# compile with the proper directive
g++ -std=c++11 -O2 timing_sequence_containers.cpp -o main

# run the executable
./main

# clean the current directory
rm main
