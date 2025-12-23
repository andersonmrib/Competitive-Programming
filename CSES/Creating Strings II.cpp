#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
#define int long long
#define endl "\n"

using namespace std;

const int INF = 1e9;
const int MOD = 1e9+7;

typedef vector<int> vi;

int fastPow(int b, int p, int m){
  if(p == 0) return 1;
  int ans = fastPow(b, p/2, m);
  ans = ans * ans % m;
  if((p&1) == 1) ans = ans * b % m;
  return ans;
}

int32_t main(){

  speedBoost;
  string s; cin >> s;
  int sz = s.size();

  unordered_map<char, int> umap;
  for(auto c : s) umap[c]++;

  vi fact(sz+1), invFact(sz+1);
  fact[0] =  invFact[0] = 1;
  for(int i=1; i<=sz; i++)
    fact[i] = (i * fact[i-1]) % MOD;
  invFact[sz] = fastPow(fact[sz], MOD-2, MOD);
  for(int i=sz-1; i>=0; i--)
    invFact[i] = (invFact[i+1] * (i + 1)) % MOD;

  int ans = fact[sz];
  for(auto [c, x] : umap)
    ans = (ans * invFact[x]) % MOD;

  cout << ans << endl;

  return 0;
}
