#include <bits/stdc++.h>
using namespace std;

int main(){

  int t;
  while(cin >> t){

    vector<int> teas;
    int x;
    for(int i=0; i<5; i++){
      cin >> x;
      teas.push_back(x);
    }
    int ans = 0;
    for(auto tea : teas){
      if(tea == t) ans++;
    }
    cout << ans << endl;
  }

  return 0;
}
