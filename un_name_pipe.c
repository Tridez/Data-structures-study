#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h> 
int main()
{
  char string[]="welcome to unnamed pipe";
  int filedes[2],pid;
  char inbuf[256];
  if(pipe(filedes)<0)
  {
    perror("could not create unnamed pipe");
exit(1);
  }
  if((pid=fork())<0)
  {
    perror("could not create subprocess");
    exit(1);
  }
  if(pid>0)
  {
    close(filedes[0]); 
write(filedes[1],string,strlen(string));
printf("the parent process sended:\n");
    close(filedes[1]);
    /*(1)*/
wait(0);
  }
  if(pid==0)
  {
    /*(2)*/
memset(inbuf,0,sizeof(inbuf));
    close(filedes[1]);
    sleep(5);
    read(filedes[0],inbuf,strlen(string));
    printf("the subprocess received:\n");
printf("%s\n",inbuf);
    close(filedes[0]);
  }
  exit(0);
}
