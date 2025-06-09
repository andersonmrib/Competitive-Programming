#include <stdio.h>

int main(){

  int t, vector[1000], x = 1000;
  scanf("%d", &t);
  int aux = 0;
  int i = 0;
  while(x--){
    vector[i] = aux;
    printf ("N[%d] = %d\n", i, aux);
    aux++;
    if (aux == t) aux = 0;
    i++;
  }

  return 0;
}
