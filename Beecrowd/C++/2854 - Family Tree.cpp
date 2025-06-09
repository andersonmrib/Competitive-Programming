#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
vector<vi> AL;
vi dfs_num;

enum { UNVISITED = -1, VISITED = -2 };

void dfs(int u){
  dfs_num[u] = VISITED;
  for(auto v : AL[u])
    if(dfs_num[v] == UNVISITED)
      dfs(v);
}

int main(){

  int M, N; cin >> M >> N;
  cin.ignore();

  unordered_map<string, int> umap;
  AL.assign(M, vi()), dfs_num.assign(M, UNVISITED);

  int coun = 0;
  for(int i=0; i<N; i++){
    string person1, person2, relation;
    cin >> person1 >> relation >> person2;

    if(umap.count(person1) == 0){
      umap[person1] = coun;
      coun++;
    }
    if(umap.count(person2) == 0){
      umap[person2] = coun;
      coun++;
    }

    AL[umap[person1]].emplace_back(umap[person2]);
    AL[umap[person2]].emplace_back(umap[person1]);
  }

  int CC = 0;
  for(int u=0; u<M; u++)
    if(dfs_num[u] == UNVISITED)
      CC++, dfs(u);

  cout << CC << endl;

  return 0;
}
