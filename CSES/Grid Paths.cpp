#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
using namespace std;

typedef long long ll;
#define MOD 1000000007

char grid[1001][1001];
ll memo[1001][1001];
int n;

void bottomUp(){

  for(int i=0; i<n; i++){
    if(grid[i][0] == '*')
      break;
    memo[i][0] = 1;
  }

  for(int j=0; j<n; j++){
    if(grid[0][j] == '*')
      break;
    memo[0][j] = 1;
  }

  for(int i=1; i<n; i++){
    for(int j=1; j<n; j++){
      if(grid[i][j] == '*')
        continue;

      memo[i][j] = (memo[i-1][j] + memo[i][j-1]) % MOD;
    }
  }
}

ll topDown(int i, int j){
  if(i == 0 && j == 0) return 1;
  if(i < 0 || j < 0) return 0;
  if(grid[i][j] == '*') return 0;

  if(memo[i][j] != -1) return memo[i][j];
  memo[i][j] = (topDown(i - 1, j) + topDown(i, j - 1)) % MOD;
  return memo[i][j];
}

int main(){

  speedBoost;

  cin >> n;
  for(int i=0; i<n; i++)
    for(int j=0; j<n; j++)
      cin >> grid[i][j];

  memset(memo, -1, sizeof memo);

  if(grid[0][0] == '*'){
    cout << 0 << "\n";
    return 0;
  }

  cout << topDown(n-1, n-1) << "\n";

  return 0;
}
