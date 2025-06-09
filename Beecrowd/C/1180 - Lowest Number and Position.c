#include <stdio.h>

int main (){

  int n;

  scanf ("%d", &n);

  int x[n];

  for (int i=0;i<n;i++)
    scanf ("%d", &x[i]);

    int menor = x[0];
    int pos = 0;

  for (int i=1;i<n;i++) //Finds the lowest value
  {

  if (x[i] < menor)
    menor = x[i];
  }

  for (int i=0;i<n;i++)
    if (x[i] != menor)
    pos++;
  else break;


  printf ("Menor valor: %d\n", menor);
  printf ("Posicao: %d\n", pos);

  return 0;
}
