#include <bits/stdc++.h>
using namespace std;

int main(){

  int n; scanf("%d", &n);
  int mtr[n][n];

  int ans[n];
  for(int i=0; i<n; i++){
    int lost = 0;
    for(int j=0; j<n; j++){
      scanf("%d", &mtr[i][j]);
      lost |= mtr[i][j];
    }
    ans[i] = lost;
  }

  printf("%d", ans[0]);
  for(int i=1; i<n; i++)
    printf(" %d", ans[i]);
  printf("\n");

  return 0;
}
