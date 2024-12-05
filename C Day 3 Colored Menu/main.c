/*#ifdef _WIN32
#include <windows.h>    // for win32 API functions
#include <io.h>         // for _get_osfhandle()
#else
#ifndef _POSIX_SOURCE
#define _POSIX_SOURCE   // enable POSIX extensions in standard library headers
#endif
#include <unistd.h>     // for isatty()
#endif

#include <stdlib.h>
#include <stdio.h>
#define SIZE 100

// use an enum for platform-independent interface:
typedef enum TextColor
{
    TC_BLACK = 0,
    TC_BLUE = 1,
    TC_GREEN = 2,
    TC_CYAN = 3,
    TC_RED = 4,
    TC_MAGENTA = 5,
    TC_BROWN = 6,
    TC_LIGHTGRAY = 7,
    TC_DARKGRAY = 8,
    TC_LIGHTBLUE = 9,
    TC_LIGHTGREEN = 10,
    TC_LIGHTCYAN = 11,
    TC_LIGHTRED = 12,
    TC_LIGHTMAGENTA = 13,
    TC_YELLOW = 14,
    TC_WHITE = 15
} TextColor;

void gotoxy(int x, int y)
{
    COORD coord;
    coord.X= x ;
    coord.Y = y ;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

typedef struct Employee
{
    int ID;
    float Age;
    float salary;
    char Name[20];
};

// set output color on the given stream:
void setTextColor(FILE *stream, TextColor color);
int moveArrows(char, int, int);
int makeChoice(int, int);
void renderMenu(int, int);
void addEmployee(int*, Employee[]);
int main(void)
{
    Employee employees[SIZE];
    int mainFlag = 1, row = 4, col = 55, numOfEmployees = 0;
    renderMenu(row,col);
    while(mainFlag = 1)
    {
        char click = getch();
        if (click == -32)
        {

            click = getch();
            if (click == 72)
            {

                if (row == 4) row = 28;
                else row-=8;
            }
            else if (click == 80)
            {

                if (row == 28) row = 4;
                else row+=8;
            }
            renderMenu(row,col);
        }

        else if (click == 13 && row == 4)
        {
            addEmployee(&numOfEmployees, employees);
            system("cls");
            click = getch();
            int option = 1;
        if (click == -32) {
            click = getch();

            if (click == 75) {
                system("cls");
                setTextColor(stdout, TC_WHITE);
                gotoxy(40, 12);
                printf("Do you want to add another employee or exit?");
                gotoxy(60, 20);
                setTextColor(stdout, TC_WHITE);
                printf("New");
                gotoxy(40, 20);
                setTextColor(stdout, TC_BLUE);
                printf("Add another");
                option = 1;
            }
            else if (click == 77) {
                system("cls");
                setTextColor(stdout, TC_WHITE);
                gotoxy(40, 12);
                printf("Do you want to add another employee or exit?");
                gotoxy(40, 20);
                printf("Add another");
                gotoxy(60, 20);
                setTextColor(stdout, TC_BLUE);
                printf("Exit");
                option = 2;
            }
        } else {
            if (option == 1) {
                addEmployee(&numOfEmployees, employees);
            } else if (option == 2) {
                renderMenu(55, 4);
            }
        }
        }
        else if (click == 13 && row == 12)
        {
            for (int j = 0; j <= numOfEmployees; j++ )
            {
                printf("%d. %s, %2f years old, earns %.2f EGP.", employees[j].ID,
                        employees[j].Name, employees[j].Age, employees[j].salary);
            }
        }


    }




    return EXIT_SUCCESS;
}
void renderMenu(int row, int col)
{
    system("cls");
    Employee employees[SIZE];
    gotoxy(col, 1);
    printf("Line: 1");
    gotoxy(col, row);
    setTextColor(stdout, TC_BLUE);
    printf("New");
    setTextColor(stdout, TC_WHITE);
    row += 8;
    gotoxy(col,row);
    printf("Display");
    row += 8;
    gotoxy(col, row);
    printf("Modify");
    row += 8;
    gotoxy(col, row);
    printf("Exit");
    row = 4;
}
void addEmployee(int *numOfEmployees, Employee employees[])
{
        Employee e1;
        system("cls");
        setTextColor(stdout, TC_WHITE);
        gotoxy(50,4);
        printf("Enter employee id: ");
        scanf("%d", &e1.ID);
        gotoxy(50,12);
        printf("Enter employee name: ");
        scanf("%s", &e1.Name);
        gotoxy(50,20);
        printf("Enter employee age: ");
        scanf("%.2f", & e1.Age);
        gotoxy(50,28);
        printf("Enter employee salary: ");
        scanf("%.2f", & e1.salary);
        employees[*numOfEmployees] = e1;
        numOfEmployees++;
}
int makeChoice(int row, int col)
{
                system("cls");
                setTextColor(stdout, TC_WHITE);
                gotoxy(col, 4);
                if (row == 2)
                {
                    puts("New");
                }
                else if(row == 4)
                {
                    puts("Display");
                }
                else {
                        puts("Exit");
                }
                char click = getch();
                if (click == 27)
                {
                    //moveArrows(click, 2,6);
                    system("cls");
                    renderMenu(2,6);
                }

}


#ifdef _WIN32

void setTextColor(FILE *stream, TextColor color)
{
    int outfd = fileno(stream);
    HANDLE out = (HANDLE)_get_osfhandle(outfd);
    DWORD outType = GetFileType(out);
    DWORD mode;
    if (outType == FILE_TYPE_CHAR && GetConsoleMode(out, &mode))
    {
        // we're directly outputting to a win32 console if the file type
        // is FILE_TYPE_CHAR and GetConsoleMode() returns success

        SetConsoleTextAttribute(out, color);
        // the enum constants are defined to the same values
        // SetConsoleTextAttribute() uses, so just pass on.
    }
}

#else

static const char *ansiColorSequences[] =
{
    "\x1B[0;30m",
    "\x1B[0;34m",
    "\x1B[0;32m",
    "\x1B[0;36m",
    "\x1B[0;31m",
    "\x1B[0;35m",
    "\x1B[0;33m",
    "\x1B[0;37m",
    "\x1B[1;30m",
    "\x1B[1;34m",
    "\x1B[1;32m",
    "\x1B[1;36m",
    "\x1B[1;31m",
    "\x1B[1;35m",
    "\x1B[1;33m",
    "\x1B[1;37m"
};

static const char *ansiColorTerms[] =
{
    "xterm",
    "rxvt",
    "vt100",
    "linux",
    "screen",
    0
    // there are probably missing a few others
};

// get current terminal and check whether it's in our list of terminals
// supporting ANSI colors:
static int isAnsiColorTerm(void)
{
    char *term = getenv("TERM");
    for (const char **ansiTerm = &ansiColorTerms[0]; *ansiTerm; ++ansiTerm)
    {
        int match = 1;
        const char *t = term;
        const char *a = *ansiTerm;
        while (*a && *t)
        {
            if (*a++ != *t++)
            {
                match = 0;
                break;
            }
        }
        if (match) return 1;
    }
    return 0;
}

void setTextColor(FILE *stream, TextColor color)
{
    int outfd = fileno(stream);
    if (isatty(outfd) && isAnsiColorTerm())
    {
        // we're directly outputting to a terminal supporting ANSI colors,
        // so send the appropriate sequence:
        fputs(ansiColorSequences[color], stream);
    }
}

#endif
*/
/////////////////////////////////////////////////////////////////////////////////////////////////////////

