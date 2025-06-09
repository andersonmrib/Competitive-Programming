#include <stdio.h>
#include <stdlib.h>

int main() {

  int EmpNum, hours;
  float money; //Amount received per hour.

  scanf ("%d %d %f", &EmpNum, &hours, &money);

  printf ("NUMBER = %d\n", EmpNum);
  printf ("SALARY = U$ %.2f\n", hours*money);

  system ("pause");
  return 0;
}
