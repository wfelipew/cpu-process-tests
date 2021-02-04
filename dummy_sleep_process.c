#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main( int argc, char *argv[]){
	printf("Starting dummy process\n");
	while(1){
		sleep(1);
	}
	return 0;
}
