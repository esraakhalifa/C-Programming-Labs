#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x = 6;
    int y = 5;
    printf("%d and %d\n", x, y);
    swap(&x,&y);
    printf("%d and %d\n", x, y);
    return 0;
}

void swap(int* x, int* y)
{
    *x = *x - *y;
    *y = *y + *x;
    *x = *y - *x;
}
