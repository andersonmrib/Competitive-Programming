#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
using namespace std;

typedef vector<int> vi;
vector<vi> AL;
vi dfs_num, memo, num_paths;

enum {UNVISITED = -1, VISITED = -2};

/*int dfs(int u){

  if(memo[u] != -1) return memo[u];
  if(AL[u].empty()) return 1;

  int sum = 0;
  for(auto v : AL[u])
    sum += dfs(v);

  return memo[u] = sum;
}*/

int main(){

  speedBoost;
  string line;
  bool first = true;
  while(getline(cin, line)){

    if(line.empty()) continue;

    if(!first) cout << "\n";
    first = false;

    int n = stoi(line);
    AL.assign(n, vi()), dfs_num.assign(n, UNVISITED);
    for(int i=0; i<n; i++){

      getline(cin, line);
      stringstream ss(line);
      int k, x;
      ss >> k;
      for(int j=0; j<k; j++){
        ss >> x;
        AL[i].emplace_back(x);
      }
    }

   // memo.assign(n, -1);
   // int ans = dfs(0);

    num_paths.assign(n, 0);
    num_paths[0] = 1;
    for(int u=0; u<n; u++){
      for(auto v : AL[u]){
        num_paths[v] += num_paths[u];
      }
    }

    int ans = 0;
    for(int i=0; i<n; i++)
      if(AL[i].empty()) ans += num_paths[i]; // leaf node

    cout << ans << "\n";
  }

  return 0;
}
