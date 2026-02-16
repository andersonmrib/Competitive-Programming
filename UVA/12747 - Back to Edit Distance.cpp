#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
#define int long long
#define endl "\n"

using namespace std;

typedef vector<int> vi;

const int INF = 1e9;

int32_t main(){

  speedBoost;
  int t; cin >> t;
  int nc = 1;
  while(t--){

    int n; cin >> n;
    vi idx(n, 0);
    for(int i=0; i<n; i++){
      int val; cin >> val;
      idx[val-1] = i;
    }

    vi A;
    for(int i=0; i<n; i++){
      int val; cin >> val;
      A.push_back(idx[val-1]);
    }

    int k = 0;
    vi L(n, 0);
    for(int i=0; i<n; i++){
      int pos = lower_bound(L.begin(), L.begin() + k, A[i]) - L.begin();
      L[pos] = A[i];
      if(k == pos)
        k = pos + 1;
    }

    cout << "Case " << nc++ << ": ";
    cout << 2 * (n - k) << endl;
  }

  return 0;
}
