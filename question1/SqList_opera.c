#include <stdio.h>
#include "main.h"

/*初始化顺序表*/
int InitSqList(SqList *L)
{
    L->length = 0;
    return 1;
}

/*求表长*/
int SqListLength(SqList *L)
{
    return L->length;
}

/*判断是否为空表*/
int ListEmpty(SqList *L) // 这里的形参是什么？不使用地址是不能更改的意思吗？
{
    if(L->length <= 0)
        return 1;
    else
        return 0;
}

/*插入元素*/
int ListInsert(SqList *L,int pos,DataType item) //既然是插入元素，那么需要形参插入的顺序表，位置和元素
{
    int i;
    if(L->length >= LISTSIZE) // LISTSIZE是初始设置，顺序表中最多就包含LISTSIZE个元素
    {
        printf("\n顺序表已满，无法进行插入元素操作！");
        return 0;
    }
    if(pos <= 0 || pos > L->length+1)
    {
        printf("\n插入位置不合法，其取值范围应该是[1,length+1]");
        return 0;
    }
    for(i = L->length-1; i >= pos-1; i--) //因为毕竟是使用数组的形式实现，因此实际上还是从位置0开始
        L->items[i+1] = L->items[i];
    L->items[pos-1] = item;
    L->length++;
    return 1;
}

/*删除元素*/
int ListDelete(SqList *L,int pos,DataType *item) //删除元素，那么需要形参删除的顺序表，位置和返回元素
{
    int i;
    //if(L->length <= 0)
    if(ListEmpty(L))
    {
        printf("\n顺序表为空表，无法进行删除操作！");
        return 0;
    }
    if(pos < 0 || pos > L->length)
    {
        printf("\n删除位置不合法，其取值范围应该是[1,length]");
        return 0;
    }
    *item = L->items[pos-1];
    for(i = pos;i < L->length;i++)
        L->items[i - 1] = L->items[i];
    L->length--;
    return 1;
}

/*取值操作*/
int GetElem(SqList L,int pos,DataType *item)
{
    if(ListEmpty(&L))
        return 0;
    if(pos <= 0||pos > L.length)
    {
        printf("\n位置信息输入不合法，请重新输入");
        return 0;
    }
    *item = L.items[pos-1];
    return 1;
}

/*遍历操作*/
int TraverseList(SqList L)
{
    int i;
    for(i = 0;i < L.length;i++)
        printf("%d\n",L.items[i]);
    printf("\n");
    return 1;
}



/*
 * 已知有一个包含7数字的Fibonacci数列{0,1,1,2,3,5,8}
 * 用一个顺序存储的线性表表示该数列，并从顺序表中删除第6个元素
 * 分析：首先应该创建一个顺序表，其次查询第6个元素，执行删除操作
 */
void question1()
{
    int i;
    int data[7] = {0,1,1,2,3,5,8};

    DataType item;
    SqList fibo;
    printf("\n建立顺序表");

    InitSqList(&fibo); // 初始化顺序列表

    /*建立顺序表*/
    for(i = 0;i < 7;i++)
    {
        if(!ListInsert(&fibo,i+1,data[i]))
        {
            printf("\n运行错误！\n");
        }
    }
    printf("\n\n删除前的顺序表中的元素\n");
    TraverseList(fibo); // 显示顺序表中所有的元素

    if(!ListDelete(&fibo,4,&item))
    {
        printf("\n运行错误！\n");
    }

    printf("\n\n删除后的顺序表的元素\n");
    TraverseList(fibo); // 显示顺序表中所有元素
}


/*
 * 设有一个顺序表L，试编写一个算法，删除表中重复出现的元素
 * 首先创建一个顺序表，以此向后查询是否存在与之相同的元素
 * 如果存在，删除。把表长减一，然后用相同方式以此向后查询剩余的元素
 */
void question2()
{
    int i,j,a;
    int data[12] = {0,1,1,2,3,4,5,1,0,3,5,8};
    a = (sizeof(data)/sizeof(int));
    printf("%d\n",a);

    DataType item;
    SqList fibo;
    printf("\n建立顺序表");

    InitSqList(&fibo); // 初始化顺序列表

    /*建立顺序表*/
    for(i = 0;i < a;i++)
    {
        if(!ListInsert(&fibo,i+1,data[i]))
        {
            printf("\n运行错误！\n");
        }
    }
    printf("\n\n删除前的顺序表中的元素\n");
    TraverseList(fibo); // 显示顺序表中所有的元素


    for(i = 0;i < fibo.length;i++) // 注意这里使用的是‘.’的形式，因为这里不是指针
    {
        j = i+1;
        while(j < fibo.length)
            if(fibo.items[j] == fibo.items[i])
                ListDelete(&fibo,j+1,&item); // 因为要改变表fibo，所以传输指针
            else
                j++; //流程其实很简单，就是一直查，一直删掉而已
    }

    printf("\n\n删除后的顺序表中的元素\n");
    TraverseList(fibo); // 显示顺序表中所有的元素
    printf("%d",fibo.length);
}
