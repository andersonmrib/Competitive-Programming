#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
#define int long long
#define endl "\n"

using namespace std;

typedef vector<int> vi;

vi a;
int inv;
vi merge(vi &l, vi &r){
  int n = l.size(), m = r.size();
  vi ans;
  int i = 0, j = 0;
  while(i < n && j < m){
    if(l[i] <= r[j]) ans.push_back(l[i++]);
    else{
      ans.push_back(r[j++]);
      inv = ((inv + n - i) % 10000007);
    }
  }

  while(i < n) ans.push_back(l[i++]);
  while(j < m) ans.push_back(r[j++]);
  return ans;
}

vi merge_sort(int l, int r){
  if(l == r) return { a[l] };
  int mid = (l + r) >> 1;
  vi left = merge_sort(l, mid);
  vi right = merge_sort(mid+1, r);
  return merge(left, right);
}

int32_t main(){

  speedBoost;
  int t; cin >> t;
  int nc = 1;
  while(t--){

    int n; cin >> n;
    a.resize(n);
    for(int i=0; i<n; i++)
      cin >> a[i];

    inv = 0;
    merge_sort(0, n-1);
    cout << "Case " << nc++ << ": ";
    cout << inv << endl;
  }

  return 0;
}
