#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pairll;
typedef vector<ll> vll;

vll p;
vector<pairll> twinP;

ll _sieve_size;
bitset<20000010> bs;

void sieve(ll upperbound){
  _sieve_size = upperbound+1;
  bs.set();
  bs[0] = bs[1] = 0;
  for(ll i=2; i<_sieve_size; i++)
    if(bs[i]){
      for(ll j=i*i; j<_sieve_size; j+=i)
        bs[j] = 0;
        p.push_back(i);
        if(p.size() >= 2){
          if(p.back() - p[p.size() - 2] == 2)
            twinP.push_back({p[p.size() - 2], p.back()});
        }
  }
}

int main(){

  speedBoost;
  sieve(20000010);

  int n;
  while(cin >> n){
    n--;
    cout << "(" << twinP[n].first << ", " << twinP[n].second << ")\n";
  }

  return 0;
}
