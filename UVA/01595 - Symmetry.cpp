#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
#define EPS 1e-9
using namespace std;

typedef long long ll;

int main(){

  speedBoost;
  int t; cin >> t;
  while(t--){

    int n; cin >> n;

    vector<pair<int, int>> points(n);
    unordered_set<ll> pointSet;

    int xMin = INT_MAX, xMax = INT_MIN;
    for(int i=0; i<n; i++){
      int x, y; cin >> x >> y;
      points[i] = {x, y};
      pointSet.insert((ll)20001 * x + y);

      xMin = min(xMin, x);
      xMax = max(xMax, x);
    }

    int symmetryX = xMin + xMax;
    bool hasSolution = true;
    for(auto [x, y] : points){

      int mirrorX = symmetryX - x;
      if(pointSet.find((ll)20001 * mirrorX + y) == pointSet.end()){
        hasSolution = false;
        break;
      }
    }

    if(hasSolution) cout << "YES\n";
    else            cout << "NO\n";
  }

  return 0;
}
