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

  int N, M, Ol; cin >> N >> M >> Ol;    // we are going to read 0 (letter),
                                        // but he has no use for us
  AL.assign(N, vii()); taken.assign(N, 0);
  for(int i=0; i<M; i++){
    int u, v, d; cin >> u >> v >> d; u--, v--;
    AL[u].emplace_back(v, d);
    AL[v].emplace_back(u, d);
  }

  process(0); // process(Ol);           // but if you want to, you can
  int mst_cost = 0, num_taken = 0;      // start processing using O (letter)
  while(!pq.empty()){                   // final result will result in the same value
    auto [w, u] = pq.top(); pq.pop();
    w = -w, u = -u;
    if(taken[u]) continue;
    mst_cost += w;
    process(u);
    num_taken++;
    if(num_taken == N-1) break;
  }

  cout << mst_cost * 2 << endl;         // simply output the cost * 2
                                        // too simple for the question statement
  return 0;
}
