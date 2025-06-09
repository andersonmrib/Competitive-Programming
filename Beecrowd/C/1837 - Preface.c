#include <stdio.h>

int main() {

  int a, b, q, r;
  int Auxb;
  int NumberAdd;                        /*  If a < 0, we're going to decrease the value of (a) until we can divide it by (b) without  */
                                        /*  a remainder. But if we decrease (a), we need to increase the remainder (r) with the same  */
                                        /*  frequency according to the number theory.                                                 */

  scanf ("%d %d", &a, &b);

  if (a >= 0)
  {
      q = a/b;
      r = a%b;
  }

  else
  {
      Auxb = b;
      if (b < 0) Auxb *= -1;

      for (r=0;r<Auxb;r++)
      {
          NumberAdd = a - r;
          if (NumberAdd%b == 0) break;
      }
      q = NumberAdd/b;
  }

  printf ("%d %d\n", q, r);

  return 0;
}
