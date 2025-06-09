#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
#define int long long
using namespace std;

const int MAX_N = 300001;
const int p1 = 31, p2 = 53;
const int MOD1 = 1e9+7;
const int MOD2 = 1e9+9;

int Pow1[MAX_N], Pow2[MAX_N], Inv1[MAX_N], Inv2[MAX_N];
vector<int> h1, h2;

int modPow(int b, int p, int m){
  if(p == 0) return 1;
  int ans = modPow(b, p/2, m);
  ans = (ans * ans) % m;
  if(p & 1) ans = (ans * b) % m;
  return ans;
}

void preCompute(int n){
  Pow1[0] = Pow2[0] = 1;
  Inv1[0] = Inv2[0] = 1;

  int InvP1 = modPow(p1, MOD1-2, MOD1);
  int InvP2 = modPow(p2, MOD2-2, MOD2);

  for(int i=1; i<n; i++){
    Pow1[i] = (Pow1[i-1] * p1) % MOD1;
    Pow2[i] = (Pow2[i-1] * p2) % MOD2;
    Inv1[i] = (Inv1[i-1] * InvP1) % MOD1;
    Inv2[i] = (Inv2[i-1] * InvP2) % MOD2;
  }
}

pair<int, int> hash_fast(int L, int R){
  int hash1 = (h1[R] - h1[L] + MOD1) % MOD1 * Inv1[L] % MOD1;
  int hash2 = (h2[R] - h2[L] + MOD2) % MOD2 * Inv2[L] % MOD2;
  return {hash1, hash2};
}

int32_t main(){
  speedBoost;
  string str; cin >> str;
  int n = str.size();
  preCompute(n);

  h1.assign(n+1, 0), h2.assign(n+1, 0);
  for(int i=0; i<n; i++){
    h1[i+1] = (h1[i] + (str[i] - 'a' + 1) * Pow1[i] % MOD1) % MOD1;
    h2[i+1] = (h2[i] + (str[i] - 'a' + 1) * Pow2[i] % MOD2) % MOD2;
  }

  int q; cin >> q;
  while(q--){
    int L, R; cin >> L >> R;
    auto [a, b] = hash_fast(L, R);
    cout << a * b << "\n";
  }

  return 0;
}
