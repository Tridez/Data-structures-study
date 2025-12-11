#include <stdio.h>   
#include <stdlib.h>   
#include <string.h>   
#include <pwd.h>   
#include <sys/types.h>   
#include <grp.h>   
#include <sys/stat.h>   

void Usage();  /*函数声明*/
int cats();

int main(int argc, char *argv[])   /* argc 传入main函数参数个数， argv传入main函数的参数序列或指针，argv[0]表示程序名*/
{     
  if (argc < 2)   /*说明没有输入要显示的文件名*/
  {  
    void Usage();  
    return -1;  
  }  
  else  
  {    
    cats(argv[1]);  
  }  
  return 0;  
}  
   
int cats(const char* filename)  
{  
  FILE *fp = NULL;  /*定义一个文件类型指针，指向文件，先赋初值,让文件指针指向空*/
  char *buffer = NULL;  
  struct stat st;   /*定义了一个叫st的结构体，stat函数可以获取指定文件的各种属性数据。所以stat函数是用来把文件或者路径的属性信息识别并保存在内存中。*/
  stat(filename, &st);  /*stat() 函数功能是获取文件相关信息，包含文件大小，&取地址，stat()用来将参数filename 所指的文件状态, 复制到参数st所指的结构中。&st表示结构体st在内存中的地址*/
  int number = 0; 
  /***********根据文件的大小动态申请内存************/
  buffer = (char *)malloc(sizeof(char)*st.st_size);   /*字符指针所占的字节数(4个字节)，因为buffer定义类型为char*，malloc默认返回值是void*（任何指针类型），由于类型不一致，所以必须强制转换成char*类型*/
  /**********************************************/ 
  memset(buffer, 0, st.st_size);  //initiate the memory allocated to 0
   
  fp = fopen(filename, "r");  /*以只读方式打开文件*/
  if (fp == NULL)   /*如果打开成功的话就把该文件的信息结构体地址赋给文件指针fp，如果打开不成功的话，就将文件指针fp置为无效（NULL）*/
  {  
    printf("open file failer!\n");  
    fclose(fp);  
    return -1;  
  }  
   
  number = fread(buffer, st.st_size, 1, fp);  /*read the file and put the content into the buffer，buffer为指针，是读入数据的存放地址，st.st_size表示要读取的数据项的大小（字节数），1，表示读取的次数，fp表示文件类型指针即已打开的文件，fread返回值是读取的数据项的总个数*/
  if (number < 0)  
  {  
    printf("read file failer!\n");  
    fclose(fp);  
    return -1;  
  }  
     
  printf("%s", buffer);     
   /********释放申请的动态内存***********/
  free(buffer);
  /************************************/
     
  fclose(fp);  
  return 0;  
}  
    void Usage()  
{  
  printf("format error!Parameter input format:\n");  
  printf("\tformat: ./cat filename\n");   /*\t 代表制表符,就是三个空格,等效于tab键*/
}  
