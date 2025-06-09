#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
vector<vi> AL, AL_T;
vi dfs_num, S;

enum { UNVISITED = -1 };

void kosaraju(int u, int pass){                  // pass = 1 (original), 2 (transpose)
  dfs_num[u] = 1;
  vi &neighbor = (pass == 1) ? AL[u] : AL_T[u]; // reference for avoiding copying
  for(auto v : neighbor)
    if(dfs_num[v] == UNVISITED)
      kosaraju(v, pass);
  S.push_back(u);                                // pretty similar to topological sort
}

int main(){

  int N, M;
  while((cin >> N >> M), N, M){
    AL.assign(N, vi()); AL_T.assign(N, vi());
    while(M--){
      int V, W, P;
      cin >> V >> W >> P; V--; W--;
      AL[V].emplace_back(W);
      AL_T[W].emplace_back(V);
      if(P == 2){
        AL[W].emplace_back(V);
        AL_T[V].emplace_back(W);
      }
    }

    S.clear();
    dfs_num.assign(N, UNVISITED);
    for(int u=0; u<N; u++)
      if(dfs_num[u] == UNVISITED)
        kosaraju(u, 1);

    int CC = 0;
    dfs_num.assign(N, UNVISITED); // cleans it for the second pass
    for(int i=N-1; i>=0; i--)
      if(dfs_num[S[i]] == UNVISITED)
        CC++, kosaraju(S[i], 2);

    if(CC == 1) cout << 1 << endl;
    else        cout << 0 << endl;
  }

  return 0;
}
