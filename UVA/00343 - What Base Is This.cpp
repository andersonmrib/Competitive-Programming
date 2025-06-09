#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
#define int long long
using namespace std;

typedef tuple<bool, int, int> tp;

int getDigit(char c) { return c <= '9' ? c - '0' : c - 'A' + 10; }

int getMinBase(string str){
  int ans = 1;
  for(auto c : str)
    ans = max(ans, getDigit(c));
  return ans + 1;
}

int convert(string str, int b){
  int ans = 0, base = 1;
  reverse(str.begin(), str.end());
  for(auto c : str){
    ans += (getDigit(c) * base);
    base *= b;
  }
  return ans;
}

tp solve(string a, string b){
  for(int i=getMinBase(a); i<=36; i++)
  for(int j=getMinBase(b); j<=36; j++)
    if(convert(a, i) == convert(b, j))
      return {true, i, j};
  return {false, 0, 0};
}

int32_t main(){

  speedBoost;

  string a, b;
  while(cin >> a >> b){

    tp ans = solve(a, b);
    auto [f, s, t] = ans;
    if(f == true)
      cout << a << " (base " << s << ") = " << b << " (base " << t << ")\n";
    else
      cout << a << " is not equal to " << b << " in any base 2..36\n";
  }

  return 0;
}
