#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


//account details
struct Account
{
   int accountNumber;
   float balance;
   char name[100];
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
void createAccount(struct Account accounts[], int *count);
void saveAccountsToFile(struct Account accounts[],int count );


void main()
 {
    int count = 0;
    welcome();
 }


 void welcome()
 {
    printf("--WELCOME TO MITHILA BANK--");
 }


int generateAccountNumber()
{
   return ++trackNumber;
}


// Function to create a new account
void createAccount(struct Account accounts[], int *count) {
    struct Account newAccount;
    newAccount.accountNumber = generateAccountNumber();
    
    printf("Enter name: ");
    scanf("%s", newAccount.name);

    // Password requirements
    int hasLower = 0, hasUpper = 0, hasDigit = 0, hasPunct = 0, hasMinSize = 0;
    int length;

    do {
        printf("Enter password: ");
        scanf("%s", newAccount.password);

//to check function criteria
        length = strlen(newAccount.password);

        for (int i = 0; i < length; i++) {
            if (isupper(newAccount.password[i])) {
                hasUpper = 1;
            } else if (islower(newAccount.password[i])) {
                hasLower = 1;
            } else if (isdigit(newAccount.password[i])) {
                hasDigit = 1;
            } else if (ispunct(newAccount.password[i])) {
                hasPunct = 1;
            }
        }

        if (length >= 8 && hasLower && hasUpper && hasDigit && hasPunct) {
            hasMinSize = 1;
        } else {
            printf("Password requirements not met. Please try again.\n");
            hasLower = hasUpper = hasDigit = hasPunct = hasMinSize = 0;
        }
    } while (!hasMinSize);

    printf("Enter initial balance: ");
    scanf("%f", &newAccount.balance);
    accounts[*count] = newAccount;
    (*count)++;

//admin authentication
    char nm[100];
    char pw[100];
    int isAdmin = 0;

    do {
        printf("Enter admin username: ");
        scanf("%s", nm);
        printf("Enter admin password: ");
        scanf("%s", pw);

        if (strcmp(adminUsername, nm) == 0 && strcmp(adminPassword, pw) == 0) {
            isAdmin = 1;
            printf("Account created successfully! Your account number is: %d\n", newAccount.accountNumber);
        } else {
            printf("Wrong admin credentials. Please try again.\n");
        }
    } while (!isAdmin);

    saveAccountsToFile(accounts, *count); // Save account data to file
}

// Function to save account data to a text file
void saveAccountsToFile(struct Account accounts[], int count) {
    FILE *file = fopen("accounts.txt", "w");
    if (file == NULL) {
        printf("Error opening file for writing.\n");
        return;
    }

    for (int i = 0; i < count; i++) {
        fprintf(file, "%d %s %.2f\n", accounts[i].accountNumber, accounts[i].name, accounts[i].balance);
    }

    fclose(file);
    printf("Account data saved to file.\n");
}