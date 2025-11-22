#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
#define endl "\n"

using namespace std;

typedef vector<int> vi;
typedef tuple<int, int, int> tup;
const int INF = 1e9;

int main(){

  speedBoost;
  int n, m;
  int NC = 1;
  while(cin >> n >> m){

    vector<vi> mtr(n, vi(n, INF));
    for(int i=0; i<n; i++)
      mtr[i][i] = 0;

    vector<tup> edges;
    for(int i=0; i<m; i++){
      int u, v, w; cin >> u >> v >> w;
      mtr[u][v] = w;
      mtr[v][u] = w;
      edges.emplace_back(u, v, w);
      edges.emplace_back(v, u, w);
    }

    for(int k=0; k<n; k++){
      for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
          if(mtr[i][k] != INF && mtr[k][j] != INF)
            mtr[i][j] = min(mtr[i][j], mtr[i][k] + mtr[k][j]);
        }
      }
    }

    cout << "Set #" << NC++ << endl;
    int q; cin >> q;
    while(q--){

      int a, b; cin >> a >> b;
      int shortest = mtr[a][b];
      int second_best = INF;

      for(auto [u, v, w] : edges){
        if(mtr[a][u] != INF && mtr[v][b] != INF){
          int this_path = mtr[a][u] + w + mtr[v][b];
          if(this_path > shortest)
            second_best = min(second_best, this_path);
        }
      }

      if(second_best == INF) cout << "?" << endl;
      else                   cout << second_best << endl;
    }
  }

  return 0;
}
