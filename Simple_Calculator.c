#include <stdio.h>
#include <math.h>

int main()
{
    float num1, num2;
    char operators;

    printf("Input:\n");
    scanf("%f", &num1);
    scanf("%f", &num2);

    printf("Input the operator(+,-,*,/):");
    scanf(" %c", &operators);

    switch (operators)
    {
    case '+':
        printf("Result %.2f\n", num1 + num2);
        break;

    case '-':
        printf("Result %.2f\n", num1 - num2);
        break;
    case '*':
        printf("Result %.2f\n", num1 * num2);
        break;
    case '/':
        if (num2 == 0)
        {
            printf("This division is invalid please write the correct value of num2\n");
            break;
        }
        else
        {
            printf("Result %.3f\n", num1 / num2);
            break;
        }
    case '%':
        if (num2 != 0)
        {
            printf("Result %d\n", (int)num1 % (int)num2); // In Modelus function we cannot use float data type.
            break;
        }
        else
        {
            printf("Error: Modelus by zero in no allowed \n");
            break;
        }

    default:
        printf("Invalid operator");
        break;
    }

    return 0;
}