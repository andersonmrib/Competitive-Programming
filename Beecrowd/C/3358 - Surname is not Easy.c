#include <stdio.h>
#include <string.h>

int main() {

  char str[43];
  int n;

  scanf ("%d", &n);

  for (int i=0;i<n;i++)
  {
     int count = 0;

     scanf ("%s", str);

     for (int j=0;j<strlen(str);j++)
     {

       if (str[j] == 'a' || str[j] == 'A' ||
           str[j] == 'e' || str[j] == 'E' ||
           str[j] == 'i' || str[j] == 'I' ||
           str[j] == 'o' || str[j] == 'O' ||
           str[j] == 'u' || str[j] == 'U')
           count = 0;

       else count++;

       if (count >= 3){
       printf ("%s nao eh facil\n", str);
       break;
       }

      }
       if (count < 3) printf ("%s eh facil\n", str);

  }

  return 0;
}
