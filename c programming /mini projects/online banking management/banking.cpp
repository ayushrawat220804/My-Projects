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
    putchar('*');
    print_n_chars(progress_bar_size * p / 100, '-');
    print_n_chars(progress_bar_size - progress_bar_size * p / 100, ' ');
    putchar('*');
}


void set_text_color(int color) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}


int main() {
    set_text_color(14);
    printf("\t\t    **  Hello!  **\n");
    printf("\t\t  **  Welcome to  **\n");
    printf("\t\t**  Bank  of  India **\n");
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

    struct user user;
    char filename[50], phone[50], password[50];
    FILE *fp;
    int opt, choice, amount;
    char cont = 'y';


    while (cont == 'y') {
        system("cls");

        printf("\n\n\nWhat do you want to do?");
        printf("\n\n1.Register your account");
        printf("\n2.Login to your account");

        printf("\n\nPlease enter your choice:\t");
        scanf("%d", &opt);
        
        

        if (opt == 1) {
            system("cls");
            printf("Enter your name:\t");
            scanf("%s", user.name);
            printf("\nEnter your account number:\t");
            scanf("%s", user.ac);
            printf("\nEnter your phone number:\t");
            scanf("%s", user.phone);
            printf("\nCreate your password:\t");
            scanf("%s", user.password);
            user.balance = 0;
            strcpy(filename, user.phone);
            fp = fopen(strcat(filename, ".txt"), "w");
            if (fwrite(&user, sizeof(user), 1, fp) != 0) {
                printf("Successfully registered");
            }
            fclose(fp);
            
            
            
        } else if (opt == 2) {
            system("cls");
            printf("\nPhone No.:\t");
            scanf("%s", phone);
            printf("Password:\t");
            scanf("%s", password);
            fp = fopen(strcat(phone, ".txt"), "r");
            
            
            if (fp == NULL) {
                printf("Account number not registered");
            } else {
                fread(&user, sizeof(struct user), 1, fp);
                fclose(fp);
                

                if (!strcmp(password, user.password)) {
                    do {
                        system("cls");
                        printf("\nWelcome %s\t%s", user.phone, user.name);
                        printf("\nPress 1 for balance inquiry");
                        printf("\nPress 2 for adding fund");
                        printf("\nPress 3 for cash withdrawal");
                        printf("\nPress 4 for changing password\n\n");
                        scanf("%d", &choice);
                        
                        

                        switch (choice) {
                            case 1:
                            	system("cls");
                                printf("Your current balance is Rs. %.2f", user.balance);
                                break;
                                
                                

                            case 2:
                                system("cls");
                                printf("Enter amount to be added:\t");
                                scanf("%d", &amount);
                                user.balance += amount;
                                fp = fopen(phone, "w");
                                if (fwrite(&user, sizeof(struct user), 1, fp) != 0) {
                                    printf("\n\nYou have deposited Rs.%d", amount);
                                }
                                fclose(fp);
                                break;
                                
                                

                            case 3:
                                system("cls");
                                printf("Enter withdrawal amount:\t");
                                scanf("%d", &amount);
                                if (amount % 500 != 0) {
                                    printf("\nSorry amount should be a multiple of 500");
                                } else if (amount > user.balance) {
                                    printf("\nSorry insufficient balance");
                                } else {
                                    user.balance -= amount;
                                    fp = fopen(phone, "w");
                                    if (fwrite(&user, sizeof(struct user), 1, fp) != 0) {
                                        printf("\n\nYou have withdrawn Rs.%d", amount);
                                    }
                                    fclose(fp);
                                }
                                break;
                                
                                

                            case 4:
                            	system("cls");
                                printf("\n\nPlease enter your old password:\t");
                                scanf("%s", password);
                                if (!strcmp(password, user.password)) {
                                    printf("\n\nPlease enter your new password:\t");
                                    scanf("%s", password);
                                    strcpy(user.password, password);
                                    strcpy(filename, user.phone);
                                    fp = fopen(strcat(filename, ".txt"), "w");
                                    if (fwrite(&user, sizeof(struct user), 1, fp) != 0) {
                                        fclose(fp);
                                        printf("\nPassword successfully changed");
                                    } else {
                                        fclose(fp);
                                        printf("\nFailed to change password");
                                    }
                                } else {
                                    printf("\nSorry, your old password is wrong");
                                }
                                break;

                            default:
                                break;
                        }
                        
                        

                        printf("\n\nDo you want to continue?[y/n]:\t");
                        scanf(" %c", &cont);
                        

                    } while (cont == 'y');
                } else {
                    printf("Invalid password");
                }
            }
            
        } else {
            printf("Invalid choice");
        }


        printf("\n\nDo you want to continue Bank Of INDIA [y/n]:\t");
        scanf(" %c", &cont);  // Note the space before %c to consume any leading whitespace
    }


    printf("\n\n***Thank you for choosing Bank of India for your banking needs!\n");
    printf("We appreciate your trust in us. Have a great day!***\n\n");


    
    return 0;
}


