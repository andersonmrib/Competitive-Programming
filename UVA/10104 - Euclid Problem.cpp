#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
using namespace std;

int extEuclid(int a, int b, int &x, int &y){
  int xx = y = 0;
  int yy = x = 1;
  while(b){
    int q = a/b;
    int t = b; b = a%b; a = t;
    t = xx; xx = x-q*xx; x = t;
    t = yy; yy = y-q*yy; y = t;
  }
  return a;
}

int main(){

  speedBoost;

  int a, b;
  while(cin >> a >> b){

    int x, y, gcd;
    gcd = extEuclid(a, b, x, y);
    cout << x << " " << y << " " << gcd << "\n";
  }

  return 0;
}
