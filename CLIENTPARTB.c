#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#deKne MAXLINE 1024

int main() {
  int client_sock;
  struct sockaddr_in serv_addr;
  char buZer [MAXLINE];
  int rand_numb;

  // Create a socket.
  client_sock = socket(AF_INET, SOCK_STREAM, 0);
  if (client_sock == -1) {
    perror("socket");
    exit(1);
  }

  // Connect to the server.
  serv_addr.sin_family = AF_INET;
  serv_addr.sin_port = htons(8080);
  serv_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
  if (connect(client_socket, (struct sockaddress *)&serv_addr, sizeof(serv_addr)) == -1) {
    perror("connect");
    exit(1);
  }

  // Receive the random number from the server.
  recv(client_sock, buZer, sizeof(buffer), 0);
  rand_numb = atoi(buffer);

  // Print the random number.
  printf("Random number: %d\n", rand_numb);

  // Close the socket.
  close(client_sock);

  return 0;


