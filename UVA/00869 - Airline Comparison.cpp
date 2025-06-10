#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
using namespace std;

typedef vector<int> vi;
const int INF = 1e9;
const int MAX = 26;

int main(){

  speedBoost;
  int t; cin >> t;
  while(t--){

    int n; cin >> n;
    vector<vector<bool>> g1(MAX, vector<bool>(MAX, false));
    for(int i=0; i<MAX; i++) g1[i][i] = true;

    for(int i=0; i<n; i++){
      char u, v; cin >> u >> v;
      g1[u - 'A'][v - 'A'] = 1;
    }

    int m; cin >> m;
    vector<vector<bool>> g2(MAX, vector<bool>(MAX, false));
    for(int i=0; i<MAX; i++) g2[i][i] = true;

    for(int i=0; i<m; i++){
      char u, v; cin >> u >> v;
      g2[u - 'A'][v - 'A'] = 1;
    }

    for(int k=0; k<MAX; k++)
      for(int i=0; i<MAX; i++)
        for(int j=0; j<MAX; j++)
          g1[i][j] = g1[i][j] || (g1[i][k] && g1[k][j]);

    for(int k=0; k<MAX; k++)
      for(int i=0; i<MAX; i++)
        for(int j=0; j<MAX; j++)
          g2[i][j] = g2[i][j] || (g2[i][k] && g2[k][j]);

    if(g1 == g2) cout << "YES\n";
    else         cout << "NO\n";
    if(t) cout << "\n";
  }

  return 0;
}
