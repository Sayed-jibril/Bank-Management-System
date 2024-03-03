#include <stdio.h>
#include <math.h>
#include <string.h>

struct info{
    char firstName[20];
    char lastName[20];
    char middlename[20];
    char mothername[20];
    char email[20];
    char icNo[20];
    char phoneNo[20];
    char username[20];
    char password[10];
    char newpassword[10];
    float balance;

}usr, usr1;


int main()
{

    char goback;
    char day;
    char month;
    char year;

    int opt;
    FILE *fp;
    char filename[50];

    first:
    system("clear");
    printf("***Welcome To Bank Account System***");
    printf("\n\n***Choose Your Options***");
    printf("\n1. Create a new account");
    printf("\n2. Already have an account, SIGN IN");
    printf("\n3. EXIT");

    printf("\nCHOOSE YOUR OPTION  : ");
    scanf("%d", &opt);

    if(opt == 1)
    {
        system("clear");
        printf("Enter your first name :");
        scanf("%s", usr.firstName);
        printf("Enter your middle name:");
        scanf("%s", usr.middlename);
        printf("Enter your last name :");
        scanf("%s", usr.lastName);
        printf("Enter your mother name :");
        scanf("%s", usr.mothername);
        printf("Enter your Email address :");
        scanf("%s",usr.email);
        printf("Enter your IC <or> Passport No. :");
        scanf("%s", usr.icNo);
        printf("Enter your Phone Number :");
        scanf("%s", usr.phoneNo);
        printf("Enter your User Name :");
        scanf("%s", usr.username);
        printf("Enter your password :");
        scanf("%s", usr.password);
        printf("\n\nDATE OF BIRTH (DD/MM/YYYY) : ");
        scanf("%s%*c%s%*c%s",&day,&month,&year);

        usr.balance = 0;

        strcpy(filename, usr.username);
        fp = fopen(strcat(filename,".dat"),"w");
        fwrite(&usr, sizeof(struct info),1,fp);
        if(fwrite != 0)
        {
            printf("Successfully Registered.........\n");
            printf("Account register completed");
        }
        if(fwrite == 0)
        {
            printf("Failed to register! Please try againg");
        }
        fclose(fp);

    }

    char uname[20];
    char password[20];
    int choice;
    char cont ;
    float amount;
    float withdrawl;
    float transfer;
    char phone[20];

    if(opt == 2)
    {
        system("clear");
        printf("User Name :");
        scanf("%s", uname);
        printf("Password :");
        scanf("%s", password);

        strcpy(filename, uname);
        fp = fopen(strcat(filename, ".dat"), "r");
        if(fp == NULL)
        {
            printf("Account is not registered");
        }
        else
        {
            fread(&usr, sizeof(struct info), 1,fp);

            if(!strcmp (password , usr.password)){
                do
                {
                    printf("\nPress 1 to CHECK BALANCE");
                    printf("\nPress 2 to DEPOSIT MONEY");
                    printf("\nPress 3 to WITHDRAWL MONEY");
                    printf("\nPress 4 to CHANGE PASSWORD");
                    printf("\nYOUR CHOICE  :  ");
                    scanf("%d", &choice);

                    switch(choice){
                        case 1:
                        system("clear");
                        printf("\nYour current balance is : %.2f RM", usr.balance);
                        break;

                        case 2:
                        system("clear");
                        printf("Enter your amount of Money to save RM : ");
                        scanf("%f", &amount);
                        usr.balance += amount;
                        fp = fopen(filename,"w");
                        fwrite(&usr, sizeof(struct info),1,fp);
                        if(fwrite!=NULL)
                        {
                            printf("Your Current Balance is : %.2f RM", usr.balance);
                            printf("\nSuccessfully Deposited");
                        }
                        fclose(fp);
                        break;
			
			case 3:
                        system("clear");
                        printf("Enter amount of money to Withdrawl RM : ");
                        scanf("%f", &withdrawl);
                        usr.balance -= withdrawl;
                        fp = fopen(filename, "w");
                        fwrite(&usr, sizeof(struct info), 1,fp);
                        if(fwrite != NULL)
                        {
                            printf("Your current balance is : %.2f RM", usr.balance);
                            printf("\nSuccessfully Withdrawl");
                        }
                        fclose(fp);
                        break;

                        case 4:
                        system("clear");
                        printf("Enter your new password : ");
                        scanf("%s", usr.newpassword);
                        fp = fopen(filename, "w");
                        strcpy(usr.password, usr.newpassword);
                        fwrite(&usr, sizeof(struct info),1,fp);
                        if(fwrite != NULL)
                        {
                            printf("Password Changed successfully!");
                        }
                        fclose(fp);
                        break;

                    }

                    printf("\n\nDo you want to continue? (Y or N)  : ");
                    scanf("%s", &cont);

                }while(cont == 'Y');
                if(cont == 'N')
                {
                    goto first;
                }
            }
            else
            {
                printf("Invalid Password");
            }
        }

    }

    if(opt == 3)
    {
        system("clear");
        printf("Thank you for using our service");
    }

    fclose(fp);
    return 0;
}