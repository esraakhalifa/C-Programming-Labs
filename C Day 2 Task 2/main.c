#include <stdio.h>
#include <stdlib.h>

int main()
{
    int sum = 0;
    do{
        int x;
        scanf("%d", &x);
        sum += x;
    }while( sum <= 100 );
    return 0;
}
