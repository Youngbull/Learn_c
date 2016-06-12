#ifndef CAPTURE14_H_INCLUDED
#define CAPTURE14_H_INCLUDED

#define MAXTITL 40
#define MAXAUTL 40
#define MAXBKS 100
#define LEN 20

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

void manybook();
void friends();

#endif // CAPTURE14_H_INCLUDED
