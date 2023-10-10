#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <windows.h>
#define progress_bar_size 40

struct user {
    char name[100];
    char phone[100];
    char ac[100];
    char password[100];
    float balance;
};

void print_n_chars(int n, int c) {
    while (n-- > 0) putchar(c);
}

void display_progress_bar(int p) {
    putchar('\r');
    putchar('[');
    print_n_chars(progress_bar_size * p / 100, '/');
    print_n_chars(progress_bar_size - progress_bar_size * p / 100, ' ');
    putchar(']');
}

void set_text_color(int color) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

int main() {
    set_text_color(14);
    printf("\t\t    Hello!\n");
    printf("\t\t  Welcome to\n");
    printf("\t\tDesi Bank of India\n");
    set_text_color(15);  // White

    // Display a loading screen
    printf("loading...");
    printf("\n\t\t\tLoading... ");

    for (int p = 0; p <= 100; ++p) {
        display_progress_bar(p);
        Sleep(20);
    }

    // Reset text color
    set_text_color(15);  // White

    struct user user, usr;
    char filename[50], name[50], phone[50], password[50], phone2[50];
    FILE *fp, *fptr;
    int opt, choice;
    int amount;
    char cont = 'y';

    printf("\n\n\nWhat do you want to do?");
    printf("\n\n1.Register your account");
    printf("\n2.Login to your account");

	printf("\n\nPlease enter your choice:\t");
	scanf("%d",&opt);
	if(opt == 1){
		system("cls");
		printf("Enter your name:\t");
		scanf("%s",user.name);
		printf("\nEnter your account number:\t");
		scanf("%s",user.ac);
		printf("\nEnter your phone number:\t");
		scanf("%s",user.phone);
		printf("\nCreate your password:\t");
		scanf("%s",user.password);
		user.balance=0;
		strcpy(filename,user.phone);
		fp=fopen(strcat(filename,".dat"),"w");
		fwrite(&user,sizeof(user),1,fp);
		if(fwrite != 0){
			printf("Succesfully registered");
		}
	}
	else if(opt == 2){
		system("cls");
		printf("\nPhone No.:\t");
		scanf("%s",phone);
		printf("Password:\t");
		scanf("%s",password);
		fp = fopen(strcat(phone,".dat"),"r");
		if(fp == NULL) printf("Account number not registered");
		else {
			fread(&user,sizeof(struct user),1,fp);
			fclose(fp);
			if(!strcmp(password,user.password)){
				while(cont == 'y'){
				system("cls");
				printf("\n\tWelcome %s%s",user.phone,user.name);
				printf("\nPress 1 for balance inquiry");
				printf("\nPress 2 for adding fund");
				printf("\nPress 3 for cash withdraw");
//				printf("\nPress 4 for online transfer");
				printf("\nPress 4 for changing password\n\n");
				scanf("%d",&choice);
				switch(choice){
					case 1:
						printf("Your current balance is Rs. %.2f",user.balance);
						break;

					case 2:
						system("cls");
						printf("Enter amount to be added:\t");
						scanf("%d",&amount);
						user.balance += amount;
						fp = fopen(phone,"w");
						fwrite(&user,sizeof(struct user),1,fp);
						if(fwrite !=0) printf("\n\nYou have depostied Rs.%d",amount);
						fclose(fp);
						break;

					case 3:
						system("cls");
						printf("Enter withdrawl amount:\t");
						scanf("%d",&amount);
						if(amount % 500 != 0) printf("\nSorry amount should be multiple of 500");
						else if(amount>user.balance) printf("\nSorry insufficeint balance");
						else {
							user.balance -= amount;
						fp = fopen(phone,"w");
						fwrite(&user,sizeof(struct user),1,fp);
						if(fwrite !=0) printf("\n\nYou have withdrawn Rs.%d",amount);
						fclose(fp);
						}
						break;
					
//					case 4:
//						printf("Please enter the phone number to trasnfer balance:\t");
//						scanf("%s",phone);
//						printf("Enter the amount to transfer:\t");
//						scanf("%d",&amount);
//						if(amount > user.balance) printf("\nSorry insufficent balance");
//						else {
//							fptr = fopen(strcat(phone,".dat"),"r");
//							if(fptr==NULL) printf("Sorry number is not registered");
//							else {
//								fread(&usr,sizeof(struct user),1,fptr);
//								fclose(fptr);
//							
//								usr.balance += amount;
//								
//								fptr = fopen(phone,"w");
//								fwrite(&usr,sizeof(struct user),1,fptr);
//								if(fwrite != 0){
//								// 	printf("ACcount:%s",usr.ac);
//								// printf("\npassword%s",usr.password);
//								// printf("\nphone%s",usr.phone);
//								// printf("\nbalance%f",usr.balance);
//									printf("Your trasfer is completed. You have trasnfered Rs.%d to %s",amount,usr.phone);
//									fclose(fptr);
//									user.balance -= amount;
//									strcpy(filename,user.phone);
//									fp = fopen(strcat(filename,".dat"),"w");
//									fwrite(&user,sizeof(struct user),1,fp);
//									fclose(fp);
//								}
//							}
//						}
//						break;
					case 4:
						printf("\n\nPlease enter your old password:\t");
						scanf("%s",password);
						if(!strcmp(password,user.password)){
							printf("\n\nPlease enter your new password:\t");
							scanf("%s",password);
							strcpy(user.password,password);
							strcpy(filename,user.phone);
							fp = fopen(strcat(filename,".dat"),"w");
							fwrite(&user,sizeof(struct user),1,fp);
							fclose(fp);	
							printf("\nPassword succesfullly changed");
						}else printf("\nSorry your password is wrong");
					
					default:
					break;
				}//switch ends here
				printf("\n\nDo you want to continue?[y/n]:\t");
				scanf("%s",&cont);
				}
			}
			else {
				printf("Invalid password");
			}	
		}
		printf("\n\n***Thank you for banking with ADV. bank***\n\n");
	}
	
	return 0;
	getchar();
}
