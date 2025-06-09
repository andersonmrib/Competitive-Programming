#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
using namespace std;

int main(){

  speedBoost;
  int t; cin >> t;
  while(t--){

    int n; cin >> n;
    int coins[n];
    for(int i=0; i<n; i++)
      cin >> coins[i];

    int sum = 0, ans = 0;
    for(int i=0; i<n; i++)
      if(i == n-1 || sum + coins[i] < coins[i+1]){
      sum += coins[i], ans++;
    }
    cout << ans << endl;
  }

  return 0;
}
