 /*③ file.h文件的内容如下：*/
#include <stdio.h>
#include <stdlib.h>
#include "book.h"        
int  createFile(Book boo[ ])              /*建立初始的数据文件*/
{
	FILE *fp;
	int n;
   	if((fp=fopen("d:\\book.dat", "wb")) == NULL) /*指定好文件名，以写入方式打开*/
	{
	    printf("can not open file !\n");         /*若打开失败，输出提示信息*/
	    exit(0);                           /*然后退出*/
    	}
	printf("input books\' information:\n");
	n=readBoo(boo,NUM);                /*调用book.h中的函数读数据*/
fwrite(boo,sizeBoo,n,fp);                  /*将刚才读入的所有记录一次性写入文件*/
 	fclose(fp);                             /*关闭文件*/
	 return n;
}

int readFile(Book boo[ ] )                     /*将文件中的内容读出置于结构体数组boo中*/
{
   	FILE *fp;
	int i=0;
	if((fp=fopen("d:\\book.dat", "rb")) == NULL)  /*以读的方式打开指定文件*/
	{
	    printf("file does not exist,create it first:\n");  /*如果打开失败输出提示信息*/
	    return 0;                              /*然后返回0*/
	}	 
    	fread(&boo[i],sizeBoo,1,fp);                   /*读出第一条记录*/
   	while(!feof(fp))                            /*文件未结束时循环*/
	{
		i++;
	    	fread(&boo[i],sizeBoo,1,fp);              /*再读出下一条记录*/
     }
	fclose(fp);                                /*关闭文件*/
	return i;                                  /*返回记录条数*/
}

void saveFile(Book boo[],int n)                  /*将结构体数组的内容写入文件*/
{   			
  	FILE *fp;	
   	if((fp=fopen("d:\\book.dat", "wb")) == NULL) /*以写的方式打开指定文件*/
	{
		printf("can not open file !\n");           /*如果打开失败，输出提示信息*/
		exit(0);                            /*然后退出*/
	}
	fwrite(boo,sizeBoo,n,fp);        
	fclose(fp);                              /*关闭文件*/
}
