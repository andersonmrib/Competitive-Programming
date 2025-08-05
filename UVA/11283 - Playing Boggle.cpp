#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
using namespace std;

int dr[] = {1, 1, 0, -1, -1, -1, 0, 1};
int dc[] = {0, 1, 1, 1, 0, -1, -1, -1};

typedef vector<int> vi;
enum {UNVISITED = -1, VISITED = -2};

vector<vi> dfs_num;
string grid[4];

int getScore(int n){
  if(n == 3 || n == 4) return 1;
  else if(n == 5) return 2;
  else if(n == 6) return 3;
  else if(n == 7) return 5;
  else if(n >= 8) return 11;
  return 0;
}

bool dfs(int x, int y, string &word, int idx){
  if(idx == word.size())
    return true;
  if(x < 0 || x >= 4 || y < 0 || y >= 4)
    return false;
  if(grid[x][y] != word[idx] || dfs_num[x][y] == VISITED)
    return false;

  dfs_num[x][y] = VISITED;

  for(int d=0; d<8; d++){
    int nx = x + dr[d], ny = y + dc[d];
    if(dfs(nx, ny, word, idx+1)) return true;
  }

  dfs_num[x][y] = UNVISITED;
  return false;
}

int main(){

  speedBoost;
  int t; cin >> t; cin.ignore();
  int nc = 0;
  while(t--){

    for(int i=0; i<4; i++)
      cin >> grid[i];

    int M; cin >> M;
    int score = 0;
    while(M--){
      string word; cin >> word;

      bool found = false;
      for(int i=0; i<4 && !found; i++){
        for(int j=0; j<4 && !found; j++){
          dfs_num.assign(4, vi(4, UNVISITED));
          if(dfs(i, j, word, 0)) found = true;
        }
      }

      if(found)
        score += getScore(word.size());
    }

    cout << "Score for Boggle game #" << ++nc << ": " << score << "\n";
  }

  return 0;
}
