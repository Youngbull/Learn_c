#ifndef SINGLE_H_INCLUDED
#define SINGLE_H_INCLUDED

typedef int DataType;
typedef struct Node{
    DataType data;
    struct Node *next;
    }ListNode,*LinkList; // 单链表的存储结构
                         // LinkList是指向LNode结点的指针类型

extern LinkList FirstCreat();
extern LinkList SecondCreat();
extern LinkList ThirdCreat();
extern int InitList(LinkList *h);
extern int ListLength(LinkList h);
extern int ListEmpty(LinkList h);
extern int ListInsert(LinkList h,int pos,DataType x);
extern int ListDelete(LinkList h,int pos,DataType *item);
extern LinkList ListFind(LinkList h,DataType item);
extern int GetElem(LinkList h,int pos,DataType *item);
extern void DestoryList(LinkList h);
extern void TraverseList(LinkList h);
extern int question1();
extern void Repetition();

#endif // SINGLE_H_INCLUDED
