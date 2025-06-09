#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
using namespace std;

typedef vector<int> vi;
typedef long long ll;
const int prime = 131;
const int MOD = 1e9+7;

vi Pow, h;

int extEuclid(int a, int b, int &x, int &y){
  int xx = y = 0;
  int yy = x = 1;
  while(b){
    int q = a/b;
    int t = b; b = a%b; a = t;
    t = xx; xx = x-q*xx; x = t;
    t = yy; yy = y-q*yy; y = t;
  }
  return a;
}

int modInv(int b, int m){
  int x, y;
  int d = extEuclid(b, m, x, y);
  if(d != 1) return -1;
  return (x+m)%m;
}

void computeRollingHash(string str){
  Pow.assign(str.size(), 0);
  Pow[0] = 1;
  for(int i=1; i<(int)str.size(); i++)
    Pow[i] = ((ll)Pow[i-1] * prime) % MOD;

  h.assign(str.size(), 0);
  for(int i=0; i<(int)str.size(); i++){
    if(i != 0) h[i] = h[i-1];
    h[i] = (h[i] + ((ll)str[i] * Pow[i])%MOD)%MOD;
  }
}

int hash_fast(int L, int R){
  if(L == 0) return h[R];
  int ans = 0;
  ans = ((h[R] - h[L-1])%MOD + MOD)%MOD;
  ans = ((ll)ans * modInv(Pow[L], MOD))%MOD;
  return ans;
}

int main(){

  speedBoost;
  string p, t;
  while(getline(cin, p)){
    getline(cin, t);

    computeRollingHash(t);

    int m = p.size();
    int n = t.size();

    int hp = 0; // P's hashing value
    for(int i=0; i<m; i++)
      hp = (hp + (ll)p[i]*Pow[i])%MOD;

    for(int i=0; i<=n-m; i++)
      if(hash_fast(i, i+m-1) == hp)
        cout << i << " ";

    cout << "\n";
  }

  return 0;
}
