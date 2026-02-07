#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
#define int long long
#define endl "\n"

using namespace std;

typedef vector<int> vi;

int32_t main(){

  speedBoost;
  int n, x; cin >> n >> x;

  vi a(n), pref(n);
  map<int, int> umap;
  umap[0] = 1;
  int ans = 0;
  for(int i=0; i<n; i++){
    cin >> a[i];

    if(i > 0) pref[i] += pref[i-1] + a[i];
    else      pref[i] = a[i];

    if(umap.count(pref[i] - x))
      ans += umap[pref[i] - x];

    umap[pref[i]]++;
  }

  cout << ans << endl;

  return 0;
}
