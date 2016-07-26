#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "main.h"

    /*初始化文具分类顺序表*/
int CreateSortList(SortList *SL) // SL是指向SortList类型结构体的指针
{
    int i,num = 0;
    SortType sty;

    /*使用顺序表的InitList操作初始化顺序表*/
    InitSqList(SL); // 因为这是顺序表的原因
    printf("请输入文具类别总数：\n");
    scanf("%d",&num); // num是类别数
    for(i = 0;i < num;i++)
    {
        printf("请输入文具分类号\n");
        scanf("%d",&sty.SortNumber);
        do{
            printf("请输入文具分类名称\n");
            scanf("%s",sty.SortName); // 这里(char*)是后来加上的，感觉不对劲，因为类型不同
        }
        while(strlen(sty.SortName) >= 9);

        SqListInsert(SL,i+1,sty); // 在顺序表中插入元素
    }
    printf("\nOK...\n");
    return 1;
}

    /*初始化文具链表*/
int CreateStockList(StockList *SL) // SL指向的并不是结构体，而是一个指向结构体指针的指针
{
    int i,num = 0;
    StockType sty;

    if(!SInitList(SL)) // SL本身就是一个指向结构体的指针,这里有一个本质区别是这是实参
    {
        printf("创建错误！\n");
        return 0;
    }
    printf("请输入文具总数：\n");
    scanf("%d",&num);
    for(i = 0;i < num;i++)
    {
        printf("请输入文具分类号：\n");
        scanf("%d",&sty.SortNumber); // 因为这里是结构体，所以要用&符号
        do{
            printf("请输入文具分类名称\n");
            scanf("%s",sty.StockName); // 这里(char*)是后来加上的，感觉不对劲，因为类型不同
        }
        while(strlen(sty.StockName) > 9);

        printf("请输入文具数量：\n");
        scanf("%d",&sty.amount);

        SListInsert(*SL,i+1,sty); // 这里的i+1真的如预测中一样吗？
                                  // 经过一步步试验之后证明是正确的方式（能不能对代码进行改变，让使用起来更加方便？？）
    }
    printf("\nOK...\n");
    return 1;
}

/*文具入库*/
/*如果该文具存在，则修改数量。如果该文具不存在，则插入到文具链表中*/
int AddStock(StockList SL) // SL是指针
{
    StockType sty;
    int pos = 0;
    LinkList p = SL->next;

    printf("请输入文具分类号：\n");
    scanf("%d",&sty.SortNumber);

    do{
        printf("请输入文具名称：\n");
        scanf("%s",sty.StockName);
    }
    while(strlen(sty.StockName) > 9);

    printf("请输入文具数量：\n");
    scanf("%d",&sty.amount);

    while(p)
    {
        /*如果该文具存在，则修改其数量*/
        if(!strcmp(p->data.StockName,sty.StockName)) // 比较，
        {
            p->data.amount += sty.amount; // 增加的数量
            break; // 这一句话很重要
        }
        p = p->next;
        pos++;
    }

    /*如果该文具不存在，则插入到文具链表中*/
    if(!p) // 如果该文具不在，就是找到最后也没找到这个结点
        SListInsert(SL,pos+1,sty);
    printf("\nOK...\n");
    return 1;
}

/*文具出库*/
/*如果出库数量大于库存数量，则从链表中删除该文具，否则，只修改该文具的数量*/
int RemoveStock(StockList SL)
{
    StockType sty;
    LinkList p = SL->next;
    int pos = 0;
    printf("请输入文具名：\n");
    scanf("%s",sty.StockName);
    printf("请输入出库数量：\n");
    scanf("%d",&sty.amount);

    while(p && strcmp(p->data.StockName,sty.StockName)) // 同样是向后查，或者是查到最后
    {
        p = p->next;
        pos++;
    }
    p->data.amount -= sty.amount; // 这里顺序一定要清楚

    /*如果出库数量大于库存数量，则从链表中删除该文具*/
    if(p->data.amount <= 0)
        SListDelete(SL,pos+1,&sty);
    printf("\nOK...\n");
    return 1;
}

/*查询文具信息*/
int QueryStock(StockList SL)
{
    int no;
    StockList p = SL->next;
    printf("请输入文具分类号：\n");
    scanf("%d",&no);

    // 查询出所有该文具分类号的文具信息
    printf("\nNumber StockName amount\n");
    while(p)
    {
        if(p->data.SortNumber == no) // 根据输入的类别号
        {
            printf("%d\t",p->data.SortNumber);
            printf("%s\t",p->data.StockName);
            printf("%d\t",p->data.amount);
            printf("\n");
        }
        p = p->next;
    }

    return 1;
}

/*显示文具信息*/
void DispStock(StockList SL)
{
    StockList p = SL->next;
    printf("\nNumber StockName amount\n");

    while(p) // 向下查找，依次显示所有的结点信息
    {
        printf("%d\t",p->data.SortNumber);
        printf("%s\t",p->data.StockName);
        printf("%d\t",p->data.amount);
        printf("\n");
        p = p->next;
    }
}

/*添加新文具类别*/
int AddSort(SortList *L) // 分清楚
{
    SortType st;

    printf("请输入文具分类号：\n");
    scanf("%d",&st.SortNumber);
    printf("请输入文具分类号：\n");
    scanf("%s",st.SortName);

    if(!SqListInsert(L,L->length + 1,st))
        return 0;
    printf("\nOK...\n");
    return 1;
}