#ifdef _WIN32
#include <windows.h>    // for win32 API functions
#include <io.h>         // for _get_osfhandle()
#else
#ifndef _POSIX_SOURCE
#define _POSIX_SOURCE   // enable POSIX extensions in standard library headers
#endif
#include <unistd.h>     // for isatty()
#endif

#include <stdlib.h>

#include <stdio.h>
#define SIZE 100

// use an enum for platform-independent interface:
typedef enum TextColor
{
    TC_BLACK = 0,
    TC_BLUE = 1,
    TC_GREEN = 2,
    TC_CYAN = 3,
    TC_RED = 4,
    TC_MAGENTA = 5,
    TC_BROWN = 6,
    TC_LIGHTGRAY = 7,
    TC_DARKGRAY = 8,
    TC_LIGHTBLUE = 9,
    TC_LIGHTGREEN = 10,
    TC_LIGHTCYAN = 11,
    TC_LIGHTRED = 12,
    TC_LIGHTMAGENTA = 13,
    TC_YELLOW = 14,
    TC_WHITE = 15
} TextColor;

typedef struct Employee
{
    char ID[5];
    char Age[10];
    char salary[10];
    char Name[20];
}Employee;

void gotoxy(int x, int y)
{
    COORD coord;
    coord.X= x ;
    coord.Y = y ;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
int isInt(char arr[],int length)
{

    if (arr[0] == '-' && length == 1) return 0;
    for (int i = 0; arr[i] != '\0'; i++)
    {
        int intArr = (int)arr[i];
        if ( (intArr == 45 && i != 0) || (intArr < 48 || intArr > 57) )
        {
            return 0;

        }
    }
    return 1;

}
int myStrlen(char str[])
{
    int i = 1;
    while(str[i] != '\0')
    {
        i++;
    }
    return i;
}
int isValidName(char arr[])
{
    if (myStrlen(arr) == 0)
    {
        return 0;
    }

    for (int i = 0; arr[i] != '\0'; i++)
    {
        int intArr = (int)arr[i];


        if (!(intArr == 32 || (intArr >= 65 && intArr <= 90) || (intArr >= 97 && intArr <= 122)))
        {
            return 0;
        }
    }

    return 1;
}


//converting string input to integer ==>

int strtoI(char arr[])
{
    int digitNum = 0;int sign = 1;
    if (arr[0] == '-') sign = -1;
    for (int i = (sign == -1 ? 1 : 0); arr[i] != '\0'; i++)
    {
        digitNum = digitNum * 10 + (arr[i] - 48);
    }
    digitNum *= sign;
    return digitNum;
}
void clearInputBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {

    }
}
// set output color on the given stream:
int moveArrows(char , int , int );
void renderMenu(int , int );

