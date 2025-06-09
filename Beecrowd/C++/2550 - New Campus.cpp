#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
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
/*
  At the date of 07/17/2024, this question is highly bugged!
  Your code may pass some test cases, others don't. I have got AC and TLE
  using the same code... be aware of that!
  Remember to use faster IO tools if you face the same problem, or BETTER, USE scanf and printf
*/


int main(){
  speedBoost;
  int N, M;
  while(cin >> N >> M){

    AL.assign(N, vii()); taken.assign(N, 0);
    pq = priority_queue<ii>();
    int mst_cost = 0, num_taken = 0;


    for(int i=0; i<M; i++){
      int a, b, c; cin >> a >> b >> c; a--, b--;
      AL[a].emplace_back(b, c);
      AL[b].emplace_back(a, c);
    }

    process(0);

    while(!pq.empty() && num_taken < N-1){   // simply implement Prim's algorithm
      auto [w, u] = pq.top(); pq.pop();
      w = -w, u = -u;
      if(taken[u]) continue;
      mst_cost += w;
      process(u);
      num_taken++;
    }

    bool impossible = false;                 // check if all the vertices have been marked as 1
    for(int i=0; i<N; i++)                   // it means we have generated the full MST!
      if(!taken[i]) impossible = true;       // if not... it means we do not have a complete graph


    if(impossible)
      cout << "impossivel" << endl;
    else
      cout << mst_cost << endl;
  }

  return 0;
}
