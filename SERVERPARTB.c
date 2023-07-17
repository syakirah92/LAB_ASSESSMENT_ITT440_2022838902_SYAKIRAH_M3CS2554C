#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>

int main() {
  int server_socket, client_socket;
  struct sockaddr_in server_address, client_address;
  char mssg[1024];
  int random_number;

  // Create a socket.
  server_socket = socket(AF_INET, SOCK_STREAM, 0);
  if (server_socket == -1) {
    perror("socket");
    exit(1);
  }

  // Bind the socket to a port.
  server_address.sin_family = AF_INET;
  server_address.sin_port = htons(8080);
  server_address.sin_addr.s_addr = INADDR_ANY;
  if (bind(server_socket, (struct sockaddr *)&server_address, sizeof(server_address)) == -1) {
    perror("bind");
    exit(1);
  }

  // Listen for connections.
  listen(server_socket, 1);

  // Accept a connection.
  client_socket = accept(server_socket, (struct sockaddr *)&client_address, sizeof(client_address));
  if (client_socket == -1) {
    perror("accept");
    exit(1);
  }

  // Generate a random number.
  random_number = rand() % (80000 - 50000 + 1) + 50000;

  // Send the random number to the client.
  sprintf(mssg, "%d", random_number);
  mssg[strlen(mssg)] = '\0';
  send(client_socket, mssg, strlen(mssg) + 1, 0);

  // Close the sockets.
  close(server_socket);
  close(client_socket);

  return 0;
}
