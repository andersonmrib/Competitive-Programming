#include <stdio.h>

void swap (int *a, int *b) {

 int temp;

 temp = *a;
 *a = *b;
 *b = temp;
}

int main() {

  int num1, num2, num3; //Original Values.
  int a, b, c; //Copy Values.

  scanf ("%d %d %d", &num1, &num2, &num3);

  a = num1, b = num2, c = num3;

  if (b < a)   swap (&a, &b);

  if (c < b) {
    swap (&b, &c);
    if (b < a) swap (&a, &b);
  }

  printf ("%d\n%d\n%d\n\n%d\n%d\n%d\n", a, b, c, num1, num2, num3);

    return 0;
}