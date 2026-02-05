#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
#define int long long
#define endl "\n"

using namespace std;

typedef vector<int> vi;

const int INF = 1e9;

vector<vi> AL;

vi match, vis;

int Aug(int L){
  if(vis[L]) return 0;
  vis[L] = 1;
  for(auto R : AL[L])
    if((match[R] == -1) || Aug(match[R])){
      match[R] = L;
      return 1;
    }
  return 0;
}

int32_t main(){

  speedBoost;
  int n, m, k; cin >> n >> m >> k;

  // Boys left, girls right
  AL.assign(n, vi());
  for(int i=0; i<k; i++){
    int a, b; cin >> a >> b;
    a--, b--;
    AL[a].push_back(b);
  }

  match.assign(m, -1);
  int r = 0;
  for(int i=0; i<n; i++){
    vis.assign(n, 0);
    r += Aug(i);
  }

  cout << r << endl;
  for(int i=0; i<m; i++)
    if(match[i] != -1)
      cout << match[i] + 1 << " " << i + 1 << endl;

  return 0;
}
