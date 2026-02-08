#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
#define int long long
#define endl "\n"

using namespace std;

typedef vector<int> vi;

int32_t main(){

  speedBoost;

  int n, x; cin >> n >> x;
  vector<pair<int, int>> a(n);
  for(int i=0; i<n; i++)
    cin >> a[i].first, a[i].second = i + 1;

  sort(a.begin(), a.end());
  int l = 0, r = n-1;
  for(int i=0; i<n; i++){
    int target = x - a[i].first;
    int l = i + 1, r = n - 1;
    while(l < r){
      int cur_sum = a[l].first + a[r].first;
      if(cur_sum == target){
        cout << a[i].second << " " << a[l].second << " " << a[r].second;
        return 0;
      }

      if(cur_sum < target)
        l++;
      else
        r--;
    }
  }

  cout << "IMPOSSIBLE\n";

  return 0;
}
