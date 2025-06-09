#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
using namespace std;

int dp[101][101];
char board[101][101];
const int MOD = 1000007;
int n;

int solve(int r, int c){
  if(r < 0 || r >= n || c < 0 || c >= n) return 0;
  if(r == 0) return 1;

  int &ans = dp[r][c];
  if(ans != -1) return ans;
  ans = 0;

  // left diagonal
  if(r > 0 && c > 0){
    if(board[r-1][c-1] == '.') 
      ans = (ans + solve(r-1, c-1))%MOD;
    else if(board[r-1][c-1] == 'B' && r > 1 && c > 1 && board[r-2][c-2] == '.')
      ans = (ans + solve(r-2, c-2))%MOD;
  }

  // right diagonal
  if(r > 0 && c < n-1){
    if(board[r-1][c+1] == '.')
      ans = (ans + solve(r-1, c+1))%MOD;
    else if(board[r-1][c+1] == 'B' && r > 1 && c <n-2 && board[r-2][c+2] == '.')
      ans = (ans + solve(r-2, c+2))%MOD;
  }
  return ans;
}

int main(){

  speedBoost;
  int t; cin >> t;
  int NC = 0;
  while(t--){

    cin >> n;
    int sr, sc;
    for(int i=0; i<n; i++){
      for(int j=0; j<n; j++){
        cin >> board[i][j];
        if(board[i][j] == 'W')
          sr = i, sc = j;
      }
    }

    memset(dp, -1, sizeof dp);
    int ans = solve(sr, sc);
    cout << "Case " << ++NC << ": " << ans << "\n";
  }

  return 0;
}
