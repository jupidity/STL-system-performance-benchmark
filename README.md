## Overview

A test for evaluating the speed of four processes on the STL containers `vector`, `linked-list`, and `deque` on a linux system with gcc compiler -O2 optimization.

Intended to function as a benchmark/comparison for system performance across embedded platforms.

the four processes are:

* grow:

  elapsed wall time in `ns` to ``push_back()`` 1000000 longs

* traverse:

  elapsed wall time in `ns` to iterate across each element in container

* shuffle:

  elapsed wall time in `ns` to shuffle all elements in container

* sort:

  elapsed wall time in `ns` to sort elements in container using `sort()`



## Usage
---


clone the repository

      git clone https://github.com/jupidity/STL-system-performance-benchmark

run the shell script

      $ ./run.sh

output should print to terminal with recorded times

example results on Ubuntu 16.04:

    -------|      grow|  traverse|   shuffle|      sort|-----
    vector |     12563|         0|     42952|    107251| (ns)
    deque  |      4921|       990|     35345|     88448| (ns)
    list   |     33180|      3219|       N/A|       N/A| (ns)



## Dependencies
---

requires c++11 gcc compiler
