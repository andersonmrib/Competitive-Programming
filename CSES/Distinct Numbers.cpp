#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
#define endl "\n"

using namespace std;

int main(){

  speedBoost;
  int n; cin >> n;

  set<int> st;
  vector<int> vec(n);
  for(int i=0; i<n; i++){
    int x; cin >> x;
    st.insert(x);
  }

  cout << st.size() << endl;

  return 0;
}
