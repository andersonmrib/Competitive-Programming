#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
#define endl "\n"
using namespace std;

typedef vector<int> vi;
vector<vi> AL;
vi ans;

int dfs(int u){
  int ctt = 0;
  for(auto v : AL[u])
    ctt += 1 + dfs(v);
  return ans[u] = ctt;
}

int main(){

  speedBoost;
  int n; cin >> n;
  AL.assign(n, vi());
  for(int i=1; i<n; i++){
    int boss; cin >> boss;
    boss--;
    AL[boss].push_back(i);
  }

  ans.assign(n, 0);
  dfs(0);

  for(int i=0; i<n; i++){
    if(i > 0) cout << " ";
    cout << ans[i];
  }

  cout << endl;

  return 0;
}
