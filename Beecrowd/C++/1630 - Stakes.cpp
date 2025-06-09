#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b){ return b == 0 ? a : gcd(b, a%b); }

int main(){

  int x, y;
  while(cin >> x >> y)
    cout << (x/gcd(x, y))*2 + (y/gcd(x, y))*2 << endl;

  return 0;
}
