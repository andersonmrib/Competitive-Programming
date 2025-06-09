#include <stdio.h>

int max(int a, int b){
  return a > b ? a : b;
}

int main(){

  int n; scanf("%d", &n);
  int vec[n];
  int ans = 1;
  for(int i=0; i<n; i++) scanf("%d", &vec[i]);
  for(int i=0; i<n; i++){
    for(int j=0; j<n; j++){
        int current = 0;
        int last = 0;
        for(int k=0; k<n; k++){
            if((vec[k] == vec[i] || vec[k] == vec[j]) && vec[k] != last){
                current++;
                last = vec[k];
            }
        ans = max(ans, current);
      }
    }
  }
  printf("%d\n", ans);

  return 0;
}
