#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
using namespace std;

int main(){

  speedBoost;
  int t; cin >> t;
  while(t--){

    int n; cin >> n;
    vector<int> vec(n);
      for(int i=0; i<n; i++)
        cin >> vec[i];

    sort(vec.rbegin(), vec.rend());

    int ans = 0;
    int collected = 0;
    for(int i=0; i<n; i++){
      collected++;
      if(collected == 3){
        collected = 0;
        ans += vec[i];
      }
    }

    cout << ans << "\n";
  }

  return 0;
}
