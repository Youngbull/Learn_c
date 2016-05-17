#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/*      用于了解getchar以及putchar的函数，在遇到‘#’字符时停止输入这里涉及到缓冲区的概念，请参看189页缓冲区内容       */
void echo()
{
    char ch;
    while((ch = getchar()) != '#')
        putchar(ch);
}

/*      对应上面函数，       */
void echo_eof()
{
    int ch;
    while((ch = getchar()) != EOF)
        putchar(ch);
}

/*      打开一个文件并且显示其内容       */
void file_eof()
{
    int ch;
    FILE *fp;
    char fname[50];

    printf("Enter the name of the file:");
    scanf("%s",fname);
    fp = fopen(fname,"r");
    if(fp == NULL)
    {
        printf("Failed to open file. Bye\n");
        exit(1);
    }
    while((ch = getc(fp)) != EOF)
        putchar(ch);
    fclose(fp);
}

/*      一个低效错误的猜数程序（包括改进）       */
void guess_data()
{
    int guess = 1;
    printf("Pick an integer from 1 to 100. I will try to guess ");
    printf("it.\nRespond with a y if my guess is right and width");
    printf("\nan n if is wrong.\n");
    printf("Uh...is your number %d?\n",guess);

//    while(getchar() != 'y')
//        printf("Well,then,is it %d?\n",++guess); // 之所以每次输入会产生两个相应，是因为换行符的存在。这里将换行符作为另一个否定了。

      /*    改进1   */
    while(getchar() != 'y')
    {
        printf("Well,then,is it %d\n",++guess);
        while(getchar() != '\n')
            continue; // 跳过了输入行的剩余部分
    }

    /*      改进2     */
//    char response;
//    while((response = getchar()) != 'y')
//    {
//        if(response == 'n')
//            printf("Well,then,is it%d?\n",++guess);
//        else
//            printf("sorry,I understand only y or n.\n");
//        while((getchar() != 'n'))
//            continue;
//    }
}

    /*      带有一个较大的I/O问题的程序         */
void display(char cr,int lines,int width)
{
    int row,col;

    for(row = 1;row <= lines;row++)
    {
        for(col = 1;col <=width;col++)
            putchar(cr);
        putchar('\n'); // 结束本行，开始新的一行
    }
}
void showchar1() // 代码有很大的问题,我们原本的愿望
{
    int ch;
    int rows,cols;
    printf("Enter a character and two integers:\n");

    while((ch = getchar()) != '\n') // 此处是换行符，如果是使用其他的比如‘a’就更能看出差别
    {
        scanf("%d %d",&rows,&cols); // 因为scanf会跳过空格、制表符和换行符，所以输入c 2 3，然后换行就会出现自动跳出的过程
        display(ch,rows,cols);
        printf("Enter another character and two integer:\n");
        printf("Enter a newline to quit.\n");
    }
    printf("Bye.\n");
}
void showchar2() // showchar1的改进方式
{
    int ch;
    int rows,cols;

    printf("Enter a character and two integers:\n");

    while((ch = getchar()) != '\n')
    {
        if(scanf("%d %d",&rows,&cols) != 2)
            break;
        display(ch,rows,cols);
        while(getchar() != '\n') // 遇到换行符，则什么都不做略掉，使换行符不对程序造成负担
            continue;
        printf("Enter another character and two integer:\n");
        printf("Enter a newline to quit.\n");
    }
    printf("Bye.\n");
}


    /*      用于输入确认的函数，本函数是来向一个算术函数传送整数，
     *      该函数计算特定范围内所有整数的平方和，限定上界不应大于1000，下界不小于-1000
     *      包含有checking.c   get_int.c   sum_squares.c   bad_limits.c
     */
int get_int(void)
{
    int input;
    char ch;

    while(scanf("%d",&input) != 1)
    {
        while((ch = getchar()) != '\n')
            putchar(ch); // 剔除错误的输入
        printf(" is not an integer.\nPlease enter an ");
        printf("integer value,such as 25,-178 or 3:");
    }
    return input;
}
double sum_squares(int a,int b)
{
    double total = 0;
    int i;

    for(i = a;i < b;i++)
        total += i*i;
    return total;
}
bool bad_limits(int begins,int ends,int low,int high)
{
    bool not_good = false;

    if (begins > ends)
    {
       printf("%d isn't smaller than %d.\n",begins,ends);
       not_good = true;
    }
    if (begins < low || ends < low)
    {
        printf("Values must be %d or greater.\n",low);
        not_good = true;
    }
    if (begins > high || ends > high)
    {
        printf("Values must be %d or less.\n",high);
        not_good = true;
    }
    return not_good;
}
void checking()
{
    const int MIN = -1000;
    const int MAX = +1000;
    int start;
    int stop;
    double answer;

    printf("This program computes the sum of the squares of "
           "integers in a range.\nThe lower bound should not "
           "be less than -1000 and\nthe upper bound should not "
           "be more than +1000.\nEnter the limits (enter 0 for "
           "both limits to quit):\nlower limits: ");
    start = get_int();
    printf("upper limits: ");
    stop = get_int();
    while(start != 0 || stop != 0)
    {
        if(bad_limits(start,stop,MIN,MAX))
            printf("Please try again.\n");
        else
        {
            answer = sum_squares(start,stop);
            printf("The sum of the squares of the integers from ");
            printf("from %d to %d is %g\n",start,stop,answer);
        }
        printf("Enter the limits(enter 0 for both limits to quit): \n");
        printf("lower limits: ");
        start = get_int();
        printf("upper limit: ");
        stop = get_int();
    }
    printf("Done.\n");
}
