#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
using namespace std;

typedef pair<int, int> ii;
typedef vector<int> vi;

char grid[51][51];
vector<int> visited;
int h, w, ctt;

int dr[] = {1, 0, -1, 0};
int dc[] = {0, 1, 0, -1};

bool inside(int x, int y){
  return x >= 0 && x < h && y >= 0 && y < w;
}

void flood_dot(int i, int j){
  if(!inside(i, j) || grid[i][j] != 'X') return;
  grid[i][j] = '*';
  for(int d=0; d<4; d++)
    flood_dot(i + dr[d], j + dc[d]);
}

int flood_dice(int i, int j){
  if(!inside(i, j) || grid[i][j] == '.') return 0;
  if(grid[i][j] == 'X'){
    flood_dot(i, j);
    ctt++;
  }
  grid[i][j] = '.';
  for(int d=0; d<4; d++)
    flood_dice(i + dr[d], j + dc[d]);
  return ctt;
}

int main(){

  speedBoost;
  int NC = 1;
  while((cin >> w >> h), (w || h)){

    for(int i=0; i<h; i++)
      for(int j=0; j<w; j++)
        cin >> grid[i][j];

    vector<int> ans;
    for(int i=0; i<h; i++){
      for(int j=0; j<w; j++){
        if(grid[i][j] == '*'){
          ctt = 0;
          int getThis = flood_dice(i, j);
          ans.push_back(getThis);
        }
      }
    }

    sort(ans.begin(), ans.end());
    cout << "Throw " << NC++ << "\n";
    for(int i=0; i<ans.size(); i++){
      if(i > 0) cout << " ";
      cout << ans[i];
    }
    cout << "\n\n";
  }

  return 0;
}
