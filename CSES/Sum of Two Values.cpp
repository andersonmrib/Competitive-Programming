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
  int n, x;
  cin >> n >> x;

  vector<ii> a(n);
  for(int i=0; i<n; i++){
    cin >> a[i].first;
    a[i].second = i + 1;
  }

  sort(a.begin(), a.end());
  int l = 0, r = n - 1;
  while(l < r){

    int sum = a[l].first + a[r].first;
    if(sum == x){
      cout << a[l].second << " " << a[r].second << endl;
      return 0;
    }

    if(sum < x)
      l++;
    else
      r--;
  }

  cout << "IMPOSSIBLE\n";

  return 0;
}
