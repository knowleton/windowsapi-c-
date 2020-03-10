#include<stdio.h>
#include<stdlib.h>
#include<windows.h>

struct stu{

    int number;
    char name[50];
    char sex;
    double score[3];
    double sum;
    struct stu *next;

};


FILE * FileLoad(char a[])
{
    FILE  *p=NULL;
    p=fopen(a,"r");
    if(p==NULL)
    {
        fclose(p);
        p=fopen(a,"w");

    }
    fclose(p);
    p=fopen(a,"r");
    return p;
}

struct stu * StuLoad(FILE *f)
{
    char c;
    int i;
    struct stu StuBuf,headd,*head,*p,*p1,*tail;
    head=p=p1=tail=(struct stu *)malloc(sizeof(struct stu));;
    p->next=NULL;
    while(!feof(f)){

        if(fscanf(f,"%d",&(StuBuf.number))==-1)
        {
            p->next=NULL;
            break;
        }
printf("%d\n",StuBuf.number);
        ///,
        fgetc(f);

       //
        c=fgetc(f);
      for(i=0;c!=',';i++)
        {
            (StuBuf.name)[i]=c;
            c=getc(f);
        }
        StuBuf.name[i]='\0';
printf("%s\n",StuBuf.name);
        //

        StuBuf.sex=fgetc(f);
/// ,
        fgetc(f);

        //
        fscanf(f,"%lf,%lf,%lf,%lf\n",&(StuBuf.score[0]),&(StuBuf.score[1]),&(StuBuf.score[2]),&(StuBuf.sum)  ) ;
    /// //////////////////////////////////////////////////////////////////////////////
    p->next=(struct stu *)malloc(sizeof(struct stu));
    p=p->next;
    *p=StuBuf;
    p->next=NULL;


    }
    fclose(f);
    return head;

};

char * ShowMessage(struct stu * head, char a[])
{
    memset(a,'\0',1000);
    struct stu *p;
    p=head;
    int i=0,j;
    char buff[1000]={'\0'};
//if(p->next==NULL &&i==0)
//{
//AllocConsole();
//freopen("conin$", "r+t", stdin);
//freopen("conout$", "w+t", stdout);
//freopen("conout$", "w+t", stderr);
//    printf("dssdfsd");
//}
        while(p->next!=NULL)
    {

        p=p->next;

        i+=sprintf(a+i,"学号:%d 姓名:%s 性别:%c FOX:%.2lf ENGLISH:%.2lf C:%.2lf 总分:%.2lf\r\n",p->number,p->name,p->sex,p->score[0],p->score[1],p->score[2],p->sum);


    }


    return a;


}

void FileSave(struct stu * head , char a[])
{

    FILE *f;
    f=fopen(a,"w");
    struct stu *p;
    p=head;

    while(p->next!=NULL)
    {
        p=p->next;
        fprintf(f,"%d,%s,%c,%.2lf,%.2lf,%.2lf,%.2lf\n",p->number,p->name,p->sex,p->score[0],p->score[1],p->score[2],p->sum);
    }
    fclose(f);

}









//struct stu * GEtMessage(char a[])
//{
//    int i,j;
//    struct stu StuBuf,*head,*p;
//    head=p=(struct stu *)malloc(sizeof(struct stu));
//    p->next=NULL;
//    char tt[10000]={'\0'};
//    i=0;
//    while(1)
//    {
//
//        j=sscanf(a+i,"学号:%d 姓名:%s 性别:%c 高数:%lf 线代:%lf C语言:%lf 总分:%lf\r\n",&(StuBuf.number),(StuBuf.name),&(StuBuf.sex),&(StuBuf.score[0]),&(StuBuf.score[1]),&(StuBuf.score[2]),&(StuBuf.sum));
//
//        if(j<0)
//        {
//            break;
//
//        }
//
//        memset(tt,'\0',10000);
//        sprintf(tt,"学号:%d 姓名:%s 性别:%c 高数:%.2lf 线代:%.2lf C语言:%.2lf 总分:%.2lf\r\n",&StuBuf.number,(StuBuf.name),&(StuBuf.sex),&(StuBuf.score[0]),&(StuBuf.score[1]),&(StuBuf.score[2]),&(StuBuf.sum));
//        i+=strlen(tt);
//
//        p->next=(struct stu *)malloc(sizeof(struct stu));
//        p=p->next;
//        *p=StuBuf;
//        p->next=NULL;
//
//    }
//    return p;
//
//}
//
