#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

#include <sys/socket.h>
#include <sys/types.h>
#include<arpa/inet.h>

int main( int argc, char *argv[]){
	
	int http_socket, client_size, fd;
	struct sockaddr_in server, client;
	char buff[8096];
	ssize_t size;
	client_size= sizeof(struct sockaddr_in);
	
	char *dummy_response_body = "<h1>Hello world!</h1>\n";
	int  dummy_response_size = strlen(dummy_response_body);
	char dummy_response[8096];
        sprintf(dummy_response,"HTTP/1.1 200 OK\r\nContent-Type: text/html\r\nContent-Length: %d\r\n\r\n%s",dummy_response_size,dummy_response_body);	
	printf("Starting dummy http server\n");

	/*Open a TCP IPv4 socket*/
	http_socket=socket(AF_INET,SOCK_STREAM,0);
	/*Check if socket is open*/
	if(http_socket<0){
                printf("Error opening socket\n");
		return 1;
        }
	printf("Socket created\n");

	/*Set sockaddr_in properties with any IP on 8066 port*/	
	server.sin_family = AF_INET;
	server.sin_addr.s_addr = INADDR_ANY;
	server.sin_port = htons(8066);
	
	/*Assign IP and PORT to socket*/
	bind(http_socket,(struct sockaddr *)&server, sizeof(server));
	printf("Binding to 8066 port\n");

	/*Set the socket as a listen socket, with max waiting connection on 5*/
	if(listen(http_socket,5)!=0){
		printf("Failed to listen on socket\n");
		return 1;
	}
	printf("Socket is listennig\n");

	/**/
	while(1){
		/*Accept incoming connections*/
		printf("Accepting connections\n");
		fd=accept(http_socket, (struct sockaddr *) &client,(socklen_t*)&client_size);
		if(fd==-1){
			printf("Error establishing connection");
			continue;
		}
		/*Read client request*/
		read(fd,buff,sizeof(buff));
		printf("Received request:\n %s \n",buff);
		/*Send client response*/
		write(fd,dummy_response,strlen(dummy_response));
		memset(buff,0,sizeof(buff));
		close(fd);		

	}
		
	return 0;
}

