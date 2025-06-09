#include <stdio.h>

int main() {

 float mtr[12][12];
 int i, j;
 char option;
 int columnPosition;
 float sum = 0;
 float med;

 scanf ("%d", &columnPosition);
 scanf (" %c", &option);

 if (option == 'S') //Sum option.
 {
   for (i=0;i<12;i++)
   {
       for (j=0;j<12;j++)
       {
         scanf ("%f", &mtr[i][j]);

         if (j == columnPosition)
            sum += mtr[i][j];
       }
   }
   printf ("%.1f\n", sum);
 }

 if (option == 'M') //Media option.
 {
     for (i=0;i<12;i++)
   {
       for (j=0;j<12;j++)
       {
         scanf ("%f", &mtr[i][j]);

         if (j == columnPosition)
            sum += mtr[i][j];
       }
   }
   printf ("%.1f\n", sum/12);
 }

  return 0;
}
