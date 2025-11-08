#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0)
#define int long long
#define endl "\n"
using namespace std;

int _sieve_size;
bitset<40000> bs;
vector<int> p;

void sieve(int upperbound){
  _sieve_size = upperbound + 1;
  bs.set();
  bs[0] = bs[1] = 0;
  for(int i=2; i<_sieve_size; i++)
    if(bs[i]){
      for(int j=i*i; j<_sieve_size; j+=i)
        bs[j] = 0;
      p.push_back(i);
    }
}

int EulerPhi(int N){
  int ans = N;
  for(int i=0; i<p.size() && (p[i] * p[i] <= N); i++){
    if(N % p[i] == 0) ans -= ans / p[i];
    while(N % p[i] == 0) N /= p[i];
  }

  if(N != 1) ans -= ans/N;
  return ans;
}

int32_t main(){

  speedBoost;
  sieve(40000);

  int n;
  while(cin >> n, n){
    cout << EulerPhi(n) << endl;
  }

  return 0;
}
