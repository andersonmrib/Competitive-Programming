#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
using namespace std;

int main(){

  string s;
  while(cin >> s){

    int len = s.size(), match = 0;
    string t; cin >> t;

    for(int i=0; i<t.size(); i++)
      if(t[i] == s[match]) match++;

    if(match == len) cout << "Yes\n";
    else             cout << "No\n";
  }

  return 0;
}
