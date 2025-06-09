#include <bits/stdc++.h>
using namespace std;

int main(){

  int Q, E; cin >> Q >> E;

  unordered_set<int> visited;
  for(int i=0; i<E; i++){
    int v; cin >> v;
    visited.insert(v);
  }

  for(int i=0; i<Q; i++){
    int ci; cin >> ci;

    if(!visited.count(ci)){
      cout << 1 << endl;
      visited.insert(ci);
    }
    else
      cout << 0 << endl;
  }

  return 0;
}
