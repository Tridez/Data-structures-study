#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <unistd.h>

int main(int argc,char *argv[])  /* 用于运行时，把命令行参数传入主程序.argc:命令行参数的总个数，argv[]:为字符串数组，用来存放指向的字符串参数的指针数组，每一个元素指向一个参数，argv[0]指向程序运行的全路径名*/
{
  pid_t  pid;
  char  cmd;
  char *arg_psa[]={"ps","-a",NULL};
  char *arg_psx[]={"ps","x",NULL};

  while(1)
  {
    printf("-----------------------------------------------\n");
    printf("输入a执行'ps -a'命令\n");
    printf("输入x执行'ps  x'命令\n");
    printf("输入q退出\n");
    cmd=getchar();     /*接收输入命令字符*/
    getchar();

    if((pid=fork())<0)
    {/*创建子进程失败*/
      perror("fork error!");
      return -1;
    }
    if(pid==0)/*子进程*/
    {
      switch(cmd)
      {
        case  'a':
          execv("/bin/ps",arg_psa); /*1、执行文件部分。2、命令参数部分。3、环境变量部分*/
          break;
        case  'x':
          execv("/bin/ps",arg_psx);
          break;
        case  'q':
          break;  /*满足条件，退出switch循环，否则继续执行下一个case语句*/
        default:
          printf("wrong cmd! try again!\n");
      }/*子进程结束*/
      exit(0);/*子进程提前结束，返回到父进程。*/
    }
    else
    {/*父进程*/
      if(cmd=='q')
        break;
    }
  }/*进程退出循环*/

  while(waitpid(-1,NULL,WNOHANG)>0);/*-1：回收所有子进程，NULL：不关心进程的状态，WNOHANG返回值为0，子进程没有结束，返回值>0，代表子进程结束。*/ 
  return 0;
}