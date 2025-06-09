#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

int dr[] = {1, 0, -1, 0};
int dc[] = {0, 1, 0, -1};

int N;
char grid[100][100];

void floodfill(int r, int c){
  if((r < 0) || (r >= N) || (c < 0) || (c >= N)) return;
  if(grid[r][c] != 'x' && grid[r][c] != '@') return;
  grid[r][c] = '#'; // visited
  for(int d=0; d<4; d++)
    floodfill(r+dr[d], c+dc[d]);
}

int main(){

  int testCases = 0;
  int t; cin >> t;
  while(t--){

    cin >> N;
    for(int i=0; i<N; i++)
      for(int j=0; j<N; j++)
        cin >> grid[i][j];

    int ans = 0;
    for(int i=0; i<N; i++)
      for(int j=0; j<N; j++)
        if(grid[i][j] == 'x'){
          ans++;
          floodfill(i, j);
        }

    cout << "Case " << ++testCases << ": " << ans << endl;
  }

  return 0;
}
