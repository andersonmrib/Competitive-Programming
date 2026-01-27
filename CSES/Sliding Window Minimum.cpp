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

  deque<int> dq;
  int ans = 0;

  for(int i=0; i<n; i++){

    if(!dq.empty() && dq.front() <= i - k)
      dq.pop_front();

    while(!dq.empty() && vec[dq.back()] >= vec[i])
      dq.pop_back();

    dq.push_back(i);

    if(i >= k-1){
      if(i == k-1) ans = vec[dq.front()];
      else         ans ^= vec[dq.front()];
    }
  }

  cout << ans << endl;

  return 0;
}
