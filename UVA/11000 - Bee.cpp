#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
using namespace std;

typedef long long ll;

int main(){

  speedBoost;
  int n;
  while(cin >> n){
    if(n < 0) break;

    ll M = 0, F = 0;

    for(int y=1; y<=n; y++){
      ll nextM = F + M + 1;
      ll nextF = M;
      M = nextM, F = nextF;
    }

    cout << M << " " << M + F + 1 << "\n";
  }

  return 0;
}
