#include "types.h"
#include "stat.h"
#include "user.h"

char buf[1024];
char buf2[1024];

void tail(int fd,char *name, int userInput, int mode, int reg){
	int i,n,m,l = 0,lines = 0, bytes = 0;
    while((n=read(fd,buf,sizeof(buf)))>0) {
        for(i=0;i<=n ;i++) {
            if(buf[i]=='\n') {
            lines++;  // Loop for total number of lines in the file
            } else {
                bytes++;
            }
        }
	}
	close(fd);
	int temp = open(name,0); //creating temporary file
    // if it is the first mode and strictly line numbers, execute this way
    if (mode == 1 || mode == 0) {
        while((m=read(temp,buf2,sizeof(buf2)))>0) {
            for(i=0;i<=m;i++){
                if(buf2[i] == '\n') l++;
                if (reg == 0){
                    if(lines-userInput<=l) {
                        if(buf2[i] !='\n' && l>=lines-userInput){
                            printf(1,"%c",buf2[i]);
                        } else if (lines-userInput == l) l++; //for some reason a new line character is printing prematurely. just ommitting
                        else {
                            printf(1,"\n");
                            l++;
                        }
                    }
                } else if (reg == 1) {
                    if(userInput<=l) {
                    if(buf2[i] !='\n' && l>=userInput){
                        printf(1,"%c",buf2[i]);
                    } else if (userInput == l) l++; //for some reason a new line character is printing prematurely. just ommitting
                    else {
                        printf(1,"\n");
                        l++;
                    }
                }
                }
            }
	    }
    }
    else if (mode == 2){
        int tempbytes = 0;
        while((m=read(temp,buf2,sizeof(buf2)))>0) {
            for(i=0;i<=m;i++){
                if(buf2[i] != '\n') tempbytes++;

                if (reg == 0) {
                    if(bytes-userInput<=tempbytes) {
                        if(buf2[i] !='\n' && tempbytes>=lines-userInput){
                            printf(1,"%c",buf2[i]);
                        } else if (bytes-userInput == tempbytes) tempbytes++; //for some reason a new line character is printing prematurely. just ommitting
                        else {
                            printf(1,"\n");
                            tempbytes++;
                        }
                    }
                } else if (reg == 1) { // this is the second option
                    if(userInput<=tempbytes) {
                        if(buf2[i] !='\n' && tempbytes>=userInput){
                            printf(1,"%c",buf2[i]);
                        } else if (userInput == tempbytes) tempbytes++; //for some reason a new line character is printing prematurely. just ommitting
                        else {
                            printf(1,"\n");
                            tempbytes++;
                        }
                    }
                }
            }
	    }
    }
	
	close(temp);
	if(n<0) { //we have an error so show error message
		printf(1,"tail: Error while reading file \n");
		exit();
	}
}

int main(int argc,char *argv[]) {
	int fd,i, mode = 0, reg = 0, line = 10;
	if(argc<=1){
		tail(0,"",line, mode, reg);
		exit();
	} else if(argc==2){// if we have 2 arguments then we call with default
		for(i=1;i<argc;i++){
			if((fd=open(argv[i],0))<0){
				printf(1,"Error, cannot read file\n");
				exit();
			} 
            tail(fd,argv[i],line, mode, reg); // call with default 10 for two arguments
            close(fd);
		}
	}
    else if (argc>2) {
        for (i = 1; i < argc; i++){
            //here we are detecting for a number
            char c[1024];
            strcpy(c, argv[i]);
            char *num = c;
            num = num;
            int temp = atoi(num);

            if (temp != 0) {
                // we are just going to pass it to the function
                line = temp;
               // printf(1,"Tringgered num; Value = %d\n", line);
            }
            //now we need to detect for a "-", which represents a byte or number
            if (argv[i][0] == '-'){
                if (argv[i][1] == 'n') {
                    mode = 1;
                //    printf(1, "Triggered 'n'\n");
                }
                else if (argv[i][1] == 'c'){
                    mode = 2;
                //    printf(1, "Triggered 'c'\n");
                }
            }
            // now we are going to check for a modifier for the pm
            if (argv[i][0] == '+'){
                char c[1024];
                strcpy(c, argv[i]);
                char *num = c;
                num = num+1;
                int temp = atoi(num);
                temp = atoi(num); //convert to an integer
                line = temp;
               // printf(1,"Tringgered +; Value = %d\n", line);
                reg = 1;
            }
        }
        for (i = 1; i < argc; i++){
          // now we are going to try to open the file now that we have everything
            if((fd=open(argv[i],0))<0){
                exit();
            }
            tail(fd, argv[i], line, mode, reg);
        }
        
    }
	else {
		printf(1,"tail: syntax error");
	}
	exit();
}