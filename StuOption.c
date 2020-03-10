#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
extern struct stu{

    int number;
    char name[50];
    char sex;
    double score[3];
    double sum;
    struct stu *next;

};
struct stu trans;
struct stu* ShaiXuanNumber(struct stu* up,int mark,char * NumberBuf)
{
      if(mark==0)
    {
        return up;
    }
    struct stu *p,*head;
    int numcmper;
    sscanf(NumberBuf,"%d",&numcmper);

    head=p=(struct stu *)malloc(sizeof(struct stu));
    p->next=NULL;
    while(up->next!=NULL)
    {
        up=up->next;
//printf("&*&^&%d\n",numcmper==up->number);
        if(up->number==numcmper)
        {
            //printf("^&^&^&");

            p->next=(struct stu *)malloc(sizeof(struct stu));
            p=p->next;
            *p=*up;
            p->next=NULL;
        }

    }

    return head;
};
struct stu*ShaiXuanName(struct stu* up,int mark,char * NameBuf)
{
  struct stu *p,*head;
     if(mark==0)
    {
        return up;
    }
    head=p=(struct stu *)malloc(sizeof(struct stu));
    p->next=NULL;
    while(up->next!=NULL)
    {
        up=up->next;
//printf("&*&^&%d\n",numcmper==up->number);
        if(strcmp(up->name,NameBuf)==0)
        {
            //printf("^&^&^&");
            p->next=(struct stu *)malloc(sizeof(struct stu));
            p=p->next;
            *p=*up;
            p->next=NULL;
        }

    }


return head;
};
struct stu*ShaiXuanSex(struct stu* up,int mark,char * SexBuf)
{
 struct stu *p,*head;

     if(mark==0)
    {
        return up;
    }

    head=p=(struct stu *)malloc(sizeof(struct stu));
    p->next=NULL;
    while(up->next!=NULL)
    {
        up=up->next;
//printf("&*&^&%d\n",numcmper==up->number);
        if(up->sex==SexBuf[0])
        {
            //printf("^&^&^&");

            p->next=(struct stu *)malloc(sizeof(struct stu));
            p=p->next;
            *p=*up;
            p->next=NULL;
        }

    }



return head;
};
struct stu*ShaiXuanScoreMath(struct stu* up,int mark,char * ScoreMathBuf)
{
 struct stu *p,*head;
     if(mark==0)
    {
        return up;
    }
    double score;
    sscanf(ScoreMathBuf,"%lf",&score);

    head=p=(struct stu *)malloc(sizeof(struct stu));
    p->next=NULL;
    while(up->next!=NULL)
    {
        up=up->next;
//printf("&*&^&%d\n",numcmper==up->number);
        if(up->score[0]==score)
        {
            //printf("^&^&^&");

            p->next=(struct stu *)malloc(sizeof(struct stu));
            p=p->next;
            *p=*up;
            p->next=NULL;
        }

    }


    return head;

};
struct stu*ShaiXuanScoreLiner(struct stu* up,int mark,char * ScoreLinerBuf)
{
 struct stu *p,*head;
     if(mark==0)
    {
        return up;
    }


    double score;
    sscanf(ScoreLinerBuf,"%lf",&score);

    head=p=(struct stu *)malloc(sizeof(struct stu));
    p->next=NULL;
    while(up->next!=NULL)
    {
        up=up->next;
//printf("&*&^&%d\n",numcmper==up->number);
        if(up->score[1]==score)
        {
            //printf("^&^&^&");

            p->next=(struct stu *)malloc(sizeof(struct stu));
            p=p->next;
            *p=*up;
            p->next=NULL;
        }

    }
    return head;

};
struct stu*ShaiXuanScoreC(struct stu* up,int mark,char * ScoreCBuf)
{

 struct stu *p,*head;;;
     if(mark==0)
    {
        return up;
    }
    double score;
    sscanf(ScoreCBuf,"%lf",&score);

    head=p=(struct stu *)malloc(sizeof(struct stu));
    p->next=NULL;
    while(up->next!=NULL)
    {
        up=up->next;
//printf("&*&^&%d\n",numcmper==up->number);
        if(up->score[2]==score)
        {
            //printf("^&^&^&");

            p->next=(struct stu *)malloc(sizeof(struct stu));
            p=p->next;
            *p=*up;
            p->next=NULL;
        }

    }


    return head;

};
struct stu*ShaiXuanSum(struct stu* up,int mark,char * ScoreSumBuf)
{
    struct stu *p,*head;
     if(mark==0)
    {
        return up;
    }

    double score;
    sscanf(ScoreSumBuf,"%lf",&score);

    head=p=(struct stu *)malloc(sizeof(struct stu));
    p->next=NULL;
    while(up->next!=NULL)
    {
        up=up->next;
//printf("&*&^&%d\n",numcmper==up->number);
        if(up->sum==score)
        {
            //printf("^&^&^&");

            p->next=(struct stu *)malloc(sizeof(struct stu));
            p=p->next;
            *p=*up;
            p->next=NULL;
        }

    }

  return head;

};
