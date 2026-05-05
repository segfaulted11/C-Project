#include <stdio.h>
#include <string.h>
#include <stdlib.h>

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

//step -2 (Login system)
void login(){
    char userName[20];
    char passWord[20];
    printf("Enter your Username : ");
    scanf("%s",userName);
    printf("Enter your password : ");
    scanf("%s",passWord);

    if(strcmp(userName,"admin")==0 && strcmp(passWord,"12345")==0){
        printf("Log In Succesful!\n");
    }else{
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

int main()
{
    login();
    printf("Dorm Room Management System!\n");
    return 0;
}