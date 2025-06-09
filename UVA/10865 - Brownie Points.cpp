#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
using namespace std;

int main(){

  speedBoost;
  int n;
  while((cin >> n), n){

    // 1 and 3    2 and 4
    int Stan = 0, Ollie = 0;
    vector<pair<int, int>> points;
    for(int i=0; i<n; i++){
      int x, y; cin >> x >> y;
      points.push_back({x, y});
    }

    int originX = points[n/2].first;
    int originY = points[n/2].second;

    for(auto [xi, yi] : points){
      if(xi == originX || yi == originY) continue;
      if((xi > originX && yi > originY) || (xi < originX && yi < originY)) Stan++;
      else if((xi < originX && yi > originY) || (xi > originX && yi < originY)) Ollie++;
    }
    cout << Stan << " " << Ollie << "\n";
  }

  return 0;
}
