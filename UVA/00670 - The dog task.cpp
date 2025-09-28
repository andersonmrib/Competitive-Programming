#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
using namespace std;

typedef vector<int> vi;
typedef pair<int, int> ii;
vector<vi> AL;

vi vis, match;

enum {VISITED = -1, UNVISITED = -2};

double euclid_dist(ii p1, ii p2){
  return hypot(p1.first - p2.first, p1.second - p2.second);
}

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

void solve(){

  int n, m; cin >> n >> m;
  vector<ii> bob_route, int_route;
  for(int i=0; i<n; i++){
    int x, y; cin >> x >> y;
    bob_route.emplace_back(x, y);
  }

  for(int i=0; i<m; i++){
    int x, y; cin >> x >> y;
    int_route.emplace_back(x, y);
  }

  AL.assign(n-1, vi());
  for(int i=0; i<n-1; i++){
    double bob_dist = euclid_dist(bob_route[i], bob_route[i+1]);
    for(int j=0; j<m; j++){
      double ralph_dist = euclid_dist(bob_route[i], int_route[j]) +
                          euclid_dist(int_route[j], bob_route[i+1]);      
      if(ralph_dist <= 2 * bob_dist)
        AL[i].push_back(j);
    }
  }

  match.assign(m, -1);
  int max_matches = 0;
  for(int i=0; i<n-1; i++){
    vis.assign(n-1, UNVISITED);
    max_matches += Aug(i);
  }

  // The problem started to get hard
  // for me from here!
  vi reconstruct(n-1, -1);
  for(int i=0; i<m; i++)
    if(match[i] != -1)
      reconstruct[match[i]] = i;

  vector<ii> final_route;
  final_route.push_back(bob_route[0]);
  for(int i=0; i<n-1; i++){
    if(reconstruct[i] != -1)
      final_route.push_back(int_route[reconstruct[i]]);
    final_route.push_back(bob_route[i+1]);
  }

  cout << final_route.size() << "\n";
  for(int i=0; i<final_route.size(); i++){
    if(i > 0) cout << " ";
    cout << final_route[i].first << " " << final_route[i].second;
  }
  cout << "\n";
}

int main(){

  speedBoost;
  int t; cin >> t;
  while(t--){
    solve();
    if(t) cout << "\n";
  }

  return 0;
}
