#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void count1(int argc,char *argv[])
{
    int ch;
    FILE *fp;
    long count = 0;

    if(argc != 2)
    {
        printf("Usage: %s filename\n",argv[0]);
        exit(1);
    }
    if((fp = fopen(argv[1],"r")) == NULL)
    {
        printf("Can't open %s\n",argv[1]);
        exit(1);
    }
    while((ch = getc(fp)) != EOF)
    {
        putc(ch,stdout);
        count++;
    }
    fclose(fp);
    printf("File %s has %ld characters\n",argv[1],count);
}

    /*      一个简单的文件压缩程序     */
void reducto(int argc,char *argv[]) // 将文件压缩为原来的三分之一
{
    FILE *in,*out; // 声明两个FILE指针
    int ch;
    char name[LEN]; //用于存储输入的文件名称
    int count = 0;

    if(argc < 2)
    {
        fprintf(stderr,"Usage: %s filename\n",argv[0]);
        exit(1);
    }

    if((in = fopen(argv[1],"r")) == NULL)
    {
        fprintf(stderr,"I couldn't open the file \"%s\"\n",argv[1]);
        exit(2);
    }

    strcpy(name,argv[1]);
    strcat(name,".red");
    if((out = fopen(name,"w")) == NULL)
    {
        fprintf(stderr,"Can't create output file.\n");
        exit(3);
    }

    while((ch = getc(in)) != EOF)
        if(count++ %3 == 0)
        putc(ch,out);

    if(fclose(in) != 0 || fclose(out) != 0)
        fprintf(stderr,"Error in closing files\n");
}
