#include <stdio.h>
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
