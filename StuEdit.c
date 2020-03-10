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

void StuInsert(struct stu *head)
{
AllocConsole();
freopen("conin$", "r+t", stdin);
freopen("conout$", "w+t", stdout);
freopen("conout$", "w+t", stderr);
int number;
struct stu *p,*add,adder;

p=head;
while(p->next!=NULL)
{
    p=p->next;
}



printf("请输入学号(-1结束):\n");
scanf("%d",&number);
while(number!=-1)
{
    adder.number=number;
    printf("请输入姓名:\n");
    scanf("%s",adder.name);
    printf("请输入性别(男m,女f):\n");
    scanf("\n%c",&(adder.sex));
    printf("请输入成绩(FOX.ENGLISH.C,以空格分隔):\n");
    scanf("%lf %lf %lf",&(adder.score[0]),&(adder.score[1]),&(adder.score[2]));
    adder.sum= adder.score[0] +adder.score[1] +adder.score[2];

    p->next=(struct stu *)malloc(sizeof(struct stu));
    p=p->next;
    *(p)=adder;
    p->next=NULL;


    printf("请输入学号(-1结束):\n");
    scanf("%d",&number);
    if(number==-1)
    {
        FreeConsole();
    }

}
 FreeConsole();
}
int IfStuEqual(struct stu *p,struct stu *up)
{
    int ans=1;

    if( p->number !=up->number)
    {
        ans=0;
    }
    if(strcmp( p->name ,up->name)!=0)
    {
        ans=0;
    }
    if( p->sex !=up->sex)
    {
        ans=0;
    }
    if( p->score[0]!=up->score[0])
    {
        ans=0;
    }
    if( p->score[1] !=up->score[1])
    {
        ans=0;
    }
    if( p->score[2] !=up->score[2])
    {
        ans=0;
    }
    return ans;

}
void StuDel(struct stu* phead,struct stu* uphead)
{
    struct stu *p,*p1,*up,*up1;
    up=uphead;
    p=phead;

    while(up->next!=NULL)
    {
        up=up->next;

        p1=p=phead;
        while(p->next!=NULL)
        {

            p=p->next;
            if( IfStuEqual(p,up))
            {

                p1->next=p->next;


            }

            p1=p;
        }

    }

}
void StuEdit(struct stu* phead,struct stu* uphead)
{
AllocConsole();
freopen("conin$", "r+t", stdin);
freopen("conout$", "w+t", stdout);
freopen("conout$", "w+t", stderr);
    struct stu *p,*p1,*up,*up1,bu;
    up=uphead;
    p=phead;
    int r[10];

    while(up->next!=NULL)
    {
        up=up->next;

        p1=p=phead;
        while(p->next!=NULL)
        {

            p=p->next;
            if( IfStuEqual(p,up))
            {
///                ///

///
                printf( "目前操作信息\n学号:%d 姓名:%s 性别:%c FOX:%.2lf ENGLISH:%.2lf C:%.2lf 总分:%.2lf\r\n",p->number,p->name,p->sex,p->score[0],p->score[1],p->score[2],p->sum);

                printf("请输入学号:\n");
                scanf("%d",&(bu.number));
//printf("%d",bu.number);
                printf("请输入姓名:\n");
                scanf("%s",bu.name);

                printf("请输入性别:\n");
                scanf("\n%c",&(bu.sex));

                printf("请输入成绩(FOX.ENGLISH.C):\n");
                scanf("%lf %lf %lf",&(bu.score[0]),&(bu.score[1]),&(bu.score[2]));
                bu.sum = bu.score[0]+bu.score[1]+bu.score[2];
                bu.next=p->next;



                *p=bu;
                printf("修改成功\n");

                ///
            }

            p1=p;
        }
        printf("修改结束");

    }
    FreeConsole();

}
