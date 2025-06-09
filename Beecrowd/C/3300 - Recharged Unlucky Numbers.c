#include <stdio.h>
#include <string.h>

int main(){

  char num[110]; scanf("%s", num);
  int malaSuerte = 0;
  for (int i=0;i<strlen(num);i++){
    if (num[i] == '1' && num[i+1] == '3'){
        malaSuerte = 1;
        break;
    }
  }
    if (malaSuerte) printf ("%s es de Mala Suerte\n", num);
    else            printf ("%s NO es de Mala Suerte\n", num);

  return 0;
}
