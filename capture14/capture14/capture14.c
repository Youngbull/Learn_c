#include <stdio.h>
#include "capture14.h"

void manybook()
{
    struct book library[MAXBKS];
    int count = 0;
    int index;

    printf("Please enter the book title.\n");
    printf("Press enter at the start of a line to stop.\n");
    while(count < MAXBKS && gets(library[count].title) != NULL && library[count].title[0] != '\0') // 达到数组值、title输入失败、title输入为空
    {
        printf("Now enter the author.\n");
        gets(library[count].author);
        printf("Now enter the value.\n");
        scanf("%f",&library[count++].value);
        while(getchar() != '\n')
            continue; // 为了清空输入行
                      // 因为scanf函数会把\n留在输入流中（它会忽略掉空格和换行符）
        if(count < MAXBKS)
            printf("Enter the next title.\n");
    }
    if(count > 0)
    {
        printf("Here is the list of your books: \n");
        for(index = 0;index < count;index++)
            printf("%s by %s: $%.2f\n",library[index].title,library[index].author,library[index].value);
    }
    else
        printf("No books? Too bad.\n");
}


    /*      嵌套结构例子      */
const char *msgs[5] = {
    "   Thank you for the wonderful evening, ",
    "You certainly prove that a ",
    "is a special kind of guy. We must get together ",
    "over a delicious ",
    " and have a few laughs"};

void friends()
{
    struct guy fellow = {   //初始化一个变量
    {"Ewen","Villard"},
    "grilled salmon",
    "personality coach",
    581120.00
    };

    printf("Dear %s, \n\n",fellow.handle.first);
    printf("%s%s.\n",msgs[0],fellow.handle.first); // 嵌套结构的使用方式
    printf("%s%s\n",msgs[1],fellow.job);
    printf("%s\n",msgs[2]);
    printf("%s%s%s",msgs[3],fellow.favfood,msgs[4]);
    if(fellow.income > 150000.0)
        puts("!!");
    else if(fellow.income > 75000.0) // income是float类型函数
        puts("!");
    else
        puts(".");
    printf("\n%40s%s\n"," ","See you soon, ");
    printf("%40s%s\n"," ","Shalala");
}
