//swap
#include <stdlib.h>
#include <sys/time.h>
#include <assert.h>
#include <stdio.h>

void myswap (int *x, int *y){
    int temp = *x;

    *x = *y;
    *y = temp;

}
/*
void myswap2( int &x, int &y ){
    int temp = x;
    x = y;
    y = temp;
}
*/
void XorSwap (int *x , int *y) {
    if (x != y){
        *x ^= *y;
        *y ^= *x;
        *x ^= *y;
    }
}

int main(){
    int x = 42, y = 54;

    printf("Before: x = %d, y = %d\n", x, y);
    myswap(&x, &y);
    //myswap2(x, y);
    XorSwap(&x, &y);
    printf("After: x = %d, y = %d\n", x, y);
    return 0;
}
