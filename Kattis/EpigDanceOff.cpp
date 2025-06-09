#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
using namespace std;

int main(){

  speedBoost;
  int N, M; cin >> N >> M;
  char grid[N][M];

  for(int i=0; i<N; i++)
    for(int j=0; j<M; j++)
      cin >> grid[i][j];

  int ans = 0;
  // Simply count the number of blank columns
  for(int i=0; i<M; i++){
    bool ok = true;
    for(int j=0; j<N; j++){
      if(grid[j][i] == '$'){
        ok = false;
        break;
      }
    }
    if(ok) ans++;
  }

  cout << ans + 1 << "\n";

  return 0;
}
