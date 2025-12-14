#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
#define endl "\n"

using namespace std;

int main(){

  speedBoost;
  int t; cin >> t;
  while(t--){

    int a, b; cin >> a >> b;
    if((a+b)%3 == 0 && a <= 2*b && b <= 2*a)
      cout << "YES\n";
    else
      cout << "NO\n";
  }

  return 0;
}
