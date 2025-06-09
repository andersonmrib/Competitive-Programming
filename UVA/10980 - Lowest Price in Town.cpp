#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
using namespace std;

int main(){

  int NC = 0;
  int a, b, m;
  while(scanf("%d.%d %d", &a, &b, &m) != EOF){

     vector<pair<int, int>> offers;
     offers.push_back({1, a*100 + b});

     for(int i=0; i<m; i++){
      int quantity, a, b;
      scanf("%d %d.%d", &quantity, &a, &b);
      offers.push_back({quantity, a*100 + b});
     }

     cin.ignore();
     string line; getline(cin, line);
     stringstream ss(line);
     vector<int> queries;

     int upper = 0, k;
     while(ss >> k){
      upper = max(upper, k);
      queries.push_back(k);
     }

     vector<int> dp(upper+1, 1e7);
     dp[0] = 0;
     for(auto [qtd, p] : offers){
      for(int i=0; i<=upper; i++){
        int newPrice = (i >= qtd) ? dp[i-qtd] : 0;
        newPrice += p;
        dp[i] = min(dp[i], newPrice);
      }
     }

     cout << "Case " << ++NC << ":\n";
     cout << fixed << setprecision(2);
     for(auto q : queries)
      printf("Buy %d for $%.2f\n", q, dp[q]/100.0);
  }

  return 0;
}
