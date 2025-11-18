#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0)
#define endl "\n"
using namespace std;

int n;
typedef vector<int> vi;
vector<vi> AL;
vi dist;

int bfs(int s, vector<int> &dist){

  dist.assign(n, -1);
  dist[s] = 0;
  queue<int> q;
  q.push(s);

  int far = s;
  while(!q.empty()){
    int u = q.front(); q.pop();
    for(auto v : AL[u]){
      if(dist[v] == -1){
        dist[v] = dist[u] + 1;
        if(dist[v] > dist[far]) far = v;
        q.push(v);
      }
    }
  }

  return far;
}

int main(){

  speedBoost;
  cin >> n;
  AL.assign(n, vi());
  for(int i=0; i<n-1; i++){
    int a, b; cin >> a >> b;
    a--, b--;
    AL[a].push_back(b);
    AL[b].push_back(a);
  }

  vi tmp, distA, distB;
  int A = bfs(0, tmp);   // First point of the diameter
  int B = bfs(A, distA); // Second point of the diameter

  bfs(B, distB);

  for(int i=0; i<n; i++){
    if(i) cout << " ";
    cout << max(distA[i], distB[i]);
  }

  cout << endl;

  return 0;
}
