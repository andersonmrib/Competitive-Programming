#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
using namespace std;

typedef long long ll;
#define MAX 1000001
#define MOD 100000

int main(){

  speedBoost
  vector<ll> table(MAX, 0);
  table[0] = 1;

  for(ll i=1; i<MAX; i++){
    table[i] = i * table[i-1];
    while(table[i] % 10 == 0) table[i] /= 10;
    table[i] %= MOD;
  }

  ll n, NC = 0;
  while(cin >> n){
    cout << "Instancia " << ++NC << "\n";
    cout << table[n] % 10 << "\n\n";
  }

  return 0;
}
