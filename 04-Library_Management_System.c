#include <stdio.h>
#include <string.h>

struct book
{
    int ISBN;
    char title[50];
    char author[50];
    int available; // 1 = available, 0 = issued
};

void addBook(struct book library[], int *count)
{
    printf("\nEnter Book ISBN: ");
    scanf("%d", &library[*count].ISBN);

    printf("Enter Book Title: ");
    scanf(" %[^\n]", library[*count].title); // scanf(" %[^\n]", ...) → ye syntax string ke andar spaces bhi accept karta hai (jaise "Atomic Habits"t

    printf("Enter Author Name: ");
    scanf(" %[^\n]", library[*count].author);

    library[*count].available = 1; // by default available
    (*count)++;

    printf("\nBook added successfully!\n");
}

void displayBooks(struct book library[], int count)
{
    printf("\n Nothing \n");
    for (int i = 0; i < count; i++)
    {
        printf("ISBN: %d | Title: %s | Author: %s | Status: %s\n",
               library[i].ISBN,
               library[i].title,
               library[i].author,
               (library[i].available ? "Available" : "Issued")); // available ? "Available" : "Issued" → ternary operator use kiya gaya hai → agar available=1 hai toh "Available", warna "Issued".
    }
}

void searchBook(struct book library[], int count)
{
    int code, found = 0;
    printf("\nEnter ISBN to search: ");
    scanf("%d", &code);

    for (int i = 0; i < count; i++)
    {
        if (library[i].ISBN == code)
        {
            printf("\nBook Found!\n");
            printf("ISBN: %d | Title: %s | Author: %s | Status: %s\n",
                   library[i].ISBN,
                   library[i].title,
                   library[i].author,
                   (library[i].available ? "Available" : "Issued"));
            found = 1;
            break;
        }
    }
    if (!found)
        printf("\n Book not found!\n");
}

int main()
{
    struct book library[100];
    int choice, count = 0;

    while (1)
    {
        printf("\n===== Library Management System =====\n");
        printf("1. Add Book\n");
        printf("2. Display All Books\n");
        printf("3. Search Book by ISBN\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            addBook(library, &count);
            break;
        case 2:
            displayBooks(library, count);
            break;
        case 3:
            searchBook(library, count);
            break;
        case 4:
            printf("\nExiting... Goodbye!\n");
            return 0;
        default:
            printf("\nInvalid choice! Please try again.\n");
        }
    }

    return 0;
}
