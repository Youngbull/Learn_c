    /*
     * 第十一章：字符串和字符串函数————
     * 函数：gets(),puts(),strcat(),strncat(),
     * strcmp(),strncmp(),strcpy(),strncpy(),
     * sprintf(),strchr()
     * 创建和使用字符串
     * 利用C库里的字符串和字符函数创建自己的字符串函数
     */
#include <stdio.h>
#include <stdlib.h>
#include "capture11.h"

int main()
{
//    strings(); // 包含了几种建立、读入和输出字符串的方式（包括gets(),puts()函数）
//    quote(); // 将字符串看做指针的验证和实验
//    gets1(); // gets函数使用
//    gets2();
//    fgets1(); // fgets函数使用
//    scan_str(); // scanf函数使用
//    put_out(); // 利用puts函数证明一种错误的字符串定义方式
//    nono(); // puts函数
//    fputs1(); // fputs函数
//    const char *sr = "Song jun hao ";
//    put1(sr); // 不输出换行符
//    put2(sr);
//    put2("Song junhao"); // 可以直接将字符串常量传送给函数，也是地址
//    test(); // strlen函数使用
//    str_cat(); // strcat函数的使用
//    join_chk(); // 连接两个字符串，并检查第一个字符串的大小
//    compare(); // strcmp函数简单实用，注意strcmp的返回值
//    quit_chk(); //  使用strcmp函数达到输入quit字符退出或者达到规定数目退出，计数输入数据
//    starsrch(); // strncmp函数的简单运用，有字符数限制
//    copy1(); //strcpy函数和strncpy函数使用，一个不检查目的字符串尺寸，一个检查
//    format(); // sprintf函数使用，就是把不同的字符串按照一定格式结合在一起
    sort_str();
    return 0;
}
