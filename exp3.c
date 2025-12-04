#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
  pid_t pid;
  int n;

  pid=fork();

  switch(pid)
  {
    case -1:
      perror("fork failed!");
      exit(EXIT_FAILURE);
      break;
    case 0:
      n=5;
      for(;n>0;n--){
      printf("child process PID is %d.\n", getpid());sleep(1);}
      break;
default:
      n=3;
      for(;n>0;n--){
      printf("parent process PID is %d.\n", getppid());sleep(1);}
  }
  return 0;
}
