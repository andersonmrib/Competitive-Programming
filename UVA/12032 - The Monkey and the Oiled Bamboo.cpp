#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
using namespace std;

typedef long long ll;

bool check(ll k, const vector<int> &vec){
  for(int i=1; i<vec.size(); i++){
    ll diff = vec[i] - vec[i-1];
    if(diff > k) return false;
    if(diff == k){
      k--;
      if(k < 0) return false;
    }
  }
  return true;
}

int main(){

  speedBoost;
  int t; cin >> t;
  int NC = 0;
  while(t--){

    int n; cin >> n;
    vector<int> vec(n+1, 0);
    for(int i=1; i<vec.size(); i++)
      cin >> vec[i];

    ll l = 1, r = 1e9, mid;
    while(r > l){
      mid = (l+r)/2;
      if(check(mid, vec)) r = mid;
      else                l = mid + 1;
    }

    cout << "Case " << ++NC << ": " << l << "\n";
  }

  return 0;
}


