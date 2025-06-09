#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
using namespace std;

typedef vector<int> vi;
vector<vi> AL, AL_T;
vi dfs_num, S;

enum {UNVISITED = -1};

void kosaraju(int u, int pass){
  dfs_num[u] = 1;
  vi &neighbors = (pass == 1) ? AL[u] : AL_T[u];
  for(auto v : neighbors)
    if(dfs_num[v] == UNVISITED)
      kosaraju(v, pass);
  S.push_back(u);
}

int main(){

  speedBoost;
  int P, T;
  while((cin >> P >> T), (P || T)){

    cin.ignore();

    AL.assign(P, vi()), AL_T.assign(P, vi());
    dfs_num.assign(P, UNVISITED), S.clear();
    unordered_map<string, int> umap;
    int counter = 0;

    string str1, str2;
    for(int i=0; i<P; i++){
      getline(cin, str1);
      umap[str1] = counter++;
    }

    for(int i=0; i<T; i++){
      int a, b;
      getline(cin, str1); getline(cin, str2);
      a = umap[str1], b = umap[str2];
      AL[a].emplace_back(b);
      AL_T[b].emplace_back(a);
    }

    for(int u=0; u<P; u++)
      if(dfs_num[u] == UNVISITED)
        kosaraju(u, 1);

    dfs_num.assign(P, UNVISITED);
    int numSCC = 0;
    for(int u=P-1; u>=0; u--)
      if(dfs_num[S[u]] == UNVISITED)
        numSCC++, kosaraju(S[u], 2);

    cout << numSCC << "\n";
  }

  return 0;
}
