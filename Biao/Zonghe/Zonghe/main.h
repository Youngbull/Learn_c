#ifndef MAIN_H_INCLUDED
#define MAIN_H_INCLUDED
#define LISTSIZE 100

    /*文具分类信息的结构*/
typedef struct{
    int SortNumber; // 文具分类号
    char SortName[10]; // 文具分类名
    }DataType,SortType;

typedef struct{
    SortType items[LISTSIZE]; // 多少个条目
    int length;
    }SqList; // 使用的是顺序表的存储形式，就是包含长度信息和总条目信息
typedef SqList SortList; // 文具分类顺序表


    /*文具信息结构*/
typedef struct{
    int SortNumber; // 文具分类号（和上面的文具分类信息中的是同样的东西）
    char StockName[10]; // 文具名称
    int amount; // 文具数量
    }StockType;
typedef struct Node{ // 结点
    StockType data;
    struct Node *next;
    }LNode,*LinkList; // 使用单链表的方式实现
typedef LinkList StockList; // 文具链表


extern int InitSqList(SqList *L);
extern int SqListLength(SqList L);
extern int SqListEmpty(SqList L);
extern int SqListInsert(SqList *L,int pos,DataType item);
extern int SqListDelete(SqList *L,int pos,DataType *item;);
extern int SqGetElem(SqList L,int pos,DataType *item);
extern int TraverseSqList(SqList L);


extern int SInitList(LinkList *h);
extern int SListLength(LinkList h);
extern int SListEmpty(LinkList h);
extern int SListInsert(LinkList h,int pos,StockType x);
extern int SListDelete(LinkList h,int pos,StockType *item);
extern LinkList SListFind(LinkList h,StockType item);
extern int SGetElem(LinkList h,int pos,StockType *item);
extern void DestorySList(LinkList h);
extern void TraverseSList(LinkList h);


extern int CreateSortList(SortList *SL);
extern int CreateStockList(StockList *SL);
extern int AddStock(StockList SL);
extern int RemoveStock(StockList SL);
extern int QueryStock(StockList SL);
extern void DispStock(StockList SL);
extern int AddSort(SortList *L);

#endif // MAIN_H_INCLUDED
