#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>


int main() {
    printf("Parent PID : %d\n", getpid());

    int rc = fork();

   if (rc < 0) {
   fprintf(stderr, "fork failed\n");
   exit(1);

}  else if (rc == 0) {
   
   printf("Child PID: %d\n", getpid());
   sleep(2);
   printf("Child done!\n");

} else {
   
   printf("Parent: created child with PID %d\n", rc);
  // wait for specific child using waitpid()
  
  int status;
  int result = waitpid(rc, &status, 0);

  printf("Parent: waitpid() returned %d\n", result);
  printf("Parent: Waited for child %d\n", rc);

}
  return 0;

}

