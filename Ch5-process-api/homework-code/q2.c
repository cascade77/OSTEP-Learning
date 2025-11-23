#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

int main() {

    //Open a file before forking
    int fd = open("test_file.txt", O_CREAT | O_WRONLY | O_TRUNC, 0644);
  
   if (fd < 0) {
      fprintf(stderr, "failed to open file\n");
      exit(1);
}

    int rc = fork();

  if (rc < 0) {
      fprintf(stderr, "fork failed\n");
      exit(1);

} else if (rc == 0) {

    // child created
    char *child_msg = "Child writing\n";
    write(fd, child_msg, strlen(child_msg));
    printf("Child wrote to file\n");

} else {

   // Parent
   char *parent_msg = "Parent writing\n";
   write(fd, parent_msg, strlen(parent_msg));
   printf("Parent wrote to file\n");

}

  close(fd);
  return 0;
}



