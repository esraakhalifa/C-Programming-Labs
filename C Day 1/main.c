#include <stdio.h>
#include <stdlib.h>


int main()
{
    int age;
    char initial;
    float pocketmoney;
    char name[25];
    printf("Enter your age: \n");
    scanf("%d", &age);
    printf("Enter your initial: \n");
    scanf(" %c", &initial);
    printf("Enter your name: \n");
    scanf("%s", &name);
    printf("Enter your pocket money: \n");
    scanf("%f", &pocketmoney);
    printf("Your name: %s\n", name);
    printf("Your age: %d\n", age);
    printf("Your age in hexadecimal: %x\n", age);
    printf("Your age in octal: %o\n", age);
    printf("Your initial in ASCII: %d\n", initial);
    printf("Your pocket money: %.3f", pocketmoney);
    return 0;
}
