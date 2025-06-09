#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
using namespace std;

int dp[40][20][20][2];
int n, r, k;

// for direction: 0 for down, 1 for up
int solve(int pos, int h, int p, int dir){
  if(h < 0 || h > n) return 0;
  if(pos == 2*n) return (h == 0 && p == r) ? 1 : 0;

  int &ans = dp[pos][h][p][dir];
  if(ans != -1) return ans;
  ans = 0;

  ans += solve(pos+1, h+1, p, 1);

  int foundPeak = (dir == 1 && h == k) ? 1 : 0;
  if(h > 0 && foundPeak + p <= r)
    ans += solve(pos+1, h-1, p+foundPeak, 0);
  return ans;
}

int main(){

  speedBoost;
  // r peaks at height k
  while(cin >> n >> r >> k){
    memset(dp, -1, sizeof dp);
    cout << solve(0, 0, 0, 0) << "\n";
  }

  return 0;
}
