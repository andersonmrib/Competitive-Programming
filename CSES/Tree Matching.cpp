#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0)
#define endl "\n"
using namespace std;

typedef vector<int> vi;
vector<bool> done;

vector<vi> AL;

void dfs(int u, int p, int &ans){

  for(auto v : AL[u]){
    if(v != p){
      dfs(v, u, ans);
      if(!done[v] && !done[u]) done[u] = done[v] = true, ans++;
    }
  }
}

int main(){

  speedBoost;
  int n; cin >> n;

  AL.assign(n, vi());
  done.assign(n, false);
  for(int i=0; i<n-1; i++){
    int a, b; cin >> a >> b;
    a--, b--;
    AL[a].emplace_back(b);
    AL[b].emplace_back(a);
  }

  int ans = 0;
  dfs(0, -1, ans);
  cout << ans << endl;

  return 0;
}
