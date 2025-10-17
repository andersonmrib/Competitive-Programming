#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
#define endl "\n"
using namespace std;

int main(){

  speedBoost;
  int t; cin >> t;
  while(t--){
    int n; cin >> n;
    int stirling = trunc (0.5 * (log10(2 * M_PI * n)) + n * log10(n / exp(1))) + 1;
    cout << stirling << endl;
  }

  return 0;
}
