#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
#define int long long
#define F(i, L, R) for(int i=L; i<R; i++)
#define FR(i, R, L) for(int i=R; i>0; i--)
#define endl "\n"

using namespace std;

const int MOD = 1e9+7;

typedef vector<int> vi;

int fastPow(int b, int p, int m){
  if(p == 0) return 1;
  int ans = fastPow(b, p/2, m);
  ans = ans * ans % m;
  if((p&1)) ans = ans * b % m;
  return ans;
}

int modInv(int b, int p){
  return fastPow(b, p-2, p);
}

int32_t main(){

  speedBoost;
  int n, m; cin >> n >> m;

  vi fact(n+m+10), invfact(n+m+1);
  fact[0] = invfact[0] = 1;
  for(int i=1; i<n+m+8; i++)
    fact[i] = (i * fact[i-1]) % MOD;
  invfact[n+m] = modInv(fact[n+m], MOD);
  for(int i=n+m-1; i>=0; i--)
      invfact[i] = (invfact[i+1] * (i + 1)) % MOD;

  cout << ((fact[n+m-1] * invfact[n-1]) % MOD) * invfact[m] % MOD << endl;

  return 0;
}

