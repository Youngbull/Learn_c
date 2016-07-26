#include <stdio.h>
#include <stdlib.h>
#include "Single.h"

// 创建链表，三种方式：头插法、无头结点尾插法、头结点尾插法。
// 下面这些代码真的不是很推荐，总觉得有太多多余的动作了。只是写出来供参考，实际未使用。
LinkList FirstCreat()
{
    LinkList L = NULL;
    ListNode *s; // ListNode是一个结构体，这里定义了一个指向结构体的指针
    char ch;

    while((ch = getchar()) != '\n')
    {
        s = malloc(sizeof(ListNode));
        s->data = ch;
        s->next = L;
        L = s;
    }
    return L;
}
LinkList SecondCreat()
{
    LinkList L;
    ListNode *r = NULL,*s;
    char ch;

    while((ch = getchar()) != '\n')
    {
        s = malloc(sizeof(ListNode));
        s->data = ch;
        if(L == NULL)
            L = s;
        else
            r->next = s;
            s = s;
    }
    if(r != NULL)
        r->next = NULL; // r作为尾结点
    return L;
}
LinkList ThirdCreat()
{
    LinkList L;
    ListNode *s,*r = NULL;
    char ch;
    L = (LinkList)malloc(sizeof(ListNode)); // 之所以要这样是因为下面的语句，它不仅仅是指针，细说应该是指向结点的指针
    r = L;

    while((ch = getchar()) != '\n')
    {
        s = malloc(sizeof(ListNode));
        s->data = ch;
        r->next = s; // S作为尾结点,r也作为尾结点
        r = s;
    }
    r->next = NULL; // 就是在头结点（L指向）后加上r，再加，再加。最后让尾结点指向NULL
    return L;
}


/*初始化单链表*/
int InitList(LinkList *h)
{
    *h = (LinkList)malloc(sizeof(ListNode)); // 这里h一定要加上*，h传输的是地址，是头指针的地址，应当让h指向头结点
    if(h == NULL)
    {
        printf("初始化链表错误！\n");
        return 0;
    }
    (*h)->next = NULL; // 这里反映的很清楚，（*h）才是头结点，这里是头指针的原因
    return 1;
}
/*求单链表长*/
int ListLength(LinkList h)
{
    int total = 0;
    LinkList p = h->next; //h->next指向下一个结点，P就是指向结点指针

     while(p != NULL)
    {
        total++;
        p = p->next;
    }
    return total;
}
/*判断表是否为空*/
int ListEmpty(LinkList h)
{
    if(h->next)
        return 0;
    else
        return 1;
}
/*链表插入*/
int ListInsert(LinkList h,int pos,DataType x)
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
    q = (LinkList)malloc(sizeof(LinkList));
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
int ListDelete(LinkList h,int pos,DataType *item)
{
    LinkList p = h,q; // 定义一个链表结点指针p和q，p为操作链表
    int i = 0;
    while(p->next && i < pos - 1) // 这里请查询符号间关系，这里是说p不是尾结点并且，并且为止还没到pos处时
    {
        p = p->next; // 这里p指向结点后移
        i++;
    }
    if(!p->next || i > pos - 1)
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
LinkList ListFind(LinkList h,DataType item)
{
    LinkList p = h->next;
    while(p && p->data != item)
        p = p->next;
    return p; // 返回的是一个LinkList的指针
}
/*链表取值*/
int GetElem(LinkList h,int pos,DataType *item)
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
void DestoryList(LinkList h)
{
    LinkList p = h->next;
    while(h)
    {
        h = p->next;
        free(p);
        p = h; // 这段代码和书中的部分是不一样的
    }
}
/*链表遍历*/
void TraverseList(LinkList h)
{
    LinkList p = h->next;
    while(p)
    {
        printf("%d\t",p->data);
        p = p->next;
    }
    printf("\n");
}


    /*
     *  已知一个含有7个数字的Fibonacci数列{0,1,1,2,3,5,8}，
     *  请用一个链式存储的线性表表示该数列，并从该链表中删除第7（5,6）个元素
     */
int question1()
{
    int i;
    int data[7] = {0,1,1,2,3,5,8};
    int time = sizeof(data)/sizeof(int);
    DataType item;
    LinkList h = NULL; // 这里是说h指向的地方是NULL，h是头指针
    InitList(&h); // 这里传输的是头指针的地址，代码中生成了头结点，*h指向所分配的地址
    for(i = 0;i < time;i++)
    {
        if(!ListInsert(h,i+1,data[i]))
        {
            printf("建立链表出现错误！\n");
            return 0;
        }
    }
    printf("显示删除之前的链表元素！\n");
    TraverseList(h);
    if(!ListDelete(h,6,&item))
    {
        printf("删除操作出现错误！\n"); // 有必要吗？代码内部我记得有啊。
        return 0;
    }
    printf("显示删除之后的链表元素！\n");
    TraverseList(h);
    DestoryList(h);
    return 1;
}

    /*
     *  将不带头结点的单链表（什么意思？）逆置，要求不能占用额外的空间
     *  实际上画一个图应该就能明白了
     */
void ListReserve(LinkList *h)
{
    LinkList p = *h;
    LinkList q = NULL,r;

    while(p)
    {
        r = q;
        q = p;
        p = p->next;
        q = r;
    }
    *h = p; // 这句话显示的很明白，h是头指针的地址，*h表明指向
}

    /*
     *  设有一个带头结点的单链表，试着编写一个算法，删除表中重复出现的元素
     *  仔细去想的话，我们应该能够意识到问题的处理方式
     */
void Repetition()
{
    int i;
    int data[7] = {0,1,1,2,3,5,8};
    int time = sizeof(data)/sizeof(int);
    LinkList h = NULL; // 这里是说h指向的地方是NULL，h是头指针
    InitList(&h); // 这里传输的是头指针的地址，代码中生成了头结点，*h指向所分配的地址
    for(i = 0;i < time;i++)
    {
        if(!ListInsert(h,i+1,data[i]))
        {
            printf("建立链表出现错误！\n");
        }
    }
    printf("显示删除之前的链表元素！\n");
    TraverseList(h);

    LinkList p = h->next;
    LinkList q,r;
    while(p)
    {
        for(r = p,q = p->next;q != NULL;q = q->next)
        {
            if(p->data == q->data)
            {
                r->next = q->next;
                free(q);
                q = r;
            }
            else
                r = r->next;
        }
        p = p->next;
    }
    TraverseList(h);
}
