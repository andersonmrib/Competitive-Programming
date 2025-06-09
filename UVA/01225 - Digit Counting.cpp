#include <bits/stdc++.h>
using namespace std;

int main(){

  int t; cin >> t;
  while(t--){

    int n; cin >> n;
    string str = "";

    for(int i=1; i<=n; i++)
      str += to_string(i);

    vector<int> ans(10, 0);

    for(auto c : str)
      ans[c - '0']++;

    cout << ans[0];
    for(int i=1; i<10; i++)
      cout << " " << ans[i];
    cout << "\n";
  }

  return 0;
}
