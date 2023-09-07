#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Account details
struct Account
{
    int accountNumber;
    float balance;
    char name[100];
    char password[100];
};

// Admin credentials
const char adminUsername[] = "admin";
const char adminPassword[] = "nocluewhatwedoing123";

// Account number origin
int trackNumber = 1000;

// Function prototypes
int generateAccountNumber();
void welcome();
void createAccount(struct Account accounts[], int *count);
void saveAccountsToFile(struct Account accounts[], int count);

int main()
{
    int count = 0;
    int isAdminLoggedIn = 0;
    struct Account accounts[100]; // Assuming a maximum of 100 accounts
    welcome();
    generateAccountNumber();
    createAccount(accounts, &count);

    return 0;
}

void welcome()
{
    printf("--WELCOME TO MITHILA BANK--\n");
}

int generateAccountNumber()
{
    return ++trackNumber;
}

// Function to create a new account
void createAccount(struct Account accounts[], int *count)
{
    struct Account newAccount;
    newAccount.accountNumber = generateAccountNumber();

    printf("Enter name: ");
    scanf(" %[^\n]s", newAccount.name); // Read name with spaces

    // Password requirements
    int hasLower = 0, hasUpper = 0, hasDigit = 0, hasPunct = 0, hasMinSize = 0;
    int length;

    do
    {
        printf("Enter password: ");
        scanf(" %[^\n]s", newAccount.password); // Read password with spaces

        // Check password criteria
        length = strlen(newAccount.password);

        for (int i = 0; i < length; i++)
        {
            if (isupper(newAccount.password[i]))
            {
                hasUpper = 1;
            }
            else if (islower(newAccount.password[i]))
            {
                hasLower = 1;
            }
            else if (isdigit(newAccount.password[i]))
            {
                hasDigit = 1;
            }
            else if (ispunct(newAccount.password[i]))
            {
                hasPunct = 1;
            }
        }

        if (length >= 8 && hasLower && hasUpper && hasDigit && hasPunct)
        {
            hasMinSize = 1;
        }
        else
        {
            printf("Password requirements not met. Please try again.\n");
            hasLower = hasUpper = hasDigit = hasPunct = hasMinSize = 0;
        }
    } while (!hasMinSize);

    printf("Enter initial balance: ");
    scanf("%f", &newAccount.balance);
    accounts[*count] = newAccount;
    (*count)++;

    // Admin authentication
    char nm[100];
    char pw[100];
    int isAdmin = 0;
    int attempts = 0;

    do
    {
        if (attempts > 0)
        {
            printf("Wrong admin credentials. Please try again.\n");
        }
        printf("Enter admin username: ");
        scanf(" %[^\n]s", nm); // Read admin username with spaces
        printf("Enter admin password: ");
        scanf(" %[^\n]s", pw); // Read admin password with spaces

        if (strcmp(adminUsername, nm) == 0 && strcmp(adminPassword, pw) == 0)
        {
            isAdmin = 1;
            printf("Account created successfully! Your account number is: %d\n", newAccount.accountNumber);
        }
        else
        {
            attempts++;
        }
    } while (!isAdmin && attempts < 3); // Allow 3 attempts

    if (isAdmin)
    {
        saveAccountsToFile(accounts, *count); // Save account data to file
    }
    else
    {
        printf("Admin authentication failed. Account creation aborted.\n");
    }
}

// Function to save account data to a text file
void saveAccountsToFile(struct Account accounts[], int count)
{
    FILE *file = fopen("accounts.txt", "w");
    if (file == NULL)
    {
        printf("Error opening file for writing.\n");
        return;
    }

    for (int i = 0; i < count; i++)
    {
        fprintf(file, "%d %s %.2f\n", accounts[i].accountNumber, accounts[i].name, accounts[i].balance);
    }

    fclose(file);
    printf("Account data saved to file.\n");
}
