#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
#define int long long
#define endl "\n"

using namespace std;

typedef vector<int> vi;

const int INF = 1e9;
const int LINF = 1e18;

int32_t main(){

  speedBoost;
  int n, k; cin >> n >> k;
  int x, a, b, c; cin >> x >> a >> b >> c;

  vi vec(n);
  vec[0] = x;
  for(int i=1; i<n; i++)
    vec[i] = (a * vec[i-1] + b) % c;

  int cur = 0;
  for(int i=0; i<k; i++)
    cur ^= vec[i];

  int ans = cur;
  for(int i=1; i<n-k+1; i++){
    cur ^= vec[i-1];   // Remove the old element
    cur ^= vec[i+k-1]; // Add the new one
    ans ^= cur;
  }

  cout << ans << endl;

  return 0;
}
