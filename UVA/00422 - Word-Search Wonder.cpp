#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
using namespace std;

int dr[] = {1, 1, 0, -1, -1, -1, 0, 1};
int dc[] = {0, 1, 1, 1, 0, -1, -1, -1};

bool outside(int x, int y, int l){
  return (x < 0 || x >= l || y < 0 || y >= l);
}

int main(){

  speedBoost;
  int l; cin >> l;
  vector<string> grid(l);
  for(int i=0; i<l; i++)
    cin >> grid[i];

  string word;
  while(true){
    cin >> word;
    if(word == "0") break;

    bool found = false;
    for(int i=0; i<l && !found; i++){
      for(int j=0; j<l && !found; j++){
        for(int d=0; d<8; d++){
          int x = i, y = j, idx = 0;

          while(idx < word.size()){
            if(outside(x, y, l) || grid[x][y] != word[idx]) break;
            idx++;
            x += dr[d], y += dc[d];
          }

          if(idx == word.size()){
            x -= dr[d], y -= dc[d];
            cout << i+1 << "," << j+1 << " " << x+1 << "," << y+1 << "\n";
            found = true;
            break;
          }
        }
      }
    }

    if(!found) cout << "Not found\n";
  }

  return 0;
}
