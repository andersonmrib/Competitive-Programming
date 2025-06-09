#include <stdio.h>

int main(){

  int n; scanf("%d", &n);
  int ans = 0;
  while(n--){
    int t, v; scanf("%d %d", &t, &v);
    ans += v*t;
  }
  printf("%d\n", ans);

 return 0;
}
