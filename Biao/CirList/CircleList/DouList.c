#include <stdio.h>
#include <stdlib.h>
#include "main.h"

/*初始化双向链表*/
DLinkList InitList(DLinkList *h) // 这里是否可以使用*h的形式实现，下面进行改变？？
{
    *h = (DLinkList)malloc(sizeof(DNode));
    if(!h)
    {
        printf("初始化链表错误！\n");
        return 0;
    }
    (*h)->next = *h;
    (*h)->prior = *h;
    return *h;
}
/*双向循环链表的元素插入操作*/
int ListInsert(DLinkList h,int pos,DataType x)
{
    DLinkList p = h->next,q;
    int i = 0;
    while(p != h && i < pos - 1)
    {
        p = p->next;
        i++;
    }

    if(p == h || i > pos - 1)
    {
        printf("插入位置不合法！\n");
        return 0;
    }
    q = (DLinkList)malloc(sizeof(DNode));
    if(!q)
    {
        printf("插入操作出错！\n");
        return 0;
    }
    q->data = x;
    q->prior = p->prior;
    p->prior->next = q;
    q->next = p;
    p->prior = q;
    return 1;
}
/*双向循环链表的元素删除操作*/
int ListDelete(DLinkList h,int pos,DataType *item) // 因为h是不会改变的
{
    DLinkList  p = h->next; // h是头结点
    int i = 1;

    while(p->next != h && i < pos) // 寻找被删结点的前驱
    {
        p = p->next;
        i++;
    }

    if(p->next == h || i > pos) // 仔细查看它的细节
    {
        printf("删除位置不合法！\n");
        return 0;
    }

    *item = p->data; // 返回被删数据元素
    p->prior->next = p->next;
    p->next->prior = p->prior;
    free(p); // 释放被删结点
    return 1;
}

    /*
     *  请编写一个将双向循环链表逆置的算法
     */
void DListReverse(DLinkList h)
{
    DLinkList p = h->next,q;

    while(p != h)
    {
        q = p->next;
        p->next = p->prior;
        p->prior = q;
        p = q;
    }

    q = h->next;
    h->next = p->prior;
    h->prior = q;
}
    /*
     *  请编写一个将单循环链表改为双向循环链表的算法
     */
void ModifyList(DLinkList h) // 这里作为形参的h，本身应该是单循环链表的定义吧？可以这样使用吗？？
{
    DLinkList p = h->next,q;

    p->prior = h; // 建立第一个结点的前驱域
    while(p != h)
    {
        q = p->next;
        q->prior = p;
        p = q;
    }
}
