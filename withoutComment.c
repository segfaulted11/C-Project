#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// step - 1 (Data Model (Structure + Array))

struct Dorm
{
    int studentID;
    char name[50];
    int roomNumber;
    char checkInDate[20];
    char paymentStatus[20];
};

struct Dorm d[100];

int count = 0;

// step - 2 (Login system)
void login()
{
    char userName[20];
    char passWord[20];
    printf("Enter your Username : ");
    scanf("%s", userName);
    printf("Enter your password : ");
    scanf("%s", passWord);

    if (strcmp(userName, "a") == 0 && strcmp(passWord, "23") == 0)
    {
        printf("Log In Succesful!\n");
    }
    else
    {
        printf("Log In failed\n");
        printf("Exiting program...\n");
        exit(0);
    }
}

// step - 4 (add function)
void add()
{
    printf("\n--- Add Student ---\n");

    printf("Enter Student ID: ");
    scanf("%d", &d[count].studentID);
    printf("Enter Student Name: ");
    scanf("%s", d[count].name);
    printf("Enter Room Number: ");
    scanf("%d", &d[count].roomNumber);
    printf("Enter Check In Date: ");
    scanf("%s", d[count].checkInDate);
    printf("Enter Payment Status: ");
    scanf("%s", d[count].paymentStatus);

    count++;

    printf("\nStudent added successfully!\n");
}

// step - 5 (view function)
void view()
{
    printf("\n--- View Student Records ---\n\n");

    if (count == 0)
    {
        printf("\nNo student has been recorded yet! Database is currently Empty! pls Enter a student first.\n");
        return;
    }
    for (int i = 0; i < count; i++)
    {
        printf("Record For Student - %d\n", i + 1);
        printf("Name : %s\n", d[i].name);
        printf("Student ID : %d\n", d[i].studentID);
        printf("Room Number : %d\n", d[i].roomNumber);
        printf("Check-In Date : %s\n", d[i].checkInDate);
        printf("Payment Status : %s\n", d[i].paymentStatus);

        printf("\n");
    }
}

// step - 6.A (Search function)
void search()
{
    char searchingKeyword[20];
    int found = 0;

    printf("Enter the name or part of the name you want to find : ");
    scanf("%s", searchingKeyword);

    printf("\n--- Search Results ---\n");
    for (int i = 0; i < count; i++)
    {
        if (strstr(d[i].name, searchingKeyword) != NULL)
        {
            found = 1;

            printf("Record For Student - %d\n", i + 1);
            printf("Name : %s\n", d[i].name);
            printf("Student ID : %d\n", d[i].studentID);
            printf("Room Number : %d\n", d[i].roomNumber);
            printf("Check-In Date : %s\n", d[i].checkInDate);
            printf("Payment Status : %s\n", d[i].paymentStatus);

            printf("\n");
        }
    }
    if (!found)
    {
        printf("Sorry! No matching records found w such name.\n");
    }
}

// step - 6.B (Edit function)
void editRecord()
{
    char searchingKeyword[20];
    int found = 0;

    printf("Enter the name or part of the name you want to find for editing : ");
    scanf("%s", searchingKeyword);

    printf("\n--- Search Results ---\n");
    for (int i = 0; i < count; i++)
    {
        if (strstr(d[i].name, searchingKeyword) != NULL)
        {
            printf("Record For Student - %d\n", i + 1);
            printf("Name : %s\n", d[i].name);
            printf("Student ID : %d\n", d[i].studentID);
            printf("Room Number : %d\n", d[i].roomNumber);
            printf("Check-In Date : %s\n", d[i].checkInDate);
            printf("Payment Status : %s\n", d[i].paymentStatus);

            printf("\n--- Enter New Data ---\n");

            printf("Enter new name: ");
            scanf("%s", d[i].name);

            printf("Enter new student ID: ");
            scanf("%d", &d[i].studentID);

            printf("Enter new room number: ");
            scanf("%d", &d[i].roomNumber);

            printf("Enter new check-in date: ");
            scanf("%s", d[i].checkInDate);

            printf("Enter new payment status: ");
            scanf("%s", d[i].paymentStatus);

            printf("\nRecord updated successfully!\n\n");

            found = 1;
            printf("\n");
        }
    }
    if (found == 0)
    {
        printf("Sorry! No matching records found w such name.\n");
    }
}

// step - 6.C (deleteRecord function)
void deleteRecord()
{
    char searchingKeyword[20];
    int found = 0;
    printf("Enter the name you want to delete : ");
    scanf("%s", searchingKeyword);

    for (int i = 0; i < count; i++)
    {
        if (strstr(d[i].name, searchingKeyword) != NULL)
        {
            for (int j = i; j < count - 1; j++)
            {
                d[j] = d[j + 1];
            }
            count--;
            i--;
            found = 1;
        }
    }
    if (found == 0)
    {
        printf("Sorry! No matching records found w such name.\n");
    }
}

// Step - 7 File Handling (make your data permanent)

// Step - 7.A (Save to file)
void saveToFile()
{
    FILE *fp;
    int i;

    fp = fopen("data.txt", "w");

    for (i = 0; i < count; i++)
    {
        fprintf(fp, "%d %s %d %s %s\n",
                d[i].studentID,
                d[i].name,
                d[i].roomNumber,
                d[i].checkInDate,
                d[i].paymentStatus);
    }

    fclose(fp);
}

// STEP 7.B (Load from file)
void loadFromFile()
{
    FILE *fp;

    fp = fopen("data.txt", "r");

    if (fp == NULL)
    {
        return;
    }

    while (fscanf(fp, "%d %s %d %s %s",
                  &d[count].studentID,
                  d[count].name,
                  &d[count].roomNumber,
                  d[count].checkInDate,
                  d[count].paymentStatus) != EOF)
    {
        count++;
    }

    fclose(fp);
}

int main()
{
    int choice;

    login(); // step-2

    loadFromFile(); // step-7.B (load old data)

    // step - 3 (Menu System)

    printf("\n====== Dorm Room Management System ======\n");
    printf("Enter 1 to add students\n");
    printf("Enter 2 to view students\n");
    printf("Enter 3 to search students\n");
    printf("Enter 4 to edit students\n");
    printf("Enter 5 to delete students\n");
    printf("Enter 0 to exit\n");
    do
    {
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            add();        // step - 4, calling the add function.
            saveToFile(); // step - 7.A
            break;
        case 2:
            view(); // step - 5, calling the view function.
            break;
        case 3:
            search(); // step - 6.A, calling the search function.
            break;
        case 4:
            editRecord(); // step - 6.B, calling the editRecord function
            saveToFile(); // step - 7.A
            break;
        case 5:
            deleteRecord(); // step - 6.C, calling the deleteRecord function
            saveToFile();   // step - 7.A
            break;
        case 0:
            printf("Exiting the program.....\n");
            break;
        default:
            printf("Invalid choice! pls choose anything from 0-5\n");
        }
    } while (choice != 0);

    return 0;
}