int main(void)
{
    int flag = 1, row = 4, col = 55,numOfEmployees = 0;
    renderMenu(4,55);
    Employee employees[SIZE];
while (1) {
    char click = getch();
    if (click == -32) {
        click = getch();
        row = moveArrows(click, row, col);
    }

    if (row == 4 && click == 13) {
        system("cls");
        char addEmployeeFlag = 'y';


        while (addEmployeeFlag == 'y' && numOfEmployees < SIZE) {
            system("cls");
            setTextColor(stdout, TC_WHITE);

            printf("Enter ID: ");
            scanf("%[^\n]", &employees[numOfEmployees].ID);
            while (isInt(&employees[numOfEmployees].ID, myStrlen(&employees[numOfEmployees].ID)) == 0)
            {
                printf("Invalid ID.\n");
                printf("Enter new ID: ");
                scanf("%[^\n]", &employees[numOfEmployees].ID);
                clearInputBuffer();
            }

            printf("Enter Name: ");
            scanf("%[^\n]", employees[numOfEmployees].Name);
            while (isValidName(&employees[numOfEmployees].Name) == 0)
            {
                printf("Invalid name.\n");
                printf("Enter new name: ");
                scanf("%[^\n]", &employees[numOfEmployees].Name);
                clearInputBuffer();
            }

            printf("Enter Age: ");
            scanf("%[^\n]", &employees[numOfEmployees].Age);
            clearInputBuffer();

            while (isInt(&employees[numOfEmployees].Age, myStrlen(&employees[numOfEmployees].Age)) == 0)
            {
                printf("Invalid age.\n");
                printf("Enter new age: ");
                scanf("%[^\n]", &employees[numOfEmployees].Age);
                clearInputBuffer();
            }

            printf("Enter Salary: ");
            scanf("%[^\n]", &employees[numOfEmployees].salary);
            clearInputBuffer();
            while (isInt(&employees[numOfEmployees].salary, myStrlen(&employees[numOfEmployees].salary)) == 0)
            {
                printf("Invalid salary.\n");
                printf("Enter new salary: ");
                scanf("%[^\n]", &employees[numOfEmployees].salary);
                clearInputBuffer();
            }

            numOfEmployees++;

            printf("Do you want to add another employee? [y/n]: ");
            getchar();
            scanf("%c", &addEmployeeFlag);
        }
        renderMenu(4, 55);
    }
    else if (row == 20 && click == 13)
    {
        system("cls");
        setTextColor(stdout, TC_WHITE);
        char modifyEmployeeFlag = 'y';
        while (modifyEmployeeFlag == 'y') {
        int id;
        int found = 0;

        printf("\nEnter ID of the employee to modify: ");
        scanf("%d", &id);


        for (int j = 0; j < numOfEmployees; j++) {
            if (employees[j].ID == id) {
                found = 1;

                printf("Do you want to modify the name, age, or salary? ");
                char modification[10];
                scanf("%s", modification);

                if (strcmp(modification, "name") == 0 || strcmp(modification, "Name") == 0) {
                    printf("Enter new Name: ");
                    scanf("%[^\n]", employees[j].Name);
                    while (isValidName(&employees[numOfEmployees].Name) == 0)
                    {
                        printf("Invalid name.\n");
                        printf("Enter new name: ");
                        scanf("%[^\n]", &employees[numOfEmployees].Name);
                        clearInputBuffer();
                    }
                } else if (strcmp(modification, "age") == 0 || strcmp(modification, "Age") == 0) {
                    printf("Enter new Age: ");
                    scanf("%[^\n]", &employees[j].Age);
                    while (isInt(&employees[numOfEmployees].Age, myStrlen(&employees[numOfEmployees].Age)) == 0)
                    {
                        printf("Invalid age.\n");
                        printf("Enter new age: ");
                        scanf("%[^\n]", &employees[numOfEmployees].Age);
                        clearInputBuffer();
                    }

                } else if (strcmp(modification, "salary") == 0 || strcmp(modification, "Salary") == 0) {
                    printf("Enter new Salary: ");
                    scanf("%[^\n]", &employees[j].salary);
                    while (isInt(&employees[numOfEmployees].salary, myStrlen(&employees[numOfEmployees].salary)) == 0)
                    {
                        printf("Invalid salary.\n");
                        printf("Enter new salary: ");
                        scanf("%[^\n]", &employees[numOfEmployees].salary);
                        clearInputBuffer();
                    }
                } else {
                    printf("Invalid field to modify.\n");
                }
            }
        }



        if (!found) {
            printf("Employee with ID %d not found.\n", id);
        }

        printf("\nDo you want to modify the data of another employee? [y/n]: ");
        getchar();
        scanf("%c", &modifyEmployeeFlag);
    }
    renderMenu(4, 55);
    }
    else if (row == 12 && click == 13)
    {
        char displayEmployeesFlag = 'n';
        system("cls");
        setTextColor(stdout, TC_WHITE);
        if (numOfEmployees == 0) printf("No employees added.\n");
        else
        {
            for (int i = 0; i < numOfEmployees; i++)
            {

                printf("%s. %s, %s years old, earns %s\n",employees[i].ID,
                        employees[i].Name, employees[i].Age, employees[i].salary);
            }

        }
        printf("Want to go back to the main menu?");
        getchar();
        scanf("%c", &displayEmployeesFlag);
        if (displayEmployeesFlag == 'y')renderMenu(4, 55);



    }
}
return EXIT_SUCCESS;


}



