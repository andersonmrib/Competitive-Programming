#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
#define endl "\n"

using namespace std;

int solve(int n, int k, int m){
  m = n - m;
  if(k <= 1) return n - m;
  int i = m;
  while(i < n){
    int r = (i - m + k - 2) / (k - 1);
    if((i + r) > n) r = n - i;
    else if(!r) r = 1;
    i += r;
    m = (m + (r * k)) % i;
  }
  return m + 1;
}

int main(){

  speedBoost;
  int q; cin >> q;
  while(q--){

    int n, k; cin >> n >> k;
    cout << solve(n, 2, k) << endl;
  }

  return 0;
}

