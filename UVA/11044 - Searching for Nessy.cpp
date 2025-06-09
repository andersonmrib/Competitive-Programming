#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
using namespace std;

int main(){

  speedBoost;
  int t; cin >> t;
  while(t--){
    int n, m; cin >> n >> m;
    int nR = ceil((n-2)/3.0);
    int nC = ceil((m-2)/3.0);
    cout << nR * nC << "\n";
  }

  return 0;
}
