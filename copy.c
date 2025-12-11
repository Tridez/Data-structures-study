#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pwd.h>
#include <sys/types.h>
#include <grp.h>
#include <sys/stat.h>

int copys(const char *filename,const char *file2); /*定义了一个名为 copys 的函数，该函数接受两个参数，这里的参数分别命名为 filename 和 file2*/
void Usage();

int main(int argc, char *argv[])
{
  if (argc < 3){
    Usage();
    return -1;
  }
  else{
    copys(argv[1],argv[2]);
  }
  return 0;
}

int copys(const char *filename,const char *file2){ 

  FILE *fp = NULL; /*C标准库中定义的一个结构体类型，用于表示一个文件流。它包含了文件操作所需的所有信息*/
  FILE *fq = NULL;  /*NULL表示一个空指针，即不指向任何有效的内存地址,表明在初始化时，fp 不指向任何文件*/
  char *buffer = NULL;
  struct stat st;
  stat(filename, &st);
  int number = 0;
  int i=0;
  buffer = (char *)malloc(sizeof(char)*st.st_size);
  memset(buffer, 0, st.st_size); /*buffer是一个指针，指向要填充的内存块的起始地址*/

  fp = fopen(filename, "r"); /*文件打开成功，则返回该文件结构体的指针，如果 打开失败,则返回NULL（即0）*/
  fq = fopen(file2, "w");
  if (fp == NULL) {
    printf("open file failer!\n");
    fclose(fp);
    return -1;
  }

  number = fread(buffer, st.st_size, 1, fp); /*fread函数返回值为实际读取的数据项个数。读了一个数据项，数据项的大小为st结构体的大小（st.st_size）字节*/
  if (number < 0){
    printf("read file failer!\n");
    fclose(fp);
    return -1;
  }

  printf("%s", buffer);
  while(buffer[i]!='\0')  /*字符串总是以'\0'作为串的结束符*/
{
   putc(buffer[i],fq);  /*该函数的作用是向终端输出一个字符*/
   i++;
  }
  free(buffer);
  fclose(fp);
  fclose(fq);
  return 0;
}

void Usage(){
  printf("format error!Parameter input format:\n");
  printf("\tformat: ./copy filename1 filename2\n");
}
