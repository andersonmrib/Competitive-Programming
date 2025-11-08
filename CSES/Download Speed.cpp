#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0)
#define int long long
#define endl "\n"
using namespace std;

typedef vector<int> vi;
typedef pair<int, int> ii;
const int INF = 1e9+7;

int n, m;
vector<vi> capacity;
vector<vi> AL;

int bfs(int s, int t, vi &parent){

  fill(parent.begin(), parent.end(), -1);
  parent[s] = -2;
  queue<ii> q;
  q.push({s, INF});

  while(!q.empty()){

    int cur = q.front().first;
    int flow = q.front().second;
    q.pop();

    for(auto next : AL[cur]){
      if(parent[next] == -1 && capacity[cur][next]){
        parent[next] = cur;
        int new_flow = min(flow, capacity[cur][next]);
        if(next == t)
          return new_flow;
        q.push({next, new_flow});
      }
    }
  }
  return 0;
}

int maxFlow(int s, int t){

  int max_flow = 0;
  int new_flow;
  vi parent(n);

  while(new_flow = bfs(s, t, parent)){
    max_flow += new_flow;
    int cur = t;
    while(cur != s){
      int prev = parent[cur];
      capacity[prev][cur] -= new_flow;
      capacity[cur][prev] += new_flow;
      cur = prev;
    }
  }

  return max_flow;
}

int32_t main(){

  speedBoost;
  cin >> n >> m;
  AL.assign(n, vi());
  capacity.assign(n, vi(n, 0));

  for(int i=0; i<m; i++){
    int a, b, c; cin >> a >> b >> c;
    a--, b--;
    AL[a].emplace_back(b);
    AL[b].emplace_back(a); // Residual graph
    capacity[a][b] += c;
  }

  int ans = maxFlow(0, n-1);
  cout << ans << endl;

  return 0;
}
