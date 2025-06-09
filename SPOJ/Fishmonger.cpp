#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
using namespace std;

typedef vector<int> vi;
typedef pair<int, int> ii;
vector<vi> travelTime, toll;
vector<vector<ii>> memo;

const int INF = 1e9;
int n, t;

ii dp(int cur, int t_left){
  if(t_left < 0) return {INF, INF};
  if(cur == n-1) return {0, 0};
  if(memo[cur][t_left] != make_pair(-1, -1)) return memo[cur][t_left];

  ii ans = {INF, INF};
  for(int x=0; x<n; x++)
    if(cur != x){
      auto [tollpaid, timeneeded] = dp(x, t_left-travelTime[cur][x]);
      if(tollpaid + toll[cur][x] < ans.first){
        ans.first = tollpaid + toll[cur][x];
        ans.second = timeneeded + travelTime[cur][x];
      }
    }
  return memo[cur][t_left] = ans;
}

int main(){

  speedBoost;

  while((cin >> n >> t), (n || t)){

    travelTime.assign(n, vi(n)), toll.assign(n, vi(n));
    memo.assign(n, vector<ii>(t+1, {-1, -1}));

    for(int i=0; i<n; i++)
      for(int j=0; j<n; j++)
        cin >> travelTime[i][j];

    for(int i=0; i<n; i++)
      for(int j=0; j<n; j++)
        cin >> toll[i][j];

    ii ans = dp(0, t);
    cout << ans.first << " " << ans.second << "\n";
  }

  return 0;
}
