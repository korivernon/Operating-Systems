# Virtualizing the CPU

Foreground - The front; Background - The back. Whatever is in the front is getting the most CPU cycles.

Virtual Memory - Each process has its own private virtual address space. 

**Concurrency:** Events occurring simultaneously and may interact with one another.

```thread.c``` Before, we had two different processes. Now we have one process accessing the same values. Incrementing a shared counter takes 3 instructions. 
- First, we load from memory to register
- Then we increment that register
- Then store that value into memory

The issue is that these instructions do not execute atomically (isolation from other operations that may be happening at the same time).

The line "timer++" gets translated into assemblt as 3 instructions: ftech the timer value, increment it then store the updated value back in memory. But the CPU controls wihich thread's instructions run. 

Therefore, thread 1 could fetch the timer from memory when it is at 7500. However, thread 2 could potentially switch to thread 2, and stay with thread 2 for a long time. In this case, thread 2 would get the value 7500 from memory, increment, and store, then repeat a ton of times. 

Say that therad 2 increments 500 times. After the last store instruction, the vaklye in memory would be aabout 8000. Then the CPU switches back to thread 1, who was about to store its updated value of 7501, which would overwrite the 8000 in memory. 

**Persistence:** Access infromation permanantly....

- Lifetime of innformation is longerr than the lifetime of any one process
- Machine may be rebooted, machine may lose power or crash unexpectedly
- Share information

**Issues:** 
- Provide abstraciton so applications do notknow how data is stored; Files, directories (fodlers), links
- Correctness with unexpected failures
- Performance: disks are very slow... many optimizations are needed

## OS Design Goals
- Build up some abstractions and make the system easy and convenient to use
- Provide High Performance by minimizing the overhead of the Operating System
- Protection between applications
- High degree of reliability
- Energy efficient

Useful commands

```grep [function name] *.[file type]```
