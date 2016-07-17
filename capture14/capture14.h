#ifndef CAPTURE14_H_INCLUDED
#define CAPTURE14_H_INCLUDED

#define MAXTITL 40
#define MAXAUTL 40
#define MAXBKS 100
#define LEN 20
#define FUNDLEN 50

struct book{
    char title[MAXTITL];
    char author[MAXAUTL];
    float value;
    }; // 这种方式是一种声明

struct names {
    char first[LEN];
    char last[LEN];
    };

struct guy {
    struct names handle; // 嵌套结构
    char favfood[LEN];
    char job[LEN];
    float income;
    };

struct namect {
    char fname[20];
    char lname[20];
    int letters;
    };
struct namect1 {
    char *fname; //使用指针的形式
    char *lname;
    int letters;
    };

struct flex {
    int count;
    double average;
    double scores[]; // 伸缩型数组成员
    };

void manybook();
void friends();
void names1();
void names3();
void flexmemb(void);

#endif // CAPTURE14_H_INCLUDED
