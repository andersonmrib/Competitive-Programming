#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
using namespace std;

int main(){

  speedBoost;
  unsigned int n;
  while((cin >> n), n){

    unsigned int sqRoot = sqrt(n);
    if(n == sqRoot*sqRoot) cout << "yes\n";
    else                   cout << "no\n";
  }

  return 0;
}
