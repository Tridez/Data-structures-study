#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

int main()
{
  pid_t pid;
  pid=fork();
  switch(     ¢Ù      )
  {
    case -1:
      printf("fork fail!\n");
      exit(1);
    case 0:
      execl(       ¢Ú         );
      printf("execl fail!\n");
      exit(1);
    default:
      wait(      ¢Û         );
      printf("Is completed!\n");
      exit(0);
  }
  return 0;
}
