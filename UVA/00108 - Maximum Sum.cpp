#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
using namespace std;

int main(){

  speedBoost;
  int n; cin >> n;
  int mtr[n][n];

  for(int i=0; i<n; i++){
    for(int j=0; j<n; j++){
      cin >> mtr[i][j];
      if(j > 0) mtr[i][j] += mtr[i][j-1];
    }
  }

  int maxSubRect = -127*100*100;
  for(int l=0; l<n; l++){
    for(int r=l; r<n; r++){
      int subRect = 0;
      for(int row=0; row<n; row++){
        if(l > 0) subRect += mtr[row][r] - mtr[row][l-1];
        else      subRect += mtr[row][r];
        if(subRect < 0) subRect = 0;
        maxSubRect = max(maxSubRect, subRect);
      }
    }
  }

  cout << maxSubRect << "\n";

  return 0;
}
