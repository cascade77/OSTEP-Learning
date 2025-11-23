#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


int main() {

     int rc = fork();  // Create child process

      if (rc < 0) {
        // Fork failed
        fprintf(stderr, "fork failed\n");
        exit(1);
    } else if (rc == 0) {
        // CHILD PROCESS
        printf("hello\n" );


    } else {
        // PARENT PROCESS
       sleep(1);
        printf("goodbye\n");
    }

    return 0;
}
