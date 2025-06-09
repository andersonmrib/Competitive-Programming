#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
using namespace std;

int main(){

  speedBoost;
  int n, p; cin >> n >> p;

  vector<int> vec(n, 0);
  for(int i=0; i<n; i++){
    cin >> vec[i];
    vec[i] -= p;
  }

  int sum = 0, ans = 0;
  for(auto x : vec){
    sum += x;
    if(sum < 0) sum = 0;
    ans = max(ans, sum);
  }

  cout << ans << "\n";

  return 0;
}
