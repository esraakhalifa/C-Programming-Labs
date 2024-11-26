#include <stdio.h>
#include <windows.h>
#include <conio.h>

#define SIZE 100

void gotoxy(int x, int y) {
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void setInsertModeCursor() {
    printf("\033[4 q");
}

void setNormalCursor() {
    printf("\033[2 q");
}

void clearScreen(char arr[], int length) {
    system("cls");
    for (int indx = 0; indx < length; indx++) {
        gotoxy(indx, 0);
        printf("%c", arr[indx]);
    }
}

int main() {
    char arr[SIZE] = {0};
    int current = 0;
    int i = 0;
    int inserModeFlag = 0;

    while (1) {
        if (i == SIZE - 1)
        {
            gotoxy(0,1);
            printf("Cannot enter more than 100 characters. Must click left and delete at least one character to work again.");
            gotoxy(SIZE - 1, 0);
        }
        char click = getch();

        if (click >= 32 && click <= 126) {
            if (inserModeFlag && current < SIZE - 1) {
                arr[current] = click;
            } else if (i < SIZE - 1) {
                for (int j = i; j > current; j--) {
                    arr[j] = arr[j - 1];
                }
                arr[current] = click;
                i++;
            }
            current++;
            clearScreen(arr, i);
            gotoxy(current, 0);

        } else if (click == 8) {
            if (current > 0) {
                for (int j = current - 1; j < i - 1; j++) {
                    arr[j] = arr[j + 1];
                }
                arr[i - 1] = '\0';
                i--;
                current--;
                clearScreen(arr, i);
                gotoxy(current, 0);
            }

        } else if (click == -32) {
            click = getch();

            if (click == 75) {
                if (current > 0) {
                    current--;
                    gotoxy(current, 0);
                }
            } else if (click == 77) {
                if (current < i) {
                    current++;
                    gotoxy(current, 0);
                }
            } else if (click == 83) {
                if (current < i) {
                    for (int j = current; j < i - 1; j++) {
                        arr[j] = arr[j + 1];
                    }
                    arr[i - 1] = '\0';
                    i--;
                    clearScreen(arr, i);
                    gotoxy(current, 0);
                }
            } else if (click == 71) {
                current = 0;
                gotoxy(current, 0);
            } else if (click == 79) {
                current = i;
                gotoxy(current, 0);
            } else if (click == 82) {
                inserModeFlag = !inserModeFlag;
                if (inserModeFlag) {
                    setInsertModeCursor();
                } else {
                    setNormalCursor();
                }
            }
        }

    }

    return 0;
}
