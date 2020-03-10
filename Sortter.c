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
void sortNumberU(struct stu *head)
{
    struct stu *b,*pre,*p;
    b=NULL;
    pre=head;
    while(head->next!=b)
    {
        p=head->next;
        pre=head;
        while(p->next!=b)
        {
            if(p->number>p->next->number)
            {
                pre->next=p->next;
                p->next=p->next->next;
                pre->next->next=p;
                p=pre->next;//����һ��
            }
            p=p->next;
            pre=pre->next;
        }
        b=p;
    }//��������ð��˼��һ��
}void sortNumberL(struct stu *head)
{
    struct stu *b,*pre,*p;
    b=NULL;
    pre=head;
    while(head->next!=b)
    {
        p=head->next;
        pre=head;
        while(p->next!=b)
        {
            if(p->number<p->next->number)
            {
                pre->next=p->next;
                p->next=p->next->next;
                pre->next->next=p;
                p=pre->next;//����һ��
            }
            p=p->next;
            pre=pre->next;
        }
        b=p;
    }//��������ð��˼��һ��
}void sortNameU(struct stu *head)
{
    struct stu *b,*pre,*p;
    b=NULL;
    pre=head;
    while(head->next!=b)
    {
        p=head->next;
        pre=head;
        while(p->next!=b)
        {
            if(strcmp(p->name,p->next->name)>0)
            {
                pre->next=p->next;
                p->next=p->next->next;
                pre->next->next=p;
                p=pre->next;//����һ��
            }
            p=p->next;
            pre=pre->next;
        }
        b=p;
    }//��������ð��˼��һ��
}void sortNameL(struct stu *head)
{
    struct stu *b,*pre,*p;
    b=NULL;
    pre=head;
    while(head->next!=b)
    {
        p=head->next;
        pre=head;
        while(p->next!=b)
        {
            if(strcmp(p->name,p->next->name)<0)
            {
                pre->next=p->next;
                p->next=p->next->next;
                pre->next->next=p;
                p=pre->next;//����һ��
            }
            p=p->next;
            pre=pre->next;
        }
        b=p;
    }//��������ð��˼��һ��
}void sortSumU(struct stu *head)
{
    struct stu *b,*pre,*p;
    b=NULL;
    pre=head;
    while(head->next!=b)
    {
        p=head->next;
        pre=head;
        while(p->next!=b)
        {
            if(p->sum>p->next->sum)
            {
                pre->next=p->next;
                p->next=p->next->next;
                pre->next->next=p;
                p=pre->next;//����һ��
            }
            p=p->next;
            pre=pre->next;
        }
        b=p;
    }//��������ð��˼��һ��
}void sortSumL(struct stu *head)
{
    struct stu *b,*pre,*p;
    b=NULL;
    pre=head;
    while(head->next!=b)
    {
        p=head->next;
        pre=head;
        while(p->next!=b)
        {
            if(p->sum<p->next->sum)
            {
                pre->next=p->next;
                p->next=p->next->next;
                pre->next->next=p;
                p=pre->next;//����һ��
            }
            p=p->next;
            pre=pre->next;
        }
        b=p;
    }//��������ð��˼��һ��
}

