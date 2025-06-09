#include <bits/stdc++.h>
using namespace std;

int main(){

  int tc; cin >> tc;
  while(tc--){

    vector<string> vec;
    int e, b; cin >> e >> b;
    for(int i=e; i<=b; i++)
      vec.push_back(to_string(i));

    for(auto s : vec) cout << s;
    reverse(vec.begin(), vec.end());
    for(auto s : vec){
      reverse(s.begin(), s.end());
      cout << s;
    }
    cout << endl;
  }

  return 0;
}
