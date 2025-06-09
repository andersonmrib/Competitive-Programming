#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
using namespace std;

int dr[] = {1, 1, 0, -1, -1, -1, 0, 1};
int dc[] = {0, 1, 1, 1, 0, -1, -1, -1};
char grid[105][105];
int n, m;

bool canCheck(int row, int col){
  if(row >= 0 && row < n && col >= 0 && col < m)
    return true;
  return false;
}

int main(){

  speedBoost;
  int fields = 0;
  bool first = true;
  while((cin >> n >> m), (n || m)){

    cin.ignore();
    if(!first) cout << "\n";
    first = false;

    for(int i=0; i<n; i++)
      for(int j=0; j<m; j++)
        cin >> grid[i][j];

    int bombs;
    for(int i=0; i<n; i++){
      for(int j=0; j<m; j++){
        if(grid[i][j] == '.'){
          bombs = 0;
          for(int k=0; k<8; k++){
            int r = i + dr[k], c = j + dc[k];
            if(canCheck(r, c)){
              if(grid[r][c] == '*')
                bombs++;
            }
          }
          grid[i][j] = bombs + '0';
        }
        else if(grid[i][j] == '*') continue;
      }
    }

    cout << "Field #" << ++fields << ":\n";
    for(int i=0; i<n; i++){
      for(int j=0; j<m; j++){
        cout << grid[i][j];
      }
      cout << "\n";
    }
  }

  return 0;
}
