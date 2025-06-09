#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
using namespace std;

int main(){

  speedBoost;
  int t; cin >> t;

  while(t--){

    string str; cin >> str;
    int ans = 0, streak = 0;
    for(auto c : str){
      if(c == 'O'){
        streak++;
        ans += streak;
      }
      else streak = 0;
    }
    cout << ans << "\n";
  }

  return 0;
}
