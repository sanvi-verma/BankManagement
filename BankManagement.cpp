#include<stdio.h>
#include<stdlib.h>
struct account 
{
    int account_number;
    char name[50];
    float balance;
};
void create_account(struct account *acc, struct account *all_accounts, int count);
void deposit(struct account *acc);
void withdraw(struct account *acc);
void view_account(struct account *acc);
int count = 0;
int main()
{
    int choice;
    struct account *accounts;
    accounts = (struct account *) malloc(sizeof(struct account));
    while(1)
    {
        printf("\n\n***BANK MANAGEMENT SYSTEM***\n");
        printf("\n1.Create Account\n");
        printf("2.Deposit\n");
        printf("3.Withdraw\n");
        printf("4.View Account Details\n");
        printf("5.Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1:
                create_account(&accounts[count], accounts, count);
                 if (accounts[count].account_number != 0) 
                 {
                    count++;
                    accounts = (struct account *)realloc(accounts, (count + 1) * sizeof(struct account));
        }
            break;
            case 2:
                deposit(accounts);
                break;
            case 3:
                withdraw(accounts);
                break;
            case 4:
               view_account(accounts);
               break;
            case 5:
                printf("\nThank you for using the banking system!\n");
                free(accounts);
                exit(0);
            default:
                printf("\nInvalid choice. Please try again.\n");
        }
    }
    return 0;
}
void create_account(struct account *acc, struct account *all_accounts, int count)
{
    int account_number, i;
    int account_exists = 0;

    printf("\nEnter Account Number: ");
    scanf("%d", &account_number);

    // Check if the account number already exists
    for (i = 0; i < count; i++)
    {
        if (all_accounts[i].account_number == account_number)
        {
            account_exists = 1;
            break;
        }
    }

    if (account_exists)
    {
        printf("An account with this number already exists. Please try again with a different account number.\n");
    }
    else
    {
        acc->account_number = account_number;
        printf("Enter Name: ");
        scanf("%s", acc->name);
        printf("Enter Initial Balance: ");
        scanf("%f", &(acc->balance));
        printf("\nAccount created successfully.\n");
    }
}

void deposit(struct account *acc)
{
    int account_number, i;
    float deposit_amount;
    int found = 0;
    printf("\nEnter Account Number: ");
    scanf("%d", &account_number);
    for(i=0; i<count; i++)
    {
        if(acc[i].account_number == account_number)
        {
            found = 1;
            printf("\nEnter Amount to be Deposited: ");
            scanf("%f", &deposit_amount);
            acc[i].balance += deposit_amount;
            printf("\nAmount Deposited Successfully.\n");
            break;
        }
    }
    if(found == 0)
        printf("\nAccount not found.\n");
}
void withdraw(struct account *acc)
{
    int account_number, i;
    float withdraw_amount;
    int found = 0;
    printf("\nEnter Account Number: ");
    scanf("%d", &account_number);
    for(i=0; i<count; i++)
    {
        if(acc[i].account_number == account_number)
        {
            found = 1;
            printf("\nEnter Amount to be Withdrawn: ");
            scanf("%f", &withdraw_amount);

            if(withdraw_amount <= acc[i].balance)
            {
                acc[i].balance -= withdraw_amount;
                printf("\nAmount Withdrawn Successfully.\n");
            }
            else
                printf("\nInsufficient Balance.\n");
            break;
        }
    }
    if(found == 0)
        printf("\nAccount not found.\n");
}
void view_account(struct account *acc)
{
    int account_number, i;
    int found = 0;
    printf("\nEnter Account Number: ");
    scanf("%d", &account_number);
    for (i = 0; i < count; i++)
    {
        if (acc[i].account_number == account_number)
        {
            found = 1;
            printf("\nAccount Number: %d", acc[i].account_number);
            printf("\nName: %s", acc[i].name);
            printf("\nBalance: %.2f\n", acc[i].balance);
            break;
        }
    }
    if (found == 0)
        printf("\nAccount not found.\n");
}
