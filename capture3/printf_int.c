#include<stdio.h>

/*      用于验证printf数据不对应时情况      */
void printf1()
{
    int ten = 10;
    int two = 2;
    printf("Doing it right: ");
    printf("%d minus %d is %d\n",ten,2,ten - two);
    printf("Doing it wrong: ");
    printf("%d minus %d is %d\n",ten); // 这里%d并没有赋予相对应值，会使用内存中任意值
}

/*      用于检验数据超出系统最大范围时情况      */
void toobig()
{
    int i = 2147483647;
    unsigned int j = 4294967295ULL; // http://blog.csdn.net/duguduchong/article/details/7709482

    printf("%d %d %d\n",i,i+1,i+2); // 有符号情况下起点不同导致
    printf("%d %d %d\n",j,j+1,j+2); // 请查看溢出结果显示
}
