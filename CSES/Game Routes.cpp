#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
#define int long long
#define endl "\n"

using namespace std;

typedef vector<int> vi;

const int MOD = 1e9+7;

vector<vi> AL;

int32_t main(){

  speedBoost;
  int n, m; cin >> n >> m;

  AL.assign(n, vi());
  vi dp(n+1, 0), in_degree(n);
  for(int i=0; i<m; i++){
    int a, b; cin >> a >> b;
    a--, b--;
    AL[a].push_back(b);
    in_degree[b]++;
  }

  queue<int> q;
  for(int i=0; i<n; i++)
    if(in_degree[i] == 0)
      q.push(i);

  dp[0] = 1;
  while(!q.empty()){

    int u = q.front(); q.pop();
    for(auto v : AL[u]){
      dp[v] = (dp[v] + dp[u]) % MOD;
      in_degree[v]--;
      if(in_degree[v] == 0)
        q.push(v);
    }
  }

  cout << dp[n-1] << endl;

  return 0;
}
