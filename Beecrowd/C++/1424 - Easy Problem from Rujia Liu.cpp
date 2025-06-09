#include <bits/stdc++.h>
#define MAXSIZE 1000005
using namespace std;

int main(){

  int n, m, k, v;
  while(cin >> n >> m){
    vector<vector<int>> adjList(MAXSIZE);
    for(int i=1; i<=n; i++){
        int v; cin >> v;
        adjList[v].push_back(i);
    }

    for(int i=0; i<m; i++){
        cin >> k >> v; k--;
        if(k < adjList[v].size())
            cout << adjList[v][k] << endl;
        else
            cout << 0 << endl;
    }
  }
  return 0;
}
