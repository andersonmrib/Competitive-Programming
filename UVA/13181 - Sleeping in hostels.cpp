#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
using namespace std;

int main(){

  speedBoost;
  string grid;
  while(cin >> grid){

    int ans = 0, prev = -1, len = grid.size();
    for(int i=0; i<len; i++){

      if(grid[i] == 'X'){
        if(prev == -1){
          ans = max(ans, i-1);
          prev = i;
        }
        else{
          ans = max(ans, (i - prev - 2)/2);
          prev = i;
        }
      }
    }

    if(prev != len - 1)
      ans = max(ans, len - prev - 2);
    cout << ans << "\n";
  }

  return 0;
}
