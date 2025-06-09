#include <stdio.h>

int main() {

 double mtr[12][12];
 int i, j;
 char option;
 double sum = 0;
 double med;

 scanf ("%c", &option);

 if (option == 'S') //Sum option.
 {
   for (i=0;i<12;i++)
   {
       for (j=0;j<12;j++)
       {
         scanf ("%lf", &mtr[i][j]);

         if (i>j && j+i<=10)
            sum += mtr[i][j];
       }
   }
   printf ("%.1lf\n", sum);
 }

 if (option == 'M') //Media option.
 {
     for (i=0;i<12;i++)
   {
       for (j=0;j<12;j++)
       {
         scanf ("%lf", &mtr[i][j]);

         if (i>j && j+i<=10)
            sum += mtr[i][j];
       }
   }
   printf ("%.1lf\n", sum/30);
 }

  return 0;
}
