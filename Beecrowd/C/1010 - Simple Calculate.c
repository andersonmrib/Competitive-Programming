#include <stdio.h>
#include <stdlib.h>

int main() {

  int itemCode1, itemCode2;
  int itemUnit1, itemUnit2;
  float price1, price2;

  scanf ("%d %d %f %d %d %f", &itemCode1, &itemUnit1, &price1, &itemCode2, &itemUnit2, &price2);

  printf ("VALOR A PAGAR: R$ %.2f\n", price1*itemUnit1 + price2*itemUnit2);

  system ("pause");
  return 0;
}
