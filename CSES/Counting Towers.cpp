#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0)
#define int long long
#define endl "\n"

using namespace std;

typedef vector<int> vi;

const int MOD = 1e9+7;
const int MAX = 1e6+1;

int f[MAX], g[MAX];

void pre_compute(){
  f[1] = g[1] = 1;
  for(int i=2; i<=MAX; i++){
    f[i] = (4 * f[i-1] + g[i-1]) % MOD;
    g[i] = (f[i-1] + 2 * g[i-1]) % MOD;
  }
}

int32_t main(){

  speedBoost;
  pre_compute();
  int t; cin >> t;
  while(t--){

    int n; cin >> n;
    cout << (f[n] + g[n]) % MOD << endl;

  }

  return 0;
}
