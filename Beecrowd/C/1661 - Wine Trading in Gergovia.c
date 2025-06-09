#include <stdio.h>
#include <stdlib.h>

int main(){

  int n;
  while(scanf("%d", &n), n){
    long long ans = 0, demand = 0;
    int arr[n];

    for(int i=0; i<n; i++){
        scanf("%d", &arr[i]);
        demand += arr[i];
        ans += labs(demand);
    }
    printf("%lld\n", ans);
  }

  return 0;
}
