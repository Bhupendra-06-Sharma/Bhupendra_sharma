#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct managementsystem
{
    char name[50];
    int productid;
    int quantity;
    float unitprice;
};

// Add product function prototype
void addproduct(struct managementsystem **product, int *count)
{
    *product = realloc(*product, (*count + 1) * sizeof(struct managementsystem));
    if (*product == NULL)
    {
        printf("Memory allocation is failed\n");
        return;
    }
    printf("Enter product name:");
    scanf("%s", &(*product)[*count].name);
    printf("Enter Product id as you want:");
    scanf("%d", &(*product)[*count].productid);
    printf("Enter the Quantity of your product:");
    scanf("%d", &(*product)[*count].quantity);
    printf("Enter the Price per unit of product:");
    scanf("%f", &(*product)[*count].unitprice);
    (*count)++;

    printf("Your product is added sucessfully!");
}

// View product function prototype
void viewproduct(struct managementsystem *product, int count)
{
    if (count == 0)
    {
        printf("Sorry!,No record is found on this product id");
        return;
    }
    int id, found = 0; // when found = 0 product not found, found = 1 product is found
    printf("Enter the ID of the product:");
    scanf("%d", &id);
    for (int i = 0; i < count; i++)
    {
        if (product[i].productid == id)
        {
            printf("\n----Viewing product---\n");
            printf("Product ID: %d | Name of the product: %s | Quantity of the product: %d | Price per unit of the product: %f",
                   product[i].productid,
                   product[i].name,
                   product[i].quantity,
                   product[i].unitprice);
            found = 1;
            break;
        }
    }
}

// Update product function prototype
void update(struct managementsystem *product, int count)
{
    if (count == 0)
    {
        printf("Sorry!,No record is found on this product id");
        return;
    }
    int id, found = 0;
    printf("Enter the ID of the product:");
    scanf("%d", &id);
    for (int i = 0; i < count; i++)
    {
        if (product[i].productid == id)
        {
            printf("Enter new name of your product:");
            scanf("%s", &product[i].name);
            printf("Enter new Product Id:");
            scanf("%d", &product[i].productid);
            printf("Enter new quantity of your product:");
            scanf("%d", &product[i].quantity);
            printf("Enter new price per unit of the product:");
            scanf("%f", &product[i].unitprice);
            printf("Updated successfully\n");
            found = 1;
            break;
        }
    }
    if (!found)
    {
        printf("Sorry! This product ID %d is not found", id);
    }
}

// Calucation of the value of the product function prototype
void calucation(struct managementsystem *product, int count)
{

    if (count == 0)
    {
        printf("Sorry!,No record is found on this product id");
        return;
    }
    int id, found = 0;
    printf("Enter the ID of the product:");
    scanf("%d", &id);
    for (int i = 0; i < count; i++)
    {
        if (product[i].productid == id)
        {
            float value = product[i].quantity * product[i].unitprice;
            printf("The value of the product is: %.2f", value);
            found = 1;
            break;
        }
    }
}
int main()
{
    struct managementsystem *product = NULL;
    int choice, count = 0;

    do
    {
        printf("\n---Mini Inventory Management System---\n");
        printf("01.Add new product\n");
        printf("02.View product\n");
        printf("03.Update product\n");
        printf("04.Calulate value of product\n");
        printf("05.Save/Exit\n");

        printf("Enter your choice:");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            addproduct(&product, &count);
            break;
        case 2:
            viewproduct(product, count);
            break;
        case 3:
            update(product, count);
            break;
        case 4:
            calucation(product, count);
            break;
        case 5:
            printf("Exiting successfully");
            break;

        default:
            printf("Invalid choice");
            break;
        }

    } while (choice != 5);

    free(product);

    return 0;
}