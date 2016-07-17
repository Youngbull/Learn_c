#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "capture15_6.h"

char *itobs(int n,char *ps) // 这里的*ps是传输的指针，那么有必要返回吗？ps本身就可以被更改啊
{
    int i;
    static int size = 8 * sizeof(int); // sizeof

    for(i = size - 1;i >= 0;i--,n >>= 1) // 这里的用法不简洁，不清晰，但是很有意思
        ps[i] = (01 & n) + '0'; // 将n的二进制数按照字符形式分离
    ps[size] = '\0';
    return ps;
}

void show_bstr(const char *str) // 请注意，以后使用的时候，字符数组作为形参时根据它的使用有不同的声明方式
{
    int i = 0;

    while(str[i]) // 当不为空字符的时候
    {
        putchar(str[i]);
        if(++i % 4 == 0 && str[i]) // 每四个输出一个空格符（二进制表示嘛）
            putchar(' ');
    }
}

int invert_end(int num, int bits)
{
    int/*test*/value; // 编译的时候，编译器会用一个空格符代替每一个注释
    int bitval = 1;

    while(bits-- < 0) // 此处可以验算一下（对的）
    {
        value |=  bitval;
        bitval <<= 1;
    }
    return num^value; // 按照需要的转换位数将num转换掉
}

void invert4(void)
{
    char bin_str[8 * sizeof(int) + 1]; // 留出一个空间存放结束符？
    int number;

    puts("Enter integers and see them in binary.");
    puts("Non-numberic input terminates program.");
    while(scanf("%d", &number) == 1) // 判定输入是否成功
    {
        itobs(number,bin_str); // 经过函数将bin_str数组转化成二进制的字符形式
        printf("%d is\n",number);
        show_bstr(bin_str); // 按照每输出四个字符输出一个空格符
        putchar('\n');
        number = invert_end(number,4); // 根据所需要的转换位数转换number
        printf("Inverting the last 4 bits gives\n");
        show_bstr(itobs(number,bin_str)); // 输出转换后的结果
        putchar('\n');
    }
    puts("Bye!");
}


    /*      带参数的宏       */
void mac_arg(void)
{
    int x = 4;
    int z;

    printf("x = %d\n",x);
    z = SQUARE(x);
    printf("Evaluating SQUARE(x): ");
    PR(z);
    z = SQUARE(2);
    printf("Evaluating SQUARE(2): ");
    PR(z);
    printf("Evaluating SQUARE(x+2): ");
    PR(SQUARE(x+2));
    printf("Evaluating 100/SQUARE(2): ");
    PR(100/SQUARE(2));
    printf("x is %d.\n",x);
    printf("Evaluating SQUARE(++x): ");
    PR(SQUARE(++x)); // 因为针对++x*++x，并没有关于运算符优先级的规定，所以有些编译器产生5*6，有些则是6*6，我们产生的是6*6
    printf("After incrementing, x is %x.\n",x);
}

void subst(void)
{
    int y = 5;

    PSQR(y);
    PSQR(2 + 4);
}

void glue(void)
{
    int XNAME(1) = 14;
    int XNAME(2) = 20;

    PRINT_XN(1);
    PRINT_XN(2);
}

void variadic(void)
{
    double x = 48;
    double y;

    y = sqrt(x);
    PRC(1,"x = %g\n",x);
    PRC(2,"x = %.2f,y = %.4f\n",x,y);
}

void sign_off(void)
{
    puts("Thus terminates another magnificent program from");
    puts("SeeSaw Software!");
}
void too_bad(void)
{
    puts("SeeSaw Software extends its heartfelt condolences");
    puts("to you upon the failure of your program.");
}
void byebye()
{
    int n;

    atexit(sign_off); // 结束时候执行，此处注册
    puts("Enter an integer: ");
    if(scanf("%d",&n) != 1) // 不能成功输入整型值时
    {
        puts("That's no integer!");
        atexit(too_bad);
        exit(EXIT_FAILURE); // 直接退出
    }
    printf("%d is %s.\n",n,(n%2 == 0)?"even":"odd");
}
