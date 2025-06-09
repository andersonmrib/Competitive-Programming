#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
using namespace std;

typedef vector<int> vi;
vector<set<int>> AL; // Graph can't have duplicates
vi numPaths;

void dfs(int u){
  for(auto v : AL[u]){
    if(!numPaths[v])
      dfs(v);
    numPaths[u] += numPaths[v];
  }
  if(!numPaths[u]) numPaths[u] = 1;
}

int query(int u, const char *c){
  if(u != *c) return u < *c ? numPaths[u] : 0;

  int ans = 0;
  for(auto v : AL[u])
    ans += query(v, c+1);

  return ans;
}

int main(){

  speedBoost;
  int t; cin >> t;
  while(t--){

    int N, M; cin >> N >> M;
    AL.assign(128, set<int>()); numPaths.assign(128, 0);
    for(int i=0; i<M; i++){
      string s; cin >> s;
      AL[s[0]].insert(s[1]);
    }

    for(int i='A'; i < N + 'A'; i++)
      if(!numPaths[i]) dfs(i);

    int Q; cin >> Q;
    for(int i=0; i<Q; i++){
      string s; cin >> s;
      cout << s << ": ";
      cout << 1 + query(s[0], s.c_str()) << "\n";
    }
  }

  return 0;
}