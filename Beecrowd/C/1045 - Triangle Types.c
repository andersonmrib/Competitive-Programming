#include <stdio.h> 

void swap (double *s1, double *s2);

int main() {

  double a, b, c;

  scanf ("%lf %lf %lf", &a, &b, &c);

  if (a < b) swap(&a, &b);

  if (b < c)
  {
      swap (&b, &c);
      if (a < b)
      swap (&a, &b);
  }

  if (a >= b + c)                    printf ("NAO FORMA TRIANGULO\n");

  else

  {
   if (a*a == b*b + c*c)             printf ("TRIANGULO RETANGULO\n");
   if (a*a > b*b + c*c)              printf ("TRIANGULO OBTUSANGULO\n");
   if (a*a < b*b + c*c)              printf ("TRIANGULO ACUTANGULO\n");
   if (a == b && b == c)             printf ("TRIANGULO EQUILATERO\n");
   if (a == b && a != c ||
       a == c && a != b ||
       b == c && b != a )            printf ("TRIANGULO ISOSCELES\n");
  }

  return 0;
}

void swap (double *s1, double *s2)
{
    double temp;
    temp = *s1;
    *s1 = *s2;
    *s2 = temp;
}

