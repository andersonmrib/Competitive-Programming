#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
using namespace std;

typedef long long ll;

string toBinary(ll n){
  if(n == 0) return "0";
  string res = "";
  while(n){
    int mod = n%2;
    res += mod + '0';
    n /= 2;
  }
  reverse(res.begin(), res.end());
  return res;
}

int main(){

  speedBoost;
  string x, y;
  bool first = true;
  while(cin >> x >> y){

    if(x == "0" && y == "0") break;

    if(!first) cout << "\n";
    first = false;

    ll Xnum = stoll(x, nullptr, 2);
    ll Ynum = stoll(y, nullptr, 2);
    ll finalProd = Xnum * Ynum;
    string str = toBinary(finalProd);
    int n = str.size();

    cout << setw(n) << right << x << "\n";
    cout << setw(n) << right << y << "\n";
    int better = max(x.size(), y.size());

    string aux(better, '-');
    cout << setw(n) << right << aux << "\n";

    for(int i=0; i<y.size(); i++){
      if(y[y.size() - i - 1] == '1')
        cout << setw(n-i) << right << x << "\n";
      else{
        string zeros(x.size(), '0');
        cout << setw(n-i) << right << zeros << "\n";
      }
    }

    aux = string(n, '-');
    cout << setw(n) << right << aux << "\n";
    cout << str << "\n";
  }

  return 0;
}
