// your code here

#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <errno.h>
#include <stdio.h>
#include <sys/wait.h>
#include <stdlib.h>



int main (int argc, char *argv[]){
	int a, b, res;
	pid_t p1, p2, p3, p4;
	res = 0;

	
	if(argc != 3) {
		perror("Enter only two arguments \n");
		exit(1);}
	
	a = atoi(argv[1]);
	b = atoi(argv[2]);

	p1 = fork();
	if (p1<0){
		perror("Fork failed/n");
		exit(1);

	}


	if (p1==0){
		res = a+b;
		printf("child1: %d+%d=%d \n", a, b, res);
		exit(0);
	}

	p2 = fork();
	if (p2<0){
		perror("Fork failed/n");
		exit(1);

	}
	if (p2==0){
		res = a-b;
		printf("child2: %d-%d=%d \n", a, b, res);
		exit(0);
	}
	p3 = fork();
	if (p3<0){
		perror("Fork failed/n");
		exit(1);

	}
	if (p3==0){
		res = a*b;
		printf("child3: %d*%d=%d \n", a, b, res);
		exit(0);
	}
	p4 = fork();
	if (p4<0){
		perror("Fork failed/n");
		exit(1);

	}
	if (p4==0){
		res = a/b;
		printf("child4: %d/%d=%d \n", a, b, res);
		exit(0);
    
	}
    else{
        wait(0);
        wait(0);
        wait(0);
        wait(0);
        printf("Parent done: \n");
        
    }
	
    
	


	}

