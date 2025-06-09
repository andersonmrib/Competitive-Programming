#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
using namespace std;

typedef vector<int> vi;
typedef pair<int, int> ii;

int main(){

  speedBoost;
  int M;
  while(cin >> M){

    vector<string> grid(M);
    vector<ii> pos1, pos3;
    for(int i=0; i<M; i++)
      cin >> grid[i];

    int count1 = 0, count3 = 0;
    for(int i=0; i<M; i++){
      for(int j=0; j<M; j++){
        if(grid[i][j] == '1'){
          count1++;
          pos1.push_back({i, j});
        }
        else if(grid[i][j] == '3'){
          count3++;
          pos3.push_back({i, j});
        }
      }
    }

    int ans = INT_MIN;
    // Manhattan distance
    for(int i=0; i<count1; i++){
      int dist = INT_MAX;
      for(int j=0; j<count3; j++)
        dist = min(dist, abs(pos1[i].first - pos3[j].first) +
                         abs(pos1[i].second - pos3[j].second));

        ans = max(ans, dist);
    }

    cout << ans << "\n";
  }

  return 0;
}


