#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include <conio.h>


struct user {
	char ac[50];
	char password[50];
	float balance;
};
int main(){
	struct user user,usr;
	char filename[50],phone[50],password[50],phone2[50];
	FILE *fp,*fptr;
	int opt,choice;
	int amount;
	char cont = 'y';
	login:
	printf("\nWELCOME TO MITHILA BANK!");
	printf("\n\n1.Register Account");
	printf("\n2.Login Account");

	printf("\n\nEnter choice: ");
	scanf("%d",&opt);
	if(opt == 1){
        printf("\n\nCreating Account...\n\n");
		printf("\nEnter Account number:");
		scanf("%s",user.ac);
		printf("Enter new password:");
		scanf("%s",user.password);
		user.balance=0;
		strcpy(filename,user.ac);
		fp=fopen(strcat(filename,".csv"),"w");
		fwrite(&user,sizeof(user),1,fp);
		if(fwrite != 0){
			printf("\nSuccessfully registered\n");
			goto login;
		}
	}
	else if(opt == 2){
		retry:
		printf("\nLogging In...\n");
		printf("\nAccount Number: ");
		char account[15];
		scanf("%s",&account);
		printf("Password: ");
		scanf("%s",password);
		fp = fopen(strcat(account,".csv"),"r");
		if(fp == NULL) printf("Account number not registered");

		else {
			fread(&user,sizeof(struct user),1,fp);
			fclose(fp);
			if(!strcmp(password,user.password)){
				while(cont == 'y'){
				printf("\n\tWelcome %s",user.ac);
				printf("\n 1. Balance inquiry");
				printf("\n 2. Adding fund");
				printf("\n 3. Cash withdraw");
				printf("\n 4. Inter-bank transfer");
				printf("\n 5. Forgot password\n");
                printf("\nEnter choice: ");
				scanf("%d",&choice);
				switch(choice){
					case 1:
						printf("\nYour current balance is Rs. %.2f",user.balance);
						break;

					case 2:
						printf("\nEnter amount to be added:\t");
						scanf("%d",&amount);
						user.balance += amount;
						fp = fopen(account,"w");
						fwrite(&user,sizeof(struct user),1,fp);
						if(fwrite !=0) printf("\n\nYou have deposited Rs.%d",amount);
						fclose(fp);
						break;

					case 3:
						printf("\nEnter withdraw amount:\t");
						scanf("%d",&amount);
						if(amount % 500 != 0) printf("\nSorry amount should be multiple of 500");
						else if(amount>user.balance) printf("\nSorry insufficient balance");
						else {
							user.balance -= amount;
						fp = fopen(account,"w");
						fwrite(&user,sizeof(struct user),1,fp);
						if(fwrite !=0) printf("\n\nYou have withdrawn Rs.%d",amount);
						fclose(fp);
						}
						break;

					case 4:
						printf("\nPlease enter the Account number to transfer balance:\t");
						scanf("%s",account);
						printf("Enter the amount to transfer:\t");
						scanf("%d",&amount);
						if(amount > user.balance) printf("\nSorry insufficient balance");
						else {
							fptr = fopen(strcat(account,".csv"),"r");
							if(fptr==NULL) printf("Sorry Account number is not registered");
							else {
								fread(&usr,sizeof(struct user),1,fptr);
								fclose(fptr);

								usr.balance += amount;

								fptr = fopen(account,"w");
								fwrite(&usr,sizeof(struct user),1,fptr);
								if(fwrite != 0){
									printf("Your transfer is completed. You have transfered Rs.%d to %s",amount,usr.ac);
									fclose(fptr);
									user.balance -= amount;
									strcpy(filename,user.ac);
									fp = fopen(strcat(filename,".csv"),"w");
									fwrite(&user,sizeof(struct user),1,fp);
									fclose(fp);
								}
							}
						}
						break;
					case 5:
						printf("\n\nPlease enter your old password:\t");
						scanf("%s",password);
						if(!strcmp(password,user.password)){
							printf("\n\nPlease enter your new password:\t");
							scanf("%s",password);
							strcpy(user.password,password);
							strcpy(filename,user.ac);
							fp = fopen(strcat(filename,".csv"),"w");
							fwrite(&user,sizeof(struct user),1,fp);
							fclose(fp);
							printf("\nPassword successfully changed");
						}else printf("\nSorry your password is wrong");

					default:
					break;
				}//switch ends here
				printf("\n\nDo you want to continue?[y/n]:\t");
				scanf("%s",&cont);
				}
			}
			else {
				printf("\nInvalid password");
				goto retry;
			}
		}
        printf("\n THANK YOU FOR BANKING WITH US!\n");
		printf("\n -----MITHILA BANK-----\n");
	}

	return 0;
}
