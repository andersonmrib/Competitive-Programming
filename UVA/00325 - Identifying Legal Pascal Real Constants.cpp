#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
using namespace std;

int main(){

  speedBoost;
  regex apply_regex("[-+]?\\d+(\\.\\d+([eE][-+]?\\d+)?|[eE][-+]?\\d+)");

  string s;
  while(getline(cin, s)){

    if(s == "*") break;

    s.erase(0, s.find_first_not_of(" \t\r\n"));
    s.erase(s.find_last_not_of(" \t\r\n") + 1);

    cout << s;
    if(regex_match(s, apply_regex))
      cout << " is legal.\n";
    else
      cout << " is illegal.\n";
  }

  return 0;
}
