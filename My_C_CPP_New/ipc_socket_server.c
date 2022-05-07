#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include<arpa/inet.h>

#define ERROR -1
#define MAX_CLIENT 2
#define MSG_SIZE 1024

int main(int argc, char** argv) {
	int sock, new, msg_len, ack_msglen;
	char ack_msg[MSG_SIZE] = "Message Received Successfull!!!";
	ack_msglen = sizeof(ack_msg);
	char msg[MSG_SIZE];

	struct sockaddr_in server;
	struct sockaddr_in client;
	int sockaddr_len = sizeof(struct sockaddr_in);

	if ((sock = socket(AF_INET, SOCK_STREAM, 0)) == ERROR) {
		perror("socket creation failed");
		exit(1);
	}
	else {
		printf("The socket creation done\n");
	}


	server.sin_family = AF_INET;
	server.sin_port = htons(atoi(argv[1]));
	server.sin_addr.s_addr = htonl(INADDR_ANY);
	bzero(&server.sin_zero, 8);

	if ((bind(sock, (struct sockaddr*) & server, sockaddr_len)) == ERROR) {
		perror("Bind failed");
		exit(1);
	}
	else {
		printf("Binding socket with sockaddr is done\n");
	}

	if (listen(sock, MAX_CLIENT) == ERROR) {
		perror("Listen failed");
		exit(1);
	}
	else {
		printf("Listen client is done\n");
	}

	while (1) {
		if ((new = accept(sock, (struct sockaddr*) & client, &sockaddr_len)) == ERROR) {
			perror("accept failed");
			exit(1);
		}
		else {
			printf("New client accepted\n");
		}

		while (1) {
			msg_len = recv(new, msg, MSG_SIZE, 0);
			if (msg_len) {
				msg[msg_len] = '\0';
				printf("Received data from client is : %s\n", msg);
				printf("Sending ack to client\n");
				send(new, ack_msg, ack_msglen, 0);
			}
		}
		printf("Client is disconneting\n");
		close(new);
	}

	return 0;
}
