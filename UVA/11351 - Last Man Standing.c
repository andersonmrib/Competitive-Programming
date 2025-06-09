#include <stdio.h>

int findSurvivor(int n, int k){
  if (n == 1) return 0;
  return (findSurvivor(n-1, k) + k)%n;
}

int main(){

  int t; scanf("%d", &t);
  int count = 1;
  while(t--){
    int n, k; scanf("%d %d", &n, &k);
    printf("Case %d: %d\n", count, findSurvivor(n, k) + 1);
    count++;
  }
 return 0;
}
