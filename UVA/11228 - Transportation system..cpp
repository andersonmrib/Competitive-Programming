#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
using namespace std;

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
vi taken;

int main(){

  speedBoost;
  int T; cin >> T;
  int numCases = 0;
  while(T--){

    int n, r; cin >> n >> r;
    vii coordinates;
    for(int i=0; i<n; i++){
      int x, y; cin >> x >> y;
      coordinates.push_back({x, y});
    }

    taken.assign(n, 0);
    priority_queue<ii> pq;
    pq.push({0, 0});

    int numStates = 1;
    double roads = 0, rails = 0;

    while(!pq.empty()){
      auto [w, u] = pq.top(); pq.pop();
      w = -w, u = -u;
      if(taken[u]) continue;

      if(sqrt(w) > r){
        numStates++;
        rails += sqrt(w);
      }
      else
        roads += sqrt(w);

      taken[u] = 1;
      bool ok = true;
      for(int i=0; i<n; i++){
        if(!taken[i]){
          ok = false;
          int xDist = coordinates[i].first - coordinates[u].first;
          int yDist = coordinates[i].second - coordinates[u].second;
          xDist *= xDist;
          yDist *= yDist;
          pq.push({-1*(xDist+yDist), -1*i});
        }
      }
      if(ok) break;
    }
    printf("Case #%d: %d %.0lf %.0lf\n", ++numCases, numStates, roads, rails);
  }

  return 0;
}
