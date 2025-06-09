#include <stdio.h>
#include <string.h>

int main(){

  int n; scanf("%d", &n);
  while(n--){

    char str[21]; scanf (" %s", str);
    int k;
    int invalid_data = 0;
    int justZeros = 0;

    for (int j=2;j<20;j++)
    {
      if (str[0] != 'R' || str[1] != 'A' || strlen(str) != 20)
      {
         printf ("INVALID DATA\n");
         invalid_data = 1;
         break;
      }

      else if (str[j] != '0')
      {
         k = j;
         break;
      }
      else
        justZeros++;
    }

      if (justZeros == 18)
      {
         printf ("INVALID DATA\n");
         continue;
      }

    if (invalid_data) continue;

  for (k;k<20;k++)
    printf ("%c", str[k]);
    printf ("\n");
  }

  return 0;
}
