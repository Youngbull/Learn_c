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
    printf("*%d*\n",PAGES);
    printf("*%2d*\n",PAGES);
    printf("*%10d*\n",PAGES);
    printf("*%-10d*\n",PAGES);
}
