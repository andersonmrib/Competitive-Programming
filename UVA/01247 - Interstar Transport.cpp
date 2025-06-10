#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
using namespace std;

typedef vector<int> vi;

const int MAX = 30;
const int INF = 1e9;
int g[MAX][MAX], parent[MAX][MAX];
vector<char> ans;

void getPath(int i, int j){
  if(i != j) getPath(i, parent[i][j]);
  ans.push_back(j + 'A');
}

int main(){

  speedBoost;
  int s, p; cin >> s >> p;

  for(int i=0; i<MAX; i++)
    for(int j=0; j<MAX; j++)
      parent[i][j] = -1;

  for(int i=0; i<MAX; i++){
    for(int j=0; j<MAX; j++)
      g[i][j] = INF;
    g[i][i] = 0;
  }

  for(int i=0; i<p; i++){
    char u, v; int w;
    cin >> u >> v >> w;
    int a = u - 'A', b = v - 'A';
    g[a][b] = g[b][a] = w;
    parent[a][b] = a, parent[b][a] = b;
  }

  for(int k=0; k<MAX; k++)
    for(int i=0; i<MAX; i++)
      for(int j=0; j<MAX; j++)
        if(g[i][k] + g[k][j] < g[i][j]){
          g[i][j] = g[i][k] + g[k][j];
          parent[i][j] = parent[k][j];
        }
  int q; cin >> q;
  while(q--){
    ans.clear();
    char src, dst;
    cin >> src >> dst;
    int u = src - 'A', v = dst - 'A';

    getPath(u, v);
    for(int i=0; i<ans.size(); i++){
      if(i > 0) cout << " " << ans[i];
      else      cout << ans[i];
    }
    cout << "\n";
  }

  return 0;
}
