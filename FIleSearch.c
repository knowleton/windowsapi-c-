#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include<io.h>

extern struct stu{

    int number;
    char name[50];
    char sex;
    double score[3];
    double sum;
    struct stu *next;

};
int FileSearch(char a[])
{
wsprintf(a,TEXT("已有文件:\n"));
char buf22[100];
    long handle;                                                //用于查找的句柄
             struct _finddata_t fileinfo;                          //文件信息的结构体
             handle=_findfirst("*.csv",&fileinfo);                        //第一次查找
             if(-1==handle)return -1;
             wsprintf(buf22,"%s\n",fileinfo.name);
             strcat(a,buf22);                         //打印出找到的文件的文件名
             while(!_findnext(handle,&fileinfo))               //循环查找其他符合的文件，知道找不到其他的为止
             {
                  wsprintf(buf22,"%s\n",fileinfo.name);
                  strcat(a,buf22);
             }
             _findclose(handle);                                      //别忘了关闭句柄

             return 0;


}
