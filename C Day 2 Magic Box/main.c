#include <stdio.h>
#include <stdlib.h>
#include "conio.h"
#include <windows.h>
void gotoxy(int x, int y)
{
    COORD coord;
    coord.X= x ;
    coord.Y = y ;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

int main()
{
    int SIZE;
    printf("Enter the size of the magic box: ");
    scanf("%d", &SIZE);
    int row = 1, col = (SIZE+1)/2;
    for (int i = 1; i <= SIZE*SIZE; i++ )
    {
        gotoxy(col * 4, row * 3);
        sleep(3);
        printf("%d", i);
        if (i%SIZE == 0){
            row++;
            if (row > SIZE)row = 1;
        }
        else{
            row--; col--;
            if (row<1)row=SIZE;
            if (col<1)col = SIZE;
        }
    }
}
