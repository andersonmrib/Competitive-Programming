#include<bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
using namespace std;

typedef vector<int> vi;
vector<vi> AL, AL_T;

vi dfs_num, S;

enum {UNVISITED = -1};

void kosaraju(int u, int pass){
  dfs_num[u] = 1;
  for(auto v : AL[u]){
    if(dfs_num[v] == UNVISITED)
      kosaraju(v, pass);
  }
    if(pass == 1)
      S.push_back(u);
}

int main(){

  speedBoost;
  int t; cin >> t;
  while(t--){

    int n, m; cin >> n >> m;
    AL.assign(n, vi()); AL_T.assign(n, vi());
    dfs_num.assign(n, UNVISITED); S.clear();

    for(int i=0; i<m; i++){
      int x, y; cin >> x >> y;
      x--, y--;
      AL[x].emplace_back(y);
      AL_T[y].emplace_back(x);
    }

    for(int i=0; i<n; i++)
      if(dfs_num[i] == UNVISITED)
        kosaraju(i, 1);

    int numSCC = 0;
    dfs_num.assign(n, UNVISITED);
    reverse(S.begin(), S.end());

    for(auto x : S){
      if(dfs_num[x] == UNVISITED){
        numSCC++;
        kosaraju(x, 2);
      }
    }

    cout << numSCC << "\n";
  }
  return 0;
}
