#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
using namespace std;

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

vector<vii> AL;
vi taken;
priority_queue<ii> pq;

void process(int u){
  taken[u] = 1;
  for(auto &[v, w] : AL[u])
    if(!taken[v])
      pq.push({-w, -v});
}

int main(){

  speedBoost;
  int N, M; cin >> N >> M;

  AL.assign(N, vii());
  for(int i=0; i<M; i++){
    int u, v, c; cin >> u >> v >> c; u--, v--;
    AL[u].emplace_back(v, c);
    AL[v].emplace_back(u, c);
  }

  taken.assign(N, 0);
  int mst_cost = 0, num_taken = 0;

  process(0);
  while(!pq.empty()){
    auto [w, u] = pq.top(); pq.pop();
    w = -w, u = -u;

    if(taken[u]) continue;

    mst_cost += w;
    process(u);
    num_taken++;

    if(num_taken == N-1) break;
  }
  cout << mst_cost << "\n";

  return 0;
}
