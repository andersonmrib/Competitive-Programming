#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
#define int long long
#define endl "\n"

using namespace std;

typedef vector<int> vi;

int32_t main(){

  speedBoost;
  int n, k; cin >> n >> k;
  int x, a, b, c; cin >> x >> a >> b >> c;

  vi vec(n);
  vec[0] = x;
  for(int i=1; i<n; i++)
    vec[i] = (a * vec[i-1] + b) % c;

  int sum = 0;
  for(int i=0; i<k; i++)
    sum += vec[i];

  int ans = sum;
  for(int i=1; i<n-k+1; i++){
    sum += (vec[i+k-1] - vec[i-1]);
    ans ^= sum;
  }

  cout << ans << endl;

  return 0;
}
