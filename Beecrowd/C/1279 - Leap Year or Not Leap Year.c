#include <stdio.h>
#define SIZE 3000

int checker (char *year, int div);

int main () {

  char year[SIZE];
  long long int div4, div15, div55, div100, div400; //Divider checkers
  int leap, hulu, bulu, flag;

  flag = 0;
  while (scanf ("%s", year) != EOF)
  {
      if (flag == 1)
        printf ("\n");

     flag = 1;
     leap = hulu = bulu = 0;

     div4 = checker(year, 4);
     div15 = checker(year, 15);
     div55 = checker(year, 55);
     div100 = checker(year, 100);
     div400 = checker(year, 400);

    if (div400 == 1 || (div4 == 1 && div100 == 0))
    {
      printf ("This is leap year.\n"); //1
      leap = 1;
      bulu = 1;
    }
    if (div15 == 1)
    {
      printf ("This is huluculu festival year.\n");
      leap = 1;
    }
    if (bulu == 1 && div55 == 1)
    {
      printf ("This is bulukulu festival year.\n");
    }
    if (leap != 1)
    {
      printf ("This is an ordinary year.\n");
    }
  }

  return 0;
}

int checker (char *year, int div){

  int i, j;

  j = 0;
  for (i=0;year[i];i++)
    j = ((year[i] - '0') + j*10)%div;

  if (j == 0)
    return 1;
  return 0;
}
