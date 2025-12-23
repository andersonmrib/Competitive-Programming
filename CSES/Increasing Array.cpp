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
  int n; cin >> n;
  int ans = 0, last = 0;
  for(int i=0; i<n; i++){
    int x; cin >> x;
    if(x < last)
      ans += last - x;
    else
      last = x;
  }

  cout << ans << endl;

  return 0;
}
