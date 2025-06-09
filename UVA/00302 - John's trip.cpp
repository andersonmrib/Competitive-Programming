#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
using namespace std;

const int MAX_VERTICES = 50;
const int MAX_EDGES = 2001;

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

vector<vii> AL;
vector<bool> vis;
vi idx, deg;

vi hierholzer(int s){
  stack<ii> st;
  vi ans;
  st.push({s, -1});

  while(!st.empty()){
    int u = st.top().first;

    while(idx[u] < AL[u].size() && vis[AL[u][idx[u]].first])
      idx[u]++; // while still has neighbours, get the last one

    if(idx[u] < AL[u].size()){
      auto [street, v] = AL[u][idx[u]];
      idx[u]++;
      vis[street] = true;
      st.push({v, street});
    }
    else{
      int useIt = st.top().second;
      st.pop();
      if(useIt != -1)
        ans.push_back(useIt);
    }
  }
  reverse(ans.begin(), ans.end());
  return ans;
}

int main(){

  speedBoost;
  int x, y, z;
  while(true){

    cin >> x;
    if(x == 0){
      cin >> y;
      break;
    }

    cin >> y >> z;

    AL.assign(MAX_VERTICES, vii());
    vis.assign(MAX_EDGES, false), idx.assign(MAX_VERTICES, 0), deg.assign(MAX_VERTICES, 0);

    int start = min(x, y);
    int total_streets = 0;
    AL[x].emplace_back(z, y);
    AL[y].emplace_back(z, x);
    deg[x]++, deg[y]++;
    total_streets++;

    while((cin >> x >> y), (x || y)){
      cin >> z;
      AL[x].emplace_back(z, y);
      AL[y].emplace_back(z, x);
      deg[x]++, deg[y]++;
      total_streets++;
    }

    bool good = true;
    for(int i=0; i<MAX_VERTICES && good; i++){
      if(deg[i]&1) good = false;
      sort(AL[i].begin(), AL[i].end());
    }

    if(!good){
      cout << "Round trip does not exist.\n\n";
      continue;
    }

    vi path = hierholzer(start);
    if(total_streets != path.size()){
      cout << "Round trip does not exist.\n\n";
      continue;
    }

    for(int i=0; i<path.size(); i++)
      cout << path[i] << " \n"[i == path.size() - 1];
    cout << "\n";
  }

  return 0;
}
