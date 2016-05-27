#include <stdio.h>
#include "capture11.h"

    /* 使用字符串与用户交互
     * 包含字符串的建立、读入和输出的几种方式
     * gets(),puts()函数的使用
     *
     * 注：刚才遇到了一个error，显示在void string(void)之后和‘{’之前又不允许出现的符号之类的，在capture11.c中并没有问题
     * 经查，实在capture11.h中没有加入分号的原因
     */
void strings(void)
{
    char name[LINELEN];
    char talents[LINELEN];
    int i;
    const char m1[40] = "Limit yourself to one line's worth. "; // 初始化一个大小已确定的char数组
    const char m2[] = "If you can't think of anything,fake it. "; // 让编译器计算char数组的大小
    const char *m3 = "\nEnough about me - what's your name? "; // 初始化一个指向常量的指针
    const char *mytal[LIM] = {"Adding numbers swiftly." ,"Multiplying accurately." ,"Stashing data.",
     "Follwing instructions to the letter","Understanding the C language"}; // 初始化一个字符串指针的数组
                                                                            // 此处如果忘记使用’,‘作为不同字符串的分隔，那么会被当成一个字符串

    printf("Hi,I'm Clyde the computer. I have many talents.\n");
    printf("Let me tell you some of them.\n");

    puts("What were they? Ag,yes,here's a partial list: ");
    for(i = 0;i < LIM;i++)
        puts(mytal[i]); // 打印计算机功能的列表
    puts(m3);
    gets(name); // 以什么为结束？
    printf("Well,%s,%s\n",name,MSG);
    printf("%s\n%s\n",m1,m2);
    gets(talents);
    puts("Let's see if I've got that list: ");
    puts(talents);
    printf("Thanks for the information. %s\n",name);
}

    /* 很小一个程序，但是很有用，阐述了一个道理————
     * 字符串常量属于静态存储类（整个引号内的内容作为指向该字符串存储位置的指针）
     * 下面函数中%p产生一个地址，故而如果"are"是个地址，那么%p应该输出字符串中第一个字符的地址
     * 而*"space farers"应该产生所指向地址的值，也就是第一个字符的值就是's'
     * 运行结果也证明了上面的观点
     */
void quote()
{
    printf("%s,%p,%c\n","We","are",*"sapce farers");
}
