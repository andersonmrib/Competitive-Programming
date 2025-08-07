#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
using namespace std;

int dr[] = {1, 1, 0, -1, -1, -1, 0, 1};
int dc[] = {0, 1, 1, 1, 0, -1, -1, -1};

int main(){

  speedBoost;

  int l; cin >> l;
  vector<string> grid;

  for(int i=0; i<l; i++){
    string line; cin >> line;
    grid.push_back(line);
  }

  while(true){
    string word; cin >> word;

    if(word == "0") break;

    bool found = false;

    for(int i=0; i<l && !found; i++){
      for(int j=0; j<l && !found; j++){
        for(int d=0; d<8; d++){
          int x = i, y = j, idx = 0;

          while(idx < word.size()){
            if(x < 0 || x >= l || y < 0 || y >= l || grid[x][y] != word[idx])
              break;
            idx++;
            x += dr[d], y += dc[d];
          }

          if(idx == word.size()){
            found = true;
            cout << i+1 << "," << j+1 << " " << x-dr[d]+1 << "," << y-dc[d]+1 << "\n";
            break;
          }
        }
      }
    }

    if(!found)
      cout << "Not found\n";
  }

  return 0;
}
