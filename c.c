#include <stdio.h>
#include <string.h>

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
struct Dorm d[100];

// Count variable (tracks number of records)
int count = 0;

int main()
{
    printf("Dorm Room Management System!\n");
    return 0;
}