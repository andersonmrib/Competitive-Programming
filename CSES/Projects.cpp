#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0)
#define int long long
#define endl "\n"
using namespace std;

typedef vector<int> vi;

const int MOD = 1e9+7;

struct project{
  int s, e;
  int reward;
};

bool cmp(const project &a, const project &b){
  return a.e < b.e;
}

int32_t main(){

  speedBoost;
  int n; cin >> n;
  vector<project> projects(n);
  for(int i=0; i<n; i++)
    cin >> projects[i].s >> projects[i].e >> projects[i].reward;

  sort(projects.begin(), projects.end(), cmp);
  vi dp(n+1, 0);
  vi end_times;
  for(auto p : projects)
    end_times.push_back(p.e);

  for(int i=1; i<=n; i++){
    int op1 = dp[i-1];
    auto it = lower_bound(end_times.begin(), end_times.end(), projects[i-1].s);
    int idx = distance(end_times.begin(), it);

    int op2 = projects[i-1].reward;
    if(idx > 0)
      op2 += dp[idx];

    dp[i] = max(op1, op2);
  }

  cout << dp[n] << endl;

  return 0;
}
