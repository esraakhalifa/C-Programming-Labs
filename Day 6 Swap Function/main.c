#include <stdio.h>
#include <stdlib.h>
#include "D:\C Programming Course\Labs\String Functions\String.h"
#define SIZE 50
int isInt(char [],int);


int main()
{
    char x[SIZE];
    int validX = 0;
    char y[SIZE];
    int validY = 0;
    printf("Enter the first number: ");
    scanf("%s", x);
    int lengthX = strlen(x);
    validX = isInt(x, lengthX);
    while (!validX)
    {
        printf("You've entered a non-integer, try again with integers only.\n");
        printf("Enter the first number: ");
        scanf("%s", x);
        lengthX = strlen(x);
        validX = isInt(x, lengthX);
    }
    int digitX = strtoI(x);


    printf("Enter the second number: ");
    scanf("%s", y);
    int lengthY = strlen(y);
    validY = isInt(y, lengthY);
    while (!validY)
    {
        printf("You've entered a non-integer, try again with integers only.\n");
        printf("Enter the second number: ");
        scanf("%s", y);
        lengthY = strlen(y);
        validY = isInt(y, lengthY);

    }
    int digitY = strtoI(y);
    printf("\n");

    swap1(&digitX,&digitY);
    printf("After swap 1: %d and %d\n", digitX, digitY);
    swap2(&digitX,&digitY);
    printf("After swap 2: %d and %d\n", digitX, digitY);
    swap3(&digitX,&digitY);
    printf("After swap 2: %d and %d\n", digitX, digitY);
    swap4(&digitX,&digitY);
    printf("After swap 2: %d and %d\n", digitX, digitY);
    return 0;
}

void swap1(int* x, int* y)
{
    *x = *x - *y;
    *y = *y + *x;
    *x = *y - *x;
}
void swap2(int *x, int *y)
{
    if (*y == 0) {
        *y = *x;
        *x = 0;
    }
    else if (*x == 0) {
        *x = *y;
        *y = 0;
    }

        *x = (*x )* (*y);
        *y = *x / *y;
        *x = *x / *y;
}
void swap3(int *x, int *y)
{
    if (*y == 0) {
        *y = *x;
        *x = 0;
    }
    else if (*x == 0) {
        *x = *y;
        *y = 0;
    }

        *y = (*y )* (*x);
        *x = *y / *x;
        *y = *y / *x;
}
void swap4(int* x, int* y)
{
    *y = *y - *x;
    *x = *x + *y;
    *y = *x - *y;
}
int isInt(char arr[],int length)
{

    if (arr[0] == '-' && length == 1) return 0;
    for (int i = 0; arr[i] != '\0'; i++)
    {
        int intArr = (int)arr[i];
        if ( (intArr == 45 && i != 0) || (intArr < 48 || intArr > 57) )
        {
            return 0;

        }
    }
    return 1;

}

int strtoI(char arr[])
{
    int digitNum = 0;int sign = 1;
    if (arr[0] == '-') sign = -1;
    for (int i = (sign == -1 ? 1 : 0); arr[i] != '\0'; i++)
    {
        digitNum = digitNum * 10 + (arr[i] - 48);
    }
    digitNum *= sign;
    return digitNum;
}
