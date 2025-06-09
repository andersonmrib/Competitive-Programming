#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
using namespace std;

typedef long long ll;

ll H(int n){
  ll sum = 0, sqRoot = sqrt(n);
  for(int i=1; i<=sqRoot; i++) sum += n/i;
  return (sum << 1) - sqRoot * sqRoot;
}

int main(){

  speedBoost;
  int t; cin >> t;
  while(t--){

    int n; cin >> n;
    cout << H(n) << "\n";
  }
  return 0;
}

// Try to see the pattern in n = 20
// 20 + 10 + 6 + 5 + 4 + 3 + 2 + 2 + 2 + 2 + 1 + 1 + 1 + 1 + 1 + 1 + 1 + 1 + 1 + 1
// = (20 + 10 + 6 + 5+ + 1*(20-10) + 2*(10-6) + 3*(6-5) + 4*(5-4)
// = 2*(20+10+6+5) - 4*4, where 4 is the square root of n.
