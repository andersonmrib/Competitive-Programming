#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
using namespace std;

typedef vector<int> vi;
vector<vi> AL;
vi dfs_num, dfs_low, visited, ans;
stack<int> St;
int numSCC, dfsNumberCounter;

enum {UNVISITED = -1};

void tarjan(int u, unordered_map<int, string> &intToName){
  dfs_low[u] = dfs_num[u] = dfsNumberCounter++;
  St.push(u);
  visited[u] = 1;
  for(auto v : AL[u]){
    if(dfs_num[v] == UNVISITED)
      tarjan(v, intToName);
    if(visited[v])
      dfs_low[u] = min(dfs_low[u], dfs_low[v]);
  }

  if(dfs_low[u] == dfs_num[u]){
    numSCC++;
    while(1){
      int v = St.top(); St.pop(); visited[v] = 0;
      cout << intToName[v];
      if(u == v) { cout << "\n"; break; }
      else         cout << ", ";
    }
  }
}

int main(){

  speedBoost;
  int n, m;
  int numCases = 0;
  bool first = true;

  while((cin >> n >> m), (n || m)){

    if(!first) cout << "\n";
    first = false;

    AL.assign(n, vi());
    dfs_num.assign(n, UNVISITED), dfs_low.assign(n, 0);
    visited.assign(n, 0), ans.clear();
    dfsNumberCounter = numSCC = 0;
    unordered_map<int, string> intToName;
    unordered_map<string, int> nameToInt;

    int counter = 0;
    for(int i=0; i<m; i++){
      string name1, name2; cin >> name1 >> name2;
      int a, b;

      if(nameToInt.count(name1) == 0){
        intToName[counter] = name1;
        nameToInt[name1] = a = counter++;
      }
      else a = nameToInt[name1];
      if(nameToInt.count(name2) == 0){
        intToName[counter] = name2;
        nameToInt[name2] = b = counter++;
      }
      else b = nameToInt[name2];

      AL[a].emplace_back(b);
    }

    cout << "Calling circles for data set " << ++numCases << ":\n";

    for(int u=0; u<n; u++)
      if(dfs_num[u] == UNVISITED)
        tarjan(u, intToName);
  }

  return 0;
}
