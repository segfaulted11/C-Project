#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// step - 1 ()

// Structure (Blueprint of one record)
struct Dorm
{
    int studentID;
    char name[50];
    int roomNumber;
    char checkInDate[20];
    char paymentStatus[20]; // Paid / Unpaid
};

// Array of structures (acts like database)
struct Dorm d[100]; // array of structures. this array contains 100 structure instances as its element.

// Count variable (tracks number of entered students)
int count = 0;

// step -2 (Login system)
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
    /*
    strcmp() → compares strings
    == 0 → means strings are equal
    != 0 -> mean they r not equal
    exit(0) → force stop program
    */
}

// step - 4 (add function)

/* Goal ->
Let the user:

enter student info
store it in the array of structure
increase count

Basically: “save new record”

What does your add() function do? => “It takes user input and stores it into an array of structures, which acts as a temporary database.”

Step 1 → create database
Step 4 → insert data into database
*/

void add()
{
    printf("\n--- Add Student ---\n");

    //  d[count]  Means: “store data in next empty slot”
    // If count = 0 → goes to d[0]
    // If count = 1 → goes to d[1]

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

    count++; // 'count' tracks how many records are currently stored and ensures new data is added to the correct index in the array. the value of 'count' increases by 1 from its current value, everytime the 'add()' function is called.

    // for the the first student array index(d[count==0].whatever) is 0 but count is 1, that means its going to be stored at index 0 as the first element of the array of structres and the 2nd student is going to be stored in the at index z as the second element. here index and count are different. right from the first student count gets updated to 0.

    printf("\nStudent added successfully!\n");
}

// step -5 (view function)

// this function is used for displaying the entered student's information. this will take place if the user takes the 2nd choice. it will show the information of the students that are on the record from the database (array of structure).
void view()
{
    printf("\n--- View Student Records ---\n\n");

    if (count == 0)
    {
        printf("\nNo student has been recorded yet! Database is currently Empty! pls Enter a student first.\n");
        return; // if no student is enterd yet then show this.
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
    /*
//strstr() (THE STAR OF THIS STEP)
strstr(d[i].name, searchingKeyword)
Means:“Does this name contain the search text(searchingKeyword)?”

Example:
Name = "lokman"
searchingKeyword = "man"
strstr() finds "man" inside "lokman" → TRUE

If not found:
strstr(...) == NULL, means no match

note : strstr() is case sensitive.

If they ask:“How did you implement partial search?”

You say:“Using strstr() to check if the search key exists as a substring within the stored names.”
    */
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

            // take input again
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
    if (found = 0)
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
            // delete that element from the array. but you can’t actually remove an element. You can only overwrite it. overwriting the removed element by pulling everything after it one step toward the front.
            for (int j = i; j < count - 1; j++)
            {
                d[j] = d[j + 1];
            }
            count--; // reducing the count since the element is being deleted.
            i--;     // important (for some reason i dont understand yet lol)
            found = 1;
        }
    }
    if (found = 0)
    {
        printf("Sorry! No matching records found w such name.\n");
    }
}

// main function
int main()
{
    int choice;

    login(); // step-2

    // step -3 (Menu System)

    // keeps running and lets the user choose actions

    printf("\n====== Dorm Room Management System ======\n");
    printf("Enter 1 to add students\n");
    printf("Enter 2 to view students\n");
    printf("Enter 3 to search students\n");
    printf("Enter 4 to edit students\n");
    printf("Enter 5 to delete students\n");
    printf("Enter 6 to exit\n");
    do
    {

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            add(); // step - 4, calling the add function.
            break;
        case 2:
            view(); // step - 5, calling the view function.
            break;
        case 3:
            search(); // step - 6.A, calling the search function.
            break;
        case 4:
            editRecord(); // step - 6.B, calling the editRecord function
            break;
        case 5:
            deleteRecord();// step - 6.C, calling the deleteRecord function
            break;
        case 0:
            printf("Exiting the program.....\n");
            break;
        default:
            printf("Invalid choice! pls choose anything from 0-5\n");
        }
    } while (choice != 0); // keep showing menu until user chooses exit

    return 0;
}