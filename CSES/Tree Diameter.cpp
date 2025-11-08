#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
#define endl "\n"
using namespace std;

typedef vector<int> vi;
typedef pair<int, int> ii;
vector<vi> AL;

const int INF = 1e9;

ii bfs(int s, int n){

  vi dist(n, INF);
  dist[s] = 0;
  queue<int> q; q.push(s);
  int far = 0;
  while(!q.empty()){

    int u = q.front();
    q.pop();

    for(auto v : AL[u]){
      if(dist[v] == INF){
        dist[v] = dist[u] + 1;
        far = v;
        q.push(v);
      }
    }
  }

  return { far, dist[far] };
}

int main(){

  speedBoost;
  int n; cin >> n;
  AL.assign(n, vi());

  for(int i=0; i<n-1; i++){
    int a, b; cin >> a >> b;
    a--, b--;
    AL[a].push_back(b);
    AL[b].push_back(a);
  }

  ii fst = bfs(0, n);
  ii scd = bfs(fst.first, n);
  cout << scd.second << endl;

  return 0;
}


