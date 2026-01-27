#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
#define int long long
#define endl "\n"

using namespace std;

typedef vector<int> vi;

const int INF = 1e12;
const int lim = 505;

int32_t main(){

  speedBoost;
  int n, m, q;
  cin >> n >> m >> q;

  int g[lim][lim];
  for(int i=0; i<lim; i++){
    for(int j=0; j<lim; j++)
      g[i][j] = INF;
    g[i][i] = 0;
  }

  for(int i=0; i<m; i++){
    int a, b, c; cin >> a >> b >> c;
    a--, b--;
    if(c < g[a][b])
      g[a][b] = g[b][a] = c;
  }

  for(int k=0; k<lim; k++)
    for(int i=0; i<lim; i++)
      for(int j=0; j<lim; j++)
        g[i][j] = min(g[i][j], g[i][k] + g[k][j]);

  while(q--){
    int a, b; cin >> a >> b;
    a--, b--;
    if(g[a][b] == INF) cout << -1;
    else               cout << g[a][b];
    cout << endl;
  }

  return 0;
}
