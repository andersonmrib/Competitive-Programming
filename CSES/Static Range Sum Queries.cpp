#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
using namespace std;

typedef long long ll;

int main(){

  speedBoost;

  int n, q; cin >> n >> q;

  vector<int> vec(n);
  vector<ll> prefixSum(n+1, 0);

  for(int i=0; i<n; i++){
    cin >> vec[i];
    prefixSum[i+1] += prefixSum[i] + vec[i];
  }

  ll ans;
  for(int i=0; i<q; i++){
    int a, b; cin >> a >> b;
    ans = prefixSum[b] - prefixSum[a-1];
    cout << ans << "\n";
  }

  return 0;
}
