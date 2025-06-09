#include <stdio.h>

int main() {

  int notes, remain;

  scanf ("%d", &notes);

  printf ("%d\n", notes);
  printf ("%d nota(s) de R$ 100,00\n", notes/100);  remain = notes%100;
  printf ("%d nota(s) de R$ 50,00\n", remain/50);   remain = remain%50;
  printf ("%d nota(s) de R$ 20,00\n", remain/20);   remain = remain%20;
  printf ("%d nota(s) de R$ 10,00\n", remain/10);   remain = remain%10;
  printf ("%d nota(s) de R$ 5,00\n", remain/5);     remain = remain%5;
  printf ("%d nota(s) de R$ 2,00\n", remain/2);     remain = remain%2;
  printf ("%d nota(s) de R$ 1,00\n", remain/1);

  return 0;
}