#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
using namespace std;

int main(){

  speedBoost;
  string code;
  while(getline(cin, code)){

    for(int i=0; i<code.size(); i++)
      code[i] = code[i] - 7;

    cout << code << "\n";
  }

  return 0;
}
