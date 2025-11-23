#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    printf("Parent PID: %d\n", getpid());
   

   int rc = fork();

   if (rc < 0) {
      fprintf(stderr, "fork failed\n");
      exit(1);

} else if (rc == 0) {
     // child
     printf("Child PID: %d\n", getpid());
    
    // calling wait in child

    int child_wait = wait(NULL);
    printf("Child: wait() returned %d\n",child_wait);

} else {
   // parent
    
   printf("Parent: created child with PID %d\n", rc);
  
  // parent waits for child
  int parent_wait = wait(NULL);
  printf("Parent: wait() returned %d\n", parent_wait);
  printf("Parent: Is this the same as child PID? %s\n", parent_wait == rc ? "YES" : "NO");

}

 return 0;

}
