#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include<sys/wait.h>

int child_task(int read_pipe, int read_pipe2) {
  char to_msg[25];
  char to_msg2[35];
  int nr;

  if ((nr = read(read_pipe, to_msg, 25)) == -1) {
    perror("child failed to read from pipe");
    return 1;
  }

  printf("child received message from parent.\n");
  printf("message received: %s\n", to_msg);

    if ((nr = read(read_pipe2, to_msg2, 35)) == -1) {
    perror("child failed to read from pipe");
    return 1;
  }

  printf("child received message from parent.\n");
  printf("message received: %s\n", to_msg2);

  return 0;
}

int parent_task(int write_pipe, int write_pipe2) {
  int nw;
  char from_msg[] = "Thank you for the money!";
  char from_msg2[] = "Wish you were here in Paris with me";

  if ((nw = write(write_pipe, from_msg, strlen(from_msg) + 1)) == -1) {
    perror("parent failed to write to pipe");
    exit(1);
  }

  printf("parent sent message to child.\n");
  printf("message sent: %s.\n", from_msg);

  if ((nw = write(write_pipe2, from_msg2, strlen(from_msg2) + 1)) == -1) {
    perror("parent failed to write to pipe");
    exit(1);
  }

  printf("parent sent message to child.\n");
  printf("message sent: %s.\n", from_msg2);

  return 0;
}

int main() {
  int parent_to_child_pipe[2];
  int parent_to_child_pipe2[2];

  // Create the pipe
  if (pipe(parent_to_child_pipe) == -1) {
    perror("could not create pipe");
    exit(1);
  }

    if (pipe(parent_to_child_pipe2) == -1) {
    perror("could not create pipe2");
    exit(1);
  }

  pid_t pid;
  if ((pid = fork()) == 0) {
    // Child process...
    // First we close the write end of the pipe.
    close(parent_to_child_pipe[1]);
    close(parent_to_child_pipe2[1]);
    exit(child_task(parent_to_child_pipe[0], parent_to_child_pipe2[0]));
    
  } else {
    // Parent process...
    // First, we close the read end of the pipe.
    close(parent_to_child_pipe[0]);
    close(parent_to_child_pipe2[0]);
    exit(parent_task(parent_to_child_pipe[1], parent_to_child_pipe2[1]));

    // Wait on child process to complete
    wait(NULL);
    printf("parent process completing.\n");
  }
}
