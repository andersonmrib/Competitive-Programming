#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
using namespace std;

bool div(string s, int m){
  int mod = 0;
  for(auto c : s) mod = (mod*10 + c - '0')%m;
  return (mod == 0);
}

int main(){

  speedBoost;
  string str;
  bool first = true;
  while(cin >> str){

    if(!first) cout << "\n";
    first = false;

    bool leap = (div(str, 400) || (div(str, 4) && !div(str, 100)));
    bool hulu = div(str, 15);
    bool buku = div(str, 55) && leap;

    if(leap)
      cout << "This is leap year.\n";
    if(hulu)
      cout << "This is huluculu festival year.\n";
    if(buku)
      cout << "This is bulukulu festival year.\n";
    if(!leap && !hulu && !buku)
      cout << "This is an ordinary year.\n";
  }

  return 0;
}
