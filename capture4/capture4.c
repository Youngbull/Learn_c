#include <stdio.h>
#include <string.h>
#include "main.h"

/*      前导程序        */
void talkback()
{
    float weight,volume;
    int siz,letters;
    char name[40];

    printf("What is your first name?\n");
//   scanf("%s",&name); // 这里加不加地址符没区别，明白数组情况name本身就是地址
    scanf("%s",name); // scanf函数读取时，会在遇到的第一个空格，制表符（tab）或者换行符（newline）处停止读取。
    printf("%s,What is your weight in pounds?\n",name);
    scanf("%f",&weight);
    siz = sizeof name; // sizeof运算符提供对象的字节数目
    letters = strlen(name);
    volume = weight/DENSITY;
    printf("Well,%s,your age is %2.2f cubic feet.\n",name,volume); // 这种打印格式%2.2f，一定要清楚
    printf("Also,your first name has %d letters,\n",letters);
    printf("and we have %d bytes to store it in.\n",volume);
}

/*      printf函数使用功能之一，玩的       */
void width()
{
    const double RENT = 3852.99; // 知道的有三种创建常量的方式————预定义模式、const类型、枚举类型。

    printf("*%d*\n",PAGES); // PAGES在main.h中，预定义模式创建
    printf("*%2d*\n",PAGES);
    printf("*%10d*\n",PAGES);
    printf("*%-10d*\n",PAGES); // ‘-’这里是一种转换说明修饰符（项目左对齐），请参看71页
    printf("*%#X*\n\n\n",PAGES); // ‘#’号符若使用%o（无符号八进制整数），则以0开始，若以%x和%X格式，则以0x或者0X开始。
                                 // 对于所有的浮点形式，‘#’保证即使不跟任何数字，也打印一个小数点字符。

    printf("It's the float:\n");
    printf("*%f*\n",RENT); // 浮点数，十进制记数法
    printf("*%e*\n",RENT); // 浮点数，e-记数法
    printf("*%4.2f*\n",RENT);
    printf("*%3.5f*\n",RENT);
    printf("*%10.3f*\n",RENT);
    printf("*%10.3e*\n",RENT);
    printf("*%+4.2f*\n",RENT); // 有符号数为正则带加号符，为负则带减号符
    printf("*%010.2f*\n",RENT); // 前导零填充字段宽度
}

/*      scanf函数的使用      */
void input()
{
    int age;
    float asserts;
    char pet[30];

    printf("Enter your age,asserts and favorite pet.\n");
    scanf("%d %f",&age,&asserts); // 此处需要&，另外请观察实际输入按照何种方式可以正常执行（可用于明白scanf的执行）
    scanf("%s",pet);
    printf("%d $%.2f %s\n",age,asserts,pet);
}
