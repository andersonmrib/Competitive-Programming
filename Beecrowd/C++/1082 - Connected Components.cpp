#include <bits/stdc++.h>
#define speedBoost ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

enum { UNVISITED = -1, VISITED = -2 };

typedef vector<int> vi;
vector<vi> AL;
vector<char> letters; // pay attention to this vector
vi dfs_num;

void dfs(int u){
  letters.push_back(u+'a'); // going to use him for the ordering criteria
  dfs_num[u] = VISITED;
  for(auto v : AL[u])
    if(dfs_num[v] == UNVISITED)
    dfs(v);
}

int main(){

  int n; cin >> n;
  int ct = 0;

  while(n--){
    int v, e;
    cin >> v >> e;

    AL.assign(v, vi());
    dfs_num.assign(v, UNVISITED);

    char u1, u2;
    for(int u=0; u<e; u++){
        cin >> u1 >> u2;

        int vertex1 = u1 - 'a';
        int vertex2 = u2 - 'a';

        AL[vertex1].emplace_back(vertex2);
        AL[vertex2].emplace_back(vertex1);
    }
    for(int i=0; i<v; i++)
      sort(AL[i].begin(), AL[i].end());

    int CC = 0; // number of connected components
    printf("Case #%d:\n", ++ct);
    for(int u=0; u<v; u++){
        if(dfs_num[u] == UNVISITED){
          CC++;
          dfs(u);                               // after completing the dfs
          sort(letters.begin(), letters.end()); // sorts the entire vector
          for(auto x : letters)                 // and starts printing
            cout << x << ',';
          cout << endl;
          letters.clear();                      // final clear for next use
        }
      }
        cout << CC << " connected components\n\n";
     }

  return 0;
}
