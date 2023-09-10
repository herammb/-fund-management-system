#include <stdio.h>
#include <string.h>

// Structure to represent an account
struct Account {
    int accountNumber;
    char name[100];
    float balance;
    char password[100];
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
