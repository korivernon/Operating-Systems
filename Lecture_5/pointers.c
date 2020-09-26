//pointers
#include <stdlib.h>
#include <sys/time.h>
#include <assert.h>
#include <stdio.h>

int main(){
    int *p = NULL;
    int y = 20;
    int x = 10;

    printf("At the start, x= %d, y = %d, p = %p\n", x, y, p);
    p = &x; // gets the address of x into p... p is pointing to x

    printf("Pointer at %p has a value %p and points to var with value %d\n", &p, p, *p);
    // .. the address of p THEN p(where p is pointing to) and p* is p dereferenced

    *p = 5;
    printf("After assigning to *p, x = %d\n", x);
    // the value of x is now changed..
    p = &y;
    // p is now pointing to y
    printf("Pointer at %p has value %p and points to var with value %d\n", &p, p, *p);
    // NOTE: DERTEFERENCING A POINTER WILLL PRINT THE POINTER ADDRESS

    *p = 50;
    printf("After assigning to *p, y = %d\n", y);
    return 0;
}
