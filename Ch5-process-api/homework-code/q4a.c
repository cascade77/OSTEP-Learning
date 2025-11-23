#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    printf("=Using exec() =\n");

    int rc = fork();

   if (rc < 0) {
       fprintf(stderr, "fork failed\n");
       exit(1);

} else if (rc == 0) {
    // child
    // execl: list of arguments, need Full path
    execl("/bin/ls", "ls", "-l", NULL);
    printf("This shouldn't print\n");

} else {

   // parent
   wait(NULL);
   printf("Child completed\n");

}

   return 0;

}
