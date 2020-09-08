# Virtualizing the CPU

Foreground - The front; Background - The back. Whatever is in the front is getting the most CPU cycles.

Virtual Memory - Each process has its own private virtual address space. 

**Concurrency:** Events occurring simultaneously and may interact with one another.

```thread.c``` Before, we had two different processes. Now we have one process accessing the same values. Incrementing a shared counter takes 3 instructions. 
- First, we load from memory to register
- Then we increment that register
- Then store that value into memory

