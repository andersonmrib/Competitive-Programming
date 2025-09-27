#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
using namespace std;

typedef vector<int> vi;
vector<vi> AL;

vi match, vis;

enum {UNVISITED = -1, VISITED = -2};

int Aug(int L){
  if(vis[L] == VISITED) return 0;
  vis[L] = VISITED;
  for(auto R : AL[L])
    if((match[R] == -1) || Aug(match[R])){
      match[R] = L;
      return 1;
    }
  return 0;;
}

int main(){

  speedBoost;
  int t; cin >> t;
  int NC = 1;
  while(t--){

    int bolts, nuts; cin >> bolts >> nuts;
    AL.assign(bolts, vi());
    for(int b=0; b<bolts; b++){
      for(int n=0; n<nuts; n++){
        int fits; cin >> fits;
        if(fits) AL[b].push_back(n);
      }
    }

    match.assign(nuts, -1);
    int max_matches = 0;
    for(int b=0; b<bolts; b++){
      vis.assign(bolts, UNVISITED);
      max_matches += Aug(b);
    }

    cout << "Case " << NC++ << ": ";
    cout << "a maximum of " << max_matches << " nuts and bolts ";
    cout << "can be fitted together\n";
  }

  return 0;
}
