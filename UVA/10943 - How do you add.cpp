#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
using namespace std;

const int MOD = 1000000;
int memo[105][105];

int dp(int N, int K){
  if(K == 1) return 1;
  if(memo[N][K] != -1) return memo[N][K];

  int ans = 0;
  for(int split=0; split<=N; split++)
    ans = (ans + dp(N - split, K-1))%MOD;
  return memo[N][K] = ans;
}

int main(){

  speedBoost;
  int N, K;
  memset(memo, -1, sizeof memo);
  while((cin >> N >> K), (N || K)){
    cout << dp(N, K) << "\n";
  }

  return 0;
}
