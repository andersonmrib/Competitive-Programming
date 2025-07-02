#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
using namespace std;

typedef pair<int, int> ii;
typedef vector<int> vi;
vi nei, dist, vis;

int dfs(int u){
  if(dist[u]) return dist[u];
  return dist[u] = 1 + dfs(nei[u]);
}

int main(){

  speedBoost;
  int NC = 1;
  int t; cin >> t;
  while(t--){

    int n; cin >> n;
    nei.assign(n, 0);
    for(int i=0; i<n; i++){
      int u, v; cin >> u >> v;
      u--, v--;
      nei[u] = v;
    }

    int st[n] = {0};
    dist.assign(n, 0), vis.assign(n, 0);
    for(int i=0; i<n; i++){
      int cur = i, cycle_begin = -1, k = 0;
      while(!vis[cur]){
        if(vis[nei[cur]]) cycle_begin = nei[cur];
        vis[cur] = 1;
        st[k++] = cur;  // Save inside the stack this node
        cur = nei[cur]; // Go to the next node
      }

      int cycle_pos = find(st, st+k, cycle_begin) - st; // Index of node which starts the cycle
      int cycle_len = k - cycle_pos; // Trivial
      for(; cycle_pos<k; cycle_pos++) dist[st[cycle_pos]] = cycle_len;
    }

    for(int i=0; i<n; i++)
      if(!dist[i])
        dfs(i);

    int idx = max_element(dist.begin(), dist.end()) - dist.begin();
    cout << "Case " << NC++ << ": " << idx+1 << "\n";
  }

  return 0;
}
