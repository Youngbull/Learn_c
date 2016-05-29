#include <stdio.h>
#include "capture11.h"

    /* 使用字符串与用户交互
     * 包含字符串的建立、读入和输出的几种方式
     * gets(),puts()函数的使用
     *
     * 注：刚才遇到了一个error，显示在void string(void)之后和‘{’之前又不允许出现的符号之类的，在capture11.c中并没有问题
     * 经查，实在capture11.h中没有加入分号的原因
     */
void strings(void)
{
    char name[LINELEN];
    char talents[LINELEN];
    int i;
    const char m1[40] = "Limit yourself to one line's worth. "; // 初始化一个大小已确定的char数组
    const char m2[] = "If you can't think of anything,fake it. "; // 让编译器计算char数组的大小
    const char *m3 = "\nEnough about me - what's your name? "; // 初始化一个指向常量的指针
    const char *mytal[LIM] = {"Adding numbers swiftly." ,"Multiplying accurately." ,"Stashing data.",
     "Follwing instructions to the letter","Understanding the C language"}; // 初始化一个字符串指针的数组
                                                                            // 此处如果忘记使用’,‘作为不同字符串的分隔，那么会被当成一个字符串

    printf("Hi,I'm Clyde the computer. I have many talents.\n");
    printf("Let me tell you some of them.\n");

    puts("What were they? Ag,yes,here's a partial list: ");
    for(i = 0;i < LIM;i++)
        puts(mytal[i]); // 打印计算机功能的列表
    puts(m3);
    gets(name); // 以什么为结束？
    printf("Well,%s,%s\n",name,MSG);
    printf("%s\n%s\n",m1,m2);
    gets(talents);
    puts("Let's see if I've got that list: ");
    puts(talents);
    printf("Thanks for the information. %s\n",name);
}

    /* 很小一个程序，但是很有用，阐述了一个道理————
     * 字符串常量属于静态存储类（整个引号内的内容作为指向该字符串存储位置的指针）
     * 下面函数中%p产生一个地址，故而如果"are"是个地址，那么%p应该输出字符串中第一个字符的地址
     * 而*"space farers"应该产生所指向地址的值，也就是第一个字符的值就是's'
     * 运行结果也证明了上面的观点
     */
void quote()
{
    printf("%s,%p,%c\n","We","are",*"sapce farers");
}

    /*      读取字符串函数练习（包括gets(),scanf(),gfets()）     */
    /*
     * 首先：gets()函数————
     * 从系统的标准输入设备（通常键盘）获得一个字符串。
     * gets()函数通过换行符(\n)来确定输入结束与否。按下换行符，会读取换行符前所有的输入字符;
     * 由于是字符串读入，最后会在输入后面加上一个'\0'字符（空字符）;
     * 结束时它会读取换行符并且丢弃，防止对下一次操作产生影响.
     */
void gets1()
{
    char name[MAX];
    printf("Hi, what's your name?\n");
    gets(name); // name此处是一个地址,gets()函数通过地址给name写入字符串
    printf("Nice name, %s.\n",name);
}
void gets2()
{
    char name[MAX];
    char *ptr;

    printf("Hi, what's your name?\n");
    ptr = gets(name); // 从这句话可以看出，gets()函数具有输出
                      // 它的输出是通过return语句返回的地址，因此这句话把返回地址赋给了一个指针（但输入字符串只有一个备份）
    printf("%s? Ah! %s!\n",name,ptr); // 这里请注意，printf函数中已经有了标识符'%s'，因此注意ptr形式千万不要写*ptr这样，会跳到不知道那里
}

    /*      fgets()函数       */
    /*
     * get()函数一个不足是它不检查预留存储区是否能够容纳实际输入的数据，多出的字符简单的溢出到相邻的内存区
     * fgets()和gets()三方面不同：
     * 需要第二个参数来说明最大读入字符数，就是说有数值n，读取n-1次或者换行符结束;
     * fgets()读取到换行符，会存储到字符串里，gets()可丢弃它;
     * 它需要第三个参数来说明读哪一个文件。从键盘读数据时，可使用stdin作为这个参数
     */
void fgets1()
{
    char name[MAX];
    char *ptr;

    printf("Hi, what's your name?\n");
    ptr = fgets(name,MAX,stdin); // stdin表示标准输入，通常是键盘
    printf("%s? Ah! %s!\n",name,ptr); // 这里通过fgets读取数据
}

    /*      scanf()函数
     * 可以使用%s格式的scanf()函数来读入一个字符串（输入）
     * 与gets()主要差别是如何决定字符串输入结束（gets()函数会读取所有字符，直到遇到第一个换行符）
     *
     * scanf()就是遇到第一个非空白字符开始，若使用%s格式，读到下一个空白字符（比如空格、制表符和换行符）
     * 如果指定了字符的宽度，例如%10是，scanf就会读到10个字符或直到遇到第一个空白字符，看先遇到哪种情况。
     */
void scan_str()
{
    char name1[11],name2[11];
    int countdat;

    printf("Please enter 2 names.\n");
    countdat = scanf("%5s %10s",name1,name2); //
    printf("I read the %d names %s and %s.\n",countdat,name1,name2);
}


    /*      字符串输出，包括puts()、 fputs()、 printf()       */
    /*
     * puts()函数，其使用方式非常简单，只需要给出字符串参数的地址
     * printf()不同，puts()显示字符串时自动在后面添加一个换行符
     * 有一点要明白，字符数组字符串名字也被看作是地址
     * 和puts一样，printf需要一个字符串地址作为参数
     */
void put_out()
{
    char str1[80] = "An array was initialized to me.";
    const char *str2 = "A pointer was initialized to me.";

    puts("I'm an argument to puts().");
    puts(DEF);
    puts(str1);
    puts(str2);
    puts(&str1[5]); // 这里会从ray开始，因为会从指定地址
    puts(str2 + 4); // 总inter开始
}
void nono() // 一个一定不要使用的函数
{
    char side_a[] = "SIDE A";
    char dont[] = {'W','O','W','!'}; // dont缺少一个结束的空字符，因此不是字符串，因此它只能一直输出dont后面的字符，直到遇到一个空字符
                                     // 这个地方就把dont放到了两个字符串之间，避免走远了
    char side_b[] = "SIDE B";
    puts(dont); // dont不是一个字符串
}
    /*      fputs函数（puts函数的面向文件版本）————
     * 和fgets函数很相似，需要第二个参数说明要写的文件。可用stdout作为参数来进行输出显示，stdout在stdio.h中定义
     * 与puts不同，fputs并不为输出自动添加换行符
     */
void fputs1()
{
    char line[81];
//    while(gets(line)) // gets遇到文件结尾，gets就返回空指针，空指针的值为0，就会结束while循环
//        puts(line); // line数组中的字符串被显示在单独的一行上，puts为其添加了一个换行符
    while(fgets(line,81,stdin))
        fputs(line,stdout); // 数组字符串也被显示在单独的一行上，由于fgets存储了一个换行符
                            // 如果把fgets输入和puts输出结合使用，每个字符串后就会显示两个换行符（但本身就不是这两个结合用的）
}
    /*      自定义字符串输入/输出函数（对put1和put2的综合使用请参考296页）       */
void put1(const char *input) // 不会改变字符串
{
    while(*input != '\0') // 不添加换行符
        putchar(*input++);
}
void put2(const char *input)
{
    int coun = 0;
    while(*input)
    {
        putchar(*input++);
        coun++;
    }
    putchar('\n');
    printf("The count of the string is %d.\n",coun);
}
