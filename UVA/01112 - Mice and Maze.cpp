#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
using namespace std;

int maze[101][101];
const int INF = 1e9;

int main(){

  speedBoost;
  int t; cin >> t;
  while(t--){

    int n, exit, time; cin >> n >> exit >> time;
    exit--;
    for(int i=0; i<n; i++){
      for(int j=0; j<n; j++)
        maze[i][j] = INF;
      maze[i][i] = 0;
    }

    int E; cin >> E;
    for(int i=0; i<E; i++){
      int a, b, w; cin >> a >> b >> w;
      a--, b--;
      maze[a][b] = w;
    }

    for(int k=0; k<n; k++)
      for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
          maze[i][j] = min(maze[i][j], maze[i][k] + maze[k][j]);

    int ans = 0;
    for(int i=0; i<n; i++)
      if(maze[i][exit] <= time) ans++;

    cout << ans << "\n";
    if(t) cout << "\n";
  }

  return 0;
}
