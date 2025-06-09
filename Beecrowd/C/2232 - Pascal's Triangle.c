#include <stdio.h>
#include <math.h>

int main(){

  int n; scanf("%d", &n);
  long long sum;
  while(n--){
    int m; scanf("%d", &m);
    sum = 0;
    while(m--){
        sum += pow(2, m);
    }
    printf("%lld\n", sum);
  }
  return 0;
}
