#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
using namespace std;

int main(){

  speedBoost;
  int p, n; cin >> p >> n;
  vector<int> h(n);
  int diff;
  for(int i=0; i<n; i++) cin >> h[i];
  for(int i=1; i<n; i++){
    diff = abs(h[i] - h[i-1]);
    if(diff > p){
      cout << "GAME OVER\n";
      return 0;
    }
  }
  cout << "YOU WIN\n";

  return 0;
}
