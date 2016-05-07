#include <stdio.h>
#include <string.h>
#include "main.h"
/*      Ç°µ¼³ÌÐò        */
void talkback()
{
    float weight,age;
    int siz,letters;
    char name[40];

    printf("What is your first name?\n");
    scanf("%s",name);
    printf("%s,What is your weight in pounds?\n",name);
    scanf("%f",&weight);
    siz = sizeof name;
    letters = strlen(name);
    age = weight/DENSITY;
    printf("Well,%s,your age is %2.2f cubic feet.\n",name,age);
    printf("Also,your first name has %d letters,\n",letters);
    printf("and we have %d bytes to store it in.\n",siz);
}
