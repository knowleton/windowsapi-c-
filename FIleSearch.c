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
wsprintf(a,TEXT("�����ļ�:\n"));
char buf22[100];
    long handle;                                                //���ڲ��ҵľ��
             struct _finddata_t fileinfo;                          //�ļ���Ϣ�Ľṹ��
             handle=_findfirst("*.csv",&fileinfo);                        //��һ�β���
             if(-1==handle)return -1;
             wsprintf(buf22,"%s\n",fileinfo.name);
             strcat(a,buf22);                         //��ӡ���ҵ����ļ����ļ���
             while(!_findnext(handle,&fileinfo))               //ѭ�������������ϵ��ļ���֪���Ҳ���������Ϊֹ
             {
                  wsprintf(buf22,"%s\n",fileinfo.name);
                  strcat(a,buf22);
             }
             _findclose(handle);                                      //�����˹رվ��

             return 0;


}
