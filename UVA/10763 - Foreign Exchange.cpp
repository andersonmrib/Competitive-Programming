#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
using namespace std;

int main(){

  speedBoost;
  int n;
  while((cin >> n), n){

    map<pair<int, int>, int> freq;

    for(int i=0; i<n; i++){
      int x, y; cin >> x >> y;
      freq[{x, y}]++;
    }

    bool hasSolution = true;
    for(auto [p, qtd] : freq){
      if(freq[{p.second, p.first}] != qtd){
        hasSolution = false;
        break;
      }
    }

    if(hasSolution) cout << "YES\n";
    else            cout << "NO\n";
  }

  return 0;
}
