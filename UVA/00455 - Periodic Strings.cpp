#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
#define int long long
#define endl "\n"

using namespace std;

int32_t main(){

  speedBoost;
  int t; cin >> t;
  bool first = true;
  while(t--){

    string s; cin >> s;

    int n = s.size();
    for(int k=1; k<=n; k++){
      if(n % k == 0){
        bool ok = true;
        for(int i=k; i<n; i++){
          if(s[i] != s[i%k]){
            ok = false;
            break;
          }
        }
        if(ok){
          if(!first) cout << endl;
          first = false;
          cout << k << endl;
          break;
        }
      }
    }
  }

  return 0;
}
