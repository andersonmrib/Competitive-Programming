#include <stdio.h>
typedef unsigned long long ull;

int main(){

  ull n, Cn2, Cn4; scanf("%llu", &n);
  Cn2 = (n * (n-1))/2;
  Cn4 = (n * (n-1) * (n-2) * (n-3))/24;
  double ans;

  ans = 1.0 + (double)Cn2 + (double)Cn4;

  printf("%.0lf\n", ans);

  return 0;
}
