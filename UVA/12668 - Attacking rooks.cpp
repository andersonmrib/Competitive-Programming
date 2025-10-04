#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
#define endl "\n"
using namespace std;

typedef vector<int> vi;
vector<vi> AL;

vi vis, match;

enum {VISITED = -1, UNVISITED = -2};

int Aug(int L){
  if(vis[L] == VISITED) return 0;
  vis[L] = VISITED;
  for(auto R : AL[L])
    if((match[R] == -1) || Aug(match[R])){
      match[R] = L;
      return 1;
    }
  return 0;
}

int main(){

  speedBoost;
  int n;
  while(cin >> n){

    vector<string> grid(n);
    for(int i=0; i<n; i++)
      cin >> grid[i];

    vector<vi> horiz_id(n, vi(n, -1));
    int horiz_count = -1;
    for(int i=0; i<n; i++){
      for(int j=0; j<n; j++){
        if(grid[i][j] == '.'){
          if(j == 0 || grid[i][j-1] == 'X')
            horiz_count++;

          horiz_id[i][j] = horiz_count;
        }
      }
    }

    vector<vi> vertical_id(n, vi(n, -1));
    int vertical_count = -1;
    for(int j=0; j<n; j++){
      for(int i=0; i<n; i++){
        if(grid[i][j] == '.'){
          if(i == 0 || grid[i-1][j] == 'X')
            vertical_count++;

          vertical_id[i][j] = vertical_count;
        }
      }
    }

    AL.assign(horiz_count+1, vi());
    for(int i=0; i<n; i++)
      for(int j=0; j<n; j++)
        if(grid[i][j] == '.')
          AL[horiz_id[i][j]].push_back(vertical_id[i][j]);

    match.assign(vertical_count+1, -1);
    int max_matches = 0;
    for(int i=0; i<=horiz_count; i++){
      vis.assign(horiz_count+1, UNVISITED);
      max_matches += Aug(i);
    }

    cout << max_matches << endl;
  }

  return 0;
}
