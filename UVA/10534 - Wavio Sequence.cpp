#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

typedef vector<int> vi;
vi A, L;

void LIS(vi &dp){ // used to store every possible length k in a sequence
  int k = 0;
  for(int i=0; i<A.size(); i++){
    int pos = lower_bound(L.begin(), L.begin()+k, A[i]) - L.begin();
    L[pos] = A[i];
    if(pos == k) k = pos + 1;
    dp.push_back(k);
  }
}

int main(){

  speedBoost;
  int n;
  while(cin >> n){

    A.assign(n, 0), L.assign(n, 0);
    for(int i=0; i<n; i++)
      cin >> A[i];

    vi dp, dpRev;

    LIS(dp);
    reverse(A.begin(), A.end());
    LIS(dpRev);

    int ans = 1;
    for(int i=0; i<A.size(); i++)
      ans = max(ans, 2*min(dp[i], dpRev[A.size()-1-i]));
    ans--; // remember to remove the duplicate element

    cout << ans << endl;
  }

  return 0;
}

