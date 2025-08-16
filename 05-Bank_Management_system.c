#include <stdio.h>
#include <string.h>
struct account
{
    char customer_name[50];
    long long mobile_no;
    char date_of_birth[11];
    char gender[10];
    int customer_id; // avaiable = 1 , not avaiable = 0
    int amount;
    int cash_withdraw;
    double check_balance;
};

// Function prototype to find a customer's index by their ID

int find_customer_by_id(struct account customer[], int count, int customer_id)
{
    for (int i = 0; i < count; i++)
    {
        if (customer[i].customer_id == customer_id)
        {
            return i;
        }
        return -1;
    }
}
// Function prototype for create account of the customer
void create_account(struct account customer[], int *count)
{
    printf("Enter your name as per your any legal verified government document:");
    scanf(" %[^\n]", customer[*count].customer_name);

    printf("Set a customer number according to your self:");
    scanf("%d", &customer[*count].customer_id);

    printf("Enter your contact number:");
    scanf("%lld", &customer[*count].mobile_no); // %lld is use for longer number

    printf("Enter your date of birth(dd/mm/yyyy):");
    scanf("%s", customer[*count].date_of_birth);

    printf("Enter your gender:");
    scanf("%s", customer[*count].gender);

    customer[*count].check_balance = 0.0; // when account is created balanced is zero
    (*count++);

    printf("Your account is created!");
}
// Function prototype for deposit the amount in the account.

void deposit(struct account customer[], int count)
{
    int customer_id;
    double amount;

    printf("Enter your customer number:");
    scanf("%d", &customer_id);

    int index = find_customer_by_id(customer, count, customer_id); // is used to search for a customer's account using their unique ID.
    if (index != -1)
    {
        printf("Enter the amount you have to deposit:");
        scanf("%lf", &amount);
    }
    if (amount > 0)
    {
        customer[index].check_balance += amount; // is used to add the amount which is already stored and the amount we deposit

        printf("Your amount %lf is deposit successfully in your account\n", amount);
        printf("Your balance is: %.2lf \n", customer[index].check_balance);
    }
    else
    {
        printf("Invalid amount. Deposit amount must be positive");
    }
}

// Function prototype for withdraw cash from the account.

void withdraw(struct account customer[], int count)
{
    int customer_id;
    double amount;
    printf("Enter your customer number:");
    scanf("%d", &customer_id);
    int index = find_customer_by_id(customer, count, customer_id); // is used to search for a customer's account using their unique ID.
    if (index != -1)
    {
        printf("Enter the amount you have to withdraw: ");
        scanf("%lf", &amount);
    }
    if (amount > 0 && customer[index].check_balance >= amount)
    {
        customer[index].check_balance -= amount; // is used to substract the amount which is already stored, when we withdrew the cash from the account.
        printf("Your amount %lf successfully withdraw from your account\n", amount);
        printf("Your balance is: %.2lf \n", customer[index].check_balance);
    }
    else if (amount <= 0)
    {
        printf("Invalid input. Withdraw amount must be positive\n");
    }
    else
    {
        printf("Insufficent balance\n");
    }
}

// Function prototype for check the balanceof the account.

void check_balance(struct account customer[], int count)
{

    int customer_id;

    printf("Enter your customer number:");
    scanf("%d", &customer_id);

    int index = find_customer_by_id(customer, count, customer_id); // is used to search for a customer's account using their unique ID.

    if (index != -1)
    {
        printf("Your balance is: %.2lf\n", customer[index].check_balance);
    }
    else
    {
        printf("Customer id not find, Sorry!");
    }
}

int main()
{
    struct account customer[100];
    int choice, count = 0;

    while (1)
    {
        printf("\n===== Bank Management System =====\n");
        printf("1. Create an account\n");
        printf("2. Deposit\n");
        printf("3. Withdrew\n");
        printf("4. Check Balance\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) // switch function is used to take the input from the user.
        {
        case 1:
            create_account(customer, &count);
            break;
        case 2:
            deposit(customer, count);
            break;
        case 3:
            withdraw(customer, count);
            break;
        case 4:
            check_balance(customer, count);
            break;
        case 5:
            printf("\nExiting... Goodbye!\n");
            return 0;
        default:
            printf("\nInvalid choice! Please try again.\n");
        }
    }

    return 0;
}