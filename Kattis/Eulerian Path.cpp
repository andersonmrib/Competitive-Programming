#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
using namespace std;

typedef vector<int> vi;
vector<vi> AL, AL_und;
vi inDeg, outDeg;
bitset<10001> visited, used;

void dfs(int u){
  visited[u] = 1;
  for(auto v : AL_und[u])
    if(visited[v] == 0)
      dfs(v);
}

int len;
vi hierholzer(int s){
  vi ans, st, idx(len, 0);
  st.push_back(s);

  while(!st.empty()){
    int u = st.back();
    if(idx[u] < AL[u].size()){
      st.push_back(AL[u][idx[u]]);
      idx[u]++;
    }
    else{
      ans.push_back(u);
      st.pop_back();
    }
  }
  reverse(ans.begin(), ans.end());
  return ans;
}

int main(){

  speedBoost;
  int n, m;
  while((cin >> n >> m), (n || m)){

    AL.assign(n, vi()), AL_und.assign(n, vi());
    inDeg.assign(n, 0), outDeg.assign(n, 0);
    visited.reset(), used.reset();

    for(int i=0; i<m; i++){
      int u, v; cin >> u >> v;
      AL[u].emplace_back(v);
      outDeg[u]++, inDeg[v]++;

      AL_und[u].emplace_back(v);
      AL_und[v].emplace_back(u);

      used[u] = used[v] = 1;
    }

    int CC = 0;
    for(int i=0; i<n; i++)
      if(visited[i] == 0 && used[i])
         CC++, dfs(i);

     if(CC > 1){
      cout << "Impossible\n";
      continue;
     }

     bool possible = true;
     int extraIn = 0, extraOut = 0;
     int start = -1;
     for(int i=0; i<n; i++){
       if(inDeg[i] == outDeg[i] + 1)        extraIn++;
       else if(outDeg[i] == inDeg[i] + 1) { start = i; extraOut++; }
       else if(inDeg[i] != outDeg[i])       possible = false;
     }

     if(!possible || (extraIn != extraOut) || extraIn > 1 || extraOut > 1){
       cout << "Impossible\n";
       continue;
     }

     if(start == -1){
       for(int i=0; i<n; i++){
         if(outDeg[i]){
           start = i;
           break;
         }
       }
     }

     len = n;
     vi path = hierholzer(start);
     if(path.size() != m+1){
      cout << "Impossible\n";
      continue;
     }

     for(int i=0; i<path.size(); i++)
      cout << path[i] << " \n"[i == path.size() - 1];
  }

  return 0;
}

// euler path valid:
//   undirected -> deg[node] % 2 == 0 except 2 nodes
//   directed   --> all nodes inDegree[node] == outDegree[node]
//                 except 2 nodes
//                   inDegree[node] + 1 == outDegree[node];
//                   inDegree[node] - 1 == outDegree[node]

// euler circuit valid:
//   undirected: deg[node] % 2 == 0 for all nodes
//   directed:   inDegree[node] == outDegree[node]

