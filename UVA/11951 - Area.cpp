#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
using namespace std;

// Better version: running ~0.040 seconds
int main(){

  speedBoost;
  int t; cin >> t;
  int NC = 0;
  while(t--){

    int n, m, k;
    cin >> n >> m >> k;

    vector<vector<int>> dp(n, vector<int>(m));
    for(int i=0; i<n; i++){
      for(int j=0; j<m; j++){
        cin >> dp[i][j];
        if(j > 0) dp[i][j] += dp[i][j-1];
      }
    }

    int maxPlotSize = 0, bestPrice = 0;
    for(int l=0; l<m; l++){
      for(int r=l; r<m; r++){
        vector<int> sum(n, 0);
        for(int i=0; i<n; i++){
          sum[i] = dp[i][r];
          if(l > 0) sum[i] -= dp[i][l-1];
        }

        int cur = 0, top = 0;
        for(int bottom=0; bottom<n; bottom++){
          cur += sum[bottom];
          while(cur > k && top <= bottom)
            cur -= sum[top++];

          int area = (bottom - top + 1) * (r - l + 1);
          if(area > maxPlotSize || (area == maxPlotSize && cur < bestPrice)){
            maxPlotSize = area;
            bestPrice = cur;
          }
        }
      }
    }

    cout << "Case #" << ++NC << ": ";
    cout << maxPlotSize << " " << bestPrice << "\n";
  }

  return 0;
}

// Naive version
/*
#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
#define int long long
using namespace std;

int32_t main(){

  speedBoost;
  int t; cin >> t;
  int NC = 0;
  while(t--){

    int n, m, k;
    cin >> n >> m >> k;

    vector<vector<int>> dp(n, vector<int>(m));
    for(int i=0; i<n; i++){
      for(int j=0; j<m; j++){
        cin >> dp[i][j];
        if(i > 0) dp[i][j] += dp[i-1][j];
        if(j > 0) dp[i][j] += dp[i][j-1];
        if(i > 0 && j > 0) dp[i][j] -= dp[i-1][j-1];
      }
    }

    int maxPlotSize = 0;
    int bestPrice = 0;
    for(int i=0; i<n; i++){
      for(int j=0; j<m; j++){
        for(int x=i; x<n; x++){
          for(int y=j; y<m; y++){
            int area = (x-i+1) * (y-j+1);
            int cur = dp[x][y];

            if(i > 0) cur -= dp[i-1][y];
            if(j > 0) cur -= dp[x][j-1];
            if(i > 0 && j > 0) cur += dp[i-1][j-1];

            if(cur <= k){
              if((area > maxPlotSize) || (area == maxPlotSize && cur < bestPrice)){
                bestPrice = cur;
                maxPlotSize = area;
              }
            }
          }
        }
      }
    }

    cout << "Case #" << ++NC << ": ";
    cout << maxPlotSize << " " << bestPrice << "\n";
  }

  return 0;
}
*/
