#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    printf("= using execv() =\n");
   
   int rc = fork();

   if (rc < 0) {
      fprintf(stderr, " fork failed\n");
      exit(1);

} else if (rc == 0) {
      // child  
      // execv: arguments as array (vector). need Full path
      char *args[] = {"ls", "-l", NULL};
      execv("/bin/ls", args);
      printf("This shouldn't print\n");

} else {

     // parent
     wait(NULL);
     printf("Child completed\n");
}

 return 0;

}
