#include <stdio.h>
#include <stdlib.h>

int main() {

  char name[20];
  double salary, sells;; //Amount received per hour.

  scanf ("%s %lf %lf", name, &salary, &sells);

  double bonus = (sells *15)/100;
  printf ("TOTAL = R$ %.2lf\n", salary + bonus);

  system ("pause");
  return 0;
}
