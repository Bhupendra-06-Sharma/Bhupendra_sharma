#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student
{
    char name[50];
    int roll_no;
    float marks;
};

// This is Add student function prototype
void addstudent(struct Student **student, int *count)
{
    *student = realloc(*student, (*count + 1) * sizeof(struct Student));
    if (*student == NULL)
    {
        printf("Memory allocation is failed\n");
        exit(1);
    }
    printf("Enter your the roll number:");
    scanf("%d", &(*student)[*count].roll_no);
    printf("Enter Your name:");
    scanf("%s", &(*student)[*count].name);
    printf("Enter your marks:");
    scanf("%f", &(*student)[*count].marks);
    (*count)++;

    printf("Your information is added successfully");
}

// This is Display Student information function prototype
void diplaystudent(struct Student *student, int count)
{

    if (count == 0)
    {
        printf("No recode is found");
        return;
    }
    printf("\n---Student Record---\n");
    for (int i = 0; i < count; i++)
    {
        printf("Name: %s | Roll Number: %d | Marks: %f",
               student[i].name,
               student[i].roll_no,
               student[i].marks);
    }
}

// This Serch student function prototype
void serchstudent(struct Student *student, int count)
{
    if (count == 0)
    {
        printf("No record found\n");
        return;
    }
    int roll;
    printf("Enter your roll number:");
    scanf("%d", &roll);

    for (int i = 0; i < count; i++)
    {
        if (student[i].roll_no == roll)
        {
            printf("Record is found Roll Number: %d | Name: %s | Marks: %.2f\n",
                   student[i].roll_no,
                   student[i].name,
                   student[i].marks);
        }
        if (student[i].roll_no != roll)
        {
            printf("Entered %d Roll number is not found sorry!", roll);
        }
    }
}

// This is Update,Student information funtion prototype
void updated(struct Student *student, int count)
{
    if (count == 0)
    {
        printf("No record is found");
    }
    int roll, found = 0; // when found = 0 student is not found, found = 1 student is found
    printf("Enter your roll number");
    scanf("%d", &roll);
    for (int i = 0; i < count; i++)
    {
        if (student[i].roll_no == roll)
        {
            printf("Update your Name:");
            scanf("%s", &student[i].name);
            printf("Update your Roll number:");
            scanf("%d", &student[i].roll_no);
            printf("Update your marks:");
            scanf("%f", &student[i].marks);
            printf("Record updated successfully\n");
            found = 1;
            break;
        }
        
    }
    if (!found)
    {
        printf("Sorry! This roll number is not find");
    }
    
}

// This is Delete Student information function prototype
void delete(struct Student **student, int *count)
{
    if (*count == 0)
    {
        printf("No record is found for delete");
    }
    int roll;
    printf("Enter your roll number");
    scanf("%d", &roll);
    for (int i = 0; i < *count; i++)
    {
        if ((*student)[i].roll_no == roll)
        {
            for (int j = i; j < *count - 1; j++)
            {
                (*student)[j] = (*student)[j + 1];
            }
            (*count)--;
            *student = realloc(*student, (*count) * sizeof(struct Student));
            printf("Record of the student is deleted successfully");
        }
    }
}
int main()
{
    struct Student *student = NULL;
    int choice, count = 0;

    do
    {
        printf("\n----Dynamic Student Record system----\n");
        printf("1. Add Student\n");
        printf("2. Display Student\n");
        printf("3. Search Student\n");
        printf("4. Update Student profile\n");
        printf("5. Delete Student information\n");
        printf("6. Exit!\n");

        printf("Enter your choice");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            addstudent(&student, &count);
            break;
        case 2:
            diplaystudent(student, count);
            break;
        case 3:
            serchstudent(student, count);
            break;
        case 4:
            updated(student, count);
            break;
        case 5:
            delete(&student, &count);
            break;
        case 6:
            printf("Exiting successfully");
            break;

        default:
            printf("Please enter the valid choice");
            break;
        }
    } while (choice != 6);

    free(student);
    return 0;
}