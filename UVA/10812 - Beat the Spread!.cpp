#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
#define endl "\n"
using namespace std;

int main(){

  speedBoost;
  int n; cin >> n;
  while(n--){

    // Simple linear system equation
    int s, d; cin >> s >> d;
    int a = (s+d)/2, b = (s-d)/2;

    if((s < d) || (s + d) % 2 != 0)
      cout << "impossible\n";
    else
      cout << a << " " << b << endl;
  }

  return 0;
}
