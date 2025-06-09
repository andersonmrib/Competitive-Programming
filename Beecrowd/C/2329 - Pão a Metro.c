#include <stdio.h>
#define MAX 10010

int main() {

  int n, k; scanf("%d %d", &n, &k);
  int breads[MAX];

  int end = 0;
  for(int i=0; i<k; i++){
    scanf("%d", &breads[i]);
    if(breads[i] > end) end = breads[i];
  }

  int begin = 1, mid;
  int ans, undershoot;
  while(begin <= end){
    mid = (begin + end)/2;
    undershoot = 0;
    for(int i=0; i<k; i++) undershoot += breads[i]/mid;
    if(undershoot >= n){
      ans = mid;
      begin = mid + 1;
    }
    else
      end = mid - 1;
  }
  printf("%d\n", ans);

    return 0;
}
