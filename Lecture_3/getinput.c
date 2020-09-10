#include<stdio.h>
#include<stdlib.h>
int main(int argc, char *argv[]){

    if (argc != 2){
        fprintf(stderr, "Enter in one argument");
        exit(1);
    }
    char *str = argv[1];
    printf("You passed in: %s\n", str);
    return 0;
}
