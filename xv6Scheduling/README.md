### Process Scheduling using Fibonacci Heaps
* Since process scheduling requires efficient switching between processes, so as to minimize the dispatch latency, we attempt to build a scheduler in [Xv6](https://github.com/mit-pdos/xv6-public) that runs on a Fibonacci Heap. 
* We first convert the default round-robin scheduler present in Xv6, to a priority scheduler (as a Fibonacci Heap improves upon standard priority queue operations), for which we modify the process structure (in proc.h), to include an unsigned integer that would act as the priority for any process.
* We then use a random unsigned integer generator function, to assign every process that enters the system, a random priority.
* We then use a process spawning program that creates children processes as per requirement, to generate processes within Xv6.
* At this point, to convert this new priority based scheduler to a Fibonacci Heap scheduler, we realise we need to allocate memory for our heap to store and access processes.
    * Unfortunately, we realise that malloc(), is only a function for user-defined programs, and hence cannot be used to modify kernel files.
* We instead run a basic Fibonacci Heap as a user program to test the working of Fibonacci Heaps on Xv6.
* Due to the complexity involved in changing the scheduler to a Fibonacci Heap Scheduler, we instead simulate processes through a user program, with the same intentions.

* Note: You will require [QEMU](https://www.qemu.org/), as the emulator for Xv6, to run the above.

## Running
Change directory to `xv6-repoExport`
```
cd xv6-repoExport
```

To compile and run the Xv6 emulator on the terminal, 
```
make clean && make && make qemu
```

To run the Fibonacci Heap user program on QEMU,
```
fib
```
To generate processes, and show their priority as assigned by the random priority generator in QEMU,
```
procspawn 10 > odmp&
```