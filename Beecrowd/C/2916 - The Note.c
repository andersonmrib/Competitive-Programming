#include <stdio.h>
#include <stdlib.h>

const int MOD = 1e9+7;

int comp(const void *a, const void* b){
  int x = *((int*)a);
  int y = *((int*)b);
  return y - x;
}

int arr[1000010];

int main(){

  int n, k;
  while(scanf("%d %d", &n, &k) != EOF){
    for(int i=0; i<n; i++)
      scanf("%d", &arr[i]);

    qsort(arr, n, sizeof(int), comp);

    int ans = 0;
    for(int i=0; i<n; i++){
      if(k == 0) break;
      ans = (ans+arr[i])%MOD;
      k--;
    }
    printf("%d\n", ans);
  }

  return 0;
}
