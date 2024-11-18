#include <stdio.h>
#include <stdlib.h>

int main()
{
    for (int i = 10; i >= 1; i--)
    {
        for (int j = 10; j >= 1; j--)
        {
            printf("%d * %d = %d\n", i, j, i*j);
        }
        printf("\n");
        printf("************************************\n");
    }
}
