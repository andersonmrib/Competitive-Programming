#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
using namespace std;

int n, k, NC = 1;
int numbers[10001];
int memo[10001][101];
int vis[10001][101];

bool dp(int i, int mod){

  mod = (mod%k + k) % k;
  if(i == n) return mod == 0;

  if(vis[i][mod] == NC) return memo[i][mod];
  vis[i][mod] = NC;

  int add = ((mod + numbers[i])%k + k) % k;
  int sub = ((mod - numbers[i])%k + k) % k;

  if(dp(i+1, add)) return memo[i][mod] = 1;
  if(dp(i+1, sub)) return memo[i][mod] = 1;
  return memo[i][mod] = 0;
}

int main(){

  int t; scanf("%d", &t);
  while(t--){

    scanf("%d %d", &n, &k);
    for(int i=0; i<n; i++)
      scanf("%d", &numbers[i]);

    int startMod = (numbers[0] % k + k) % k;
    bool check = dp(1, startMod);

    if(check) printf("Divisible\n");
    else      printf("Not divisible\n");

    NC++;
  }

  return 0;
}
