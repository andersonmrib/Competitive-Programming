#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
#define endl "\n"

using namespace std;

typedef vector<int> vi;

int main(){

  speedBoost;
  int n, q; cin >> n >> q;

  vector<vi> mtr(n, vi(n));
  for(int i=0; i<n; i++){
    for(int j=0; j<n; j++){
      char c; cin >> c;
      if(c == '*') mtr[i][j] = 1;
      else         mtr[i][j] = 0;
    }
  }

  for(int i=0; i<n; i++){
    for(int j=0; j<n; j++){
      if(i > 0)  mtr[i][j] += mtr[i-1][j];
      if(j > 0)  mtr[i][j] += mtr[i][j-1];
      if(i && j) mtr[i][j] -= mtr[i-1][j-1];
    }
  }

  while(q--){

    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    x1--, y1--, x2--, y2--;

    int ans = mtr[x2][y2];
    if(x1 > 0)   ans -= mtr[x1-1][y2];
    if(y1 > 0)   ans -= mtr[x2][y1-1];
    if(x1 && y1) ans += mtr[x1-1][y1-1];
    cout << ans << endl;
  }

  return 0;
}
