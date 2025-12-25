#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
#define endl "\n"

using namespace std;

typedef vector<int> vi;

int main(){

  speedBoost
  vi coins = {1, 5, 15, 30, 150};
  vi ans(5, 0);

  int n; cin >> n;
  for(int i=4; i>=0; i--){
    while(n - coins[i] >= 0){
      n -= coins[i];
      ans[i]++;
    }
  }

  for(int i=0; i<5; i++){
    if(i > 0) cout << " ";
    cout << ans[i];
  }

  cout << endl;

  return 0;
}
