#include <bits/stdc++.h>
#define speedBoost ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

int mtr[101][1001];

int survivor(int n, int k){
  if(mtr[n][k] == -1)
     mtr[n][k] = (survivor(n-1, k) + k)%n;
  return mtr[n][k];
}

int main(){

  int n, m;

  for(int i=0; i<2; i++)         // problem based on index 1 or 0 are trivial
    for(int j=0; j<1001; j++)
      mtr[i][j] = 0;

  for(int i=2; i<101; i++)       // for the other cases that are
    for(int j=0; j<1001; j++)    // not trivial, going to mark the matrix
      mtr[i][j] = -1;            // using -1

  while((cin >> n), n){          // don't forget 12 is the last region (13)
    m = 1;
    while((survivor(n-1, m) + 1)%n != 12)
      m++;

    cout << m << endl;
  }

  return 0;
}
