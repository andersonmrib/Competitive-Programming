#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0)
#define endl "\n"
using namespace std;

typedef vector<int> vi;

int n, l;
vector<vi> AL, up;

int timer;
vi tin, tout;

void dfs(int u, int p){

  tin[u] = timer++;
  up[u][0] = p;

  for(int i=1; i<=l; i++){
    if(up[u][i-1] != -1)
      up[u][i] = up[up[u][i-1]][i-1];
    else
      up[u][i] = -1;
  }

  for(auto v : AL[u])
    if(v != p)
      dfs(v, u);

  tout[u] = timer++;
}

int get_kth_ancestor(int node, int k){
  for(int i=0; i<=l; i++){
    if((k >> i) & 1){
      node = up[node][i];
      if(node == -1)
        return -1;
    }
  }
    return node;
}

void preprocess(int root){
  tin.assign(n, 0);
  tout.assign(n,  0);
  timer = 0;
  l = ceil(log2(n));
  up.assign(n, vi(l+1, -1));
  dfs(root, -1);
}

int main(){

  speedBoost;
  int q;
  cin >> n >> q;

  AL.assign(n, vi());
  for(int i=1; i<n; i++){
    int boss; cin >> boss;
    boss--;
    AL[boss].push_back(i);
    AL[i].push_back(boss);
  }

  preprocess(0);
  while(q--){

    int x, k; cin >> x >> k;
    x--;
    int ans = get_kth_ancestor(x, k);
    if(ans == -1) cout << -1 << endl;
    else          cout << ans + 1 << endl;
  }

  return 0;
}
