#include <stdio.h>

int main() {

   double a, b;
   double aver;

   scanf ("%lf %lf", &a, &b);

   aver = (3.5 * a + 7.5 * b)/(3.5+7.5);

   printf ("MEDIA = %.5lf\n", aver);

    return 0;
}
