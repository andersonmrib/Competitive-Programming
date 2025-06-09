#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
using namespace std;

int main(){

  speedBoost;
  int t; cin >> t; cin.ignore();
  string line;
  while(t--){

    cin >> line;
    int n = line.size();

    vector<vector<int>> mtr(n, vector<int>(n));
    for(int i=0; i<n; i++){
      if(i) cin >> line;
      for(int j=0; j<n; j++){
        mtr[i][j] += line[j] - '0';
        if(i > 0) mtr[i][j] += mtr[i-1][j];
        if(j > 0) mtr[i][j] += mtr[i][j-1];
        if(i > 0 && j > 0) mtr[i][j] -= mtr[i-1][j-1];
      }
    }

    int ans = 0;
    for(int i=0; i<n; i++){
      for(int j=0; j<n; j++){
        for(int k=i; k<n; k++){
          for(int l=j; l<n; l++){
            int area = (k-i+1) * (l-j+1);
            int cur = mtr[k][l];
            if(i > 0) cur -= mtr[i-1][l];
            if(j > 0) cur -= mtr[k][j-1];
            if(i > 0 && j > 0) cur += mtr[i-1][j-1];
            if(area == cur) ans = max(ans, area);
          }
        }
      }
    }
    cout << ans << "\n";
    if(t) cout << "\n";
  }

  return 0;
}
