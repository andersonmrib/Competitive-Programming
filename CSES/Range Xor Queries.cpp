#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
#define endl "\n"

using namespace std;

typedef vector<int> vi;

int main(){

  speedBoost;
  int n, q; cin >> n >> q;
  vi a(n);
  for(int i=0; i<n; i++)
    cin >> a[i];

  vi pref(n);
  for(int i=0; i<n; i++){
    if(i == 0) pref[i] = a[i];
    else       pref[i] = a[i] ^ pref[i-1];
  }

  while(q--){

    int l, r; cin >> l >> r;
    l--, r--;
    if(l == 0) cout << pref[r] << endl;
    else       cout << (pref[r] ^ pref[l-1]) << endl;
  }

  return 0;
}
