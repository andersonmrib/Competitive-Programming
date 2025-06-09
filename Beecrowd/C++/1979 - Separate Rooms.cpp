#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
using namespace std;

typedef vector<int> vi;
vector<vi> AL;
vi color;

const int INF = 1e9;

int main(){

  speedBoost;
  int N;
  while((cin >> N), N){

    AL.assign(N, vi());

    for(int i=0; i<N; i++){
      int id; cin >> id; id--;
      cin.ignore();
      string friends; getline(cin, friends);
      stringstream ss(friends);
      int copy;
      while(ss >> copy){
        AL[id].emplace_back(--copy);
        AL[copy].emplace_back(id);
      }
    }

    color.assign(N, INF); color[0] = 0;
    bool isBipartite = true;
    queue<int> q; q.push(0);

    while(!q.empty() && isBipartite){
      int u = q.front(); q.pop();
      for(auto v : AL[u]){
        if(color[v] == INF){
          color[v] = 1 - color[u];
         q.push(v);
        }
        else if(color[v] == color[u]){
          isBipartite = false;
          break;
        }
      }
    }

    if(isBipartite) cout << "SIM\n";
    else            cout << "NAO\n";
  }

  return 0;
}
