#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
using namespace std;

int main(){

  speedBoost;
  int t; cin >> t;
  while(t--){

    int n; cin >> n;

    int diff = INT_MIN;
    int biggest; cin >> biggest;

    for(int i=1; i<n; i++){
      int v; cin >> v;
      diff = max(diff, biggest - v);
      biggest = max(biggest, v);
    }
    cout << diff << "\n";
  }

  return 0;
}
