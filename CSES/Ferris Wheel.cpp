#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
#define int long long
#define endl "\n"

using namespace std;

const int INF = 1e9;

typedef vector<int> vi;
typedef pair<int, int> ii;

int32_t main(){

  speedBoost;
  int p, x; cin >> p >> x;
  vi a(p);
  for(int i=0; i<p; i++)
    cin >> a[i];

  sort(a.begin(), a.end());
  int l = 0, r = p-1;
  int ans = 0;

  while(l <= r){

    if(a[l] + a[r] <= x)
      l++, r--;
    else
      r--;
    ans++;
  }

  cout << ans << endl;

  return 0;
}
