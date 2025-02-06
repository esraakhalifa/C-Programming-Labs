

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

int moveArrows(char , int , int );
void renderMenu(int , int, int );

int main(void)
{
    int flag = 1, row = 4, col = 55,numOfEmployees = 0;

    renderMenu(4,55, 4);
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
        int addFound = 0;
        while (addEmployeeFlag == 'y' && numOfEmployees < SIZE) {
            system("cls");
            setTextColor(stdout, TC_MAGENTA);

            printf("Enter ID: ");
            scanf(" %99[^\n]", employees[numOfEmployees].ID);
            clearInputBuffer();
            for (int j = 0; j < numOfEmployees; j++) {
                    if (strcmp(employees[j].ID, employees[numOfEmployees].ID) == 0) addFound =1;
            }

            while (isInt(employees[numOfEmployees].ID, myStrlen(employees[numOfEmployees].ID)) == 0|| addFound == 1)
            {

                printf("Invalid ID. ID must be a unique integer only.\n");
                printf("Enter new ID: ");
                scanf(" %99[^\n]", employees[numOfEmployees].ID);
                clearInputBuffer();
                addFound = 0;
                for (int j = 0; j < numOfEmployees; j++) {
                    if (strcmp(employees[j].ID, employees[numOfEmployees].ID) == 0) addFound =1;
                }
            }


            printf("Enter Name: ");
            scanf(" %99[^\n]", employees[numOfEmployees].Name);
            clearInputBuffer();
            while (isValidName(employees[numOfEmployees].Name) == 0 || myStrlen(employees[numOfEmployees].Name) == 0)
            {
                printf("Invalid name.\n");
                printf("Enter new name: ");
                scanf(" %99[^\n]", employees[numOfEmployees].Name);
                clearInputBuffer();
            }

            printf("Enter Age: ");
            scanf(" %99[^\n]", employees[numOfEmployees].Age);
            clearInputBuffer();
            while (isInt(employees[numOfEmployees].Age, myStrlen(employees[numOfEmployees].Age)) == 0)
            {
                printf("Invalid age.\n");
                printf("Enter new age: ");
                scanf(" %99[^\n]", employees[numOfEmployees].Age);
                clearInputBuffer();
            }

            printf("Enter Salary: ");
            scanf(" %99[^\n]", &employees[numOfEmployees].salary);
            clearInputBuffer();
            while (isInt(employees[numOfEmployees].salary, myStrlen(employees[numOfEmployees].salary)) == 0)
            {
                printf("Invalid salary.\n");
                printf("Enter new salary: ");
                scanf(" %99[^\n]", employees[numOfEmployees].salary);
                clearInputBuffer();
            }

            numOfEmployees++;
            addFound = 0;

            printf("Do you want to add another employee? [y/n]: ");
            getchar();
            scanf("%c", &addEmployeeFlag);
        }
        renderMenu(4, 55, 4);
    }
        else if (row == 12 && click == 13) {
            system("cls");
            setTextColor(stdout, TC_MAGENTA);
            char modifyEmployeeFlag = 'y';
            while (modifyEmployeeFlag == 'y') {
                char id[100];
                int found = 0;
                int employeeNumber;
                if (numOfEmployees == 0) {
                    char choice;
                    printf("There are no employees to modify.\n");
                    printf("Do you want to go back to the main menu or exit? 1. Main menu  2. Exit\n");
                    getchar();
                    scanf("%c", &choice);
                    if (choice == '1') {
                        modifyEmployeeFlag = 'n';
                        renderMenu(4, 55, 12);
                        break;
                    } else if (choice == '2'){
                        exit(0);
                    }
                }


                printf("\nEnter ID of the employee to modify: ");
                scanf(" %99[^\n]", id);

                for (int j = 0; j < numOfEmployees; j++) {

                    if (strcmp(employees[j].ID, id) == 0) {
                        found = 1;
                        employeeNumber = j;
                        //printf("Employee with ID %s is found.\n", id);
                        break;
                    }
                }

                if (found) {
                    printf("Do you want to modify the name, age, or salary? ");
                    char modification[10];
                    scanf(" %99[^\n]", modification);

                    if (strcmp(modification, "name") == 0 || strcmp(modification, "Name") == 0) {
                        printf("Enter new Name: ");
                        scanf(" %99[^\n]", employees[employeeNumber].Name);
                        while (isValidName(employees[employeeNumber].Name) == 0) {
                            printf("Invalid name.\n");
                            printf("Enter new name: ");
                            scanf(" %99[^\n]", employees[employeeNumber].Name);
                            clearInputBuffer();
                        }
                    } else if (strcmp(modification, "age") == 0 || strcmp(modification, "Age") == 0) {
                        printf("Enter new Age: ");
                        scanf(" %99[^\n]", &employees[employeeNumber].Age);
                        while (isInt(employees[employeeNumber].Age, myStrlen(employees[employeeNumber].Age)) == 0) {
                            printf("Invalid age.\n");
                            printf("Enter new age: ");
                            scanf(" %99[^\n]", &employees[employeeNumber].Age);
                            clearInputBuffer();
                        }
                    } else if (strcmp(modification, "salary") == 0 || strcmp(modification, "Salary") == 0) {
                        printf("Enter new Salary: ");
                        scanf(" %99[^\n]", &employees[employeeNumber].salary);
                        while (isInt(employees[employeeNumber].salary,myStrlen(employees[employeeNumber].salary) ) == 0) {
                            printf("Invalid salary.\n");
                            printf("Enter new salary: ");
                            scanf(" %99[^\n]", &employees[employeeNumber].salary);
                            clearInputBuffer();
                        }
                    } else {
                        printf("Invalid field to modify.\n");
                    }
                } else {
                    printf("Employee with ID %s not found.\n", id);
                }


                printf("\nDo you want to modify the data of another employee? [y/n]: ");
                getchar();
                scanf("%c", &modifyEmployeeFlag);
            }
            renderMenu(4, 55, 20);
        }

    else if (row == 8 && click == 13)
    {
        char displayEmployeesFlag = 'n';
        system("cls");
        setTextColor(stdout, TC_CYAN);
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
        if (displayEmployeesFlag == 'y') renderMenu(4, 55, 8);



    }
   /* else if ( row == 16 && click == 13)
    {

        User should enter only delete by id, id should exist in employees array, id should be int,
        and then, should be deleted, by shifting the array, and then user is given the option to choose to return to the main menu or delete another employee



    }*/
    else if (row == 16 && click == 13) {
        system("cls");
        setTextColor(stdout, TC_MAGENTA);
        char deleteEmployeeFlag = 'y';

        while (deleteEmployeeFlag == 'y') {
            char id[100];
            int found = 0;
            int employeeNumber;

            printf("Enter ID of the employee to delete: ");
            scanf(" %99[^\n]", id);


            for (int j = 0; j < numOfEmployees; j++) {
                if (strcmp(employees[j].ID, id) == 0) {
                    found = 1;
                    employeeNumber = j;
                    printf("Employee with ID %s found. Proceeding to delete...\n", id);
                    break;
                }
            }


            if (found) {

                for (int i = employeeNumber; i < numOfEmployees - 1; i++) {
                    employees[i] = employees[i + 1];
                }


                memset(&employees[numOfEmployees - 1], 0, sizeof(Employee));
                numOfEmployees--;
                printf("Employee with ID %s has been deleted.\n", id);
            } else {
                printf("Employee with ID %s not found.\n", id);
            }


            printf("\nDo you want to delete another employee? [y/n]: ");
            getchar();
            scanf("%c", &deleteEmployeeFlag);
        }

        renderMenu(4, 55, 16);
    }

    else if ( row == 20 && click == 13)
    {
        system("cls");
        setTextColor(stdout, TC_LIGHTGREEN);
        gotoxy(40, 12);
        puts("THANK YOU FOR USING MY PROGRAM :D");
        exit(0);

    }
}
return EXIT_SUCCESS;


}



