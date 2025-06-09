#include <stdio.h>

int findSurvivor(int n, int k){ //Uses a simple recurrence for checking the last man alive 
  if (n == 1) return 0;
  return (findSurvivor(n-1, k) + k)%n; 
}

int main(){

  int nc; scanf("%d", &nc);
  int count = 1;
  while(nc--){
    int n, k; scanf("%d %d", &n, &k);
    printf("Case %d: %d\n", count, findSurvivor(n, k) + 1);
    count++;
  }
 return 0;
}
