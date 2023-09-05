#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ACCOUNTS 100

// Structure to represent a bank account
typedef struct {
    int account_number;
    char account_holder[50];
    float balance;
} Account;

// Function to create a new account
Account createAccount(int account_number, char account_holder[50], float initial_balance) {
    Account account;
    account.account_number = account_number;
    strcpy(account.account_holder, account_holder);
    account.balance = initial_balance;
    return account;
}

// Function to deposit money into an account
void deposit(Account *account, float amount) {
    if (amount > 0) {
        account->balance += amount;
        printf("Deposited %.2f into account %d\n", amount, account->account_number);
    } else {
        printf("Invalid deposit amount\n");
    }
}

// Function to withdraw money from an account
void withdraw(Account *account, float amount) {
    if (amount > 0 && amount <= account->balance) {
        account->balance -= amount;
        printf("Withdrawn %.2f from account %d\n", amount, account->account_number);
    } else {
        printf("Invalid withdrawal amount or insufficient balance\n");
    }
}

// Function to display account details
void displayAccount(Account account) {
    printf("Account Number: %d\n", account.account_number);
    printf("Account Holder: %s\n", account.account_holder);
    printf("Balance: %.2f\n", account.balance);
}

// Function to save accounts to a text file
void saveAccountsToFile(Account accounts[], int num_accounts, const char *filename) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        perror("Error opening file for writing");
        return;
    }

    for (int i = 0; i < num_accounts; i++) {
        fprintf(file, "%d %s %.2f\n", accounts[i].account_number, accounts[i].account_holder, accounts[i].balance);
    }

    fclose(file);
}

// Function to load accounts from a text file
int loadAccountsFromFile(Account accounts[], int max_accounts, const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening file for reading");
        return 0;
    }

    int num_accounts = 0;
    while (num_accounts < max_accounts && fscanf(file, "%d %s %f", &accounts[num_accounts].account_number,
                                                   accounts[num_accounts].account_holder, &accounts[num_accounts].balance) == 3) {
        num_accounts++;
    }

    fclose(file);
    return num_accounts;
}

int main() {
    Account accounts[MAX_ACCOUNTS];
    int num_accounts = 0;

    // Load accounts from a text file (if it exists)
    num_accounts = loadAccountsFromFile(accounts, MAX_ACCOUNTS, "accounts.txt");

    int choice;
    do {
        printf("\nBank Management System\n");
        printf("1. Create Account\n");
        printf("2. Deposit\n");
        printf("3. Withdraw\n");
        printf("4. Display Account Details\n");
        printf("5. Save Accounts to File\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: // Create Account
                if (num_accounts < MAX_ACCOUNTS) {
                    int account_number;
                    char account_holder[50];
                    float initial_balance;
                    printf("Enter Account Number: ");
                    scanf("%d", &account_number);
                    printf("Enter Account Holder Name: ");
                    scanf("%s", account_holder);
                    printf("Enter Initial Balance: ");
                    scanf("%f", &initial_balance);
                    accounts[num_accounts++] = createAccount(account_number, account_holder, initial_balance);
                    printf("Account created successfully!\n");
                } else {
                    printf("Maximum number of accounts reached!\n");
                }
                break;

            case 2: // Deposit
                // Implement deposit functionality
                break;

            case 3: // Withdraw
                // Implement withdrawal functionality
                break;

            case 4: // Display Account Details
                // Implement account details display
                break;

            case 5: // Save Accounts to File
                saveAccountsToFile(accounts, num_accounts, "accounts.txt");
                printf("Accounts saved to file.\n");
                break;

            case 6: // Exit
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 6);

    return 0;
}
