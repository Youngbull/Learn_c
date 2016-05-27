#include <stdio.h>
#include "capture10.h"

    /*      使用指定初始化项目（在C99标准下的一种指定位置初始化方式，真的有什么用处吗？）        */
void designate(void)
{
    int days[MONTHS] = {31,28,[4] = 31,30,31,[1] = 29}; // 将days[1]赋予了29，给days[4]赋予了31。(具体查看248页)
                                                        // 但是如果是类推的话，为什么中间值为0？这是因为，赋给了days[4]之后，紧接着是5he6.
    int i;

    for(i = 0;i < MONTHS;i++)
        printf("%2d %d\n",i+1,days[i]); // 这里的输出请仔细观看
}

    /*      指针加法        */
void put_add(void)
{
    short dates[SIZE];
    short *pti;
    short index;
    double bills[SIZE];
    double *ptf;
    pti = dates;
    ptf = bills;
    printf("%23s %10s\n","short","dpuble");
    for(index = 0;index < SIZE;index++)
        printf("pointers + %d: %10p %10p\n",index,pti + index,ptf + index);
}

    /*      如何在函数中利用数组作为形参      */
void sum1(int *ar) //
{
    int i;
    int total = 0;

    for(i = 0;i < 10;i++) // 只适用于数组大小小于10的？还是等于？
        total += ar[i];
    printf("The sum of ar is %d.\n",total);
}
void sum2(int *ar,int n) // 基于sum1()函数的改进方案，传递两个参数
{
    int i;
    int total = 0;

    for(i = 0;i < n;i++)
        total += ar[i];
    printf("The sum of ar is %d.\n",total);
    printf("The size of ar is %d bytes.\n",sizeof ar);
}
void sum3(int *start,int *ends) // 函数中传递数组大小的另一种方式，传递头和尾地址
{
    int total = 0;
    while(start < ends) // 这里使用的是while循环方式不是for的形式
    {
        total += *start; // total累计值(这里是*start，而不是start，要明白区别)
        start++; // 指针指向了下一个元素
    }
    printf("The sum of the ar is %d.\n",total);
}

    /*      指针运算的优先级        */
void order()
{
    int *p1,*p2,*p3;

    p1 = p2 = data;
    p3 = moredata;
    printf(" *p1 = %d, *p2 = %d, *p3 = %d\n",*p1,*p2,*p3); // 100,100,300
    printf(" *p1++ = %d, *++p2 = %d, (*p3)++ = %d\n",*p1++,*++p2,(*p3)++); // 100,200,300
    printf(" *p1 = %d, *p2 = %d, *p3 = %d\n",*p1,*p2,*p3); // 200,200,301(*p3)++
}

    /*      指针操作（用于练习）        */
void ptr_ops()
{
    int urn[5] = {100,200,300,400,500};
    int *ptr1,*ptr2,*ptr3;

    ptr1 = urn; // 把一个地址赋给指针
    ptr2 = &urn[2]; // 取得指针指向的值，并且得到指针的地址

    printf("pointer value,dereference pointer,pointer address:\n");
    printf("ptr1 = %p,*ptr1 = %d,&ptr1 = %p\n",ptr1,*ptr1,&ptr1);

    ptr3 = ptr1 + 4;
    printf("\nadding an int to a pointer:\n");
    printf("ptr1 + 4 = %p, *(ptr1 + 3) = %d\n",ptr1 + 4,*(ptr1 + 3));

    ptr1++; // 递增指针
    printf("\nvalues after ptr1++\n");
    printf("ptr1 = %p, *ptr1 = %d, &ptr1 = %p\n",ptr1,*ptr1,&ptr1);

    ptr2--; // 递减指针
    printf("\nvalues after --ptr2\n");
    printf("ptr2 = %p, *ptr2 = %d, &ptr2 = %p\n",ptr2,*ptr2,&ptr2);

    --ptr1; // 恢复至初始值
    ++ptr2; // 恢复至初始值
    printf("\nPointers reset to original values:\n");
    printf("ptr1 = %p, ptr2 = %p\n",ptr1,ptr2);
            // 一个指针减去另一个指针
    printf("\nsubtractng one pointer from another:\n");
    printf("ptr2 = %p, ptr1 = %p, ptr2 - ptr1 = %d\n",ptr2,ptr1,ptr2 - ptr1);
            // 一个指针减去一个整数
    printf("\nsubtracting an int from a pointer:\n");
    printf("ptr3 = %p, ptr3 - 2 = %p\n",ptr3,ptr3 - 2);
}

    /*
     * 通常函数中传递数组可以传递值，也可以传递指针
     * 当传递值的时候，不会对其结果进行修改，但是对于这种形式的数据，这种方式明显太过繁琐
     * 所以实际使用中大多是传递指针的方式
     * 但是这也就产生了改变数组值得隐患，人总会犯错
     * 相对应的，就有了保护数组内容的传递方式
     */
