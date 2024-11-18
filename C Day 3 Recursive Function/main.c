#include <stdio.h>
#include <stdlib.h>

int pow(int, int);

int main()
{
    int x, y, result;
    printf("Enter the number: ");
    scanf("%d", &x);
    printf("Enter the power: ");
    scanf("%d", &y);
    result = pow(x, y);
    printf("Result: %d", result);

}

int pow(int x, int y)
{
    if (y == 1) return x;
    else return x * pow(x, y - 1);
}
