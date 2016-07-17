#ifndef MAIN_H_INCLUDED
#define MAIN_H_INCLUDED

#define LISTSIZE 100

typedef int DataType;

typedef struct{
    DataType items[LISTSIZE];
    int length;
    }SqList;

int InitSqList(SqList *L);
int SqListLength(SqList *L);
int ListEmpty(SqList *L);
int ListInsert(SqList *L,int pos,DataType item);
int ListDelete(SqList *L,int pos,DataType *item);
int GetElem(SqList L,int pos,DataType *item);
int TraverseList(SqList L);

void question1();
void question2();

#endif // MAIN_H_INCLUDED
