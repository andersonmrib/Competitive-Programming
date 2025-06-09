#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
using namespace std;

int main(){

  int t; cin >> t;
  while(t--){

    string line; cin >> line;
    transform(line.begin(), line.end(), line.begin(), ::tolower);

    int ans = 1;
    for(auto c : line){
      if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 's')
        ans *= 3;
      else ans *= 2;
    }

    cout << ans << "\n";
  }

  return 0;
}
