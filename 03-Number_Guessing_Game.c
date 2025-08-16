#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(0));// If you run the program multiple times, rand() will generate the same sequence of numbers each time.
                   // To avoid this, we use: srand(time(0));

    int random_number = (rand() % 100) + 1; // It gernates the rendom number between (1 to 100)
    int guessed_number;
    int no_of_guesses = 0;
    // int limit;
    printf("You have only 10 guesses to guess the number,so please play carefully\n");
    
        do
        {
            printf("Guess the number:");
            scanf("%d", &guessed_number);
            if (guessed_number > random_number)
            {
                printf("The number you guessed is to large,please enter small number:\n");
            }
            else if (guessed_number < random_number)
            {
                printf("The number you guessed is to small,please enter large number\n");
            }
            else
            {
                printf("Congratulation!\n", no_of_guesses);
            }
           no_of_guesses++;
            
            
        } while (guessed_number != random_number);
        printf("The number you guess is: %d in %d guesses", guessed_number, no_of_guesses);

    return 0;
}