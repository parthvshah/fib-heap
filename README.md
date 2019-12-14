# advAlgoFibHeaps

## Process Scheduling using Fibonacci Heaps

Due to the complexity involved in modifying the scheduler to use Fibonacci heaps, we decide to simulate processes by using a user program. The program uses a Fibonacci heap and bench-marks it against a binary heap. The simulation of process scheduling was implemented in C and simulated a maximum of 100 runnable processes, with about 75,000 context switches between them.

On observing the results, we notice that a Binary heap  marginally  outperforms  a  Fibonacci  heap  in  our  implementation. This could be reasoned out by considering the relatively small (at-most 100) processes that our program simulates as the only speedup observed is in the insert operation. A Fibonacci heap is expected to significantly outperform other priority queue data structures only for larger input values, as the difference between O(1) operations and O(log(n)) operations is not visibly significant for relativelysmall values of n.
