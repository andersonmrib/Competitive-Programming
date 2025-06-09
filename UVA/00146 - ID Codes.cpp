#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
using namespace std;

int main(){

  string str;
  while(cin >> str){
    if(str == "#") break;

    if(next_permutation(str.begin(), str.end()))
      cout << str << "\n";
      else cout << "No Successor\n";
  }

  return 0;
}
