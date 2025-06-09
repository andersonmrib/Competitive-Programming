#include <bits/stdc++.h>
using namespace std;

typedef tuple<int, int, int> iii;
typedef vector<int> vi;

class UnionFind{
  private:
    vi p, rank, setSize;
    int numSets;
  public:
    UnionFind(int N){
      p.assign(N, 0); for(int i=0; i<N; i++) p[i] = i;
      rank.assign(N, 0);
      setSize.assign(N, 1);
      numSets = N;
    }
    int findSet(int i){ return (p[i] == i) ? i : (p[i] = findSet(p[i])); }
    bool isSameSet(int i, int j){ return findSet(i) == findSet(j); }

    void unionSet(int i, int j){
      if(isSameSet(i, j)) return;
      int x = findSet(i), y = findSet(j);
      if(rank[x] > rank[y]) swap(x, y);
        p[x] = y;
      if(rank[x] == rank[y]) rank[y]++;
      setSize[y] += setSize[x];
      numSets--;
    }
    int numDisjontSets(){ return numSets; }
    int sizeOfSet(int x){ return setSize[findSet(x)]; }
};

int main(){

  int V, E;                                // vertices and edges, respectively
  while((cin >> V >> E), V, E){

    vector<iii> EL(E);                     // a simple edge list
    int max_cost = 0;                      // going to store the cost of all roads

    for(int i=0; i<E; i++){
      int u, v, w;                         // reads as u, v, w
      cin >> u >> v >> w; max_cost += w;
      EL[i] = {w, u, v};                   // using as w, u, v
    }

    sort(EL.begin(), EL.end());            // sort before we use Kruskal's algorithm

    int mst_cost = 0, num_taken = 0;
    UnionFind UF(V);

    for(int i=0; i<E; i++){
      auto [w, u, v] = EL[i];
      if(UF.isSameSet(u, v)) continue;
      mst_cost += w;
      UF.unionSet(u, v);
      num_taken++;
      if(num_taken == V-1) break;
    }

    cout << max_cost - mst_cost << endl;
  }

  return 0;
}
