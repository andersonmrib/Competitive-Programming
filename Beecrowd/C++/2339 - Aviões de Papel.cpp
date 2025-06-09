#include <bits/stdc++.h>
using namespace std;

int main(){

  int c, p, f; cin >> c >> p >> f;

  bool possible =  c <= p/f;

  if(possible) cout << "S" << endl;
  else         cout << "N" << endl;

  return 0;
}
