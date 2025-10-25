#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
#define endl "\n"
using namespace std;

int main(){

  speedBoost;
  int t; cin >> t;
  while(t--){

    int n, I;
    float p;
    cin >> n >> p >> I;

    if(p == 0.0){
      cout << "0.0000" << endl;
      continue;
    }

    float q = 1.0 - p;
    float ans = p * pow(q, I-1) / (1.0 - pow(q, n));

    cout << fixed << setprecision(4);
    cout << ans << endl;
  }

  return 0;
}
