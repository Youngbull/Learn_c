#include<stdio.h>

void printf1()
{
    int ten = 10;
    int two = 2;
    printf("Doing it right: ");
    printf("%d minus %d is %d\n",ten,2,ten - two);
    printf("Doing it wrong: ");
    printf("%d minus %d is %d\n",ten); // 这里%d并没有赋予相对应值，会使用内存中任意值
}
