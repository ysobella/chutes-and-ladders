#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void rollDice(/*int nLower, int nUpper, int nCount, */int nPos)
{

    // nLower = 1;
    // nUpper = 6;
    // nCount = 1;
  
    // // Use current time as 
    // // seed for random generator
    // srand(time(0));

    // int nR;
    // for (nR = 0; nR < nCount; nR++) {
    //     int nNum = (rand() %
    //        (nUpper - nLower + 1)) + nLower;

    //        nPos = 0;
    //        nPos = nPos + nNum;
           
        //     // singular or plural
        //    nNum == 1 ? printf("You moved %d step.", nNum) : printf("You moved %d steps.", nNum); 

        //     //printf("You moved %d step/s.", nNum);
        //     //printf("You are now at tile %d.", nPos);


   // }
  
        srand(time(NULL));
        int nNum = rand() % 6 + 1;
        nNum == 1 ? printf("You moved %d step.\n", nNum) : printf("You moved %d steps.\n", nNum);

        if (nNum == 6)
        {
            printf("Press ENTER to roll the die again.\n");
            getchar();
            rollDice(/*nLower, nUpper, nCount, */nPos);
        }
   

}

int main()
{
    int nLower, nUpper, nCount, nPos;
    int nP1 = 0;
    int nP2 = 0;
    int nP3 = 0;
    int nP4 = 0;

    printf("Press ENTER to roll the die.\n");
    getchar();

    nP1 = nPos;
    rollDice(/*nLower, nUpper, nCount, */nPos);

    return 0;
}