#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    printf("Parent: Before fork\n");
   
    int rc = fork();

   if (rc < 0) {
      fprintf(stderr, "fork failed\n");
      exit(1);

} else if (rc == 0) {

    // child
    printf("Child: Before closing STDOUT\n");

    // close standard  output

    close(STDOUT_FILENO);
   
   // Now try to print after closin stdout

    printf("Child: After closing STDOUT can you see this?\n");

  // try writing directory to check

   printf("Child: Is this visible?\n");

} else {

  // parent
   wait(NULL);
   printf("Parent: Child finished\n");

}

  return 0;

}
