# Performance comparison - Fibonacci Heap vs STL Priority Queue

## File Organization

1. `main.cpp` - Driver code to run the program
2. `dijkstra.hpp` - Header file, containing the class and function for dijkstra's algorithms
3. `generateGraph.cpp` - Program to generate graphs
4. `fiboheap/` -  Directory of Fibonacci Heap implementation
5. `tests/` - Contains sample graphs and test results

## Running
```
g++ main.cpp --std=c++14 -g  -o dijkstra
./dijkstra
```
Note 1: Options can be provided in the macros defined in `main.cpp` for custom input and multiple runs. There are multiple test graphs in `tests` folder. 

Note 2: Results are tabulated in `tests/avg.txt` and shown in `tests/plots/`.