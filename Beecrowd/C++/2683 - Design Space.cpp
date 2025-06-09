#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

vector<vii> AL;
priority_queue<ii> pq;
vi taken;

void process_min(int u){
  taken[u] = 1;
  for(auto &[v, w] : AL[u])
    if(!taken[v])
      pq.push({-w, -v});
}

void process_max(int u){
  taken[u] = 1;
  for(auto &[v, w] : AL[u])
    if(!taken[v])
      pq.push({w, v});
}

int main(){
  speedBoost;
  int N; cin >> N;
  int numberOfReadings = N;

  AL.assign(N, vii()); taken.assign(N, 0);

  while(numberOfReadings--){
    int a, b, c; cin >> a >> b >> c; a--, b--;
    AL[a].emplace_back(b, c);
    AL[b].emplace_back(a, c);
  }

  int mst_cost = 0, max_cost = 0, num_taken = 0;

  process_min(0);
  while(!pq.empty()){     // process the minimum spanning tree
    auto [w, u] = pq.top(); pq.pop();
    w = -w, u = -u;
    if(taken[u]) continue;
    mst_cost += w;
    process_min(u);
    num_taken++;
    if(num_taken == N-1) break;
  }

  while(!pq.empty()) pq.pop();
  taken.assign(N, 0), num_taken = 0, process_max(0);

  while(!pq.empty()){     // process the maximum spanning tree
    auto [w, u] = pq.top(); pq.pop();
    if(taken[u]) continue;
    max_cost += w;
    process_max(u);
    num_taken++;
    if(num_taken == N-1) break;
  }

  cout << max_cost << endl << mst_cost << endl;

  return 0;
}
