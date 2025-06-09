#include <stdio.h>

int main(){

  int n; scanf("%d", &n);
  long long int ans = 2;

  while(n--){
    ans += ans - 1;
  }
  printf("%lld\n", ans*ans);

  return 0;
}
