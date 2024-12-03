#include <stdio.h>
#include <stdlib.h>
#define SIZE 9

void display(int arr[], int n)
{
    int row, col;

    // Get valid row input
    printf("Enter the number of rows: ");
    scanf("%d", &row);
    while (SIZE % row != 0) // Ensure row divides SIZE evenly
    {
        printf("Invalid row. It must divide %d evenly.\n", SIZE);
        printf("Enter the number of rows: ");
        scanf("%d", &row);
    }

    col = SIZE / row; // Calculate columns based on rows

    // Print the array in grid format
    for (int i = 0; i < row; i++) // Loop over rows
    {
        for (int j = 0; j < col; j++) // Loop over columns
        {
            int index = i * col + j; // Calculate index in 1D array
            printf("%d\t", arr[index]);
        }
        printf("\n");
    }
}

int main()
{
    int arr[SIZE];

    // Input array elements
    for (int i = 0; i < SIZE; i++)
    {
        printf("Enter element: " );
        scanf("%d", &arr[i]);
    }

    // Call display function
    display(arr, SIZE);

    return 0;
}/*
