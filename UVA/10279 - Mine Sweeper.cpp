#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
using namespace std;

int dr[] = {1, 1, 0, -1, -1, -1, 0, 1};
int dc[] = {0, 1, 1, 1, 0, -1, -1, -1};

char grid[11][11];
char touched[11][11];
int n;

bool canCheck(int row, int col){
  if(row >= 0 && row < n && col >= 0 && col < n)
    return true;
  return false;
}

int main(){

  speedBoost;
  int t; cin >> t;
  while(t--){

    cin >> n;
    for(int i=0; i<n; i++)
      for(int j=0; j<n; j++)
        cin >> grid[i][j];

    for(int i=0; i<n; i++)
      for(int j=0; j<n; j++)
        cin >> touched[i][j];

    int bombs;
    bool explosion = false;
    for(int i=0; i<n; i++){
      for(int j=0; j<n; j++){
        if(touched[i][j] == 'x'){
          if(grid[i][j] == '.'){
            bombs = 0;
            for(int k=0; k<8; k++){
              int r = dr[k] + i, c = dc[k] + j;
              if(canCheck(r, c))
                if(grid[r][c] == '*') bombs++;
            }
            grid[i][j] = bombs + '0';
          }
          else if(grid[i][j] == '*'){
            explosion = true;
            continue;
          }
        }
        else continue;
      }
    }

    if(!explosion){
      for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
          if(grid[i][j] == '*') cout << ".";
          else                  cout << grid[i][j];
        }
        cout << "\n";
      }
    }

    else{
      for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
          cout << grid[i][j];
        }
        cout << "\n";
      }
    }

    if(t) cout << "\n";
  }

  return 0;
}
