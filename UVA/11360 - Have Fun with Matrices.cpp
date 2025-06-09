#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
using namespace std;

int n;

void row(vector<vector<int>> &grid, int a, int b){
  for(int j=0; j<n; j++)
    swap(grid[a][j], grid[b][j]);
}

void col(vector<vector<int>> &grid, int a, int b){
  for(int i=0; i<n; i++)
    swap(grid[i][a], grid[i][b]);
}

void inc(vector<vector<int>> &grid){
  for(int i=0; i<n; i++)
    for(int j=0; j<n; j++)
      grid[i][j] = (grid[i][j] + 1) % 10;
}

void dec(vector<vector<int>> &grid){
  for(int i=0; i<n; i++)
    for(int j=0; j<n; j++)
      grid[i][j] = (grid[i][j] - 1 + 10) % 10;
}

void transpose(vector<vector<int>> &grid){
  for(int i=0; i<n; i++)
    for(int j=i; j<n; j++)
      swap(grid[i][j], grid[j][i]);
}

void print(vector<vector<int>> &grid){
  for(int i=0; i<n; i++){
    for(int j=0; j<n; j++)
      cout << grid[i][j];
    cout << "\n";
  }
}

int main(){

  int T; cin >> T;
  int numCases = 0;
  bool first = true;

  while(T--){

    cin >> n;
    vector<vector<int>> grid(n, vector<int>(n));

    for(int i=0; i<n; i++)
      for(int j=0; j<n; j++)
        scanf("%1d", &grid[i][j]);

    int M; cin >> M;
    for(int i=0; i<M; i++){
      string command;
      int a, b; a--, b--;
      cin >> command;

      if(command == "row"){
        cin >> a >> b; a--, b--;
        row(grid, a, b);
      }
      else if(command == "col"){
        cin >> a >> b; a--, b--;
        col(grid, a, b);
      }
      else if(command == "inc")
        inc(grid);
      else if(command == "dec")
        dec(grid);
      else
        transpose(grid);
    }
    cout << "Case #" << ++numCases << "\n";
    print(grid);
    cout << "\n";
  }

  return 0;
}
