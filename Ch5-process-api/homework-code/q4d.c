#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    printf("= Using execvp() =\n");

    int rc = fork();

    if (rc < 0) {

       fprintf(stderr, "fork failed\n");
       exit(1);

} else if (rc == 0) {

       // child
       // execvp: arguments as array, searches Path
       // This is the one used in p3.c from the book

      char *args[] = {"ls","-l", NULL};
      execvp("ls", args);
      printf("This shouldn't print\n");

} else {

     wait(NULL);
     printf("Child completed\n");
   }

 return 0;

}
     