void renderMenu(int row, int col, int currentRow)
{
    system("cls");
    Employee employees[SIZE];

    setTextColor(stdout, TC_WHITE);
    gotoxy(35, 0);
    puts("WELCOME TO THE EMPLOYEE DATA MANAGEMENT SYSTEM!");

    const char *options[] = {"New Employee", "Display Employees", "Modify Employee","Delete Employee", "Exit Program"};
    int numOptions = sizeof(options) / sizeof(options[0]);

    for (int i = 0; i < numOptions; i++)
    {
        gotoxy(col, row);

        if (row == currentRow)
        {
            setTextColor(stdout, TC_BLUE);
        }
        else
        {
            setTextColor(stdout, TC_WHITE);
        }

        printf("%s", options[i]);
        row += 4;
    }

    setTextColor(stdout, TC_WHITE);
}

int moveArrows(char click, int row, int col)
{
            if (click == 72) // up
            {
                if(row == 4) row =20;
                else row -=4;

            }
            else if ( click == 80) // down
            {
                if(row == 20) row =4;
                else row += 4;
            }
            setTextColor(stdout, TC_WHITE);
            if (row == 4){
                /*
                new ==> row 4
                display ==> row 8
                modify ==> row 12
                delete ==> row 16
                exit ==> row 20
                */


                gotoxy(35, 0);
                puts("WELCOME TO THE EMPLOYEE DATA MANAGEMENT SYSTEM!");
                gotoxy(col,8);
                puts("Display Employees");
                gotoxy(col,12);
                puts("Modify Employee");
                gotoxy(col, 16);
                puts("Delete Employee");
                gotoxy(col, 20);
                puts("Exit Program");
                gotoxy(col,row);
                setTextColor(stdout, TC_BLUE);
                puts("New Employee");
            }
            else if ( row == 8){


                gotoxy(35, 0);
                puts("WELCOME TO THE EMPLOYEE DATA MANAGEMENT SYSTEM!");
                gotoxy(col,4 );
                puts("New Employee");
                gotoxy(col,12);
                puts("Modify Employee");
                gotoxy(col,16);
                puts("Delete Employee");
                gotoxy(col, 20);
                puts("Exit Program");
                gotoxy(col,row);
                setTextColor(stdout, TC_BLUE);
                puts("Display Employees");
            }
            else if (row == 12){


                    gotoxy(35, 0);
                    puts("WELCOME TO THE EMPLOYEE DATA MANAGEMENT SYSTEM!");
                    gotoxy(col, 4);
                    puts("New Employee");
                    gotoxy(col, 8);
                    puts("Display Employees");
                    gotoxy(col, 16);
                    puts("Delete Employee");
                    gotoxy(col, 20);
                    puts("Exit Program");
                    gotoxy(col,row);
                    setTextColor(stdout, TC_BLUE);
                    puts("Modify Employee");

                }
            else if (row == 16){


                    gotoxy(35, 0);
                    puts("WELCOME TO THE EMPLOYEE DATA MANAGEMENT SYSTEM!");
                    gotoxy(col, 4);
                    puts("New Employee");
                    gotoxy(col, 8);
                    puts("Display Employees");
                    gotoxy(col, 12);
                    puts("Modify Employee");
                    gotoxy(col, 20);
                    puts("Exit Program");
                    gotoxy(col,row);
                    setTextColor(stdout, TC_BLUE);
                    puts("Delete Employee");

                }
            else {

                    setTextColor(stdout, TC_WHITE);
                    gotoxy(35, 0);
                    puts("WELCOME TO THE EMPLOYEE DATA MANAGEMENT SYSTEM!");
                    gotoxy(col, 4);
                    puts("New Employee");
                    gotoxy(col, 8);
                    puts("Display Employees");
                    gotoxy(col, 12);
                    puts("Modify Employee");
                    gotoxy(col, 16);
                    puts("Delete Employee");
                    gotoxy(col,row);
                    setTextColor(stdout, TC_BLUE);
                    puts("Exit Program");

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






