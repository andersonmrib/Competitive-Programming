#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
using namespace std;

void rotate90(vector<vector<char>> &grid){
  int n = grid.size();
  vector<vector<char>> temp(n, vector<char>(n));

  for(int i=0; i<n; i++)
    for(int j=0; j<n; j++)
      temp[j][n-i-1] = grid[i][j];

  grid = temp;
}

int compare(vector<vector<char>> &grid, vector<vector<char>> GRID){
  int ans = 0;
  int n = grid.size();
  int N = GRID.size();

  for(int i=0; i<=N - n; i++){
    for(int j=0; j<=N - n; j++){
      bool match = true;

      for(int x=0; x<n; x++){
        for(int y=0; y<n; y++){
          if(GRID[i+x][j+y] != grid[x][y]){
            match = false;
            break;
          }
        }
        if(!match) break;
      }
      if(match) ans++;
    }
  }
  return ans;
}

int main(){

  speedBoost;
  int N, n;
  while((cin >> N >> n), (N || n)){

    vector<vector<char>> GRID(N, vector<char>(N)), grid(n, vector<char>(n));
    for(int i=0; i<N; i++)
      for(int j=0; j<N; j++)
        cin >> GRID[i][j];

    for(int i=0; i<n; i++)
      for(int j=0; j<n; j++)
        cin >> grid[i][j];

    vector<int> counts(4);
    for(int r=0; r<4; r++){
      counts[r] = compare(grid, GRID);
      rotate90(grid);
    }

    for(int r=0; r<4; r++){
      if(r > 0) cout << " ";
      cout << counts[r];
    }
    cout << "\n";
  }

  return 0;
}
