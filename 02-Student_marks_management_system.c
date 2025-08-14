#include <stdio.h>
#include <string.h>

struct student
{
    int roll_number;
    float percentage, total;
    char name[30], grade[5];
}; // semicolon is important

int main()
{
    int seat_number;
    struct student s1, s2, s3;
    printf("Enter you roll number: ");
    scanf("%d", &seat_number);

    if (seat_number == 100)
    {
        strcpy(s1.name, "Bhupendra sharma");
        strcpy(s1.grade, "A");
        s1.roll_number = 100;
        s1.percentage = 87.5;
        s1.total = 525;
        printf("Your name is: %s\nYour roll number is: %d\nYour percentage is: %.2f\nYour total marks outoff 600 is: %.2f\n", s1.name, s1.roll_number, s1.percentage, s1.total);
        printf("Congratulation! you are pass, with %s grade.", s1.grade);
    }
    else if (seat_number == 101)
    {
        strcpy(s2.name, "Chotu sharma");
        strcpy(s2.grade, "F");
        s2.roll_number = 101;
        s2.percentage = 30;
        s2.total = 180;
        printf("Your name is: %s\nYour roll number is: %d\nYour percentage is: %.2f\nYour total marks outoff 600 is: %.2f\n", s2.name, s2.roll_number, s2.percentage, s2.total);
        printf("Sorry! you are fail batter luck next time and your grade is: %s.", s2.grade);
    }
    else if (seat_number == 102)

    {
        strcpy(s3.name, "Raj sharma");
        strcpy(s3.grade, "B+");
        s3.roll_number = 102;
        s3.percentage = 72.5;
        s3.total = 435;
        printf("Your name is:%s\nYour roll number is:%d\nYour percentage is: %.2f\nYour total marks outoff 600 is: %.2f\n", s3.name, s3.roll_number, s3.percentage, s3.total);
        printf("Congratulation! you are pass, with %s grade.", s3.grade);
    }
    else
        printf("You enter invalid roll number,Sorry!");
    return 0;
}