void show_array(const double ar[],int n) // 数组内容输出 （这里不需要对数组内容进行改变，因此使用了关键字const）
{
    int i;

    for(i = 0;i < n;i++)
        printf("%8.3f",ar[i]);
    putchar('\n');
}
void mult_array(double ar[],int n,double mult) // 数组内的元素分别乘以一个因数值mult，这里需要改变，形参就不是const的（数组类型是double型的）
{
    int i;

    for(i = 0;i < n;i++)
        ar[i] *= mult;
}
void arf()
{
    double dip[SIZE] = {20.0, 17.66, 8.2, 15.3, 22.22};

    printf("The original dip array: \n");
    show_array(dip,SIZE);
    mult_array(dip,SIZE,2.5); // 这里对数组内容进行了修改，因为传递的是指针，所以可以直接对数组内容更改
    printf("The dip array after calling mult_array(): \n");
    show_array(dip,SIZE);
}

    /*
     * 指针常量的学习，在不同情况下的结果。具体有：
     * 常指针、常引用定义格式为———— const 数据类型 常量名=常量值；
     * 例如，const int *p = &b和int const *p = &b；（常指针） const int &m= b；（常引用）
     * 常指针和常引用功能上受到限制，即不能通过它们更改其指向的变量的数据！！！！
     *
     * 指针常量，定义格式———— 数据类型 *const 指针常量=常量值；
     * 例如，char ch， *const pch=&ch；（可分开或者一步完成）
     * 也就是说这个指针本身是个常量，不可改变（指向地址），但是可通过该指针改变指向内容
     *
     */
void const_test()
{
    double rates[5] = {88.93,100.12,59.45,183.11,340.5};
    const double locked[4] = {0.08,0.075,0.0735,0.07};
//    double *pnc = rates; // 产生了警告（warning），因为非常量数据的地址才可以赋给普通的指针
                         // 常量或非常量数据的地址赋给指向常量的指针是合法的（防止通过指针修改常量的数据）
    const double *pnc = rates; // 正确方式
    pnc = locked;
    printf("The number of the pointer pnc is %f.\n",*pnc);
    // 情况一：
//    double* const pd = rates; // pd是个指向double的常指针
//    *pd =29.49; // 允许
//    pd[2] = 34.5; // 允许
//    printf("The number of rates[0] and rates[2] are %f and %f.\n",*pd,*(pd+2));
//    pd++; // 不允许
    // 情况二：
//    const double* pd = rates; // pd是个指向double型常量的指针（或者double const *pd都一样）
//    *pd = 29.49; // 不允许
//    pd[2] = 34.5; // 不允许
//    pd++; // 允许
}

    /* 指针和多维数组————例如：int zippo[4][2]
     * 首先，zippo同时是数组首元素的地址，zippo首元素本身也是包含2个int的数组，因此zippo包含2个int的数组的地址
     * 简单说，zippo[0]是一个整数大小对象的地址，而zippo是两个整数大小对象的地址；
     *
     * 其次，对于zippo+1和zippo[0]+1这样的运算，所以一个是两个int对象，一个是一个int对象；
     *
     * 对一个指针（地址）取值（使用运算符*或者带有索引的[]运算符）得到的是指针指向的对象的数值。
     * 所以*zippo[0]代表存储在zippo[0][0]中的数值。同样*zippo代表首元素zippo[0]的值但是zippo[0]本身就是一个int数的地址，即&zippo[0][0]
     * **zippo等价于zippo[0][0]（这种数组是双重间接的典型例子）。
     *
     * zippo[2][1]的等价指针符号表示为*(*(zippo+2)+1)
     */
void zippo1()
{
    int zippo[4][2] = { {2,4},{6,8},{1,3},{5,7} };

    printf(" zippo = %p, &zippo[0] = %p, &zippo[0][0] = %p\n",zippo,&zippo[0],&zippo[0][0]); // 三者结果相同
    printf(" zippo = %p, zippo + 1 = %p\n",zippo,zippo + 1);
    printf(" zippo[0] = %p, zippo[0] + 1 = %p\n",zippo[0],zippo[0] + 1);
    printf(" *zippo = %p, zippo + 1 = %p\n",*zippo,*zippo + 1);
    printf(" zippo[0][0] = %d\n",zippo[0][0]);
    printf(" *zippo[0] = %d\n",*zippo[0]);
    printf(" **zippo = %d\n",**zippo);
    printf(" zippo[2][1] = %d\n",zippo[2][1]);
    printf(" *(*(zippo + 2)+1) = %d\n\n\n\n\n",*(*(zippo + 2)+1)); // 等价于zippo[2][1]

    /*      多维数组的指针声明方式     */
    int (*pz)[2]; // 指向多维数组指针的声明（这里pz指向了一包含两个int值的数组）
                  // pz必须是一个指向两个int数组的指针，具体还要根据多维数组的定义来确定
                  // 使用()的原因是表达式中的[]优先级高于*，因此不加括号的话就是两个指向int值的指针构成的数组，会创建两个指针
                  // 而使用()结果就是创建了一个指向包含两个int值的数组的指针
                  // 之所以这么做其实是有原因的，你试想一下一位数组和指针，我们试图使用*(pz+1)这样的方式实现对pz[1]的访问
                  // 同样对二维数组，我们希望用*(*(pz+2)+1)这样的方式实现pz[2][1]（也就是3）的访问
                  // 那么我们就希望创建一个指向两个int型数据的指针。
    pz = zippo;
    printf(" pz = %p, pz + 1 = %p\n",pz,pz+1);
    printf(" pz[0] = %p, pz[0] + 1 = %p\n",pz[0],pz[0]+1);
    printf(" *pz = %p, *pz + 1 = %p\n",*pz,*pz+1);
    printf(" pz[0][0] = %d\n", pz[0][0]);
    printf(" *pz[0] = %d\n",*pz[0]);
    printf(" **pz = %d\n",**pz);
    printf(" pz[2][1] = %d\n",pz[2][1]);
    printf(" *(*(pz + 2) + 1) = %d\n",*(*(pz + 2) + 1));
}

    /*      处理二维数组的函数（下面是三种声明方式）（首先应该有声明）       */
