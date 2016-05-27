/*
 * 第十章：数组和指针————
 * 关键字：static
 * 运算符（&，*）
 * 创建于初始化数组的方法
 * 指针及指针和数组间的关系
 * 编写使用数组的函数
 * 二维数组
 */
#include <stdio.h>
#include <stdlib.h>
#include "capture10.h"

int data[2] = {100,200};
int moredata[2] = {300,400};

int main()
{
//    int marbles[SIZE] = {20,10,5,39,4,16,19,26,31,20};
//    printf("Thhe size of marbles is %d bytes.\n",sizeof marbles);
//    sum2(marbles,SIZE); // 对一个数组中所有元素求和，知识点是函数、数组和指针的综合使用
//    sum3(marbles,marbles + SIZE); // 指针的加法（marbles是地址，因此不存在问题）
//    designate(); // 一种指定方式的数组赋值
//    put_add(); // 指针加法
//    order(); // 用于判定指针符号‘*’和‘++’运算符之间的优先级
//    ptr_ops(); // 指针操作，用于验证和帮助理解指针的各种加，减操作
//    arf(); // const关键字使用，防止错误发生
//    const_test(); // const使用检测，包含常指针（常引用）和指针常量的定义、理解和使用
//    zippo1(); // 多维数组中指针的使用，（请参看267页注解）
//    array2d(); // 多维数组与函数的简单应用（有许多多维数组实际上不光需要数值大小，还需要知道行和列的信息）
    vararr2d();
    return 0;
}
