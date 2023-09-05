#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

//account details
struct account
{
   int accountNumber;
   float balance;
   char name[50];
   char password[100];
};

//admin credentials
const char adminUsername[]= "admin";
const char adminPassword[] = "nocluewhatwedoing123";

//account number origin
int trackNumber = 1000;

//all prototypes mentioned here

int generateAccountNumber();
void welcome();
int account_data();
void createAccount(struct Account accounts[], int *count);

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

int generateAccountNumber()
{
   return ++trackNumber;
}

// Function to create a new account
void createAccount(struct Account accounts[], int *count) {
    struct Account newAccount;
    char name[100];
    char pw[100];
    newAccount.accountNumber = generateAccountNumber();
    printf("Enter name: ");
    scanf("%s", newAccount.name);
    int haslower,hasupper,hasdigit,haspunct,minsize;
    do
    {
        printf("Enter Password: ");
        printf("enter password:\nthe password should contain atleast 1 \nuppercase\nlowercase\ndigit\npunctuation\natleast 8 characters\n");
        scanf("%s",newAccount.password);
        
        int length = strlen(newAccount.password);
        
        for(int i=0;i <= length;i++){
        if(isupper(newAccount.password)){
            hasupper=1;
        }else if(islower(newAccount.password)){
        haslower=1;}
        else if(isdigit(newAccount.password)){
            hasdigit=1;
        }else if(ispunct(newAccount.password)){
        haspunct=1;
        }else if(length>=8){
        minsize=1;
        }
        }

    }while( haslower &&hasupper&&hasdigit&&haspunct&&minsize == 0);
    printf("Enter initial balance: ");
    scanf("%f", &newAccount.balance);
    accounts[*count] = newAccount;
    (*count)++;
    do
    {
        printf("Enter admin username");
    
    scanf("%s",name);
    printf("Enter admin password");
    scanf("%s",pw);
    
    if(strcmp(adminUsername,name) == 0 && strcmp(adminPassword,pw) == 0)
    {
            printf("Account created successfully! Your account number is: %d\n", newAccount.accountNumber);
    }
    else
    {
        printf("Wrong Credentials");
    }
    } while (strcmp(adminUsername,name) == 0 && strcmp(adminPassword,pw) == 0);
    
    printf("Enter admin username");
    char name[100];
    char pw[100];
    scanf("%s",name);
    printf("Enter admin password");
    scanf("%s",pw);
    
    if(strcmp(adminUsername,name) == 0 && strcmp(adminPassword,pw) == 0)
    {
            printf("Account created successfully! Your account number is: %d\n", newAccount.accountNumber);
    }
    else
    {
        printf("Wrong Credentials");
    }
    
    saveAccountsToFile(accounts, *count); // Save account data to file
}