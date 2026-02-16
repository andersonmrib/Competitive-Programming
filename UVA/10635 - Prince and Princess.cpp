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

    int n, p, q; cin >> n >> p >> q;
    vi pos(n*n+1, 0);
    for(int i=1; i<=p+1; i++){
      int val; cin >> val;
      pos[val] = i;
    }

    vi A;
    for(int i=0; i<=q; i++){
      int val; cin >> val;
      if(pos[val] != 0)
        A.push_back(pos[val]);
    }

    int sz = A.size();
    cout << "Case " << nc++ << ": ";
    if(sz == 0){
      cout << 0 << endl;
      continue;
    }

    int k = 0;
    vi L(sz, 0);
    for(int i=0; i<sz; i++){
      int pos = lower_bound(L.begin(), L.begin() + k, A[i]) - L.begin();
      L[pos] = A[i];
      if(pos == k)
        k = pos + 1;
    }

    cout << k << endl;
  }

  return 0;
}
