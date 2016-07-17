#include <stdio.h>
#include <string.h>
#include <stdlib.h>
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
//    struct guy fellow[2] = {   //初始化一个变量
//    {"Ewen","Villard"},
//    "grilled salmon",
//    "personality coach",
//    58112.00
//    };

//    printf("Dear %s, \n\n",fellow.handle.first);
//    printf("%s%s.\n",msgs[0],fellow.handle.first); // 嵌套结构的使用方式
//    printf("%s%s\n",msgs[1],fellow.job);
//    printf("%s\n",msgs[2]);
//    printf("%s%s%s",msgs[3],fellow.favfood,msgs[4]);
//    if(fellow.income > 150000.0)
//        puts("!!");
//    else if(fellow.income > 75000.0) // income是float类型函数
//        puts("!");
//    else
//        puts(".");
//    printf("\n%40s%s\n"," ","See you soon, ");
//    printf("%40s%s\n"," ","Shalala");

    /*      使用指针的形式使用结构体        */
    struct guy fellow[2] = {   // 定义一个结构体数组
    {{"Ewen","Villard"},
    "grilled salmon",
    "personality coach",
    58112.00},
    {{"Eodney","Swillbelly"},
    "tripe",
    "tabloid editor",
    232400.00
    }
    };

    struct guy *him;
    printf("address #1: %p #2: %p\n",&fellow[0],&fellow[1]);
    him = &fellow[0]; // 结构体指针指向结构体（与数组不同,结构体的名字并不是结构体的地址，所以必须使用&符号）
    printf("pointer #1: %p #2: %p\n",him,him+1); // 因为输出是指针，因此直接用him就可以了（指针按照结构体变量长度增加）
    printf("him->income is $%.2f: (*him) .income is $%.2f\n", him->income,(*him).income); // 两种通过指针形式访问结构体的方式
    him++;
    printf("him->favfood is %s: him->handle.last is %s\n",him->favfood,him->handle.last); // 指针的嵌套使用
}

    /*      使用指向结构的指针       */
void getinfo(struct namect *pst)
{
    printf("Please enter your first name.\n");
    gets(pst->fname);
    printf("Please enter your last name.\n");
    gets(pst->lname);
}

void makeinfo(struct namect *pst)
{
    pst->letters = strlen(pst->fname) + strlen(pst->lname);
}

void showinfo(const struct namect *pst)
{
    printf("%s %s, your name contains %d letters.\n", pst->fname,pst->lname,pst->letters);
}

void names1()
{
    struct namect person;
    getinfo(&person);
    makeinfo(&person);
    showinfo(&person);
}

    /*      使用指针和malloc函数       */
void getinfo1(struct namect1 *pst)
{
    char temp[81];
    printf("Please enter your first name.\n");
    gets(temp);
    // 分配用来存放名字的内存
    pst->fname = (char *)malloc(strlen(temp) + 1); // 这里用结构体内的字符串指针保存分配内存的的地址
    // 把名字复制到已分配的内存中
    strcpy(pst->fname,temp); // temp和pst->fname是完全不同的，上一步只是分配了这么个空间
    printf("Please enter your last name.\n");
    gets(temp);
    pst->lname = (char *)malloc(strlen(temp) + 1);
    strcpy(pst->lname,temp);
}
void makeinfo1(struct namect1 *pst)
{
    pst->letters = strlen(pst->fname) + strlen(pst->lname);
}
void showinfo1(const struct namect1 *pst)
{
    printf("%s %s,your name contains %d letters.\n",pst->fname,pst->lname,pst->letters);
}
void cleanup(struct namect1 *pst)
{
    free(pst->fname);
    free(pst->lname); // 释放空间
}

void names3(void)
{
    struct namect1 person;

    getinfo1(&person);
    makeinfo1(&person);
    showinfo1(&person);
    cleanup(&person);
}


    /*      伸缩型数组成员     */
void showflex(const struct flex *p)
{
    int i;
    printf("Scores: ");
    for(i = 0;i < p->count;i++)
        printf("%g ",p->scores[i]);
    printf("\nAverage: %g\n",p->average);
}
void flexmemb(void)
{
    struct flex *pf1,*pf2;
    int n = 5;
    int i;
    int tot = 0;

    //用结构和数组分配存储空间
    pf1 = malloc(sizeof(struct flex) + n * sizeof(double));
    pf1->count = n;
    for(i = 0;i < n;i++)
    {
        pf1->scores[i] = 20.0 - i;
        tot += pf1->scores[i];
    }
    pf1->average = tot / n;
    showflex(pf1);

    n = 9;
    tot = 0;
    pf2 = malloc(sizeof(struct flex) + n * sizeof(double));
    pf2->count = n;
    for(i = 0;i < n;i++)
    {
        pf2->scores[i] = 20.0 - i/2.0;
        tot += pf2->scores[i];
    }
    pf2->average = tot/n;
    showflex(pf2);
    free(pf1);
    free(pf2);
}
