#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
using namespace std;

typedef vector<int> vi;
typedef pair<double, double> dd;
vector<vi> AL;

vi vis, match;
enum {VISITED = -1, UNVISITED = -2};

int Aug(int L){
  if(vis[L] == VISITED) return 0;
  vis[L] = VISITED;
  for(auto R : AL[L])
  if((match[R] == -1) || Aug(match[R])){
    match[R] = L;
    return 1;
  }
  return 0;
}

int main(){

  speedBoost;
  int n, m, s, v;
  while(cin >> n >> m >> s >> v){

    AL.assign(n, vi());
    vector<dd> gophers, holes;
    for(int i=0; i<n; i++){
      double x, y; cin >> x >> y;
      gophers.emplace_back(x, y);
    }

    for(int i=0; i<m; i++){
      double x, y; cin >> x >> y;
      holes.emplace_back(x, y);
    }

    // t = d / v
    for(int g=0; g<n; g++){
      for(int h=0; h<m; h++){
        double dx = gophers[g].first - holes[h].first;
        double dy = gophers[g].second - holes[h].second;
        double d = hypot(dx, dy);
        double t = d/(double)v;
        // If possible to create and edge between these 2
        if(t <= s)
          AL[g].emplace_back(h);
      }
    }

    match.assign(m, -1);
    int max_match = 0;
    for(int g=0; g<n; g++){
      vis.assign(n, UNVISITED);
      max_match += Aug(g);
    }

    cout << n - max_match << "\n";
  }

  return 0;
}
