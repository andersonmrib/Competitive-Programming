#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
using namespace std;

typedef vector<int> vi;
vector<vi> AL;
vi weight, dist;
int total;

int toNum(char c){
  return c - 'A';
}

void dfs(int u){
  for(auto v : AL[u]){
    if(dist[u] + weight[v] > dist[v]){
      dist[v] = dist[u] + weight[v];
      total = max(total, dist[v]);
    }
    dfs(v);
  }
}

int main(){

  speedBoost;
  int t; cin >> t;
  string dummy;
  getline(cin, dummy);
  getline(cin, dummy);
  while(t--){

    int ans = 0;
    AL.assign(26, vi());
    weight.assign(26, -1);

    string line;
    while(getline(cin, line)){

      if(line.empty()) break;

      stringstream ss(line);
      char node;
      ss >> node;
      int u, w, v;
      u = toNum(node);
      ss >> w;
      weight[u] = w;
      while(ss >> node){
        v = toNum(node);
        AL[u].emplace_back(v);
      }
    }

    for(int i=0; i<26; i++){
      if(weight[i] != -1){
        dist.assign(26, 0);
        total = 0;
        dist[i] = weight[i];
        dfs(i);
        ans = max(ans, total);
      }
    }

    cout << ans << "\n";
    if(t) cout << "\n";
  }

  return 0;
}
