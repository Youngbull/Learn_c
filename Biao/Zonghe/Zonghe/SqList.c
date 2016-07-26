#include <stdio.h>
#include <stdlib.h>
#include "main.h"

/*初始化*/
int InitSqList(SqList *L)
{
    L->length = 0;
    return 1;
}

/*求表长*/
int SqListLength(SqList L)
{
    return L.length;
}

/*判断是否为空表*/
int SqListEmpty(SqList L) // 这里的形参是什么？不使用地址是不能更改的意思吗？
{
    if(L.length <= 0)
        return 1;
    else
        return 0;
}

/*插入元素*/
int SqListInsert(SqList *L,int pos,DataType item) //既然是插入元素，那么需要形参插入的顺序表，位置和元素
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
    L->items[pos-1] = item; // 相同类型结构体之间可以相互之间赋值
    L->length++;
    return 1;
}

/*删除元素*/
int SqListDelete(SqList *L,int pos,DataType *item) //删除元素，那么需要形参删除的顺序表，位置和返回元素
{
    int i;
    //if(L->length <= 0)
    if(SqListEmpty(*L))
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
int SqGetElem(SqList L,int pos,DataType *item)
{
    if(SqListEmpty(L))
        return 0;
    if(pos <= 0||pos > L.length)
    {
        printf("\n位置信息输入不合法，请重新输入");
        return 0;
    }
    *item = L.items[pos-1];
    return 1;
}

///*遍历操作（此处的操作只是针对int类型的打印情况，还是不太好，因此暂时不适用）*/
//int TraverseSqList(SqList L)
//{
//    int i;
//    for(i = 0;i < L.length;i++)
//        printf("%d\n",L.items[i].SortNumber); // 这里做了更改，根据DataType而更改
//    printf("\n");
//    return 1;
//}
