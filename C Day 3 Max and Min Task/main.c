#include <stdio.h>
#include <stdlib.h>
#define SIZE 100
void findMinimumMaximum(int arr[], int N)
{
    int i;

    int minElement = INT_MAX, maxElement = INT_MIN;


    for (i = 0; i < N; i++) {


        if (arr[i] < minElement) {
            minElement = arr[i];
        }

        if (arr[i] > maxElement) {
            maxElement = arr[i];
        }
    }

    printf("The minimum element is %d", minElement);
    printf("\n");
    printf("The maximum element is %d", maxElement);

    return;
}
int main()
{
    int arr[SIZE];
    int arraySize;
    printf("Enter the size of the array: ");
    scanf("%d", &arraySize);
    for (int i = 0; i < arraySize; i++)
    {
        int element;
        scanf("%d", &element);
        arr[i] = element;
    }
    findMinimumMaximum(arr, arraySize);
    return 0;
}
