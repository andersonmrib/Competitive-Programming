#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
using namespace std;

int main(){

  int first;
  while((cin >> first), first){
    int value;
    int ans = 0;
    while((cin >> value), value){
      ans = __gcd(ans, value-first);
    }
    cout << abs(ans) << "\n";
  }

  return 0;
}
