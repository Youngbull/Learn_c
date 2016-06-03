#include <stdio.h>
#include <stdlib.h>
#include "capture12.h"

    /*      内层定义覆盖外部定义实例        */
void hiding()
{
    int x = 30;
    printf("x in outer block: %d\n",x);
    {
        int x = 77;
        printf("x in inner block: %d\n",x); // 会发现，输出的结果显示这里的x作用域范围只有花括号以内的空间
    }
    printf("x in outer block: %d\n",x);
    while(x++ < 33) // 此处执行的是x = 30的初始化部分
    {
        int x = 100;
        x++;
        printf("x in while loop: %d\n",x); //因为每一次x都会再次定义，因此输出一直是101
    }
    printf("x in outer block:%d\n",x); // 运行离开内存代码块时，外部变量重新恢复使用
}
void hiding2() // 整个循环是该循环所在代码块，循环体是整个循环代码块的字代码块（if语句也是一个代码块）
{
    int n = 10;

    printf("Initially, n = %d\n",n);
    for(int n = 1;n < 3;n++)
        printf("loop 1: n = %d\n",n);
    printf("After loop 1, n = %d\n",n);
    for(int n = 1;n < 1;n++)
    {
        printf("loop 2 index n = %d\n",n);
        int n = 300;
        printf("loop 2: n = %d\n",n);
        n++;
    }
    printf("After loop 2, n = %d\n",n);
}

    /*      静态变量（局部静态变量、具有外部链接的静态变量、具有内部链接的局部变量）        */
    /* 静态是指变量的位置固定不动
     * 具有文件作用域的变量自动具有静态存储空间
     * 可创建具有代码块作用域，兼具静态存储的局部变量（与自动变量有相同的作用域，当包含这些变量的函数完成时，它们并不消失）
     * 上面所述的变量通过使用存储类说明符static在代码块内声明创建
     */
void trystat(void)
{
    int fade = 1; // 非静态局部变量
    static int stay = 1; // 局部静态变量stay （变量stay只在编译trystat时被初始化一次）
                         // 静态变量和外部变量在程序调入内存时已经就位了，并非程序运行过程中的语句（说的是初始化过程）
    printf("fade = %d and stay = %d\n",fade++,stay++);
}
void loc_stat(void)
{
    int count;
    for(count = 1;count <= 3;count++)
    {
        printf("Here comes iteration %d: \n",count);
        trystat();
    }
}

    /*      具有外部链接的静态变量（变量的定义放在所有函数之外，就创建了一外部变量。为更清晰，使用它的函数会用extern再次声明）     */
//int hocus;
//int magic();
//int main(void)
//{
//    extern int hocus; // 声明hocus为外部变量（这里只是为了使调用函数更加清晰）
//    ...
//}
//int magic1()
//{
//    int hocus; // 这里声明了hocus，默认为自动变量
//    ...
//}
//int pocus; // 这里的定义是一个外部变量，对magic2可见但是对magic1和main不可见，因为所在位置的原因
//int magic2()
//{
//    auto int hocus; // 把局部变量hocus显式的声明为自动变量
//    ...
//}
int units = 0; // 定义一个外部变量
void global(void)
{
    extern int units; // 声明，这里不声明应该也可以

    printf("How many pounds to a firkin of butter?\n");
    scanf("%d",&units);
    while(units != 56) // 通过这句话能够说明全局变量的性质
        critic();
    printf("You must have looked it up!\n");
}
void critic()
{
    printf("No luck, chunny. Try again.\n");
    scanf("%d",&units); // units是全局变量
}

    /*      具有内部链接的静态变量（一句很重要的描述————具有静态存储时期、文件作用域以及内部链接）     */
int count = 0; // 文件作用域，外部链接
static int total = 0; // 静态定义，内部链接（在个人理解：本文件内部是全局变量，但是不能被其他函数调用）
void accumulate(int k)
{
    static int subtotal = 0; // 静态局部变量，代码块作用域，空链接，静态存储时期
                             // 实际上不在代码执行内，只有初始化的时候有用到

    if(k <= 0)
    {
        printf("loop cycle: %d\n",count);
        printf("subtotal: %d; total: %d\n",subtotal,total);
        subtotal = 0;
    }
    else
    {
        subtotal += k;
        total += k;
    }
}
void report_count()
{
    printf("Loop executed %d times\n",count);
}
void parta(void)
{
    int value; // 局部变量
    register int i; // 代码块作用域，局部变量

    printf("Enter a positive integer (0 to quit): ");
    while(scanf("%d",&value) == 1 && value > 0)
    {
        ++count; // 无需声明
        for(i = value;i >= 0;i--)
            accumulate(i);
        printf("Enter a positive integer ( 0 to quit): ");
    }
    report_count();
}

    /*      分配内存（malloc和free函数）————使用库函数来分配和管理内存     */
    /*
     * malloc函数具有动态分配内存的功能：
     * 需要一个指示所需内存字节数的参数，函数会在内存中寻找合适大小的块，它分配了块，却是匿名的。
     * 但是malloc可以返回那块内存的第一个字节的地址，将其赋给一个指针变量。
     * 这里可涉及void指针，malloc可返回数组指针、结构指针等，因此一般需要将返回的指针指派合适类型。
     * 因此可以使用空指针作为其返回值，这样不会冲突。（malloc在找不到所需空间时候，会返回一个空指针）
     *
     * free函数的参数是先前malloc函数的返回地址，会释放先前分配的内存，内存持续时间就是从malloc到free
     * 程序还可以调用exit函数，用来在内存分配失败时结束程序
     */
void dyn_arr()
{
    double *ptd;
    int max,number,i = 0;

    puts("What is the maximum number of type double entries?");
    scanf("%d",&max);

    ptd = (double *)malloc(max*sizeof(double)); // 分配相应大小的内存空间
    if(ptd == NULL)
    {
        puts("Memory allocation failed. Goodebye. ");
        exit(EXIT_FAILURE); // 不成功则退出
    }

    puts("Enter the values (q to quit): ");
    while(i < max && scanf("%lf",&ptd[i]) == 1)
        i++;
    printf("Here aer your %d entries: \n",number = i);
    for(i = 0;i < number;i++)
    {
        printf("%7.2f ",ptd[i]);
        if(i%7 == 6)
            putchar('\n'); // 每7个数据，输出一个换行字符
    }
    if(i % 7 != 0)
        putchar('\n');
    puts("Done.");
    free(ptd); // 记得一定要用free函数释放空间，否则可能出现内存泄漏的问题
}
