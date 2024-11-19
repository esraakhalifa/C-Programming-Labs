#include <stdio.h>
#include <stdlib.h>
#define ROW 3
#define COL 4

int main()
{
    int matrix[ROW][COL];
    for (int i = 0; i < ROW; i++)
    {
        for (int j = 0; j < COL; j++)
        {
            printf("Enter value: ");
            while (scanf("%d", &matrix[i][j]) == 0)
            {
                fflush(stdin);
                printf("Invalid input. Try again.\n");
                printf("Enter value: ");
            }
        }
    }

    for (int i = 0; i < ROW; i++)
    {
        int sum = 0;
        for (int j = 0; j < COL; j++)
        {
            sum += matrix[i][j];
        }
        printf("Sum of row %d is %d\n", i + 1, sum);
    }

    for (int j = 0; j < COL; j++)
    {
        int sum = 0;
        for (int i = 0; i < ROW; i++)
        {
            sum += matrix[i][j];
        }

        double average = (double)sum / ROW;
        printf("Average of column %d is %.3f\n", j + 1, average);
    }
    return 0;
}
