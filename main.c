#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//account details
struct account
{
   int accountNumber;
   float balance;
   char name[50];
};

//admin credentials
const char username[]= "admin";
const char password[] = "nocluewhatwedoing123";

//account number origin
int trackNumber = 1000;


void welcome();
int account_data();

void main()
 {
    welcome();
    account_data();

 }
 void welcome()
 {
    printf("--WELCOME TO MITHILA BANK--");
 }
 int account_data()
 {
    FILE *file = fopen("accountdata.txt","a");
    fprintf(file,"hey this is dev");
    fclose(file);
 }
