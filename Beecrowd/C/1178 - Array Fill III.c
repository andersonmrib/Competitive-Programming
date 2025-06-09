#include <stdio.h>

int main(){

  int vector[100], x = 100;
  double t;
  scanf("%lf", &t);
  int i = 0;
  while(x--){
    vector[i] = t;
    printf ("N[%d] = %.4lf\n", i, t);
    t /= 2;
    i++;
  }

  return 0;
}
