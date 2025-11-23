#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>


int main() {
    printf("Running ls using exec()\n");


    int rc = fork();

    if (rc < 0) {
       fprintf(stderr, "fork failed\n");
       exit(1);

} else if (rc == 0) {

     // Child runs ls
   execl("/bin/ls", "ls", NULL);

    // if exec succeeds, this line never runs

   printf("This shouldn't print\n");

} else {

   // Parent wait for child
  wait(NULL);
  printf("Child completed\n");

}

return 0;
}
