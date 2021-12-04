#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct pos
{
    int nPos;
} ;

int rollDice(int nNum)
{

        // time as seed for random generator
        srand(time(NULL));
        nNum = rand() % 6 + 1;

        // singular or plural
        nNum == 1 ? printf("You moved %d step.\n", nNum) : printf("You moved %d steps.\n", nNum);
/*
        // position increment
        nPos = 0;
        nPos += nNum;
        printf("You are currently on tile %d.\n", nPos);
*/
/*        // die is rolled again
        if (nNum == 6) //ERROR
        {
            printf("Press ENTER to roll the dice again.\n");
            getchar();
            rollDice(nPos);
        }
*/
        
    return nNum;
}

void mainGame()
{
    int nLower, nUpper, nCount, nNum;
    
    struct pos P1, P2, P3, P4;
    P1.nPos = 0;
    P2.nPos = 0;
    P3.nPos = 0;
    P4.nPos = 0;

    while (P1.nPos !=100 && P2.nPos !=100 && P3.nPos !=100 && P4.nPos !=100)
    {
        // ----- PLAYER 1 ------
        printf("P L A Y E R  1\n");

        char cDiceKey;

        do // press 1 to roll the die
        {
            printf("Press 1 to roll the die.\n");
            cDiceKey = getchar();
            scanf(" %c", &cDiceKey);

        } while (cDiceKey != '1');

        // nP1 = nPos;
        int nDice = rollDice(nNum);
        P1.nPos = P1.nPos + nDice; //[ERROR]
        printf("You are currently on tile %d\n", P1.nPos);

        // system ('cls'); [ERROR]
        
        // ------ PLAYER 2 -------
        printf("P L A Y E R  2\n");

        do // press 1 to roll the die
        {
            printf("Press 1 to roll the die.\n");
            cDiceKey = getchar();
            scanf(" %c", &cDiceKey);

        } while (cDiceKey != '1');

        // nP1 = nPos;
        nDice = rollDice(nNum);
        P2.nPos = P2.nPos + nDice; //[ERROR]
        printf("You are currently on tile %d\n", P2.nPos);

        // system ('cls'); [ERROR]


    }
    

}

int main()
{
    
    int nPlayerCount;
    printf("How many players? (1-4)\n");
    scanf("%d", &nPlayerCount);
    
    while (nPlayerCount < 1 || nPlayerCount > 4) // only accepts 1-4 as input //ERROR?
    {
        printf("Enter a value between 1 and 4 only.\n"); 
        scanf("%d", &nPlayerCount);
    }

    
    if (nPlayerCount == 1) // playing with pseudo-AI player
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

        mainGame();
    }
    else if (nPlayerCount > 1) // human players
    {
        
        mainGame();

    }


    return 0;
}