#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
using namespace std;

int solve(string x0){
  int ans = 1;
  string prev = x0;
  while(true){
    string cur = to_string(prev.size());
    if(cur == prev) break;
    prev = cur;
    ans++;
  }
  return ans;
}

int main(){

  speedBoost;
  string number;
  while(cin >> number){

    if(number == "END") break;
    cout << solve(number) << "\n";
  }

  return 0;
}
