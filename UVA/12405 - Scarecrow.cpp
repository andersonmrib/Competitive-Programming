#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
using namespace std;

int main(){

  speedBoost;
  int t; cin >> t;
  int NC = 0;
  while(t--){

    int n; cin >> n;
    string s; cin >> s;

    int ans = 0;
    for(int i=0; i<s.size(); i++)
      if(s[i] == '.'){
        ans++;
        i+=2;
      }

    cout << "Case " << ++NC << ": ";
    cout << ans << "\n";
  }

  return 0;
}
