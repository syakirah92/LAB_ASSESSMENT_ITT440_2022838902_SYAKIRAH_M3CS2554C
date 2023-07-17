#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/wait.h>

void signal_handler(int signal) {
  printf("Received signal: %d\n", signal);
}

int main() {
  int pipefd[2];
  int child_pid;
  char mssg[100];

  // To create a pipe.
  pipe(pipefd);

  // Set up signal handler.
  signal(SIGINT, signal_handler);

  // Fork 3 child processes.
  for (int i = 0; i < 3; i++) {
    child_pid = fork();
    if (child_pid == 0) {
      // This is a child process.
      // Send a message to the parent process.
      int c = 0;
      sprintf(mssg, "Hello from child %d!", c);
      write(pipefd[1], mssg, strlen(mssg));
      // Terminate the child process.
      exit(0);
    }
  }

  // This is the parent process.
  // Read the message from the child process.
  read(pipefd[0], mssg, sizeof(mssg));
  printf("Received message from child: %s\n", mssg);

  // Wait for all child processes to terminate.
  for (int i = 0; i < 3; i++) {
    wait(NULL);
  }

  // Interrupt the program by pressing `Ctrl+C`.
  printf("Press Ctrl+C to interrupt the program.\n");
  while (1) {
  }

  return 0;
}
