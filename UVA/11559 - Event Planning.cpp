#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
#define endl "\n"
using namespace std;

const int INF = 1e9;

int main(){

  speedBoost;
  int n, b, h, w;
  while(cin >> n >> b >> h >> w){

    int minimum_cost = INF;
    for(int i=0; i<h; i++){
      int p; cin >> p;
      for(int j=0; j<w; j++){
        int a; cin >> a;
        // Not all rooms are available
        if(a < n){
          continue;
        }
        // We can pick this one
        else{
          int total_cost = p * n;
          if(total_cost <= b) minimum_cost = min(minimum_cost, total_cost);
        }
      }
    }

    if(minimum_cost == INF) cout << "stay home\n";
    else                    cout << minimum_cost << endl;
  }

  return 0;
}
