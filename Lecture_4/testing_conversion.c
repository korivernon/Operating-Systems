//testing_conversion
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char * argv[]){
    
    int i, sz;
    for (i = 0; i < argc; i++){

        int temp = atoi(argv[i]);
        if (temp!= 0 ){
            printf("%d, num works\n", temp);
        }
        if (argv[i][0] == '-' ){
            printf("%s this works\n", argv[i]);
        }
        if (argv[i][1] == '+'){
            int next = atoi(argv[i][1]);
            printf("%d", next);
        }
        sz = sz + sizeof(argv[i]);
    }
    printf("Total Size: %d\n", sz);
    return 0;
}
