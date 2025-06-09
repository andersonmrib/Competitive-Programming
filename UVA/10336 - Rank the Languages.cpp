#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
using namespace std;

int h, w;
int dr[] = {1, 0, -1, 0};
int dc[] = {0, 1, 0, -1};

bool reachable(int i, int j){
  return (i >= 0 && i < h && j >= 0 && j < w);
}

void floodfill(vector<string> &grid, int i, int j, char c){
  if(!reachable(i, j)) return;
  if(grid[i][j] != c) return;
  grid[i][j] = '.';
  for(int d=0; d<4; d++)
    floodfill(grid, i+dr[d], j+dc[d], c);
}

struct st{
  char c;
  int freq;
  bool operator<(const st &other){
    if(freq != other.freq)
      return freq > other.freq;
    return c < other.c;
  }
};

int main(){

  speedBoost;
  int t; cin >> t;
  int NC = 0;
  while(t--){

    cin >> h >> w;
    cin.ignore();

    vector<string> grid(h);
    for(int i=0; i<h; i++)
      cin >> grid[i];

    cout << "World #" << ++NC << "\n";
    unordered_map<char, int> umap;
    for(int i=0; i<h; i++){
      for(int j=0; j<w; j++){
        char c = grid[i][j];
        if(c != '.'){
          floodfill(grid, i, j, c);
          umap[c]++;
        }
      }
    }

    vector<st> ans;
    for(auto [ch, num] : umap)
      ans.push_back({ch, num});

    sort(ans.begin(), ans.end());

    for(auto [a, b] : ans)
      cout << a << ": " << b << "\n";
  }

  return 0;
}
