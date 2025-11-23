#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>


int main() {
    int pipefd[2];     //array to hold the two ends of the pipe


    // create the pipe
    if (pipe(pipefd) == -1) {
        fprintf(stderr, "pipe failed\n");
        exit(1);

}

     // pipefd[0] is the READ end
     // pipefd[1] is the WRITE end

     // create First child

     int rc1 = fork();
    
     if (rc1 < 0) {
         fprintf(stderr, "fork1 failed\n");
         exit(1);

} else if (rc1 == 0) {

     // first child this will write the pipe

     printf("Child1 (PID: %d): I will write to the pipe\n", getpid());

      // close the read end ( we don't need it)
     close(pipefd[0]);

    // redirect stdout to the write end of the pipe
 
    close(STDOUT_FILENO);
    dup(pipefd[1]);    // now stdout goes to the pipe
    close(pipefd[1]);  // close the original fd

   // now writing something, that will go into the pipe
   printf("Hello from child 1!\n");

   exit(0);

}


   // create second child

  int rc2 = fork();

  if (rc2 < 0) {
     fprintf(stderr, "fork2 failed\n");
     exit(1);

} else if (rc2 == 0) {
     // second child this will read from the pipe

     printf("Child 2 (PID: %d): I will read from the pipe\n", getpid());

    // close the write end 

    close(pipefd[1]);

        // Redirect stdin to the read end of the pipe
    close(STDIN_FILENO);
    dup(pipefd[0]);  // Now stdin comes from the pipe
    close(pipefd[0]);  // Close the original fd

    char buffer[100];
    read(STDIN_FILENO, buffer, sizeof(buffer));


     printf("Child 2 received: %s", buffer);

     exit(0);
    }
    // PARENT - close both ends of pipe and wait for children
  close(pipefd[0]);

  wait(NULL);
  wait(NULL);


   printf("Parent: Both children finished\n");

    return 0;
}
