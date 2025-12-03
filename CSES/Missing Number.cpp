#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
#define endl "\n"

using namespace std;

int main(){

  speedBoost;
  int n; cin >> n;

  vector<int> vec(n);
  iota(vec.begin(), vec.end(), 1);

  unordered_set<int> st(vec.begin(), vec.end());
  for(int i=0; i<n-1; i++){
    int x; cin >> x;
    st.erase(x);
  }

  for(auto x : st)
    cout << x << endl;

  return 0;
}
