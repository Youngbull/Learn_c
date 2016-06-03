    /*
     * 第12章：存储类、链接和内存管理————
     * 关键字：auto,extern,static,register,const,volatile,restricted;
     * 函数：rand(),srand(),time(),malloc(),calloc(),free();
     * C中如何确定变量的作用域（它在多大范围内可知）以及变量的生存期（存在多长时间）
     * 设计复杂程序
     */
#include <stdio.h>
#include <stdlib.h>
#include "capture12.h"

int main()
{
//    hiding(); // 内层定义覆盖外部定义实例
//    hiding2(); // C99特性（激活方式请查询），语句若为循环或者if语句的部分，即使没有使用[],也认为是一个代码块
//    loc_stat(); // 使用局部静态变量
//    global(); // 几种全局变量
//    parta(); // 各种存储类（自动变量、具有外部链接，文件作用域等、局部变量、内部链接等）
    dyn_arr(); // malloc函数（动态分配内存）使用
    return 0;
}
