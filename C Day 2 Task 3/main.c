#include <stdio.h>
#include <stdlib.h>

int main()
{
    char x;
    printf("Enter one of the 3 letters: M, E, I\n");
    scanf("%c", &x);
    switch(x)
    {
    case'M':
        printf("Monalisa\n");
        break;
    case 'E':
        printf("Esraa\n");
        break;
    case'I':
        printf("ISO\n");
    default:
        printf("Invalid Input");
    }
}
