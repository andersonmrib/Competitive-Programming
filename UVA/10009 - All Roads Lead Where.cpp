#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
using namespace std;

void printPath(map<string, string> prev, string v){
  string u = prev[v];
  if(u != v)
    printPath(prev, u);
  cout << v[0];
}

int main(){

    speedBoost;
    int t; cin >> t;
    while(t--){

      int m, n; cin >> m >> n;
      map<string, vector<string>> AL;

      for(int i=0; i<m; i++){
        string u, v; cin >> u >> v;
        AL[u].push_back(v);
        AL[v].push_back(u);
      }

      for(int i=0; i<n; i++){
        string s, t; cin >> s >> t;
        map<string, string> prev; prev[s] = s;

        queue<string> q; q.push(s);
        while(!q.empty()){
          string u = q.front(); q.pop();
          for(int j=0; j<AL[u].size(); j++){
            string v = AL[u][j];

            if(!prev.count(v)){
              prev[v] = u;
              q.push(v);
            }
          }
        }

        printPath(prev, t);
        cout << "\n";
      }
      if(t) cout << "\n";
    }

  return 0;
}
