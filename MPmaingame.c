#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int rollDice(int nNum)
{

        // time as seed for random generator
        srand(time(NULL));
        nNum = rand() % 6 + 1;

        // singular or plural
        nNum == 1 ? printf("You moved %d step.\n", nNum) : printf("You moved %d steps.\n", nNum);

    return nNum;
}

int playerCount(int nPlayerCount)
{
    nPlayerCount;
    printf("How many players? (1-4)\n");
    scanf("%d", &nPlayerCount);
    
    while (nPlayerCount < 1 || nPlayerCount > 4) // only accepts 1-4 as input //ERROR?
    {
        printf("Enter a value between 1 and 4 only.\n"); 
        scanf("%d", &nPlayerCount);
    }

    return nPlayerCount;
}

void maingame()
{
    struct pos // structure for players' positions
    {
        int nPos;
    } ;

    int nNum; // declaring variable of dice
    struct pos P1, P2, P3, P4; // declaration for structures for player progress
    P1.nPos = 0;
    P2.nPos = 0;
    P3.nPos = 0;
    P4.nPos = 0;

    int nPlayerCount; // declaring variable of number of players from playerCount function
    int nPC = playerCount(nPlayerCount); // getting return value of playerCount function

    if (nPC == 1) // for pseudo-AI players
    {
        int nAI;
        printf("You will play with an AI.\n");
        printf("How many AI players do you want to play with? (1-3)\n");
        scanf("%d", &nAI);

        while (nAI < 1 || nAI > 3) // only accepts 1-3 as input for AI players
        {
            printf("Invalid input. Choose between 1 and 3.\n");
            scanf("%d", &nAI);
        } 
    }

    else
    {
        while (P1.nPos !=100 && P2.nPos !=100 && P3.nPos !=100 && P4.nPos !=100)
        {
            // ----- PLAYER 1 ------
            printf("P L A Y E R  1\n");

            char cDiceKey; // declaring variable for rolling the dice

            do // press D to roll the die
            {
                printf("Press D to roll the die.\n");
                cDiceKey = getchar();
                scanf(" %c", &cDiceKey);

            } while (cDiceKey != 'd' && cDiceKey != 'D');

            int nDice = rollDice(nNum);
            P1.nPos = P1.nPos + nDice; 
            // score exceeds 100
            if (P1.nPos > 100)
            {
                P1.nPos -= (P1.nPos - 100) * 2;
            }
            printf("You are currently on tile %d\n\n", P1.nPos);
            

            // rolling the die again (6)
            while (nDice == 6) 
            {
                printf("You rolled a 6! You get to roll the die again.\n");

                do // press D to roll the die
                {
                    printf("Press D to roll the die.\n");
                    cDiceKey = getchar();
                    scanf(" %c", &cDiceKey);

                } while (cDiceKey != 'd' && cDiceKey != 'D');

                nDice = rollDice(nNum);
                P1.nPos = P1.nPos + nDice; 
                // score exceeds 100
                if (P1.nPos > 100)
                {
                    P1.nPos -= (P1.nPos - 100) * 2;
                }
                printf("You are currently on tile %d\n\n", P1.nPos);

            
            }
            
            
            // ------ PLAYER 2 -------
            printf("P L A Y E R  2\n");

            do // press D to roll the die
            {
                printf("Press D to roll the die.\n");
                cDiceKey = getchar();
                scanf(" %c", &cDiceKey);

            } while (cDiceKey != 'd' && cDiceKey != 'D');

            nDice = rollDice(nNum);
            P2.nPos = P2.nPos + nDice;
            // score exceeds 100 
            if (P2.nPos > 100)
            {
                P2.nPos -= (P2.nPos - 100) * 2;
            }
            printf("You are currently on tile %d\n\n", P2.nPos);


            // rolling the die again (6)
            while (nDice == 6) 
            {
                printf("You rolled a 6! You get to roll the die again.\n");

                do // press D to roll the die
                {
                    printf("Press D to roll the die.\n");
                    cDiceKey = getchar();
                    scanf(" %c", &cDiceKey);

                } while (cDiceKey != 'd' && cDiceKey != 'D');

                nDice = rollDice(nNum);
                P2.nPos = P2.nPos + nDice; 
                // score exceeds 100
                if (P2.nPos > 100)
                {
                    P2.nPos -= (P2.nPos - 100) * 2;
                }
                printf("You are currently on tile %d\n\n", P2.nPos);

            }
            

            if (nPC > 2)
            {
                // ------ PLAYER 3 -------
                printf("P L A Y E R  3\n");

                do // press D to roll the die
                {
                    printf("Press D to roll the die.\n");
                    cDiceKey = getchar();
                    scanf(" %c", &cDiceKey);

                } while (cDiceKey != 'd' && cDiceKey != 'D');

                nDice = rollDice(nNum);
                P3.nPos = P3.nPos + nDice;
                // score exceeds 100
                if (P3.nPos > 100)
                {
                    P3.nPos -= (P3.nPos - 100) * 2;
                }
                printf("You are currently on tile %d\n\n", P3.nPos);


                // rolling the die again (6)
                while (nDice == 6) 
                {
                    printf("You rolled a 6! You get to roll the die again.\n");

                    do // press D to roll the die
                    {
                        printf("Press D to roll the die.\n");
                        cDiceKey = getchar();
                        scanf(" %c", &cDiceKey);

                    } while (cDiceKey != 'd' && cDiceKey != 'D');

                    nDice = rollDice(nNum);
                    P3.nPos = P3.nPos + nDice; 
                    // score exceeds 100
                    if (P3.nPos > 100)
                    {
                        P3.nPos -= (P3.nPos - 100) * 2;
                    }
                    printf("You are currently on tile %d\n\n", P3.nPos);

                }
            

                if (nPC == 4)
                {
                    // ------ PLAYER 4 -------
                    printf("P L A Y E R  4\n");

                    do // press D to roll the die
                    {
                        printf("Press D to roll the die.\n");
                        cDiceKey = getchar();
                        scanf(" %c", &cDiceKey);

                    } while (cDiceKey != 'd' && cDiceKey != 'D');

                    nDice = rollDice(nNum);
                    P4.nPos = P4.nPos + nDice;
                    // score exceeds 100
                    if (P4.nPos > 100)
                    {
                        P4.nPos -= (P4.nPos - 100) * 2;
                    }
                    printf("You are currently on tile %d\n\n", P4.nPos);


                    // rolling the die again (6)
                    while (nDice == 6) 
                    {
                        printf("You rolled a 6! You get to roll the die again.\n");

                        do // press D to roll the die
                        {
                            printf("Press D to roll the die.\n");
                            cDiceKey = getchar();
                            scanf(" %c", &cDiceKey);

                        } while (cDiceKey != 'd' && cDiceKey != 'D');

                        nDice = rollDice(nNum);
                        P4.nPos = P4.nPos + nDice; 
                        // score exceeds 100
                        if (P4.nPos > 100)
                        {
                            P4.nPos -= (P4.nPos - 100) * 2;
                        }
                        printf("You are currently on tile %d\n\n", P4.nPos);


                    }
                    

                }

            }


        }
        // player gets to 100
        if (P1.nPos == 100)
        {
            printf("\n\nCongratulations Player 1! You won the game!\n\n");
        }

        else if (P2.nPos == 100)
        {
            printf("\n\nCongratulations Player 2! You won the game!\n\n");
        }

        else if (P3.nPos == 100)
        {
            printf("\n\nCongratulations Player 3! You won the game!\n\n");
        }

        else
        {
            printf("\n\nCongratulations Player 4! You won the game!\n\n");
        }

    }

}

int main()
{
    maingame();

    return 0;
}
