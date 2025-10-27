#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
#define endl "\n"
using namespace std;

int n, m; // distinct chocolates, number of boxes
double dp[101][101];

int main(){

  speedBoost;
  int NC = 1;
  while(cin >> n){

    if(n == -1) return 0;
    cin >> m;

    memset(dp, 0, sizeof dp);

    dp[0][0] = 1.0;
    double m_double = (double)m;

    // For every chocolate...
    for(int i=1; i<=n; i++){
      // And for every box...
      for(int j=1; j<=m; j++){

        double prob_hit  = dp[i-1][j] * (j / m_double);
        double prob_miss = dp[i-1][j-1] * (m - (j - 1)) / m_double;
        dp[i][j] = prob_hit + prob_miss;
      }
    }

    cout << "Case " << NC++ << ": ";
    cout << fixed << setprecision(7);
    cout << 1.0 - dp[n][m] << endl;
  }

  return 0;
}
