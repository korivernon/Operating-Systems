//casting
#include <stdlib.h>
#include <sys/time.h>
#include <assert.h>
#include <stdio.h>

int main() {
    char x[] = "POLY";
    int *y;
    y = (int *) &x;
    printf("%s is %d\n", x, *y);
    /*
     * POLY is 1498173264
     * Why?!?!?!
     * Because "POLY" = {'P', 'O', 'L', 'Y', '\0'}
     *  = 0x50, 0x4f, 0x4c, 0x59, 0x00
     *  0x594c4f50
     *  148173264
     */
    // You can also cast int he other direction
    int poly = 1498173264;
    return 0;
}
