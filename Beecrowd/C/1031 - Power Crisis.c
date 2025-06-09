#include <stdio.h>

int mtr[110][1200];

int survivor(int n, int k){
  if(mtr[n][k] == -1)
     mtr[n][k] = (survivor(n-1, k) + k)%n;
  return mtr[n][k];
}

int main(){

  int n, m;

  for(int i=0; i<2; i++)
    for(int j=0; j<1200; j++)
      mtr[i][j] = 0;

  for(int i=2; i<110; i++)
    for(int j=0; j<1200; j++)
      mtr[i][j] = -1;

  while(scanf("%d", &n) != EOF && n){
    m = 1;
    while((survivor(n-1, m) +1)%n != 12)
      m++;

    printf("%d\n", m);
  }

  return 0;
}
