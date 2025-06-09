#include <stdio.h>

int main () {

  double value;
  int Valueint, Remainint;
  scanf ("%lf", &value);

  Valueint = value;

  printf ("NOTAS:\n");
  printf ("%d nota(s) de R$ 100.00\n", Valueint/100);   Remainint = Valueint%100;
  printf ("%d nota(s) de R$ 50.00\n", Remainint/50);    Remainint = Remainint%50;
  printf ("%d nota(s) de R$ 20.00\n", Remainint/20);    Remainint = Remainint%20;
  printf ("%d nota(s) de R$ 10.00\n", Remainint/10);    Remainint = Remainint%10;
  printf ("%d nota(s) de R$ 5.00\n", Remainint/5);      Remainint = Remainint%5;
  printf ("%d nota(s) de R$ 2.00\n", Remainint/2);      Remainint = Remainint%2;
  printf ("MOEDAS:\n");
  printf ("%d moeda(s) de R$ 1.00\n", Remainint/1);     Remainint = Remainint%1;

  Valueint = value*100 - Valueint*100;

  printf ("%d moeda(s) de R$ 0.50\n", Valueint/50);     Remainint = Valueint%50;
  printf ("%d moeda(s) de R$ 0.25\n", Remainint/25);    Remainint = Remainint%25;
  printf ("%d moeda(s) de R$ 0.10\n", Remainint/10);    Remainint = Remainint%10;
  printf ("%d moeda(s) de R$ 0.05\n", Remainint/5);     Remainint = Remainint%5;
  printf ("%d moeda(s) de R$ 0.01\n", Remainint/1);     Remainint = Remainint%1;

  return 0;
}