void sum_rows(int ar[][CLOS],int rows); // 列数是在函数体内定义的，但是行数是靠函数传递得到的
void sum_clos(int [][CLOS],int); // 可以省略名称，但是不能用类似int ar[][]的声明形式。因为代码需要知道，ar所指向对象的数据大小
int sum2d(int (*ar)[CLOS],int rows); // 这种初始化的形式其实从上一个代码里面就能看出端倪。
                                     // 这里使用int (*ar)[4],就是说ar被看做是指向包含4个int值得数组的指针（首先是一个指针）

void array2d(void)
{
    int junk[ROWS][CLOS] = {{2,4,6,8},{3,5,7,9},{12,10,8,6}};

    sum_rows(junk,ROWS);
    sum_clos(junk,ROWS);
    printf("Sum of all elements = %d\n",sum2d(junk,ROWS));
}
void sum_rows(int ar[][CLOS],int rows)
{
    int r;
    int c;
    int tot;

    for(r = 0;r < rows;r++)
    {
        tot = 0;
        for(c = 0;c < CLOS;c++)
            tot += ar[r][c];
        printf("row %d: sum = %d\n",r,tot);
    }
}
void sum_clos(int ar[][CLOS], int rows) // 同样对于三维数组，需要知道两个量
{
    int r;
    int c;
    int tot;

    for(c = 0;c < CLOS;c++)
    {
        tot = 0;
        for(r = 0;r < rows; r++)
            tot += ar[r][c];
        printf("col %d: sum  = %d\n",c,tot);
    }
}
int sum2d(int ar[][CLOS],int rows)
{
    int r;
    int c;
    int tot = 0;

    for(r = 0;r < rows;r++)
        for(c = 0;c < CLOS;c++)
        tot += ar[r][c];
    return tot;
}

    /* 变长数组————
     * C99引入，允许使用变量定义数组各维。例如int a = 4,b = 5; double example[a][b];这里example就是一个变长数组
     * 限制：必须是自动存储类，就是说它们必须在函数内部或作为函数参量声明，而且声明时不可以进行初始化
     * 并不是说它在创建后可以改变大小，而是说维数大小可以用变量来指定
     *
     *
     * 针对上一个函数来看，例如：int sum2d(int roes,int clos,int ar[rows][clos])就可以声明带有一个二维变长数组参数的函数
     */

    /*      函数声明        */
int sum2ds(int rows,int cols,int ar[rows][cols]); // 变长数组使用方式，针对上一个函数提出的疑问。
void vararr2d(void)
{
    int i,j;
    int rs = 3;
    int cs = 10;
    int junk[ROWS][CLOS] = {{2,4,6,8},{3,5,7,9},{12,10,8,6}};
    int morejunk[ROWS-1][CLOS+2] = {{20,30,40,50,60,70},{5,6,7,8,9,10}};
    int varr[rs][cs];

    for(i = 0;i < rs;i++)
        for(j = 0;j < cs;j++)
            varr[i][j] = i*j + j;
    printf("3x5 array\n");
    printf("Sum of all elements = %d\n",sum2ds(ROWS,CLOS,junk));
    printf("2x6 array\n");
    printf("Sum of all elements = %d\n",sum2ds(ROWS-1,CLOS+2,morejunk));
    printf("3x10 VLA\n");
    printf("Sum of all elements = %d\n",sum2ds(rs,cs,varr));
}
int sum2ds(int rows,int cols,int ar[rows][cols]) // 带有一个VLA参数的函数
{
    int r;
    int c;
    int tot = 0;

    for(r = 0;r < rows;r++)
        for(c = 0;c < cols;c++)
        tot += ar[r][c];
    return tot;
}
