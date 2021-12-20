#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include <stdbool.h>

int random()
{
    int nNum;
    // time as seed for random generator
    srand(time(NULL));
    nNum = rand() % 6 + 1;

    // singular or plural
    nNum == 1 ? printf("You moved %d step.\n", nNum) : printf("You moved %d steps.\n", nNum);

    return nNum;
}

void rollDice()
{
    char cDiceKey; // getchar value

    do // press D to roll the die
    {
        printf("Press D to roll the die.\n");
        cDiceKey = getchar();
        scanf(" %c", &cDiceKey);
        cDiceKey = tolower(cDiceKey);

    } while (cDiceKey != 'd');

}

int playerCount()
{
    int nPlayerCount;
    printf("How many players do you want to play with? [1-3]: ");
    scanf("%d", &nPlayerCount);
    
    while (nPlayerCount < 1 || nPlayerCount > 3) // only accepts 1-3 as input
    {
        printf("Enter a value between 1 and 3 only.\n"); 
        scanf("%d", &nPlayerCount);
    }

    return nPlayerCount;
}

int AI()
{
    char cHA;
    printf("Do you want to play with another human or an AI? [H] or [A]: ");
    scanf(" %c", &cHA);
    cHA = tolower(cHA);

    while (cHA != 'a' && cHA != 'h')
    {
        printf("Invalid input. Please try again: ");
        scanf(" %c", &cHA);
    }

    if (cHA == 'a')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int candl(int nScore) 
{
    switch (nScore)
    {
        // ladders
        case 1: nScore = 38; break;
        case 4: nScore = 14; break;
        case 8: nScore = 30; break;
        case 21: nScore = 42; break;
        case 28: nScore = 65; break;
        case 50: nScore = 67; break;
        case 71: nScore = 92; break;
        case 88: nScore = 100; break;

        // chutes
        case 17: nScore = 3; break;
        case 32: nScore = 10; break;
        case 36: nScore = 6; break;
        case 48: nScore = 26; break;
        case 62: nScore = 18; break;
        case 87:  nScore = 24; break;
        case 95: nScore = 56; break;
        case 97: nScore = 78; break;

        default:
        nScore = nScore;
    }
    
    return nScore;
}

void game (int *nPos, int nAI, bool bP1Turn)
{
    if (nAI == 0 || bP1Turn == true)
    {
        rollDice();
    }
    else
    {
        char c = getchar();
    }

    int nDice = random();
    *nPos = *nPos + nDice; 
    // score exceeds 100
    if (*nPos > 100)
    {
        *nPos -= (*nPos - 100) * 2;
    }
    printf("You are currently on tile %d\n\n", *nPos);
            
    // chutes and ladders
    int nCandl = candl(*nPos); // variable for the candl function

    if (nCandl > *nPos)
    {
        printf("You reached a ladder! Moving up to %d\n", nCandl);
    }
    else if (nCandl < *nPos)
    {
        printf("You landed on a chute! Going down to %d\n", nCandl);
    }
            
    *nPos = nCandl;
            

    // rolling the die again (6)
    while (nDice == 6 && *nPos != 100) 
    {
        //char c = getchar();
        printf("\nYou rolled a 6! You get to roll the die again.\n");

        if (nAI == 0 || bP1Turn == true)
        {
            rollDice();
        }
        else
        {
            char c = getchar();
        }

        nDice = random();
        *nPos = *nPos + nDice; 
        // score exceeds 100
        if (*nPos > 100)
        {
            *nPos -= (*nPos - 100) * 2;
        }
        printf("You are currently on tile %d\n\n", *nPos);

        // chutes and ladders
        nCandl = candl(*nPos); // variable for the candl function

        //printf("[TEST] nCandl = %d\n", nCandl); //[TEST]

        if (nCandl > *nPos)
        {
            printf("You reached a ladder! Moving up to %d\n", nCandl);
        }
        else if (nCandl < *nPos)
        {
            printf("You landed on a chute! Going down to %d\n", nCandl);
        }
                
        *nPos = nCandl;
            
    }
}

void mainGame(int nP1, int nP2, int nP3, int nP4, int nPC, int nAI) // recursive
{
    bool bP1Turn, bP2Turn, bP3Turn, bP4Turn; // player turn

    bP1Turn = true;

    // ----- PLAYER 1 ------
    if (bP1Turn == true)
    {
        printf("\n\n\nP L A Y E R  1\n");

        game (&nP1, nAI, bP1Turn);

        if (nP1 == 100)
        {
            bP1Turn = false;
            printf("\n\nCongratulations Player 1! You won the game!\n\n");
            return;
        }
        else
        {
            bP1Turn = false;
            bP2Turn = true;
        }
    }

    // ----- PLAYER 2 ------
    if (bP2Turn == true)
    {
        printf("\n\n\nP L A Y E R  2\n");

        game (&nP2,  nAI, bP1Turn);

        if (nP2 == 100)
        {
            bP1Turn = false;
            bP2Turn = false;
            bP3Turn = false;
            bP4Turn = false;
            printf("\n\nCongratulations Player 2! You won the game!\n\n");
            return;
        }
        else
        {
            if (nPC > 1)
            {
                bP2Turn = false;
                bP3Turn = true;
            }
            else
            {
                bP2Turn = false;
                mainGame(nP1, nP2, nP3, nP4, nPC, nAI);
            }
        }

    }

    // ----- PLAYER 3 ------
    if (bP3Turn == true)
    {
        printf("\n\n\nP L A Y E R  3\n");

        game (&nP3, nAI, bP1Turn);

        if (nP3 == 100)
        {
            bP1Turn = false;
            bP2Turn = false;
            bP3Turn = false;
            bP4Turn = false;
            printf("\n\nCongratulations Player 3! You won the game!\n\n");
            return;
        }
        else
        {
            if (nPC > 2)
            {
                bP4Turn = true;
                bP3Turn = false;
            }
            else
            {
                bP3Turn = false;
                mainGame(nP1, nP2, nP3, nP4, nPC, nAI);
            }
        }

    }

    // ----- PLAYER 4 ------
    if (bP4Turn == true)
    {
        printf("\n\n\nP L A Y E R  4\n");

        game (&nP4, nAI, bP1Turn);

        if (nP4 == 100)
        {
            bP1Turn = false;
            bP2Turn = false;
            bP3Turn = false;
            bP4Turn = false;
            printf("\n\nCongratulations Player 4! You won the game!\n\n");
            return;
            
        }
        else
        {
            bP4Turn = false;
            mainGame(nP1, nP2, nP3, nP4, nPC, nAI);
        }

    }

}

int main()
{
    struct players // struct for player data
    {
        int nPos;
        char *cName;
    } ;

    int nNum; // declaring variable of dice
    struct players P1, P2, P3, P4; // declaration for structures for player progress
    P1.nPos = 0;
    P2.nPos = 0;
    P3.nPos = 0;
    P4.nPos = 0;
    
    P1.cName = "Player 1";
    P2.cName = "Player 2";
    P3.cName = "Player 3";
    P4.cName = "Player 4";

    int nPC = playerCount(); // getting return value of playerCount function

    int nAI = AI(); // returns 1 or 0

    mainGame(P1.nPos, P2.nPos, P3.nPos, P4.nPos, nPC, nAI);

    return 0;
}