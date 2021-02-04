#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int main( int argc, char *argv[]){
	int fd;
	char buff[10];
	ssize_t size;
	printf("Starting dummy process\n");
	fd=0;

	if(fd<0){
		printf("Error opening %s file\n",argv[1]);
	}

	while(1){
		size=read(fd,buff,sizeof(buff));
		buff[size]='\0';
		printf("%s",buff);
		if(size<0){
			printf("ERROR READING\n");
		}
	}
		
	return 0;
}

