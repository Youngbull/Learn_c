/*
 * 本章为字符输入/输出和输入确认
 * 主要内容————
 * 有关输入、输出以及缓冲和费缓冲输入之间的区别的更多内容
 * 从键盘模拟文件结尾条件的方法
 * 如何重定向将程序和文件相连接
 * 更好的用户界面
 */
#include <stdio.h>
#include <stdlib.h>
#include "capture8.h"

int main()
{
//    echo(); // getchar与putchar的使用，在遇到‘#’字符时停止
//    echo_eof();
//    file_eof();
//    guess_data(); // 一个低效并且错误的猜数程序
//    showchar1(); // 一个存在问题的I/O程序，具体原因代码中有注释
    showchar2(); //
    return 0;
}
