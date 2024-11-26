#include <stdio.h>
#include <stdlib.h>
#define SIZE 100

int strlen(char[]);
int strcmp (char [], char[]);
void strcat(char [], char [], int );
int strtoI(char arr[]);
char * strcpy(char [], char [], int);
int main()
{
    char str[SIZE] = "Hello world!\n";
    char str2[SIZE] = "Hello world!\n";
    char str3[SIZE] = "YAWZA\n";
    printf("%d\n",strlen(str));
    printf("%d\n", strcmp(str, str2));
    printf("%d\n", strcmp(str, str3));
    printf("%d\n", strcmp(str2, str3));
    strcat(str2, str3, SIZE);
    printf("%s\n", str2);
    strcpy( str, str3, SIZE);
    printf("%s\n", str);
    return 0;
}
int strlen(char str[])
{
    int i = 1;
    while(str[i] != '\0')
    {
        i++;
    }
    return i;
}

int strcmp(char str1[], char str2[])
{


        for (int i = 0; str1[i] != '\n'; i++)
        {
            int curr_str1 = str1[i];
            int curr_str2 = str2[i];
            if (curr_str1 > curr_str2) return 1;
            else if (curr_str1 < curr_str2) return -1;

        }
    return 0;

    }

void strcat(char dest[], char source[], int Size)
{
    int dest_size = strlen(dest);
    int source_size = strlen(source);
    if (Size > dest_size + source_size)
    {
        int indx1 = 0;
        for (int indx2 = dest_size; indx1 < source_size; indx2++, indx1++)
        {
            dest[indx2] = source[indx1];
        }
        dest[dest_size + source_size] = '\0';
    }
    else
    {
        printf("Error: Not enough space in destination buffer.\n");
    }
}
char * strcpy(char dest[], char source[], int Size)
{
    int source_size = strlen(source);
    if (Size > source_size)
    {
        int indx = 0;
        for (; source[indx] != '\0'; indx++)
        {
            dest[indx] = source[indx];
        }
        dest[indx] = '\0';
        for (indx++; indx < Size; indx++)
        {
            dest[indx] = '\0';
        }
    }
    else
    {
        printf("Error: Not enough space in destination buffer.\n");
    }
    return dest;

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

