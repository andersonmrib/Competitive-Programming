#include <stdio.h>
#include <string.h>

int main() {

  int n; //Number of test cases.
  char number1[11], number2[11];
  int match = 0; //Number of times digit of number 2 (coming from right) matches with the digit of number 1.
  int i, j, k;

  scanf ("%d", &n);

  for (i=0;i<n;i++)
  {
      scanf ("%s %s", number1, number2);
      int sizeNumber1 = strlen(number1);
      int sizeNumber2 = strlen(number2);
      j = sizeNumber1 - 1; //1
      k = sizeNumber2 - 1; //2

       while (j >= 0 && k >= 0 && number2[k] == number1[j]) {
            match++;
            j--;
            k--;
        }

          if (match == sizeNumber2)
            printf ("encaixa\n");
          else
            printf ("nao encaixa\n");

          match = 0;
  }

  return 0;
}
