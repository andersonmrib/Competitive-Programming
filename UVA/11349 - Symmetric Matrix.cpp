#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

typedef long long ll;

ll mtr[105][105];  // use a long long!

int main(){

  speedBoost;
  int t; cin >> t;
  int numCases = 0;
  while(t--){

    char d1, d2; cin >> d1 >> d2; // dummy 1 and 2
    int n; cin >> n;
    for(int i=0; i<n; i++)
      for(int j=0; j<n; j++)
        cin >> mtr[i][j];

    bool symmetric = true;
    for(int i=0; i<n && symmetric; i++){
      for(int j=0; j<n; j++){
        if(mtr[i][j] != mtr[n-i-1][n-j-1] || mtr[i][j] < 0 || mtr[n-i-1][n-j-1] < 0){
          symmetric = false;
          break;
        }
      }
    }

    if(symmetric) cout << "Test #" << ++numCases << ": " << "Symmetric.\n";
    else          cout << "Test #" << ++numCases << ": " << "Non-symmetric.\n";
  }

  return 0;
}
