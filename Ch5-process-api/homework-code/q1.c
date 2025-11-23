#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    int x = 100;    // setting x to 100 before forking

    printf("Before fork: x = %d\n", x);

    int rc = fork();         // creating child process

    if (rc < 0) {
    // fork failed

       fprintf(stderr, "fork failed\n");
       exit(1);

 } else if (rc == 0) {

   // child process created

  printf("Child: x = %d\n", x);
  x = 200;
  printf("Child after change: x = %d\n", x);

} else {

  // parent process created

  printf("Parent: x = %d\n", x);
  x = 300;
  printf("Parent after change: x = %d\n", x);

}

 return 0;

}
