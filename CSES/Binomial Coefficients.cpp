#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
#define int long long
#define endl "\n"

using namespace std;

typedef vector<int> vi;
const int MOD = 1e9+7;

int fastPow(int b, int p, int m){
  if(p == 0) return 1;
  int ans = fastPow(b, p/2, m);
  ans = (ans*ans) % m;
  if(p&1) ans = (ans*b) % m;
  return ans;
}

int modInv(int n, int m){
  return fastPow(n, m-2, m);
}

vi fact, invFact;
void preCompute(int limit){
  fact.assign(limit+1, 0), invFact.assign(limit+1, 0);
  fact[0] = invFact[0] = 1;
  for(int i=1; i<=limit; i++)
    fact[i] = (fact[i-1] * i) % MOD;
  invFact[limit] = modInv(fact[limit], MOD);
  for(int i=limit-1; i>=0; i--)
    invFact[i] = (invFact[i+1] * (i+1)) % MOD;
}

int nCk(int n, int k){
  if(k < 0 || k > n) return 0;
  return(((fact[n] * invFact[k]) % MOD) * invFact[n-k] % MOD);
}

int32_t main(){

  speedBoost;
  int n; cin >> n;
  preCompute(1000005);
  while(n--){

    int a, b; cin >> a >> b;
    cout << nCk(a, b) << endl;
  }

  return 0;
}
