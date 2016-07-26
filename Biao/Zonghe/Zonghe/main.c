    /*  文具店日常经营过程中，存在对各种文具管理问题。
     *  当库存稳居不足或者缺货的时候，需要进货。日常销售时，需要出库
     *  盘点货物时，需要查询货物信息，请根据这些要求编写软件完成库存文具的管理功能
     */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "main.h"

int main()
{
    int choice;
    StockList SL;
    SortList L;

    do{
        printf("首先建立链表和顺序表！\n");
        printf("Please input 1,2,3,4,6,0");

        scanf("%d",&choice);

        if(choice < 0 && choice > 7)
            continue;
        switch(choice)
        {
            case 1:CreateSortList(&L);break;
            case 2:CreateStockList(&SL);break;
            case 3:AddStock(SL);break;
            case 4:RemoveStock(SL);break;
            case 5:QueryStock(SL);break;
            case 6:DispStock(SL);break;
            case 7:AddSort(&L);break;
            case 0:exit(0);
            default:break;
        }
    }
    while(1);

    return 0;
}
