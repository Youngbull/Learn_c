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
    const double RENT = 3852.99; // ֪���������ִ��������ķ�ʽ��������Ԥ����ģʽ��const���͡�ö�����͡�

    printf("*%d*\n",PAGES); // PAGES��main.h�У�Ԥ����ģʽ����
    printf("*%2d*\n",PAGES);
    printf("*%10d*\n",PAGES);
    printf("*%-10d*\n",PAGES); // ��-��������һ��ת��˵�����η�����Ŀ����룩����ο�71ҳ
    printf("*%#X*\n\n\n",PAGES); // ��#���ŷ���ʹ��%o���޷��Ű˽���������������0��ʼ������%x��%X��ʽ������0x����0X��ʼ��
                                 // �������еĸ�����ʽ����#����֤��ʹ�����κ����֣�Ҳ��ӡһ��С�����ַ���

    printf("It's the float:\n");
    printf("*%f*\n",RENT); // ��������ʮ���Ƽ�����
    printf("*%e*\n",RENT); // ��������e-������
    printf("*%4.2f*\n",RENT);
    printf("*%3.5f*\n",RENT);
    printf("*%10.3f*\n",RENT);
    printf("*%10.3e*\n",RENT);
    printf("*%+4.2f*\n",RENT); // �з�����Ϊ������Ӻŷ���Ϊ��������ŷ�
    printf("*%010.2f*\n",RENT); // ǰ��������ֶο��
}

/*      scanf������ʹ��      */
void input()
{
    int age;
    float asserts;
    char pet[30];

    printf("Enter your age,asserts and favorite pet.\n");
    scanf("%d %f",&age,&asserts); // �˴���Ҫ&��������۲�ʵ�����밴�պ��ַ�ʽ��������ִ�У�����������scanf��ִ�У�
    scanf("%s",pet);
    printf("%d $%.2f %s\n",age,asserts,pet);
}
