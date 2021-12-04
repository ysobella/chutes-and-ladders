#include <stdio.h>

int main()
{
 /*   
    for (int rows = 100; rows > 95; rows--)
    {
        for (int columns = 100; columns > 90; columns--)
        {
            printf(" [%d] ", columns);
        }
        printf("\n");
        printf("\n");

    }
    */
   
   /*
   for(int nRow10=100, nRow9=81, nRow8=80, nRow7=61, nRow6=60, nRow5=41, nRow4=40, nRow3=21, nRow2=20, nRow1=1; 
   nRow10>90, nRow9<91, nRow8>70, nRow7<71, nRow6>50, nRow5<51, nRow4>30, nRow3<31, nRow2>10, nRow1<11; nRow10++)
   {
       printf(" [%d] ", nRow10);
       printf("\n");
       printf("\n");


   }
   
    */
   
   for (int nCol = 1; nCol > 0; nCol--)
   {
       for (int nRow10 = 100; nRow10 > 90; nRow10--)
       {
           printf("[%d]  ", nRow10);
       }
           printf("\n\n");

       for (int nRow9 = 81; nRow9 < 91; nRow9++)
       {
           printf(" [%d] ", nRow9);
       }
           printf("\n\n");
       for (int nRow8 = 80; nRow8 > 70; nRow8--)
       {
           printf(" [%d] ", nRow8);
       }
           printf("\n\n");
           
       for (int nRow7 = 61; nRow7 < 71; nRow7++)
       {
           printf(" [%d] ", nRow7);
       }
           printf("\n\n");
           
       for (int nRow6 =60; nRow6 > 50; nRow6--)
       {
           printf(" [%d] ", nRow6);
       }
           printf("\n\n");
           
       for (int nRow5 = 41; nRow5 < 51; nRow5++)
       {
           printf(" [%d] ", nRow5);
       }
           printf("\n\n");
           
       for (int nRow4 = 40; nRow4 > 30; nRow4--)
       {
           printf(" [%d] ", nRow4);
       }
           printf("\n\n");
            

       for (int nRow3 = 21; nRow3 < 31; nRow3++)
       {
           printf(" [%d] ", nRow3);
       }
           printf("\n\n");
            

       for (int nRow2 = 20; nRow2 > 10; nRow2--)
       {
           printf(" [%d] ", nRow2);
       }
           printf("\n\n");

       for (int nRow1 = 1; nRow1 < 11; nRow1++)
       {
           printf(" [%d]  ", nRow1);
       }
           printf("\n\n");

   }

    return 0;
}