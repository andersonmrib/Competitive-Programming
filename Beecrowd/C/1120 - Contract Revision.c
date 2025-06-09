#include <stdio.h>
#include <string.h>

int main (){

  int d;
  char n[200];
  while (scanf ("%d %s", &d, &n)){

    if (d == 0 && n[0] == '0' && n[1] == '\0') break;

    int foundNonZero = 0;
    int len = strlen(n);

    for (int i=0; i<len; i++)
    {
        if (n[i] == d + '0') continue;
        if (n[i] != '0' || foundNonZero){
        printf("%c", n[i]);
        foundNonZero = 1;
        }
    }

    if (!foundNonZero) printf("0");
                       printf("\n");

  }
  return 0;
}
