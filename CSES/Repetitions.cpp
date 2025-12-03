#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
#define endl "\n"

using namespace std;

int main(){

  speedBoost;
  string s; cin >> s;

  int ans = 0, ctt = 1;
  for(int i=1; i<s.size(); i++){
    if(s[i] == s[i-1]) ctt++;
    else{
      ans = max(ans, ctt);
      ctt = 1;
    }
  }

  cout << max(ans, ctt) << endl;

  return 0;
}
