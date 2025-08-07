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
