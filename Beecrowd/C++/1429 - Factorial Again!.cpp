#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int fac(int x){
  int f = 1;
  for(int i=1; i <= x; i++)
    f *= i;
  return f;
}

int main(){

  string str;
  while(cin >> str){
    if(str[0] == '0') break;

    int len = str.size();

    ll ans = 0;
    for(auto c : str){
      ans += (c - '0') * fac(len);
      len--;
    }
  cout << ans << endl;
  }

  return 0;
}
