//define a maxNumber int variable 
//define a masterMaxNumber int variable
//define a randInt variable 
//define showMenu boolean

//define a currentMenuVal int variable, checks what the user has chosen based on 
//the 3 possible menu options 

//define a guess int variable, holds the user's guessed number 

//              [IF OPTION 1 IS SELECTED]
//prompt the user to enter their guessing number 

//  ** IF GUESS == 'q' then:
//      -showMenu == true
//      -CONTINUE (the statement like break)

//check if guess == randInt: if so then:
//      -print congradulations
//      -showMenu = true
//      -Loop

//if guess != randInt && guess < randInt:
//      -print that the guess is too low 
//      -keep randInt the same
//      -keep currentMenuVal the same

//if guess != randInt && guess > randInt:
//      -print that the guess is too high 
//      -keep randInt the same
//      -keep currentMenuVal the same



//              [IF OPTION 2 IS SELECTED]
// print out an enter number statement
// prompt the user for their number and store it in guess
// evaluate if that number is > masterMaxNumber and currentMenuVal = true
// if not then pass it to maxNumber 
// if it is then:
//      -print error
//      -showMenu = false
//      -currentMenuVal stays the same 



//              [IF OPTION 3 IS SELECTED]
// set currentMenuVal to 3 and call CONTINUE (let the while loop break itself)

//use a while loop to determine if the program should end 

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include "NumberGuessingGame.h"

int maxNumber = 50;
int randInt = 31;
char guess[100];
int currentMenuVal = 0;

bool showMenu = true;

 void printMenu()
{
    if (showMenu == true)
    {
        printf("Type the number of a menu option below...\n");
        printf("\nMenu Options:\n");
        printf("[1]: Play the game\n[2]: Set max number\n[3]: Quit\n");

        printf("\nEnter a number: ");
        scanf("%i", &currentMenuVal);
    }
}

int main(int argc, char *argv[]) 
{
    while (currentMenuVal != 3)
    {
        printMenu();

        switch (currentMenuVal)
        {
            case 1:
                if (currentMenuVal == 1)
                {
                    showMenu = false;

                    char temp[50];

                    FILE *filePointer;
                    filePointer = fopen("maxNumberSave.txt", "r");

                    fgets (temp, 50, filePointer );

                    maxNumber = atoi(temp);

                    printf("Enter a guessing number: ");
                    scanf("%s", &guess);

                    printf("Guess: %s, %i, %f\n", guess, atoi(guess), atoi(guess));

                    if (strcmp(guess, "q") == 0)
                    {
                        printf("\n~ Returning to menu ~\n\n");
                        showMenu = true;
                        currentMenuVal = 0;
                        continue;
                    }

                    if (atoi(guess) == randInt)
                    {
                        printf("\n ~ ! You guessed correctly ! ~ \n\n");
                        showMenu = true;
                        continue;
                    }

                    if (atoi(guess) < randInt)
                    {
                        printf("Your guess was too low...\n");
                    }

                     if (atoi(guess) > randInt)
                    {
                        printf("Your guess was too high...\n");
                    }
                }
            case 2:
                if (currentMenuVal == 2)
                {
                    showMenu = false;

                    FILE *filePointer ; 
                    filePointer = fopen("maxNumberSave.txt", "w");

                    printf("\nEnter a maximum number: \n");
                    scanf("%i", &maxNumber);

                    if (maxNumber < 0)
                    {
                        printf("Number must be greater than 0.");
                    }else{
                        char strMaxNumber[20];

                        sprintf(strMaxNumber, "%d", maxNumber);
                        fputs(strMaxNumber, filePointer);

                        fclose(filePointer);

                        showMenu = true;
                        continue;
                    }
                }
        }

    }


    printf("Thank you for playing!");
}