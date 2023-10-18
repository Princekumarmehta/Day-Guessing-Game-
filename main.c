#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(NULL)); // Seed the random number generator with the current time

    char *days[] = {"Saturday", "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday"};
    char *months[] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};

    int randomMonth, randomYear, randomDay;

    randomMonth = rand() % 12;                      // Generate a random month between 0 and 11 (0 = January, 1 = February, ..., 11 = December)
    randomYear = rand() % (2023 - 1900 + 1) + 1900; // Generate a random year between 1900 and 2023
    randomDay = rand() % 31 + 1;                    // Generate a random day between 1 and 31

    printf("Welcome to the Day Guessing Game!\n");
    printf("I have generated a random date: %s %d, %d\n", months[randomMonth], randomDay, randomYear);

    int guess, attempts = 0;
    int dayOfWeek; // Declare dayOfWeek here

    do
    {
        printf("Guess the day of the week (0 = Saturday, 1 = Sunday, ..., 6 = Friday): ");

        // Check for valid integer input
        if (scanf("%d", &guess) != 1 || guess < 0 || guess > 6)
        {
            printf("Invalid input. Please enter a number between 0 and 6.\n");
            while (getchar() != '\n')
                ; // Clear the input buffer
            continue;
        }

        attempts++;

        // Apply Gauss's formula to calculate the day of the week
        int A = randomYear;
        int m = (randomMonth - 2 + 12) % 12;
        dayOfWeek = (randomDay + 2 * m + 3 * (m + 1) / 5 + A + A / 4 - A / 100 + A / 400) % 7; // Calculate dayOfWeek here

        if (guess < dayOfWeek)
        {
            printf("Try a later day.\n");
        }
        else if (guess > dayOfWeek)
        {
            printf("Try an earlier day.\n");
        }
    } while (guess != dayOfWeek);

    printf("Congratulations! You guessed the correct day, %s, in %d attempts.\n", days[dayOfWeek], attempts); // Use dayOfWeek here

    return 0;
}
