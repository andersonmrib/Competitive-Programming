#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

vector<vii> AL;
priority_queue<ii> pq;
vi taken;

void process(int u){
  taken[u] = 1;
  for(auto &[v, w] : AL[u])
    if(!taken[v])
  pq.push({-w, -v});
}

int main(){

  int R, C; cin >> R >> C;

  AL.assign(R, vii()); taken.assign(R, 0);
  int mst_cost = 0, num_taken = 0;

  for(int i=0; i<C; i++){
    int v, w, p; cin >> v >> w >> p; v--, w--;
    AL[v].emplace_back(w, p);
    AL[w].emplace_back(v, p);
  }

  process(0);
    while(!pq.empty()){
      auto [w, u] = pq.top(); pq.pop();
      w = -w, u = -u;
      if(taken[u]) continue;
      mst_cost += w;
      process(u);
      num_taken++;
      if(num_taken == R-1) break;
    }

  cout << mst_cost << endl;

  return 0;
}
