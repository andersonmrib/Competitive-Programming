#include <stdio.h>

int main() {

  float a, b, c;
  float triRec, circle, trapezi, square, rectan;

  scanf ("%f %f %f", &a, &b, &c);

  triRec = (a * c)/2;
  circle = 3.14159 * c * c;
  trapezi = ((a + b) * c)/2;
  square = b * b;
  rectan = a * b;

  printf ("TRIANGULO: %.3f\n", triRec);
  printf ("CIRCULO: %.3f\n", circle);
  printf ("TRAPEZIO: %.3f\n", trapezi);
  printf ("QUADRADO: %.3f\n", square);
  printf ("RETANGULO: %.3f\n", rectan);

  return 0;
}
