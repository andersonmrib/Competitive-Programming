#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
#define int long long
#define F(i, L, R) for(int i=L; i<R; i++)
#define FR(i, R, L) for(int i=R; i>0; i--)
#define endl "\n"

using namespace std;

typedef vector<int> vi;

bool check(int mid, int t, vi &a){
  for(auto x : a){
    t -= mid/x;
    if(t <= 0) return true;
  }
  return false;
}

int32_t main(){

  speedBoost;
  int n, t; cin >> n >> t;
  vi a(n);
  F(i, 0, n)
    cin >> a[i];

  int low = 0, high = 1e18;  ;
  while(low < high){

    int mid = low + (high - low)/2;
    if(check(mid, t, a))
      high = mid;
    else
      low = mid + 1;
  }

  if(check(low, t, a)) cout << low << endl;
  else                 cout << high << endl;

  return 0;
}

