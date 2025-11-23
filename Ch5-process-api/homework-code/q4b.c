#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    printf("= using execlp() = \n");

    int rc = fork();

    if (rc < 0) {
       fprintf(stderr, "fork failed\n");
       exit(1);

} else if (rc == 0) {
      // child
      // execlp: list of arguments, searches Path (no full path needed)
      execlp("ls", "ls", "-l", NULL);
      printf("This shouldn't print");

} else {
     // parent
     wait(NULL);
     printf("Child completed\n");

}

  return 0;
}
