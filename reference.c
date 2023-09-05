#include <stdio.h>
#include <string.h>

// Structure to represent an account
struct Account {
    int accountNumber;
    char name[100];
    float balance;
};

// Global variable to keep track of the last assigned account number
int lastAccountNumber = 1000;

// Admin credentials
const char adminUsername[] = "admin";
const char adminPassword[] = "admin123";

// Function to generate the next account number
int generateAccountNumber() {
    return ++lastAccountNumber;
}

// Function to create a new account
void createAccount(struct Account accounts[], int *count) {
    struct Account newAccount;
    newAccount.accountNumber = generateAccountNumber();
    printf("Enter name: ");
    scanf("%s", newAccount.name);
    printf("Enter initial balance: ");
    scanf("%f", &newAccount.balance);
    accounts[*count] = newAccount;
    (*count)++;
    printf("Account created successfully! Your account number is: %d\n", newAccount.accountNumber);
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

// Function to load account data from a text file
void loadAccountsFromFile(struct Account accounts[], int *count) {
    FILE *file = fopen("accounts.txt", "r");
    if (file == NULL) {
        printf("No existing account data found.\n");
        return;
    }

    while (fscanf(file, "%d %s %f", &accounts[*count].accountNumber, accounts[*count].name, &accounts[*count].balance) != EOF) {
        (*count)++;
    }

    fclose(file);
    printf("Account data loaded from file.\n");
}

// Rest of the functions remain the same as in the previous example

int main() {
    struct Account accounts[100];
    int count = 0;
    int isAdminLoggedIn = 0;

    // Load existing account data from file (if any)
    loadAccountsFromFile(accounts, &count);

    while (1) {
        // ... Rest of the main function remains the same as in the previous example
    }

    return 0;
}
