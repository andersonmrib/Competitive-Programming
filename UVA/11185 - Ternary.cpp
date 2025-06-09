#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
using namespace std;

typedef long long ll;

string convert(ll n){

  string ans = "";
  if(n == 0) return "0";
  while(n){

    int get = n%3;
    ans.push_back(get + '0');
    n /= 3;
  }
  reverse(ans.begin(), ans.end());
  return ans;
}

int main(){

  speedBoost;
  ll n;
  while(cin >> n){
    if(n < 0) break;
    string ans = convert(n);
    cout << ans << "\n";
  }

  return 0;
}
