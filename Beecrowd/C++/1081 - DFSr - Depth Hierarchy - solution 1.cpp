#include <bits/stdc++.h>
#define speedBoost ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

enum { UNVISITED = -1, VISITED = -2 };

typedef vector<int> vi;
vector<vi> AL;

vi dfs_num;
bool flag;

void dfs(int u, string indent){
  dfs_num[u] = VISITED;
  for(auto v : AL[u]){
    flag = true;
    if(dfs_num[v] == UNVISITED){
        cout << indent << u << '-' << v << " pathR(G," << v << ")" << endl;
        dfs(v, indent + "  ");
    }
    else
        cout << indent << u << "-" << v << endl;
    }
  }

int main(){

  int n, v, e; cin >> n;
  int u1, u2;
  int coun = 0;

  while(n--){
    cin >> v >> e;
    AL.assign(v, vi());
    dfs_num.assign(v, UNVISITED);

    for(int u=0; u<e; u++){
        cin >> u1 >> u2;
        AL[u1].emplace_back(u2);
    }

    for(int i=0; i<v; i++)
      sort(AL[i].begin(), AL[i].end());

    cout << "Caso" << " " << ++coun << ':' << endl;
    for(int i=0; i<v; i++){
        flag = false;
        if(dfs_num[i] == UNVISITED){
           dfs(i, "  ");
        if(flag) cout << endl;
         }
       }
     }

  return 0;
}
