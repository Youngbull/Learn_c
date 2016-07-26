#include <stdio.h>
#include <stdlib.h>
#include "main.h"
/*初始化单链表*/
int SInitList(LinkList *h)
{
    *h = (LinkList)malloc(sizeof(LNode)); // 这里h一定要加上*，h传输的是地址，是头指针的地址，应当让h指向头结点
    if(h == NULL)
    {
        printf("初始化链表错误！\n");
        return 0;
    }
    (*h)->next = NULL; // 这里反映的很清楚，（*h）才是头结点，这里是头指针的原因
    return 1;
}
/*求单链表长*/
int SListLength(LinkList h)
{
    int total = 0;
    LinkList p = h->next; // h->next指向下一个结点，P就是指向结点指针

     while(p != NULL)
    {
        total++;
        p = p->next;
    }
    return total;
}
/*判断表是否为空*/
int SListEmpty(LinkList h)
{
    if(h->next)
        return 0;
    else
        return 1;
}
/*链表插入*/
int SListInsert(LinkList h,int pos,StockType x) // 这里有许多地方采用*h的形式，传递的是指针的指针，就是指针h的地址，
                                                // 下面的使用也要配套使用p = *h;这样能对其进行修改。但是这里h所指向的位置无需更改
{
    LinkList p = h,q;
    int i = 0;
    while(p && i < pos - 1)
    {
        p = p->next;
        i++;
    }
    if(!p || i > pos - 1) // 这里出现了错误，i>pos-1被写成了pos-1。造成下面的代码无法正常运行
    {
        printf("插入位置不合法！\n");
        return 0;
    }
    q = (LinkList)malloc(sizeof(LNode)); // 返回指向LNode的指针，然后强会转化为LinkList的指针
    if(!q)
    {
        printf("不能生成新结点\n");
        return 0;
    }
    q->data = x;
    q->next = p->next;
    p->next = q;
    return 1;
}
/*链表删除*/
int SListDelete(LinkList h,int pos,StockType *item) // 同上
{
    LinkList p = h,q; // 定义一个链表结点指针p和q，p为操作链表
    int i = 0;
    while(p->next && i < pos - 1) // 这里请查询符号间关系，这里是说p不是尾结点并且，并且为止还没到pos处时
    {
        p = p->next; // 这里p指向结点后移
        i++;
    }
    if(!p->next || i > pos - 1) // 请查阅资料
    {
        printf("删除出现错误！\n");
        return 0;
    }
    q = p->next;
    p->next = q->next; // 删除操作
    *item = q->data;

    free(q); // 这一步是很重要的一步

    return 1;
}
/*链表查找*/
LinkList SListFind(LinkList h,StockType item)
{
    LinkList p = h->next;
    while(p && (p->data.SortNumber != item.SortNumber))
        p = p->next;
    return p; // 返回的是一个LinkList的指针
}
/*链表取值*/
int SGetElem(LinkList h,int pos,StockType *item)
{
    int i = 0;
    LinkList p = h->next;

    while(p && i < pos - 1)
    {
        p = p->next;
        i++;
    }
    if(!p || i > pos - 1) // 说真的，一直认为这里很多余
    {
        printf("链表查找错误！\n");
        return 0;
    }
    *item = p->data; // 这里item传输的是地址，p->data是DataType类型的，就算这里不加*符号，应该也会报错
    return 1;
}
/*销毁单链表*/
void DestorySList(LinkList h)
{
    LinkList p = h->next;
    while(h)
    {
        h = p->next;
        free(p);
        p = h; // 这段代码和书中的部分是不一样的
    }
}
///*链表遍历*/
//void TraverseSList(LinkList h)
//{
//    LinkList p = h->next;
//    while(p)
//    {
//        printf("%d\t",p->data.SortNumber);
//        p = p->next;
//    }
//    printf("\n");
//}
