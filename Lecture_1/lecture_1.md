
## What is an Operating System?

**Operating System:** Software that converts hardware into a useful from for applications.

Levels: (1) Hardware, (2) Operating System, (3) Applications, (4) Users

The Operating Systems Requests: Memory Management/Allocation, File System Management, Cache Access and Storage. 

**Note: Applications don't talk to the hardware directly, they talk to the operating system.**

### Virtualization

The OS takes a physical resource and transforms it into a virtual form of itself. 

### Resource Manager

The OS manages resources such as CPU, memory, and disk. 

The OS allows many programs to run which shares CPU.

Many programs concurrently access their own instructions and data.

## Three Pieces: First

Virtualizing the CPU

```out
int main(int argc, char *argv[]){
    if (argc != 2){
        fprintf(stderr, "usage: cpu <string>\n");
        exit(1);
    }
    char *str = argv[1];
    while (1) {
        Spin(1); // checks the time and returns once it has run for a second
        printf("%s\n", str);
    }
    return 0'
}
```

Confusing stuff... ```int main(int argc, char *argv[])```

What ```argc``` does is count the amount of arguments in the command line. ```argc``` is int and stores number of command-line arguments passed by the user including the name of the program. 

The ```*argv[]``` gathers all of the references to the string in the command line. ```argv[]```  is array of character pointers listing all the arguments.

The ```Spin(const int time)``` function sleeps for one second when it's called. 



## Virtualizing Memory

The model of physical memory is an array of bytes. 

A program keeps all of its data structures in memory. 

Read Memory (load)

Write Memory (store)

**Concurrency: Events occurring** 

**Volatile:** C's volatile keyword is a qualifier that is applied to a variable when it is declared. It tells the compiler that the value of the variable may change at any time--without any action being taken by the code the compiler finds nearby. The implications of this are quite serious.

```void *function(void *arg)```
It's just a way of creating a 'harmless' reference to the variable. The compiler doesn't complain about an unused variable, because you did reference the value, and it doesn't complain that you didn't do anything with the value of the expression var because you explicitly cast it to void (nothing), indicating that you didn't care about the value.
