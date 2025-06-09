#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
using namespace std;

int main(){

  speedBoost;
  int n;
  int NC = 0;
  while((cin >> n), n){

    vector<int> layer(ceil(n/2.0));
    for(int i=0; i<n; i++){
      for(int j=0; j<n; j++){
        int v; cin >> v;
        layer[min(min(i, j), min(n-i-1, n-j-1))] += v;
      }
    }

    cout << "Case " << ++NC << ":";
    for(int i=0, z = ceil(n/2.0); i<z; i++)
      cout << " " << layer[i];
    cout << "\n";
  }

  return 0;
}
