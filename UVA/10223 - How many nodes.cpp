#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
using namespace std;

typedef long long ll;

int main(){

  speedBoost;
  unordered_map<ll, int> umap;
  umap[0] = 1;

  vector<ll> res(20, 0);
  res[0] = 1;

  for(int i=1; i<20; i++){
    res[i] = (res[i-1] * (4 * (i-1) + 2))/(i + 1);
    umap[res[i]] = i;
  }

  ll n;
  while(cin >> n){
    cout << umap[n] << "\n";
  }

  return 0;
}
