#include <stdio.h>


    /*      比两个整数中的较小者（用作函数的讲解，包含imin.c子部分以及lesser.c函数）
     *      请试着比较一下不同输入形势下的运行。（参看书本219页注解）
     */
int imin(int n,int m)
{
    int mins;

    if(n < m)
        mins = n;
    else
        mins = m;
    return mins;
}
void lesser()
{
    int evil1,evil2;

    printf("Enter a pair of integers(q to quit): \n");
    while(scanf("%d %d",&evil1,&evil2) == 2)
    {
        printf("The letter of %d and %d is %d.\n",
               evil1,evil2,imin(evil1,evil2));
        printf("Enter a pair of integers (q to quit); \n");
    }
    printf("Bye.\n");
}

    /*      该函数用来验证不正确使用函数情况下的运行结果      */
int imax(n,m)
int n,m;
{
    int maxs;
    if(n > m)
        maxs = n;
    else
        maxs = m;
    return maxs;
}

    /*      递归举例        */
void up_and_down(int n)
{
    printf("Level %d: n location %p\n",n,&n);
    if(n < 4)
        up_and_down(n+1);
    printf("Level %d: n location %p\n",n,&n);
}

    /*      使用循环和递归计算阶乘（使用尾递归的方式）
     *      这两种方法里面最好是使用循环————
     *      1、每次递归调用都拥有自己的变量集合，所以占用内存较大，每次递归调用需要把新的变量集合存储在堆栈中
     *      2、每次花的时间也比较多
     */
long fact(int n) // 使用循环形式计算阶乘
{
    long ans;

    for(ans = 1; n > 1; n--) // 此处本来我是打算使用（n >= 0），发现这种方式更好
    {
        ans = ans*n;
    }
    return ans;
}
long rfact(int n) // 使用递归形式计算阶乘
{
    long ans;

    if(n > 0)
        ans = n*rfact(n - 1); // 这里本来是n--，但是会出现错误，无法执行下去，那么在你看来问题的原因是什么？
                              // 如果是--n又是什么结果？为什么，修改哪里能够弥补？
    else
        ans = 1;
    return ans;
}
void factor() // 对于fact和rfact的运用
{
    int num;

    printf("This program calculates factorials.\n");
    printf("Enter a value in the range 0-12(q to quit): \n");
    while(scanf("%d",&num) == 1)
    {
        if(num < 0)
            printf("No negative numbers,please.\n");
        else if(num > 12)
            printf("Kepp input under 13.\n"); // 限制在了0-12之间
        else
        {
            printf("loop: %d factorial = %ld\n",num,fact(num)); // 在使用循环情况下的打印情况
            printf("recursion: %d factorial = %ld\n",num,rfact(num)); // 使用递归情况下打印输出
        }
        printf("Enter a value in the range 0-12(q to quit):\n");
    }
    printf("Bye.\n");
}
    /*      二进制形式输出整数       */
void to_binary(unsigned long n)
{
    int r;
    r = n % 2;
    if(n >= 2)
        to_binary(n/2); // 对一个数据进行二进制计算
    putchar('0' + r); // 先输出的是最高的，最后输出的是最低的
}
void binary(void)
{
    unsigned long number;
    printf("Enter an integer(q to quit): \n");
    while(scanf("%lu",&number) == 1) // 这样子结束不太好啊
    {
        printf("Binary equivalent: ");
        to_binary(number);
        putchar('\n'); // 输出换行符
        printf("Enter an inteer(q to quit): \n");
    }
    printf("Done. \n");
}
    /*      一种利用递归解决问题的方式————菲波那切数列，就是1,1,2,3,5,8,13这种      */
long Fibonacci(int n)
{
    if(n > 2)
        return Fibonacci(n - 1) + Fibonacci(n - 2);
    else
        return 1;
}

    /*      改变调用函数中的变量(使用指针的方式实现函数间的通信)      */
void interchange1(int u,int v)
{
    int temp;

    printf("Originally  u = %d and v = %d.\n",u,v);
    temp = u;
    u = v;
    v = temp;
    printf("Now u = %d and v = %d.\n",u,v); // 比较两次打印的结果，会发现实际程序时执行了的，但是只是结果未能对形参产生影响
}
void swap1(void)
{
    int x = 5,y = 10;
    printf("Originally x = %d and y = %d.\n",x,y);
    interchange1(x,y);
    printf("Now x = %d and y = %d.\n",x,y);
}
void interchange2(int *u,int *v) // 注意这里的声明，是声明的指针
{
    int temp;

    temp = *u;
    *u = *v;
    *v = temp;
}
void swap2(void)
{
    int x = 5,y = 10;

    printf("Originally  x = %d and y = %d.\n",x,y);
    interchange2(&x,&y); // 传输的是地址
    printf("Now x = %d and y = %d.\n",x,y); // 比较两次打印的结果，会发现实际程序时执行了的，但是只是结果未能对形参产生影响
}
