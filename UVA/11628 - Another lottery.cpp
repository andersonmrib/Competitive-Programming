#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
#define int long long
#define endl "\n"
using namespace std;

int gcd(int a, int b) { return (b == 0) ? a : gcd(b, a%b); }

int32_t main(){

  speedBoost;
  int n, m;
  while(cin >> n >> m, n || m){

    vector<int> p(n);
    int last_round = 0;
    for(int i=0; i<n; i++){
      for(int j=0; j<m; j++){
        int x; cin >> x;
        if(j == m-1){
          p[i] = x;
          last_round += x;
        }
      }
    }

    for(int i=0; i<n; i++){
      cout << p[i] / gcd(p[i], last_round) << " / ";
      cout << last_round / gcd(p[i], last_round) << endl;
    }
  }

  return 0;
}
