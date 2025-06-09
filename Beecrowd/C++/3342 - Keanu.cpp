#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
using namespace std;

int main(){

  int n; scanf("%d", &n);
  if((n&1) == 0) printf("%d casas brancas e %d casas pretas\n", n*n/2, n*n/2);
  else           printf("%d casas brancas e %d casas pretas\n", n*n/2+1, n*n/2);

  return 0;
}
