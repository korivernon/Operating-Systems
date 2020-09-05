#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <assert.h>

void Spin(const int time){
    sleep(time);
}

int main(int argc, char *argv[]){
    if (argc != 2) {
        fprintf(stderr, "usage: cpu <string>\n");
        // http://www.cplusplus.com/reference/cstdio/fprintf/
        exit(1);
    }
    char *str = argv[1];
    while (1) {
        Spin(1);
        printf("%s\n",str);
    }
    return 0;
}
