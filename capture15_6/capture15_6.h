#ifndef CAPTURE15_6_H_INCLUDED
#define CAPTURE15_6_H_INCLUDED

#define FMT "X is %d.\n"
#define PX printf(FMT,SIX) //宏定义中可包含其他的宏
#define PX1 printf("FMT",SIX) //宏定义中可包含其他的宏
#define SIX 3
//#define SIX 4 //会提出警告，但是允许新定义取代旧定义
#define SQUARE(X) (X)*(X)
#define PR(X) printf("The result is %d.\n",X)
#define PSQR(x) printf("The square of " #x " is %d.\n",((x)*(x)))
#define XNAME(n) x ## n
#define PRINT_XN(n) printf("x" #n " = %d\n",x ## n)

#define PRC(X,...) printf("Message " #X ": " __VA_ARGS__) // 实现思想是宏定义中参数列表的最后一个参数为省略号，
                                                          // 预定义宏__VA_ARGS__就可以用于替换部分，以表明省略号代表的
void invert4(void);
void mac_arg(void);
void subst(void);
void glue(void);
void variadic(void);
void byebye(void);

#endif // CAPTURE15_6_H_INCLUDED
