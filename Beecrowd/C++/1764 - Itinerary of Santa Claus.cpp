#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

vector<vii> AL;
vi taken;
priority_queue<ii> pq;

void process(int u){       // set u as taken and enqueue neighbors of u
  taken[u] = 1;
  for(auto &[v, w] : AL[u])
    if(!taken[v])
  pq.push({-w, -v});       // sort by increasing weight
}                          // then by increasing id

int main(){

  int V, E;
  while((cin >> V >> E), (V || E)){

    AL.assign(V, vii());
    pq = priority_queue<ii>();
    for(int i=0; i<E; i++){
      int u, v, w;
      cin >> u >> v >> w;
      AL[u].emplace_back(v, w);
      AL[v].emplace_back(u, w);
    }
    taken.assign(V, 0);
    process(0);
    int mst_cost = 0, num_taken = 0;
    while(!pq.empty()){
      auto [w, u] = pq.top(); pq.pop();
      w = -w; u = -u;
      if(taken[u]) continue;
      mst_cost += w;
      process(u);
      ++num_taken;
      if(num_taken == V-1) break;
    }

    cout << mst_cost << endl;
  }

  return 0;
}

// Down below you can check the same solution using UFDS (Union Find Disjoint Set)

/*
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

  int V, E; // vertices and edges, respectively
  while((cin >> V >> E), V, E){

    vector<iii> EL(E);
    int max_cost = 0;

    for(int i=0; i<E; i++){
      int u, v, w;
      cin >> u >> v >> w; max_cost += w;
      EL[i] = {w, u, v};
    }

    sort(EL.begin(), EL.end());

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

    cout << mst_cost << endl;
  }

  return 0;
}
*/
