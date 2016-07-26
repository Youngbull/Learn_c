#ifndef MAIN_H_INCLUDED
#define MAIN_H_INCLUDED

typedef int DataType;
typedef struct Node{
    DataType data;
    struct Node *prior;
    struct Node *next;
    }DNode,*DLinkList;

#endif // MAIN_H_INCLUDED
