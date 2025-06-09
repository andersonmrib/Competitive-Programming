#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
using namespace std;

int main(){

  speedBoost;
  int t; cin >> t;
  int NC = 0;
  while(t--){

    string s1, s2;
    cin >> s1 >> s2;

    if(s1 == s2){
      cout << "Pair #" << ++NC << ": All you need is love!\n";
      continue;
    }

    int v1 = stoi(s1, nullptr, 2);
    int v2 = stoi(s2, nullptr, 2);

    if(__gcd(v1, v2) != 1)
      cout << "Pair #" << ++NC << ": All you need is love!\n";
    else
      cout << "Pair #" << ++NC << ": Love is not all you need!\n";
  }

  return 0;
}
