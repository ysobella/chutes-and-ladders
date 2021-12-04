#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
   
   int nPlayerCount;
   char cInput; // options to start or read mechanics

    do 
    {
        printf("C H U T E S   A N D   L A D D E R S\n\n"); // title
        printf("Press M to read the mechanics\n\n");
        printf("OR\n\n");
        printf("Press S to start the game\n\n");
        scanf(" %c", &cInput);

            switch(cInput)
            {
                case 's' :
                printf("start\n");
                break;

                case 'S' :
                printf("start\n");
                break;

                case 'm' :
                printf("MECHANICS\n");
                printf("1. The game can be played by 2-4 human players, but you can also choose to play with a pseudo-AI player.\n");
                printf("2. If a 6 is rolled in the vitual die, the same player will get to roll the die again.\n");
                printf("3. Players take turns rolling a single die to move their token by the number of squares indicated by the die rolled.\n");
                printf("4. When a player's token lands on the bottom of a ladder, the player moves up to the upper part of the ladder. \n");
                printf("5. If the player lands on the upper part of a chute, the token must be moved down to the bottom of the chute. \n");
                printf("6. The first player who brings their token to the last square of the track wins the game. \n\n");

                printf("Press S to continue.\n");
                scanf(" %c", &cInput);

                while (cInput != 'S' && cInput != 's') // option to start game after reading mechanics
                {
                    printf("Invalid input. Please try again.\n"); //[ERROR] double printf at first input
                    scanf("%c", &cInput);
                }

                printf("START"); //insert maingame function
                break;

                case 'M' :
                printf("MECHANICS\n");
                printf("1. The game can be played by 2-4 human players, but you can also choose to play with a pseudo-AI player.\n");
                printf("2. If a 6 is rolled in the vitual die, the same player will get to roll the die again.\n");
                printf("3. Players take turns rolling a single die to move their token by the number of squares indicated by the die rolled.\n");
                printf("4. When a player's token lands on the bottom of a ladder, the player moves up to the upper part of the ladder. \n");
                printf("5. If the player lands on the upper part of a chute, the token must be moved down to the bottom of the chute. \n");
                printf("6. The first player who brings their token to the last square of the track wins the game. \n\n");

                printf("Press S to continue.\n");
                scanf(" %c", &cInput);

                while (cInput != 'S' && cInput != 's') // option to start game after reading mechanics
                {
                    printf("Invalid input. Please try again.\n"); //ERROR double printf at first input
                    scanf("%c", &cInput);
                }

                printf("START"); //insert maingame function
                break;
                
                default:
                printf("Invalid input. Press any key and try again.\n");
                
            }

        scanf("%c", &cInput); 
        getchar();


    } while (cInput != 's' && cInput != 'm' && cInput != 'S' && cInput != 'M');

   return 0;

}
