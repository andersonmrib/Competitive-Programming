#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
using namespace std;

typedef long long ll;

int main(){

  speedBoost;
  int N;
  while((cin >> N), N){

    ll ans = 0;
    for(int i=1; i<N; i++)
      for(int j=i+1; j<=N; j++)
        ans += __gcd(i, j);

    cout << ans << "\n";
  }

  return 0;
}