void renderMenu(int row, int col)
{
    system("cls");
    Employee employees[SIZE];
    setTextColor(stdout, TC_WHITE);
    gotoxy(col, 0);
    printf("Line: 1");
    gotoxy(col, row);
    setTextColor(stdout, TC_BLUE);
    printf("New");
    setTextColor(stdout, TC_WHITE);
    row += 8;
    gotoxy(col,row);
    printf("Display");
    row += 8;
    gotoxy(col, row);
    printf("Modify");
    row += 8;
    gotoxy(col, row);
    printf("Exit");
    row = 4;
    gotoxy(col, row);
}
int moveArrows(char click, int row, int col)
{
            if (click == 72) // up
            {
                if(row == 4) row =28;
                else row -=8;

            }
            else if ( click == 80) // down
            {
                if(row == 28) row =4;
                else row += 8;
            }
            setTextColor(stdout, TC_WHITE);
            if (row == 4){


                gotoxy(col, 0);
                puts("Line: 1");
                gotoxy(col,12);
                puts("Display");
                gotoxy(col,20);
                puts("Modify");
                gotoxy(col, 28);
                puts("Exit");
                gotoxy(col,row);
                setTextColor(stdout, TC_BLUE);
                puts("New");
            }
            else if ( row == 12){


                gotoxy(col, 0);
                puts("Line: 2");
                gotoxy(col,4 );
                puts("New");
                gotoxy(col,20);
                puts("Modify");
                gotoxy(col, 28);
                puts("Exit");
                gotoxy(col,row);
                setTextColor(stdout, TC_BLUE);
                puts("Display");
            }
            else if (row == 20){


                    gotoxy(col, 0);
                    puts("Line: 3");
                    gotoxy(col, 4);
                    puts("New");
                    gotoxy(col, 12);
                    puts("Display");
                    gotoxy(col, 28);
                    puts("Exit");
                    gotoxy(col,row);
                    setTextColor(stdout, TC_BLUE);
                    puts("Modify");

                }
            else {

                    setTextColor(stdout, TC_WHITE);
                    gotoxy(col, 0);
                    puts("Line: 4");
                    gotoxy(col, 4);
                    puts("New");
                    gotoxy(col, 12);
                    puts("Display");
                    gotoxy(col, 20);
                    puts("Modify");
                    gotoxy(col,row);
                    setTextColor(stdout, TC_BLUE);
                    puts("Exit");

                }
                return row;
}







