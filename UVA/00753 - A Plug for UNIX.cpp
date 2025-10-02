#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
#define endl "\n"
using namespace std;

typedef vector<int> vi;
typedef pair<int, int> ii;

vi vis, match;
vector<vi> AL;

enum {VISITED = -1, UNVISITED = -2};

int Aug(int L){
  if(vis[L] == VISITED) return 0;
  vis[L] = VISITED;
  for(auto R : AL[L])
    if((match[R] == -1) || Aug(match[R])){
      match[R] = L;
      return 1;
    }
  return 0;
}

void solve(){

  int n, m, k;
  map<string, int> umap;
  int ctt = 0;

  auto get_id = [&](const string &s){
    if(umap.find(s) == umap.end()){
      umap[s] = ctt++;
    }
    return umap[s];
  };

  cin >> n; vector<string> receptacles(n);
  for(int i=0; i<n; i++){
    cin >> receptacles[i];
    get_id(receptacles[i]);
  }

  cin >> m; vector<pair<string, string>> devices(m);
  for(int i=0; i<m; i++){
    cin >> devices[i].first >> devices[i].second;
    get_id(devices[i].second);
  }

  cin >> k; vector<pair<string, string>> adapters(k);
  for(int i=0; i<k; i++){
    cin >> adapters[i].first >> adapters[i].second;
    get_id(adapters[i].first);
    get_id(adapters[i].second);
  }

  vector<vector<bool>> transitive(ctt, vector<bool>(ctt, false));
  for(int i=0; i<ctt; i++) transitive[i][i] = true;

  for(auto a : adapters)
    transitive[get_id(a.second)][get_id(a.first)] = true;

  for(int k=0; k<ctt; k++)
    for(int i=0; i<ctt; i++)
      for(int j=0; j<ctt; j++)
        if(transitive[i][k] && transitive[k][j])
          transitive[i][j] = true;

  AL.assign(n, vi());
  for(int i=0; i<n; i++){
    int receptacle_id = get_id(receptacles[i]);
    for(int j=0; j<m; j++){
      int device_id = get_id(devices[j].second);
      if(transitive[receptacle_id][device_id])
        AL[i].push_back(j);
    }
  }

  match.assign(m, -1);
  int max_matches = 0;
  for(int i=0; i<n; i++){
    vis.assign(n, UNVISITED);
    max_matches += Aug(i);
  }

  cout << m - max_matches << endl;
}

int main(){

  speedBoost;
  int t; cin >> t;
  string dummy;
  getline(cin, dummy);
  getline(cin, dummy);
  while(t--){
    solve();
    if(t) cout << endl;
  }

  return 0;
}
