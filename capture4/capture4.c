#include <stdio.h>
#include <string.h>
#include "main.h"

/*      ǰ������        */
void talkback()
{
    float weight,volume;
    int siz,letters;
    char name[40];

    printf("What is your first name?\n");
//   scanf("%s",&name); // ����Ӳ��ӵ�ַ��û���������������name������ǵ�ַ
    scanf("%s",name); // scanf������ȡʱ�����������ĵ�һ���ո��Ʊ����tab�����߻��з���newline����ֹͣ��ȡ��
    printf("%s,What is your weight in pounds?\n",name);
    scanf("%f",&weight);
    siz = sizeof name; // sizeof������ṩ������ֽ���Ŀ
    letters = strlen(name);
    volume = weight/DENSITY;
    printf("Well,%s,your age is %2.2f cubic feet.\n",name,volume); // ���ִ�ӡ��ʽ%2.2f��һ��Ҫ���
    printf("Also,your first name has %d letters,\n",letters);
    printf("and we have %d bytes to store it in.\n",volume);
}

/*      printf����ʹ�ù���֮һ�����       */
void width()
{
    printf("*%d*\n",PAGES);
    printf("*%2d*\n",PAGES);
    printf("*%10d*\n",PAGES);
    printf("*%-10d*\n",PAGES);
}
