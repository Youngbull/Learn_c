#include <stdio.h>
#include "capture10.h"

    /*      使用指定初始化项目（在C99标准下的一种指定位置初始化方式，真的有什么用处吗？）        */
void designate(void)
{
    int days[MONTHS] = {31,28,[4] = 31,30,31,[1] = 29}; // 将days[1]赋予了29，给days[4]赋予了31。(具体查看248页)
                                                        // 但是如果是类推的话，为什么中间值为0？这是因为，赋给了days[4]之后，紧接着是5he6.
    int i;

    for(i = 0;i < MONTHS;i++)
        printf("%2d %d\n",i+1,days[i]); // 这里的输出请仔细观看
}

    /*      指针加法        */
void put_add(void)
{
    short dates[SIZE];
    short *pti;
    short index;
    double bills[SIZE];
    double *ptf;
    pti = dates;
    ptf = bills;
    printf("%23s %10s\n","short","dpuble");
    for(index = 0;index < SIZE;index++)
        printf("pointers + %d: %10p %10p\n",index,pti + index,ptf + index);
}

    /*      如何在函数中利用数组作为形参      */
void sum1(int *ar) //
{
    int i;
    int total = 0;

    for(i = 0;i < 10;i++) // 只适用于数组大小小于10的？还是等于？
        total += ar[i];
    printf("The sum of ar is %d.\n",total);
}
void sum2(int *ar,int n) // 基于sum1()函数的改进方案，传递两个参数
{
    int i;
    int total = 0;

    for(i = 0;i < n;i++)
        total += ar[i];
    printf("The sum of ar is %d.\n",total);
    printf("The size of ar is %d bytes.\n",sizeof ar);
}
void sum3(int *start,int *ends) // 函数中传递数组大小的另一种方式，传递头和尾地址
{
    int total = 0;
    while(start < ends) // 这里使用的是while循环方式不是for的形式
    {
        total += *start; // total累计值(这里是*start，而不是start，要明白区别)
        start++; // 指针指向了下一个元素
    }
    printf("The sum of the ar is %d.\n",total);
}

    /*      指针运算的优先级        */
void order()
{
    int *p1,*p2,*p3;

    p1 = p2 = data;
    p3 = moredata;
    printf(" *p1 = %d, *p2 = %d, *p3 = %d\n",*p1,*p2,*p3); // 100,100,300
    printf(" *p1++ = %d, *++p2 = %d, (*p3)++ = %d\n",*p1++,*++p2,(*p3)++); // 100,200,300
    printf(" *p1 = %d, *p2 = %d, *p3 = %d\n",*p1,*p2,*p3); // 200,200,301(*p3)++
}

    /*      指针操作（用于练习）        */
void ptr_ops()
{
    int urn[5] = {100,200,300,400,500};
    int *ptr1,*ptr2,*ptr3;

    ptr1 = urn; // 把一个地址赋给指针
    ptr2 = &urn[2]; // 取得指针指向的值，并且得到指针的地址

    printf("pointer value,dereference pointer,pointer address:\n");
    printf("ptr1 = %p,*ptr1 = %d,&ptr1 = %p\n",ptr1,*ptr1,&ptr1);

    ptr3 = ptr1 + 4;
    printf("\nadding an int to a pointer:\n");
    printf("ptr1 + 4 = %p, *(ptr1 + 3) = %d\n",ptr1 + 4,*(ptr1 + 3));

    ptr1++; // 递增指针
    printf("\nvalues after ptr1++\n");
    printf("ptr1 = %p, *ptr1 = %d, &ptr1 = %p\n",ptr1,*ptr1,&ptr1);

    ptr2--; // 递减指针
    printf("\nvalues after --ptr2\n");
    printf("ptr2 = %p, *ptr2 = %d, &ptr2 = %p\n",ptr2,*ptr2,&ptr2);

    --ptr1; // 恢复至初始值
    ++ptr2; // 恢复至初始值
    printf("\nPointers reset to original values:\n");
    printf("ptr1 = %p, ptr2 = %p\n",ptr1,ptr2);
            // 一个指针减去另一个指针
    printf("\nsubtractng one pointer from another:\n");
    printf("ptr2 = %p, ptr1 = %p, ptr2 - ptr1 = %d\n",ptr2,ptr1,ptr2 - ptr1);
            // 一个指针减去一个整数
    printf("\nsubtracting an int from a pointer:\n");
    printf("ptr3 = %p, ptr3 - 2 = %p\n",ptr3,ptr3 - 2);
}

    /*
     * 通常函数中传递数组可以传递值，也可以传递指针
     * 当传递值的时候，不会对其结果进行修改，但是对于这种形式的数据，这种方式明显太过繁琐
     * 所以实际使用中大多是传递指针的方式
     * 但是这也就产生了改变数组值得隐患，人总会犯错
     * 相对应的，就有了保护数组内容的传递方式
     */
void show_array(const double ar[],int n) // 数组内容输出 （这里不需要对数组内容进行改变，因此使用了关键字const）
{
    int i;

    for(i = 0;i < n;i++)
        printf("%8.3f",ar[i]);
    putchar('\n');
}
void mult_array(double ar[],int n,double mult) // 数组内的元素分别乘以一个因数值mult，这里需要改变，形参就不是const的（数组类型是double型的）
{
    int i;

    for(i = 0;i < n;i++)
        ar[i] *= mult;
}
void arf()
{
    double dip[SIZE] = {20.0, 17.66, 8.2, 15.3, 22.22};

    printf("The original dip array: \n");
    show_array(dip,SIZE);
    mult_array(dip,SIZE,2.5); // 这里对数组内容进行了修改，因为传递的是指针，所以可以直接对数组内容更改
    printf("The dip array after calling mult_array(): \n");
    show_array(dip,SIZE);
}
