#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/prctl.h>


void handler(){
	return;
}


int main(int argc,char *argv[]){
	int pid;
	signal(SIGCHLD,handler);

	pid=fork();

	if(pid==0){
		printf("Child process\n");
		while(1){
			sleep(20);
		}
        }else {
		printf("Parent process\n");
		while(1){
			sleep(20);
		}
	}

 
}

