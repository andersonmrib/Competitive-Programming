#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
#define int long long
#define endl "\n"

using namespace std;

typedef vector<int> vi;

const int MOD = 1e9+7;
const int INF = 1e9;

vector<vi> AL;

int32_t main(){

  speedBoost;
  int n, m; cin >> n >> m;

  AL.assign(n, vi());
  vi in_degree(n), par(n, -1);
  for(int i=0; i<m; i++){
    int a, b; cin >> a >> b;
    a--, b--;
    AL[a].push_back(b);
    in_degree[b]++;
  }

  vi dp(n, -INF);
  queue<int> q;
  for(int i=0; i<n; i++)
    if(in_degree[i] == 0)
      q.push(i);

  dp[0] = 1;
  vi topo_sort;
  while(!q.empty()){

    int u = q.front(); q.pop();
    topo_sort.push_back(u);
    for(auto v : AL[u]){
      in_degree[v]--;
      if(in_degree[v] == 0)
        q.push(v);
    }
  }

  for(auto u : topo_sort){
    if(dp[u] != -INF){
      for(auto v : AL[u]){
        if(dp[u] + 1 > dp[v]){
          dp[v] = dp[u] + 1;
          par[v] = u;
        }
      }
    }
  }

  if(dp[n-1] < 0) cout << "IMPOSSIBLE\n";
  else{
    cout << dp[n-1] << endl;
    vi path;
    for(int cur = n-1; cur != -1; cur=par[cur]){
      path.push_back(cur);
    }
    reverse(path.begin(), path.end());
    for(int i=0; i<path.size(); i++)
      cout << path[i] + 1 << (i == path.size() - 1 ? "" : " ");
    cout << endl;
  }

  return 0;
}
