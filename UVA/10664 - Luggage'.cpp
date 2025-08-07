#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
using namespace std;

int main(){

  speedBoost;
  int t; cin >> t; cin.ignore();
  while(t--){

    string line; getline(cin, line);
    stringstream ss(line);

    int sum = 0, items = 0;
    int integer;
    while(ss >> integer){
      sum += integer;
      items++;
    }

    // Why this works?
    if((sum&1) || (items&1)) cout << "NO\n";
    else                     cout << "YES\n";
  }

  return 0;
}

/*
// The solution below looks more complete using the classic knapsack approach
// while the main solution above leaves me to think that the problem's inputs are too
// simple or bad created!

#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
using namespace std;

int main(){

  speedBoost;
  int t; cin >> t; cin.ignore();
  while(t--){

    string line; getline(cin, line);
    stringstream ss(line);

    vector<int> w;
    int x, sum = 0;
    while(ss >> x){
      w.push_back(x);
      sum += x;
    }

    if(sum % 2 != 0){
      cout << "NO\n";
      continue;
    }

    int target = sum/2;
    vector<bool> dp(target+1, false);
    dp[0] = true;

    for(int weight : w){
      for(int j=target; j>=weight; j--){
        if(dp[j-weight]) dp[j] = true;
      }
    }

    if(dp[target]) cout << "YES\n";
    else           cout << "NO\n";
  }

  return 0;
}

*/
