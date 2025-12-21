#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0)
#define endl "\n"

using namespace std;

typedef vector<int> vi;

void solve(){

  int n, q; cin >> n >> q;
  vi A(n);
  for(int i=0; i<n; i++)
    cin >> A[i];

    vi pref1(n), pref2(n), pref3(n);
    for(int i=0; i<n; i++){

      if(i > 0){
         pref1[i] = pref1[i-1];
         pref2[i] = pref2[i-1];
         pref3[i] = pref3[i-1];
      }

      if(A[i] == 1) pref1[i]++;
      if(A[i] == 2) pref2[i]++;
      if(A[i] == 3) pref3[i]++;
    }

  while(q--){

    int l, r; cin >> l >> r;
    l--, r--;

    if(l == 0){
      cout << pref1[r] << " ";
      cout << pref2[r] << " ";
      cout << pref3[r] << "\n";
    }
    else{
      cout << pref1[r] - pref1[l-1] << " ";
      cout << pref2[r] - pref2[l-1] << " ";
      cout << pref3[r] - pref3[l-1] << "\n";
    }
  }
}

int32_t main(){

  #ifndef ONLINE_JUDGE
  freopen("bcount.in", "r", stdin);
  freopen("bcount.out", "w", stdout);
  #endif

  speedBoost;
    solve();

  return 0;
}
