#include<stdio.h>
#include <inttypes.h>

/*      ������֤printf���ݲ���Ӧʱ���      */
void printf1()
{
    int ten = 10;
    int two = 2;
    printf("Doing it right: ");
    printf("%d minus %d is %d\n",ten,2,ten - two);
    printf("Doing it wrong: ");
    printf("%d minus %d is %d\n",ten); // ����%d��û�и������Ӧֵ����ʹ���ڴ�������ֵ
}

/*      ���ڼ������ݳ���ϵͳ���Χʱ���      */
void toobig()
{
    int i = 2147483647;
    uint32_t j = 4294967295UL; // http://blog.csdn.net/duguduchong/article/details/7709482

    printf("%d %d %d\n",i,i+1,i+2); // �з����������㲻ͬ����
    printf("%d %d %d\n",j,j+1,j+2); // ��鿴��������ʾ
}

/*      ����ȷ��������     */
void badcount()
{
    int f = 4;
    int g = 5;
    float h = 5.0f;

    printf("%d\n",f,g);
    printf("%d %d\n",f);
}
