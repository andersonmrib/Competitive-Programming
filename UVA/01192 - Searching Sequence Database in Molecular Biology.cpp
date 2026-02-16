#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
#define int long long
#define endl "\n"

using namespace std;

typedef vector<int> vi;

int get_score(const string &a, const string &b){
  int n = a.size(), m = b.size();
  vector<vi> dp(n+1, vi(m+1));
  for(int i=1; i<=n; i++) dp[i][0] = i * -7;
  for(int j=1; j<=m; j++) dp[0][j] = j * -7;
  for(int i=1; i<=n; i++){
    for(int j=1; j<=m; j++){
      dp[i][j] = dp[i-1][j-1];
      if(a[i-1] == b[j-1])
        dp[i][j] += 5;
      else
        dp[i][j] += -4;
      dp[i][j] = max(dp[i][j], dp[i-1][j] - 7);
      dp[i][j] = max(dp[i][j], dp[i][j-1] - 7);
    }
  }

  return dp[n][m];
}

int32_t main(){

  speedBoost;
  string query, data;
  if(!(cin >> query >> data)) return 0;

  vector<pair<string, int>> res;
  int mx = -2e9;

  string name, seq_data;
  while(cin >> name >> seq_data){
    int cur = get_score(data, seq_data);
    if(cur > mx){
      mx = cur;
      res.clear();
      res.push_back({seq_data, cur});
    }
    else if(cur == mx)
      res.push_back({seq_data, cur});
  }

    cout << "The query sequence is:" << endl;
    cout << data << endl << endl;

    cout << "The most similar sequences are:" << endl << endl;
    for(int i=0; i<res.size(); i++){
      auto [s, v] = res[i];
      cout << s << endl;
      cout << "The similarity score is: " << v << endl;
      if(i < res.size() - 1) cout << endl;
    }

  return 0;
}