#ifdef _WIN32

void setTextColor(FILE *stream, TextColor color)
{
    int outfd = fileno(stream);
    HANDLE out = (HANDLE)_get_osfhandle(outfd);
    DWORD outType = GetFileType(out);
    DWORD mode;
    if (outType == FILE_TYPE_CHAR && GetConsoleMode(out, &mode))
    {
        // we're directly outputting to a win32 console if the file type
        // is FILE_TYPE_CHAR and GetConsoleMode() returns success

        SetConsoleTextAttribute(out, color);
        // the enum constants are defined to the same values
        // SetConsoleTextAttribute() uses, so just pass on.
    }
}

#else

static const char *ansiColorSequences[] =
{
    "\x1B[0;30m",
    "\x1B[0;34m",
    "\x1B[0;32m",
    "\x1B[0;36m",
    "\x1B[0;31m",
    "\x1B[0;35m",
    "\x1B[0;33m",
    "\x1B[0;37m",
    "\x1B[1;30m",
    "\x1B[1;34m",
    "\x1B[1;32m",
    "\x1B[1;36m",
    "\x1B[1;31m",
    "\x1B[1;35m",
    "\x1B[1;33m",
    "\x1B[1;37m"
};

static const char *ansiColorTerms[] =
{
    "xterm",
    "rxvt",
    "vt100",
    "linux",
    "screen",
    0
    // there are probably missing a few others
};

// get current terminal and check whether it's in our list of terminals
// supporting ANSI colors:
static int isAnsiColorTerm(void)
{
    char *term = getenv("TERM");
    for (const char **ansiTerm = &ansiColorTerms[0]; *ansiTerm; ++ansiTerm)
    {
        int match = 1;
        const char *t = term;
        const char *a = *ansiTerm;
        while (*a && *t)
        {
            if (*a++ != *t++)
            {
                match = 0;
                break;
            }
        }
        if (match) return 1;
    }
    return 0;
}

void setTextColor(FILE *stream, TextColor color)
{
    int outfd = fileno(stream);
    if (isatty(outfd) && isAnsiColorTerm())
    {
        // we're directly outputting to a terminal supporting ANSI colors,
        // so send the appropriate sequence:
        fputs(ansiColorSequences[color], stream);
    }
}

#endif






